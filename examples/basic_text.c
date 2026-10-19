#ifdef _WIN32
#    define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#define LA_IMPLEMENTATION
#include "external/la.h"

#include "external/glad.h"
#define RGFW_OPENGL
#define RGFW_IMPLEMENTATION
#include "external/RGFW.h"


#define HT_IMPLEMENTATION
#include "external/ht.h"


#define MAX_TEXT 128
#define VERTECIES_PER_GLYPH 6


#define WINDOW_WIDTH  960
#define WINDOW_HEIGHT 540

typedef struct Slug_Vertex Slug_Vertex;
struct Slug_Vertex
{
    float pos_x, pos_y, norm_x, norm_y;
    float tex_x, tex_y, packed_loc, max_band_indecies;
    float jac_00, jac_01, jac_10, jac_11;
    float band_scale_x, band_scale_y, band_offset_x, band_offset_y;
    float r, g, b, a;
};

typedef struct Bytes Bytes;
struct Bytes
{
    uint8_t* data;
    size_t count;
};

typedef union Convert_Float_U32 Convert_Float_U32;
union Convert_Float_U32
{
    float f;
    uint32_t u;
};

typedef struct Glyph Glyph;
struct Glyph
{
    int16_t band_loc_x, band_loc_y, band_count;
    int32_t x1, y1, x2, y2;
    int32_t advance, left_side_bearing;
};

typedef Ht(int32_t, Glyph) Glyphs;

typedef struct Dynamic_Font Dynamic_Font;
struct Dynamic_Font
{
    float em_scale;
    int32_t ascent;
    int32_t descent, line_gap;
    int32_t x1, y1, x2, y2; // bounding box
    uint32_t band_texture, curve_texture;
    uint32_t vao, vbo;
    uint32_t shader; // TODO: it's dumb to store the shader on the font, but for now...
    Glyphs glyphs;
};

Bytes try_read_entire_file(FILE* f)
{
    Bytes bytes = {0};
    fseek(f, 0, SEEK_END);
    long long file_size = ftell(f);
    rewind(f);
    bytes.data = (uint8_t*)malloc(file_size);
    bytes.count = fread(bytes.data, 1, file_size, f);
    assert((long long)bytes.count == file_size);
    return bytes;
}

#define BytesStruct(count) \
typedef struct B##count B##count;\
struct B##count {uint8_t b[count];}

BytesStruct(4);
BytesStruct(2);

B4 b4_deserialize(Bytes data, int32_t* cursor)
{
    int32_t c = *cursor;
    B4 result = {0};
    for (int i = 0;i < 4;++i)
    {
        assert((size_t)(c + i) < data.count);
        result.b[i] = data.data[c + i];
    }
    *cursor += 4;
    return result;
}


B2 b2_deserialize(Bytes data, int32_t* cursor)
{
    int32_t c = *cursor;
    B2 result = {0};
    for (int i = 0;i < 2;++i)
    {
        assert((size_t)(c + i) < data.count);
        result.b[i] = data.data[c + i];
    }
    *cursor += 2;
    return result;
}

int32_t i32_deserialize(Bytes data, int32_t* cursor)
{
    B4 i32le = b4_deserialize(data, cursor);
    int32_t result = 0;
    result |= (int32_t)i32le.b[0];
    result |= (int32_t)i32le.b[1] << 8;
    result |= (int32_t)i32le.b[2] << 16;
    result |= (int32_t)i32le.b[3] << 24;
    return result;
}

float f32_deserialize(Bytes data, int32_t* cursor)
{
    // TODO: actual deserialization
    B4 f32le = b4_deserialize(data, cursor);
    float result = *(float*)&f32le;
    return result;
}

int16_t i16_deserialize(Bytes data, int32_t* cursor)
{
    B2 i16le = b2_deserialize(data, cursor);
    int16_t result = 0;
    result |= (int32_t)i16le.b[0];
    result |= (int32_t)i16le.b[1] << 8;
    return result;
}

uint16_t u16_deserialize(Bytes data, int32_t* cursor)
{
    B2 u16le = b2_deserialize(data, cursor);
    int16_t result = 0;
    result |= (int32_t)u16le.b[0];
    result |= (int32_t)u16le.b[1] << 8;
    return result;
}

bool shader_compile_specific(uint32_t* return_handle, char* _source, uint32_t kind)
{
    uint32_t shader = glCreateShader(kind);

    char* source = _source;
    glShaderSource(shader, 1, (const char* const*)&source, NULL);
    glCompileShader(shader);

    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLint length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        length += 1;
        char* error_log = calloc(length, 1);

        glGetShaderInfoLog(shader, length, NULL, error_log);

        fprintf(stderr, "--------------------------\n");
        fprintf(stderr, "%s", error_log);
        fprintf(stderr, "--------------------------\n\n");
        free(error_log);
        return false;
    }

    *return_handle = shader;
    return true;
}

