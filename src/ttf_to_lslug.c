#ifdef _WIN32
#    define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <math.h>

#include <raylib.h>
#include <raymath.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

#define Clamp(A,X,B) (((X)<(A))?(A):((X)>(B))?(B):(X))

#define LSLUG_VERSION 1

#define FLOAT16_ASSERT_ON_OVERFLOW 1

#define DA_INIT_CAP 256
#define da_append(da, item)                                                          \
    do {                                                                             \
        if ((da)->count >= (da)->capacity) {                                         \
            (da)->capacity = (da)->capacity == 0 ? DA_INIT_CAP : (da)->capacity*2;   \
            (da)->items = realloc((da)->items, (da)->capacity*sizeof(*(da)->items)); \
            assert((da)->items != NULL && "Buy more RAM lol");                       \
        }                                                                            \
                                                                                     \
        (da)->items[(da)->count++] = (item);                                         \
    } while (0)

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

int32_t codepoints_to_process[] = {
    'q',
    //'@', '$', '&', '*',
    //'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
};

#define PADDING_X 30
#define PADDING_Y 30



void print_usage(void)
{
    fprintf(stderr, "    Usage: ttf_to_lslug <input_ttf_file_path> <output_ttf_file_path>\n");
}

typedef struct Bytes Bytes;
struct Bytes
{
    uint8_t* data;
    size_t count;
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

typedef struct Vec2 Vec2;
struct Vec2
{
    int16_t x, y;
};

typedef struct Curve Curve;
struct Curve
{
    Vec2 p1, p2, p3;
};

Curve* g_curves = NULL;

// typedef struct Band_Component Band_Component;
// struct Band_Component
// {
//     int32_t idx;
//     int32_t count;
// };

typedef struct Int_Array Int_Array;
struct Int_Array
{
    int32_t* items;
    size_t count;
    size_t capacity;
};


typedef struct Bands Bands;
struct Bands
{
    Int_Array* items;
    size_t count;
    size_t capacity;
};

typedef uint16_t float16_t;

typedef struct Curve_Component Curve_Component;
struct Curve_Component
{
    uint16_t x1, y1, x2, y2;
};

typedef struct Curves Curves;
struct Curves
{
    Curve* items;
    size_t count;
    size_t capacity;
};

typedef struct Curves_Packed Curves_Packed;
struct Curves_Packed
{
    Curve_Component* items;
    size_t count;
    size_t capacity;
};

typedef struct Bounds Bounds;
struct Bounds
{
    int32_t x1, y1, x2, y2;
};

typedef struct Glyph Glyph;
struct Glyph
{
    // glyph unicode codepoint
    int32_t cp;
    Bounds bbox;
    int32_t advance, left_side_bearing;
    // index of the first quadratice bezier curve in the curve texture
    // and how many curves there are
    // the curve texture is stored in Slug_Font struct
    int32_t glyph_texture_index, glyph_texture_curves_count;
    // int32_t band_loc;
    // int16_t max_bands;
    Bands horizontal;
    Bands vertical;
};

typedef struct Glyphs Glyphs;
struct Glyphs
{
    Glyph* items;
    size_t count;
    size_t capacity;
};

typedef struct Band_Component Band_Component;
struct Band_Component
{
    union
    {
        int32_t val1, offset;
    };
    union
    {
        int32_t val2, length;
    };
};

typedef struct Band Band;
struct Band
{
    Band_Component* items;
    size_t count;
    size_t capacity;
};

typedef struct Slug_Font Slug_Font;
struct Slug_Font
{
    float em_scale; // scale for em to a single pixel
    int32_t ascent, descent, line_gap; // vertical metrics
    Bounds bbox; // worst-case scenario of the bounding box of a glyph
    Curves curves;
    Glyphs glyphs;
};

#if 0
typedef union Convert_Float_To_U32 Convert_Float_To_U32;
union Convert_Float_To_U32
{
    float f;
    uint32_t u;
};

// shamelessly copied from jai's Float16 module
float16_t f32_to_f16(float f)
{
    const uint32_t f32infty = 255ul << 23;
    const uint32_t f16infty = 31ul  << 23;

    const float magic = 0x07800000;
    const uint32_t sign_mask = 0x80000000;
    const uint32_t round_mask = 0xfffff000;

    Convert_Float_To_U32 in;
    in.f = f;
    uint32_t sign = in.u & sign_mask;
    in.u ^= sign;

    float16_t o = 0;

    // NOTE all the integer compares in this function can be safely
    // compiled into signed compares since all operands are below
    // 0x80000000. Important if you want fast straight SSE2 code
    // (since there's no unsigned PCMPGTD).

    if (in.u >= f32infty)
    {
        o = (in.u > f32infty) ? 0x7e00 : 0x7c00; // NaN->qNaN and Inf->Inf
    }
    else
    { // (De)normalized number or zero
        in.u &= round_mask;
        in.f *= magic;
        in.u -= round_mask;
        if (in.u > f16infty)
        {
            in.u = f16infty; // Clamp to signed infinity if overflowed.
            #if FLOAT16_ASSERT_ON_OVERFLOW
            fprintf(stderr, "Input value for target %f\n to large", f);
                assert(false && "Input value to larget for float16 and overflowed");
            #endif
        }

        o = in.u >> 13; // Take the bits!
    }

    o |= (sign >> 16);
    return o;
}
#endif

float fmin3(float a, float b, float c)
{
    float temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}


float fmax3(float a, float b, float c)
{
    float temp = (a > b) ? a : b;
    return (temp > c) ? temp : c;
}

typedef struct Vec2f Vec2f;
struct Vec2f
{
    float x, y;
};

Vec2f vec2f_sub(Vec2f a, Vec2f b)
{
    return (Vec2f){a.x - b.x, a.y - b.y};
}

Vec2f vec2f_add(Vec2f a, Vec2f b)
{
    return (Vec2f){a.x + b.x, a.y + b.y};
}

Vec2f vec2f_scale(Vec2f a, float b)
{
    return (Vec2f){a.x * b, a.y * b};
}

Vec2f lerp(Vec2f a, Vec2f b, float t)
{
    Vec2f b_minus_a = vec2f_sub(b, a);
    Vec2f b_minus_a_times_t = vec2f_scale(b_minus_a, t);
    return vec2f_add(b_minus_a_times_t, a);
}

#define BAND_EPS 0.5f
#define LERP_SAMPLE_RATE (1.0f/2048.0f)
bool curve_overlaps_band_horizontal(Curve c, int band_idx, float scale, Bounds gl_bbox)
{
    float band_y1 = (float)gl_bbox.y1 + (float)band_idx * scale - BAND_EPS;
    float band_y2 = (float)gl_bbox.y1 + (float)(band_idx+1) * scale + BAND_EPS;
    assert(band_y2 >= band_y1);
    bool overlaps = false;

    for (float t = 0.0f; t <= 1.0f; t += LERP_SAMPLE_RATE)
    {
        Vec2f p1 = (Vec2f){(float)c.p1.x, (float)c.p1.y};
        Vec2f p2 = (Vec2f){(float)c.p2.x, (float)c.p2.y};
        Vec2f p3 = (Vec2f){(float)c.p3.x, (float)c.p3.y};
        Vec2f first = lerp(p1, p2, t);
        Vec2f second = lerp(p2, p3, t);

        Vec2f result_point = lerp(first, second, t);
        if (result_point.y >= band_y1 && result_point.y <= band_y2)
        {
            overlaps = true;
            break;
        }
    }
    return overlaps;
}

bool curve_overlaps_band_vertical(Curve c, int band_idx, float scale, Bounds gl_bbox)
{
    float band_x1 = (float)gl_bbox.x1 + (float)band_idx * scale - BAND_EPS;
    float band_x2 = (float)gl_bbox.x1 + (float)(band_idx+1) * scale + BAND_EPS;
    assert(band_x2 >= band_x1);
    bool overlaps = false;

    for (float t = 0.0f; t <= 1.0f; t += LERP_SAMPLE_RATE)
    {
        Vec2f p1 = (Vec2f){(float)c.p1.x, (float)c.p1.y};
        Vec2f p2 = (Vec2f){(float)c.p2.x, (float)c.p2.y};
        Vec2f p3 = (Vec2f){(float)c.p3.x, (float)c.p3.y};
        Vec2f first = lerp(p1, p2, t);
        Vec2f second = lerp(p2, p3, t);

        Vec2f result_point = lerp(first, second, t);
        if (result_point.x >= band_x1 && result_point.x <= band_x2)
        {
            overlaps = true;
            break;
        }
    }
    return overlaps;
}


int compare_band_by_y(void const* item1, void const* item2)
{
    int32_t idx_a = *(int32_t*)item1;
    int32_t idx_b = *(int32_t*)item2;

    Curve c1 = g_curves[idx_a];
    Curve c2 = g_curves[idx_b];

    float c1_min = fmax3((float)c1.p1.y, (float)c1.p2.y, (float)c1.p3.y);
    float c2_min = fmax3((float)c2.p1.y, (float)c2.p2.y, (float)c2.p3.y);

    // sort in descending order
    if (c1_min > c2_min) return -1;
    if (c1_min < c2_min) return  1;
    return 0;
}

int compare_band_by_x(void const* item1, void const* item2)
{
    int32_t idx_a = *(int32_t*)item1;
    int32_t idx_b = *(int32_t*)item2;

    Curve c1 = g_curves[idx_a];
    Curve c2 = g_curves[idx_b];
    float c1_min = fmax3((float)c1.p1.x, (float)c1.p2.x, (float)c1.p3.x);
    float c2_min = fmax3((float)c2.p1.x, (float)c2.p2.x, (float)c2.p3.x);
    // sort in descending order
    if (c1_min > c2_min) return -1;
    if (c1_min < c2_min) return  1;
    return 0;
}

bool process_codepoint(Slug_Font* font, stbtt_fontinfo* info, int32_t codepoint, Glyph* gl)
{
    int gl_index = stbtt_FindGlyphIndex(info, codepoint);
    Int_Array curve_index_dict = {0};
    if (gl_index == 0) return false;

    stbtt_GetGlyphHMetrics(info, gl_index, &gl->advance, &gl->left_side_bearing);
    stbtt_GetGlyphBox(info, gl_index, &gl->bbox.x1, &gl->bbox.y1, &gl->bbox.x2, &gl->bbox.y2);

    // shape extraction
    stbtt_vertex* verticies = NULL;
    int vert_count = stbtt_GetGlyphShape(info, gl_index, &verticies);
    if (vert_count <= 0)
    {
        return true;
    }

    Curves curves = {0};
    Curve curve = {0};
    bool could_process = true;
    for (int i = 0;i < vert_count;++i)
    {
        stbtt_vertex v = verticies[i];
        // TODO: actually does stb_truetype already use y-is-up?
        // transform to y-is-up coordinates
        //Vec2 p = {v.x, (int16_t)gl->bbox.y2 - v.y + (int16_t)gl->bbox.y1};
        //Vec2 c = {v.cx, (int16_t)gl->bbox.y2 - v.cy + (int16_t)gl->bbox.y1};
        Vec2 p = {v.x, v.y};
        Vec2 c = {v.cx, v.cy};

        switch (v.type)
        {
            case STBTT_vmove:
            {
                curve.p1 = p;
            } break;
            case STBTT_vline:
            {
                curve.p2 = p;
                curve.p3 = curve.p2;
                da_append(&curves, curve);
                curve.p1 = p;
            } break;
            case STBTT_vcurve:
            {
                curve.p2 = c;
                curve.p3 = p;
                da_append(&curves, curve);
                curve.p1 = p;
            } break;
            case STBTT_vcubic:
            {
                fprintf(stderr, "Splitting of cubic beziers not yet implemented!\n");
                could_process = false;
                goto fail;
            } break;
        }
    }
    printf("processed %zu curves\n", curves.count);
    gl->glyph_texture_curves_count = (int32_t)curves.count;
    gl->glyph_texture_index = font->curves.count;

    float glyph_width = (float)gl->bbox.x2 - (float)gl->bbox.x1;
    float glyph_height = (float)gl->bbox.y2 - (float)gl->bbox.y1;

    int bands_count = (int)Clamp(sqrt((double)curves.count), 1.0, 16.0);
    printf("Esitmated band count = %d\n", bands_count);

    float band_scale_x = glyph_width/(float)bands_count;
    float band_scale_y = glyph_height/(float)bands_count;


    for (size_t i = 0;i < curves.count;++i)
    {
        int32_t idx = (int32_t)font->curves.count;
        da_append(&font->curves, curves.items[i]);
        da_append(&curve_index_dict, idx);
    }

    // check for horizonatl bands
    for (int i = 0;i < bands_count;++i)
    {
        Int_Array band = {0};
        for (size_t j = 0; j < curves.count;++j)
        {
            Curve c = curves.items[j];
            // exclude strictly horizontal curves
            if (!((c.p1.y == c.p2.y) && (c.p2.y == c.p3.y)))
            {
                if (curve_overlaps_band_horizontal(c, i, band_scale_y, gl->bbox))
                {
                    da_append(&band, curve_index_dict.items[j]);
                }
            }
        }
        g_curves = font->curves.items; // TODO: qsort implementation with userdata parameter
        qsort(band.items, band.count, sizeof(band.items[0]), compare_band_by_x);
        da_append(&gl->horizontal, band);
    }

    // do the same for vertical bands
    for (int i = 0;i < bands_count;++i)
    {
        Int_Array band = {0};
        for (size_t j = 0; j < curves.count;++j)
        {
            Curve c = curves.items[j];
            // exclude strictly vertical curves
            if (!((c.p1.x == c.p2.x) && (c.p2.x == c.p3.x)))
            {
                if (curve_overlaps_band_vertical(c, i, band_scale_x, gl->bbox))
                {
                    da_append(&band, curve_index_dict.items[j]);
                }
            }
        }
        g_curves = font->curves.items;
        qsort(band.items, band.count, sizeof(band.items[0]), compare_band_by_y);
        da_append(&gl->vertical, band);
    }

fail:
    free(curve_index_dict.items);
    free(curves.items);
    stbtt_FreeShape(info, verticies);
    return could_process;
}

#define RasterSomething(name) Image name(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)

typedef RasterSomething(Raster_Something_Proc);

#define RasterHorizontalOrVerticalBands(is_horizontal) \
    Image* images = calloc(gl->horizontal.count, sizeof(Image));                               \
    for (size_t i = 0;i < gl->horizontal.count;++i)                                            \
    {                                                                                          \
        RenderTexture2D target = LoadRenderTexture(size.x, size.y);                            \
        BeginTextureMode(target);                                                              \
        {                                                                                      \
            ClearBackground(BLACK);                                                            \
                                                                                               \
            Color band_color = (i % 2 == 0) ? GREEN : LIME;                                    \
            if (is_horizontal)                                                                 \
            {                                                                                  \
                int glyph_h = (int)(gl->bbox.y2 - gl->bbox.y1);                                \
                int band_h = glyph_h/gl->horizontal.count;                                     \
                int band_y = i * band_h + PADDING_Y;                                           \
                DrawRectangle(PADDING_X, band_y, size.x - PADDING_X*2, band_h, band_color);    \
            }                                                                                  \
            else                                                                               \
            {                                                                                  \
                int glyph_w = (int)(gl->bbox.x2 - gl->bbox.x1);                                \
                int band_w = glyph_w/gl->vertical.count;                                       \
                int band_x = i * band_w + PADDING_X;                                           \
                DrawRectangle(band_x, PADDING_Y, band_w, size.y - PADDING_Y*2, band_color);    \
            }                                                                                  \
                                                                                               \
            Int_Array band = (is_horizontal) ? gl->horizontal.items[i] : gl->vertical.items[i];\
            for (size_t j = 0;j < band.count;++j)                                              \
            {                                                                                  \
                int32_t c_idx = band.items[j];                                                 \
                Curve c = font->curves.items[c_idx];                                           \
                                                                                               \
                Vector2 p1 = Vector2Add(translate, (Vector2){(float)c.p1.x, (float)c.p1.y});   \
                Vector2 c2 = Vector2Add(translate, (Vector2){(float)c.p2.x, (float)c.p2.y});   \
                Vector2 p3 = Vector2Add(translate, (Vector2){(float)c.p3.x, (float)c.p3.y});   \
                                                                                               \
                DrawLineEx(p1, c2, 2.0f, LIGHTGRAY);                                           \
                DrawLineEx(c2, p3, 2.0f, LIGHTGRAY);                                           \
                DrawLineEx(p1, p3, 2.0f, LIGHTGRAY);                                           \
                                                                                               \
                DrawCircleV(p1, 10.0f, BLUE);                                                  \
                DrawCircleV(c2, 10.0f, BLUE);                                                  \
                DrawCircleV(p3, 10.0f, BLUE);                                                  \
                                                                                               \
                DrawSplineSegmentBezierQuadratic(p1, c2, p3, 5.0, WHITE);                      \
            }                                                                                  \
                                                                                               \
            Rectangle bounding_rec = (Rectangle){0, 0, size.x, size.y};                        \
            DrawRectangleLinesEx(bounding_rec, 2.0f, WHITE);                                   \
        } EndTextureMode();                                                                    \
                                                                                               \
        images[i] = LoadImageFromTexture(target.texture);                                      \
        ImageFlipVertical(&images[i]);                                                         \
        UnloadRenderTexture(target);                                                           \
    }                                                                                          \
                                                                                               \
    Image result = GenImageColor(                                                              \
        gl->horizontal.count * size.x,                                                         \
        size.y,                                                                                \
        BLACK                                                                                  \
    );                                                                                         \
                                                                                               \
    for (size_t i = 0;i < gl->horizontal.count;++i)                                            \
    {                                                                                          \
        Image img = images[i];                                                                 \
        Rectangle src_rect = (Rectangle){0, 0, img.width, img.height};                         \
        Rectangle dest_rect = (Rectangle){(int)i*size.x, 0, img.width, img.height};            \
                                                                                               \
        ImageDraw(&result, img, src_rect, dest_rect, WHITE);                                   \
        UnloadImage(img);                                                                      \
    }                                                                                          \
                                                                                               \
    free(images);                                                                              \
    return result;                                                                             \

Image raster_horizontal_bands(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RasterHorizontalOrVerticalBands(true)
}

Image raster_vertical_bands(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RasterHorizontalOrVerticalBands(false)
}

Image raster_glyph_curves(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RenderTexture2D target = LoadRenderTexture(size.x, size.y);
    BeginTextureMode(target);
    {
        ClearBackground(BLACK);
        for (int32_t i = 0;i < gl->glyph_texture_curves_count;++i)
        {
            Curve c = font->curves.items[gl->glyph_texture_index + i];
            Vector2 p1 = Vector2Add(translate, (Vector2){(float)c.p1.x, (float)c.p1.y});
            Vector2 c2 = Vector2Add(translate, (Vector2){(float)c.p2.x, (float)c.p2.y});
            Vector2 p3 = Vector2Add(translate, (Vector2){(float)c.p3.x, (float)c.p3.y});

            DrawCircleV(p1, 10.0f, BLUE);
            DrawCircleV(c2, 10.0f, BLUE);
            DrawCircleV(p3, 10.0f, BLUE);
            if (c.p2.x == c.p3.x && c.p2.y == c.p3.y)
            {
                DrawLineEx(p1, p3, 5.0f, WHITE);
            }
            else
            {
                DrawLineEx(p1, c2, 2.0f, LIGHTGRAY);
                DrawLineEx(c2, p3, 2.0f, LIGHTGRAY);
                DrawSplineSegmentBezierQuadratic(p1, c2, p3, 5.0, WHITE);
            }
        }
        Rectangle bounding_rec = (Rectangle){0, 0, size.x, size.y};
        DrawRectangleLinesEx(bounding_rec, 2.0f, WHITE);
    } EndTextureMode();
    Image result = LoadImageFromTexture(target.texture);
    ImageFlipVertical(&result);
    UnloadRenderTexture(target);
    return result;
}

Raster_Something_Proc* raster_procs[] = {
    raster_glyph_curves,
    raster_horizontal_bands,
    raster_vertical_bands,
};


Image raster_glyph_to_image(Slug_Font* font, Glyph* gl)
{
    Bounds bbox = gl->bbox;
    Vector2 translate = (Vector2){-(float)bbox.x1 + PADDING_X, -(float)bbox.y1 + PADDING_Y}; // snaps the bounding box to 0,0
    Vector2 size = Vector2Add((Vector2){(float)bbox.x2, (float)bbox.y2}, translate);
    size = Vector2Add(size, (Vector2){2*PADDING_X, 2*PADDING_Y});

    size_t raster_procs_count = ARRAY_SIZE(raster_procs);
    Image* images = calloc(raster_procs_count, sizeof(Image));

    int images_width = 0;
    for (size_t i = 0;i < raster_procs_count;++i)
    {
        images[i] = raster_procs[i](font, gl, translate, size);

        images_width += images[i].width;
    }

    Image final_img = GenImageColor(
        images_width,
        size.y,
        BLACK
    );

    int accumulator = 0;
    for (size_t i = 0; i < raster_procs_count;++i)
    {
        Image img = images[i];

        Rectangle src_rect = (Rectangle){0, 0, img.width, img.height};
        // allow for variable width
        Rectangle dest_rect = (Rectangle){accumulator, 0, img.width, img.height};
        accumulator += img.width;

        ImageDraw(&final_img, img, src_rect, dest_rect, WHITE);

        // not needed anymore
        UnloadImage(img);
    }

    //ExportImage(final_img, path);

    free(images);
    //UnloadImage(final_img);
    return final_img;
}

void raster_glyph_atlas(Slug_Font* font, const char* path)
{
    Image* images = calloc(font->glyphs.count, sizeof(Image));
    int max_width = 0;
    int total_height = 0;
    for (size_t i = 0;i < font->glyphs.count;++i)
    {
        images[i] = raster_glyph_to_image(font, &font->glyphs.items[i]);
        if (images[i].width > max_width) max_width = images[i].width;
        total_height += images[i].height;
    }

    Image final_img = GenImageColor(max_width, total_height, BLACK);
    int accumulator = 0;
    for (size_t i = 0; i < font->glyphs.count;++i)
    {
        Image img = images[i];
        Rectangle src_rect = (Rectangle){0, 0, img.width, img.height};
        Rectangle dest_rect = (Rectangle){0, accumulator, img.width, img.height};
        ImageDraw(&final_img, img, src_rect, dest_rect, WHITE);
        accumulator += img.height;
        UnloadImage(img);
    }

    free(images);

    ExportImage(final_img, path);
    UnloadImage(final_img);
}


int main(int argc, char* argv[])
{
    for (int i = 0;i < argc;++i)
    {
        if
        (
            strcmp(argv[i], "-help") == 0
            || strcmp(argv[i], "-h") == 0
            || strcmp(argv[i], "--help") == 0
        )
        {
            fprintf(stderr, "ttf_to_lslug version %d\n", LSLUG_VERSION);
            print_usage();
            return 1;
        }
    }

    if (argc < 3)
    {
        fprintf(stderr, "Did not provide enough arguments!\n");
        print_usage();
        return 1;
    }

    char* input_path = argv[1];
    char* output_path = argv[2];

    FILE* f = fopen(input_path, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Could not open file %s!\n", input_path);
        return 1;
    }

    Bytes ttf_bytes = try_read_entire_file(f);
    if (ttf_bytes.data == NULL)
    {
        fprintf(stderr, "Buy more ram lol\n");
        return 1;
    }
    stbtt_fontinfo info = {0};
    Slug_Font font = {0};
    fclose(f);

    if (!stbtt_InitFont(&info, ttf_bytes.data, 0))
    {
        fprintf(stderr, "Could not parse file %s\n", input_path);
        free(ttf_bytes.data);
        return 1;
    }

    font.em_scale = stbtt_ScaleForMappingEmToPixels(&info, 1.0);


    stbtt_GetFontVMetrics(&info, &font.ascent, &font.descent, &font.line_gap);
    stbtt_GetFontBoundingBox(&info, &font.bbox.x1, &font.bbox.y1, &font.bbox.x2, &font.bbox.y2);

    int32_t processed_codepoints = 0;
    for (size_t i = 0;i < ARRAY_SIZE(codepoints_to_process);++i)
    {
        Glyph gl = {0};
        gl.cp = codepoints_to_process[i];
        if (!process_codepoint(&font, &info, gl.cp, &gl))
        {
            fprintf(stderr, "Could not process codepoint 0x%x\n", gl.cp);
        }
        else
        {
            da_append(&font.glyphs, gl);
            processed_codepoints += 1;
        }
    }
    printf("Processed %d glyphs\n", processed_codepoints);

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIDDEN);
    InitWindow(100, 100, "Dummy");

    raster_glyph_atlas(&font, "out\\atlas.png");

    return 0;
}