bool shader_compile(uint32_t* return_shader, const char* path)
{
    FILE* f = fopen(path, "rb");
    if (f == NULL) 
    {
        fprintf(stderr, "Could not load shader %s\n", path);
        return false;
    }
    Bytes data = try_read_entire_file(f);
    assert(data.data);

    const size_t buffer_size = (1<<16);
    char* buffer = calloc(buffer_size, 1);

    snprintf(buffer, buffer_size, "#version 330 core\n#define VERTEX_SHADER 1\n%.*s", (int)data.count, data.data);
    uint32_t frag = 0, vert = 0;

    bool vok = shader_compile_specific(&vert, buffer, GL_VERTEX_SHADER);
    memset(buffer, 0, buffer_size);
    snprintf(buffer, buffer_size, "#version 330 core\n#define FRAGMENT_SHADER 1\n%.*s", (int)data.count, data.data);
    bool fok = shader_compile_specific(&frag, buffer, GL_FRAGMENT_SHADER);
    free(buffer);

    if (!fok || !vok) return false;

    uint32_t shader = glCreateProgram();
    glAttachShader(shader, vert);
    glAttachShader(shader, frag);
    glLinkProgram(shader);

    glDeleteShader(vert);
    glDeleteShader(frag);
    int32_t success = 0;
    glGetProgramiv(shader, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLint length = 0;
        glGetProgramiv(shader, GL_INFO_LOG_LENGTH, &length);
        length += 1;
        char* error_log = calloc(length, 1);

        glGetProgramInfoLog(shader, length, NULL, error_log);

        fprintf(stderr, "%s\n", error_log);
        free(error_log);
        glDeleteProgram(shader);
        return false;
    }

    *return_shader = shader;

    return true;
}

bool load_dynamic_font(Dynamic_Font* font, Bytes lslug)
{
    char buffer[8] = {0};
    int32_t cursor = 0;
    B4 str = b4_deserialize(lslug, &cursor);
    memcpy(buffer, str.b, 4);
    int32_t version = i32_deserialize(lslug, &cursor);
    assert(version == 1);
    font->em_scale = f32_deserialize(lslug, &cursor);
    font->ascent = i32_deserialize(lslug, &cursor);
    font->descent = i32_deserialize(lslug, &cursor);
    font->line_gap = i32_deserialize(lslug, &cursor);
    font->x1 = i32_deserialize(lslug, &cursor);
    font->y1 = i32_deserialize(lslug, &cursor);
    font->x2 = i32_deserialize(lslug, &cursor);
    font->y2 = i32_deserialize(lslug, &cursor);
    int32_t glyphs_count = i32_deserialize(lslug, &cursor);
    for (int32_t i = 0;i < glyphs_count;++i)
    {
        Glyph gl = {0};
        int32_t cp = i32_deserialize(lslug, &cursor);
        gl.x1 = i32_deserialize(lslug, &cursor);
        gl.y1 = i32_deserialize(lslug, &cursor);
        gl.x2 = i32_deserialize(lslug, &cursor);
        gl.y2 = i32_deserialize(lslug, &cursor);
        gl.advance = i32_deserialize(lslug, &cursor);
        gl.left_side_bearing = i32_deserialize(lslug, &cursor);
        gl.band_loc_x = i16_deserialize(lslug, &cursor);
        gl.band_loc_y = i16_deserialize(lslug, &cursor);
        gl.band_count = i16_deserialize(lslug, &cursor);

        *ht_put(&font->glyphs, cp) = gl;
    }
    int32_t curves_count = i32_deserialize(lslug, &cursor);
    int32_t curves_texture_width = i32_deserialize(lslug, &cursor);
    int32_t curves_texture_height = i32_deserialize(lslug, &cursor);
    // 4 components per curve, width * height
    // width * height is almost certainly more then count
    // but textures need to be aligned to a certain width anyway
    // so there will be some padding
    int16_t* curves = calloc(curves_texture_width * curves_texture_height * 4, sizeof(int16_t));

    for (int32_t i = 0;i < curves_count*4;++i)
    {
        curves[i] = i16_deserialize(lslug, &cursor);
    }
    int32_t band_count = i32_deserialize(lslug, &cursor);
    int32_t band_texture_width = i32_deserialize(lslug, &cursor);
    int32_t band_texture_height = i32_deserialize(lslug, &cursor);

    uint16_t* bands = calloc(band_texture_width * band_texture_height * 2, sizeof(uint16_t));
    for (int32_t i = 0;i < band_count*2;++i)
    {
        bands[i] = u16_deserialize(lslug, &cursor);
    }

    bool ok = shader_compile(&font->shader, "./assets/shaders/slug.glsl");
    if (ok)
    {
        glUseProgram(font->shader);
        glGenTextures(1, &font->band_texture);
        glBindTexture(GL_TEXTURE_2D, font->band_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RG16UI, band_texture_width, band_texture_height, 0, GL_RG_INTEGER, GL_UNSIGNED_SHORT, bands);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glGenTextures(1, &font->curve_texture);
        glBindTexture(GL_TEXTURE_2D, font->curve_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16I, curves_texture_width, curves_texture_height, 0, GL_RGBA_INTEGER, GL_SHORT, curves);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glGenVertexArrays(1, &font->vao);
        glGenBuffers(1, &font->vbo);
        glBindVertexArray(font->vao);
        glBindBuffer(GL_ARRAY_BUFFER, font->vbo);
        glBufferData(GL_ARRAY_BUFFER, MAX_TEXT * VERTECIES_PER_GLYPH * sizeof(Slug_Vertex), NULL, GL_DYNAMIC_DRAW);


        glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Slug_Vertex), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Slug_Vertex), (void*)(4 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Slug_Vertex), (void*)(8 * sizeof(float)));
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, sizeof(Slug_Vertex), (void*)(12 * sizeof(float)));
        glEnableVertexAttribArray(3);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, sizeof(Slug_Vertex), (void*)(16 * sizeof(float)));
        glEnableVertexAttribArray(4);
        glUseProgram(0);
    }
    free(bands);
    free(curves);
    return ok;
}



M4f m4f_translate(float x, float y, float z)
{
    M4f m = m4f_id();
    m._14 = x;
    m._24 = y;
    m._34 = z;
    return m;
}

M4f m4f_scale(float scale)
{
    M4f m = {0};
    m._11 = scale;
    m._22 = scale;
    m._33 = scale;
    m._44 = 1.0f;
    return m;
}

/*
I cannot name the params just near and far because i get this bizzare error:
../src/ttf_to_lslug.c(1121,82): warning: omitting the parameter name in a function definition is a C23 extension     
      [-Wc23-extensions]
 1121 | M4f m4f_orthographic(float left, float right, float bottom, float top, float near, float far)

Probably some library takes the names far and near for reasons
*/
M4f m4f_orthographic(float left, float right, float bottom, float top, float near_, float far_)
{
    M4f m = {0};
    m._11 = 2.0f/(right - left);
    m._22 = 2.0f/(top - bottom);
    m._33 = -2.0f/(far_ - near_);
    m._14 = -1.0f * (right + left) / (right - left); 
    m._24 = -1.0f * (top + bottom) / (top - bottom);
    m._34 = -1.0f * (far_ + near_) / (far_ - near_);
    m._44 = 1.0f;
    return m;
}

M2f m2f_invert(M2f m)
{
    float det = m._11 * m._22 - m._12 * m._21;
    float id = 1.0f/det;
    M2f result;
    result._11 =  m._22 * id;
    result._12 = -m._12 * id;
    result._21 = -m._21 * id;
    result._22 =  m._11 * id;
    return result;
}

void draw_text(Dynamic_Font* font, float x, float y, float size, float r, float g, float b, char* text)
{
    size_t len = strlen(text);

    Slug_Vertex* verticies = calloc(len * VERTECIES_PER_GLYPH, sizeof(Slug_Vertex));

    int32_t vertex_count = 0;
    float cursor = 0;

    float n = 0.70710678f;

    float scale = font->em_scale * size;

    M4f model = m4f_translate(x, y, 1.0);//m4f_mul(m4f_translate(x, y, 1.0), m4f_scale(scale));
    M2f jac;
    jac._11 = model._11;
    jac._12 = model._12;
    jac._21 = model._21;
    jac._22 = model._22;
    jac = m2f_invert(jac);

    for (size_t j = 0;j < len;++j)
    {
        char c = text[j];
        Glyph* gl_ptr = ht_find(&font->glyphs, c);
        if (gl_ptr == NULL) gl_ptr = ht_find(&font->glyphs, '?');
        Glyph gl = *gl_ptr;
        if (c == ' ')
        {
            cursor += gl.advance * scale;
            continue;
        }

        float ex1 = (float)gl.x1;
        float ex2 = (float)gl.x2;
        float ey1 = (float)gl.y1;
        float ey2 = (float)gl.y2;

        float ox1 = ex1 * scale + cursor;
        float ox2 = ex2 * scale + cursor;
        float oy1 = ey1 * scale;
        float oy2 = ey2 * scale;

        Convert_Float_U32 packed_loc;
        Convert_Float_U32 packed_band_info;
        packed_loc.u = ((uint32_t)gl.band_loc_y << 16) | (uint32_t)gl.band_loc_x;
        packed_band_info.u = ((uint32_t)(gl.band_count-1) << 16) | (uint32_t)(gl.band_count-1);

        // tl, bl, br, tl, tr, br
        float positions_x[6] = {ox1, ox1, ox2, ox1, ox2, ox2};
        float positions_y[6] = {oy2, oy1, oy1, oy2, oy2, oy1};
        float norms_x    [6] = { -n,  -n,   n,  -n,   n,   n};
        float norms_y    [6] = {  n,  -n,  -n,   n,   n,  -n};
        float ems_x      [6] = {ex1, ex1, ex2, ex1, ex2, ex2};
        float ems_y      [6] = {ey2, ey1, ey1, ey2, ey2, ey1};

        for (int i = 0;i < VERTECIES_PER_GLYPH;++i)
        {
            Slug_Vertex* v = verticies + vertex_count;
            v->pos_x = positions_x[i];
            v->pos_y = positions_y[i];
            v->norm_x = norms_x[i];
            v->norm_y = norms_y[i];
            v->tex_x = ems_x[i];
            v->tex_y = ems_y[i];
            v->packed_loc = packed_loc.f;
            v->max_band_indecies = packed_band_info.f;
            v->jac_00 = jac._11; v->jac_01 = jac._12;
            v->jac_10 = jac._21; v->jac_11 = jac._22;
            v->band_scale_x = ((float)gl.x2 - (float)gl.x1) / (float)gl.band_count;
            v->band_scale_y = ((float)gl.y2 - (float)gl.y1) / (float)gl.band_count;
            v->band_offset_x = (float)gl.x1;
            v->band_offset_y = (float)gl.y1;
            v->r = r; v->g = g; v->b = b; v->a = 1.0f;
            vertex_count += 1;
        }

        cursor += (float)gl.advance * scale;
    }


    M4f projection = m4f_orthographic(0.0f, WINDOW_WIDTH, 0.0f, WINDOW_HEIGHT, -1.0f, 1.0f);

    M4f mvp = m4f_mul(projection, model);
    V2f viewport = (V2f){{WINDOW_WIDTH, WINDOW_HEIGHT}};
    glUseProgram(font->shader);
    //glUniformMatrix4fv(glGetUniformLocation(font->shader, "mvp"), 1, false, mvp.c);
    glUniform4fv(glGetUniformLocation(font->shader, "mvp"), 4, mvp.c);
    glUniform2fv(glGetUniformLocation(font->shader, "viewport"), 1, viewport.c);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, font->curve_texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, font->band_texture);

    glUniform1i(glGetUniformLocation(font->shader, "curve_texture"), 0);
    glUniform1i(glGetUniformLocation(font->shader, "band_texture"),  1);

    glBindVertexArray(font->vao);
    glBindBuffer(GL_ARRAY_BUFFER, font->vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(Slug_Vertex), verticies);


    glDrawArrays(GL_TRIANGLES, 0, vertex_count);

    free(verticies);
}


int main(void)
{
    RGFW_glHints* hints = RGFW_getGlobalHints_OpenGL();
    hints->debug = true;
    RGFW_setGlobalHints_OpenGL(hints);

    RGFW_window* window = RGFW_createWindow("Slug Font", 10, 10, WINDOW_WIDTH, WINDOW_HEIGHT, RGFW_windowAllowDND | RGFW_windowCenter | RGFW_windowOpenGL);
    if (!window)
    {
        fprintf(stderr, "window creation\n");
        return 1;
    }

    RGFW_window_swapInterval_OpenGL(window, 1);

    if (!gladLoadGLLoader((GLADloadproc)RGFW_getProcAddress_OpenGL))
    {
        fprintf(stderr, "Coult not load opengl\n");
        return 1;
    }

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    FILE* f = fopen("./assets/fonts/opensans.lslg", "rb");
    assert(f != NULL);
    Bytes file = try_read_entire_file(f);
    assert(file.data);
    fclose(f);
    Dynamic_Font df = {0};
    if (!load_dynamic_font(&df, file)) return 1;

    free(file.data);

    while (RGFW_window_shouldClose(window) == RGFW_FALSE)
    {
        RGFW_event event;
        while (RGFW_window_checkEvent(window, &event))
        {
            if (event.type == RGFW_quit) break;
        }
        glClearColor(0.0, 0.0, 0.0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_text(&df, 90, 250, 150.0f, 1.0f, 1.0f, 1.0f, "Hello World!");

        RGFW_window_swapBuffers_OpenGL(window);
    }
    return 0;
}

#include "external/glad.c"
