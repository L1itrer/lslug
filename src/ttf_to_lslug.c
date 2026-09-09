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

#define LA_IMPLEMENTATION
#include "la.h"

#include "glad.h"
#define RGFW_OPENGL
#define RGFW_IMPLEMENTATION
#include "RGFW.h"

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

#define Clamp(A,X,B) (((X)<(A))?(A):((X)>(B))?(B):(X))

#define LSLUG_VERSION 1

#define FLOAT16_ASSERT_ON_OVERFLOW 1

#define WINDOW_WIDTH  960
#define WINDOW_HEIGHT 540

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
    '$', '&', '*', '%',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'o', 'p', 'r', 's', 't', 'y', 'z',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'O', 'P', 'R', 'S', 'T', 'Y', 'Z',
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
    int16_t x1, y1, x2, y2;
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
    int16_t band_loc_x;
    int16_t band_loc_y;
    int16_t max_bands;
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
        int16_t x, length;
    };
    union
    {
        int16_t y, offset;
    };
};

#define TEXEL_WIDTH 2048
typedef struct Band_Line Band_Line;
struct Band_Line
{
    Band_Component bc[TEXEL_WIDTH];
};

typedef struct Band_Texture Band_Texture;
struct Band_Texture
{
    Band_Line* items;
    size_t count;
    size_t capacity;
};

typedef struct Slug_Font Slug_Font;
struct Slug_Font
{
    float em_scale; // scale for em to a single pixel
    int32_t ascent, descent, line_gap; // vertical metrics
    Bounds bbox; // worst-case scenario of the bounding box of a glyph
    Curves_Packed curves;
    Glyphs glyphs;
    Band_Texture band;
    Int_Array allocated_per_texture;
};

static void merge(void* arr, void* L, void* R, size_t left_index, size_t right_index, size_t sizeof_element, int (*comparator)(const void*, const void*, void*), void* user_param)
{
    size_t i = 0, j = 0, k = 0;
    //k is the index of the main array
    //i is the index of the L sub-array
    //j is the index of the R sub-array
    while (i < left_index && j < right_index)
    {
        if (comparator((char*)L + i * sizeof_element, (char*)R + j * sizeof_element, user_param) <= 0)
        {
            memcpy((char*)arr + k * sizeof_element, (char*)L + i * sizeof_element, sizeof_element);
            ++k;
            ++i;
        }
        else
        {
            memcpy((char*)arr + k * sizeof_element, (char*)R + j * sizeof_element, sizeof_element);
            ++k;
            ++j;
        }
    }

    //copy the remaining sub-arrays
    while (i < left_index) 
    {
        memcpy((char*)arr + k * sizeof_element, (char*)L + i * sizeof_element, sizeof_element);
        ++i;
        ++k;
    }
    while (j < right_index) 
    {
        memcpy((char*)arr + k * sizeof_element, (char*)R + j * sizeof_element, sizeof_element);
        ++j;
        ++k;
    }
}

// TODO: this implementation of merge_sort sucks ass! I copied it
// quicly from an old project so there is probably a lot of room
// for improvement
void merge_sort(void* arr, size_t number_of_elements, size_t sizeof_element, int (*comparator)(const void*, const void*, void*), void* user_param)
{
    size_t mid = number_of_elements/2;

    void* L, *R;
    if (number_of_elements < 2) return;

    L = malloc(mid * sizeof_element); //Left sub-array is from 0 to mid-1
    R = malloc((number_of_elements - mid) * sizeof_element); //Right sub-array is from mid to number_of_elements-1
    if (L == NULL || R == NULL)
    {
        fprintf(stderr, "Get more ram lol\n");
        abort();
    }

    memcpy(L, arr, mid * sizeof_element);
    memcpy(R, (char*)arr + mid * sizeof_element, (number_of_elements - mid) * sizeof_element);

    merge_sort(L, mid, sizeof_element, comparator, user_param);
    merge_sort(R, (number_of_elements - mid), sizeof_element, comparator, user_param);
    merge(arr, L, R, mid, number_of_elements - mid, sizeof_element, comparator, user_param);

    free(L);
    free(R);
}

Vec2 offset_to_abs(Vec2 offset_from, int16_t offset, int16_t w)
{
    Vec2 result = {0};

    int16_t target = offset_from.x + offset;
    result.x = target % w;
    result.y = offset_from.y + (target >= w);

    return result;
}

typedef union Convert_Float_U32 Convert_Float_U32;
union Convert_Float_U32
{
    float f;
    uint32_t u;
};

#if 0

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

Vec2f vec2f_lerp(Vec2f a, Vec2f b, float t)
{
    Vec2f b_minus_a = vec2f_sub(b, a);
    Vec2f b_minus_a_times_t = vec2f_scale(b_minus_a, t);
    return vec2f_add(b_minus_a_times_t, a);
}

Curve curve_from_points(int16_t x1, int16_t y1, int16_t x2, int16_t y2, int16_t x3, int16_t y3)
{
    return (Curve){
        .p1 = (Vec2){.x = x1, .y = y1},
        .p2 = (Vec2){.x = x2, .y = y2},
        .p3 = (Vec2){.x = x3, .y = y3},
    };
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
        Vec2f first =  vec2f_lerp(p1, p2, t);
        Vec2f second = vec2f_lerp(p2, p3, t);

        Vec2f result_point = vec2f_lerp(first, second, t);
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
        Vec2f first =  vec2f_lerp(p1, p2, t);
        Vec2f second = vec2f_lerp(p2, p3, t);

        Vec2f result_point = vec2f_lerp(first, second, t);
        if (result_point.x >= band_x1 && result_point.x <= band_x2)
        {
            overlaps = true;
            break;
        }
    }
    return overlaps;
}


int compare_band_by_y(void const* item1, void const* item2, void* font)
{
    int32_t idx_a = *(int32_t*)item1;
    int32_t idx_b = *(int32_t*)item2;
    Slug_Font* f = font;

    Curve_Component cc_a1 = f->curves.items[idx_a];
    Curve_Component cc_a2 = f->curves.items[idx_a+1];
    Curve_Component cc_b1 = f->curves.items[idx_b];
    Curve_Component cc_b2 = f->curves.items[idx_b+1];

    Curve c1 = curve_from_points(cc_a1.x1, cc_a1.y1, cc_a1.x2, cc_a1.y2, cc_a2.x1, cc_a2.y1);
    Curve c2 = curve_from_points(cc_b1.x1, cc_b1.y1, cc_b1.x2, cc_b1.y2, cc_b2.x1, cc_b2.y1);

    float c1_min = fmax3((float)c1.p1.y, (float)c1.p2.y, (float)c1.p3.y);
    float c2_min = fmax3((float)c2.p1.y, (float)c2.p2.y, (float)c2.p3.y);

    // sort in descending order
    if (c1_min > c2_min) return -1;
    if (c1_min < c2_min) return  1;
    return 0;
}

int compare_band_by_x(void const* item1, void const* item2, void* font)
{
    int32_t idx_a = *(int32_t*)item1;
    int32_t idx_b = *(int32_t*)item2;

    Slug_Font* f = font;

    Curve_Component cc_a1 = f->curves.items[idx_a];
    Curve_Component cc_a2 = f->curves.items[idx_a+1];
    Curve_Component cc_b1 = f->curves.items[idx_b];
    Curve_Component cc_b2 = f->curves.items[idx_b+1];

    Curve c1 = curve_from_points(cc_a1.x1, cc_a1.y1, cc_a1.x2, cc_a1.y2, cc_a2.x1, cc_a2.y1);
    Curve c2 = curve_from_points(cc_b1.x1, cc_b1.y1, cc_b1.x2, cc_b1.y2, cc_b2.x1, cc_b2.y1);

    float c1_min = fmax3((float)c1.p1.x, (float)c1.p2.x, (float)c1.p3.x);
    float c2_min = fmax3((float)c2.p1.x, (float)c2.p2.x, (float)c2.p3.x);
    // sort in descending order
    if (c1_min > c2_min) return -1;
    if (c1_min < c2_min) return  1;
    return 0;
}

size_t count_curves(stbtt_vertex* verts, int vert_count)
{
    size_t result = 0;
    for (int i = 0;i < vert_count;++i)
    {
        stbtt_vertex v = verts[i];
        switch (v.type)
        {
            case STBTT_vmove: {} break; // nothing
            case STBTT_vcurve: // fallthrough
            case STBTT_vline:
            {
                result += 1;
            } break;
            default:
            {
                assert(false);
            } break;
        }
    }
    return result;
}

int32_t find_block_with_smallest_enough_space(Band_Texture* band, Int_Array* allocated, int32_t component_count)
{
    int32_t result = -1;
    int32_t smallest_current = TEXEL_WIDTH+1;
    for (size_t i = 0;i < allocated->count;++i)
    {
        int32_t free_space = TEXEL_WIDTH - allocated->items[i];
        if (component_count <= free_space)
        {
            if (free_space < smallest_current) result = (int32_t)i;
        }
    }

    if (result == -1)
    {
        result = band->count;
        Band_Line ln = {0};
        da_append(band, ln);
        da_append(allocated, 0);
    }
    return result;
}

int32_t allocate_in_block(Int_Array* all, int32_t block_idx, int32_t count)
{
    assert(block_idx < (int32_t)all->count);
    int32_t free_space = TEXEL_WIDTH - all->items[block_idx];
    assert(count <= free_space);

    int32_t x_idx = all->items[block_idx];
    all->items[block_idx] += count;
    return x_idx;
}

Vec2 allocate_bands(Slug_Font* font, Int_Array* bnd_horiz, Int_Array* bnd_vert, int band_count)
{
    Band_Texture* bnd = &font->band;
    Int_Array* allocated = &font->allocated_per_texture;

    int metadata_count = band_count * 2;

    int16_t metadata_loc_y = find_block_with_smallest_enough_space(
        bnd, allocated, metadata_count
    );
    int16_t metadata_loc_x = allocate_in_block(
        allocated, metadata_loc_y, metadata_count
    );


    for (int j = 0;j < band_count*2;++j)
    {
        // allocate the data of the current band
        Int_Array* curr_bnd = (j < band_count) ? bnd_horiz + j : bnd_vert + (j - band_count);
        int32_t block_idx = find_block_with_smallest_enough_space(
            bnd, allocated, (int32_t)curr_bnd->count
        );
        int32_t x_idx = allocate_in_block(
            allocated, block_idx, curr_bnd->count
        );

        // convert absolute curve index into (x,y) format
        // and store it in the texture
        for (size_t i = 0;i < curr_bnd->count;++i)
        {
            int32_t idx_in_curve_texture = curr_bnd->items[i];
            int16_t curve_y = idx_in_curve_texture / TEXEL_WIDTH;
            int16_t curve_x = idx_in_curve_texture - curve_y * TEXEL_WIDTH;

            bnd->items[block_idx].bc[x_idx+i].x = curve_x;
            bnd->items[block_idx].bc[x_idx+i].y = curve_y;
        }

        // fill the metadata for the current band
        Band_Component bc = {0};
        int32_t offset = (int32_t)((block_idx * TEXEL_WIDTH + x_idx) - (metadata_loc_y * TEXEL_WIDTH + metadata_loc_x));
        assert(offset >= 0 && "Offset was negative");
        assert(offset < 0xffff);
        bc.offset = (uint16_t)offset;
        bc.length = (uint16_t)curr_bnd->count;
        bnd->items[metadata_loc_y].bc[metadata_loc_x+j] = bc;
    }

    return (Vec2){metadata_loc_x, metadata_loc_y};
}


bool process_codepoint(Slug_Font* font, stbtt_fontinfo* info, int32_t codepoint, Glyph* gl)
{
    int gl_index = stbtt_FindGlyphIndex(info, codepoint);
    if (gl_index == 0) return false;

    stbtt_GetGlyphHMetrics(info, gl_index, &gl->advance, &gl->left_side_bearing);
    stbtt_GetGlyphBox(info, gl_index, &gl->bbox.x1, &gl->bbox.y1, &gl->bbox.x2, &gl->bbox.y2);

    float glyph_width = (float)gl->bbox.x2 - (float)gl->bbox.x1;
    float glyph_height = (float)gl->bbox.y2 - (float)gl->bbox.y1;

    // shape extraction
    stbtt_vertex* verticies = NULL;
    int vert_count = stbtt_GetGlyphShape(info, gl_index, &verticies);
    if (vert_count <= 0)
    {
        return true;
    }

    size_t curves_count = count_curves(verticies, vert_count);
    int bands_count = (int)Clamp(sqrt((double)curves_count), 1.0, 16.0);
    gl->max_bands = (int16_t)bands_count;

    float band_scale_x = glyph_width/(float)bands_count;
    float band_scale_y = glyph_height/(float)bands_count;

    Int_Array* bnd_horiz = calloc((size_t)bands_count, sizeof(Int_Array));
    Int_Array* bnd_vert  = calloc((size_t)bands_count, sizeof(Int_Array));

    //Curves_Packed curves = {0};
    Curve_Component cc = {0};
    Curve_Component* c_curr = NULL;
    bool could_process = true;
    for (int j = 0;j < vert_count;++j)
    {
        stbtt_vertex v = verticies[j];
        // TODO: actually does stb_truetype already use y-is-up?
        // transform to y-is-up coordinates
        //Vec2 p = {v.x, (int16_t)gl->bbox.y2 - v.y + (int16_t)gl->bbox.y1};
        //Vec2 c = {v.cx, (int16_t)gl->bbox.y2 - v.cy + (int16_t)gl->bbox.y1};
        //Vec2 p = {v.x, v.y};
        //Vec2 c = {v.cx, v.cy};
        int16_t x = v.x;
        int16_t y = v.y;
        int16_t cx = v.cx;
        int16_t cy = v.cy;

        switch (v.type)
        {
            case STBTT_vmove:
            {
                cc = (Curve_Component){};
                cc.x1 = x;
                cc.y1 = y;
                da_append(&font->curves, cc);
            } break;
            case STBTT_vline:
            case STBTT_vcurve:
            {
                size_t idx = font->curves.count-1;
                c_curr = &font->curves.items[idx];
                c_curr->x2 = (v.type == STBTT_vline) ? x : cx;
                c_curr->y2 = (v.type == STBTT_vline) ? y : cy;
                cc = (Curve_Component){};
                cc.x1 = x;
                cc.y1 = y;
                da_append(&font->curves, cc);

                // loop over the bands
                Curve c = curve_from_points(c_curr->x1, c_curr->y1, c_curr->x2, c_curr->y2, cc.x1, cc.y1);
                for (int i = 0;i < bands_count;++i)
                {
                    // exclude horizontal lines from horizontal bands
                    if (!((c.p1.y == c.p2.y) && (c.p2.y == c.p3.y)))
                    {
                        if (curve_overlaps_band_horizontal(c, i, band_scale_y, gl->bbox))
                        {
                            da_append(&bnd_horiz[i], (int32_t)idx);
                        }
                    }

                    // exclude vertical lines from vertical bands
                    if (!((c.p1.x == c.p2.x) && (c.p2.x == c.p3.x)))
                    {
                        if (curve_overlaps_band_vertical(c, i, band_scale_x, gl->bbox))
                        {
                            da_append(&bnd_vert[i], (int32_t)idx);
                        }
                    }
                }
            } break;
            case STBTT_vcubic:
            {
                fprintf(stderr, "Splitting of cubic beziers not yet implemented!\n");
                could_process = false;
                goto end;
            } break;
        }
    }

    // sort the bands by descending x or y
    for (int i = 0;i < bands_count;++i)
    {
        merge_sort(bnd_horiz[i].items, bnd_horiz[i].count, sizeof(bnd_horiz[i].items[0]), compare_band_by_x, font);
        merge_sort(bnd_vert[i].items, bnd_vert[i].count, sizeof(bnd_vert[i].items[0]), compare_band_by_y, font);
    }

    Vec2 band_loc = allocate_bands(font, bnd_horiz, bnd_vert, bands_count);

    gl->band_loc_x = band_loc.x;
    gl->band_loc_y = band_loc.y;

end:
    for (int i = 0;i < bands_count;++i)
    {
        free(bnd_horiz[i].items);
        free(bnd_vert [i].items);
    }
    free(bnd_horiz);
    free(bnd_vert);
    stbtt_FreeShape(info, verticies);
    return could_process;
}

#if 0

#define RasterSomething(name) Image name(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)

typedef RasterSomething(Raster_Something_Proc);

#define RasterHorizontalOrVerticalBands(is_horizontal) \
    Image* images = calloc(gl->max_bands, sizeof(Image));                               \
    int max_bands = gl->max_bands;                                                      \
    for (int32_t j = 0;j < gl->max_bands;++j)                                           \
    {                                                                                   \
        RenderTexture2D target = LoadRenderTexture(size.x, size.y);                     \
        BeginTextureMode(target);                                                       \
        ClearBackground(BLACK);                                                         \
                                                                                        \
        Color band_color = (j % 2 == 0) ? GREEN : LIME;                                 \
                                                                                        \
        int16_t x = gl->band_loc_x;                                                     \
        int16_t y = gl->band_loc_y;                                                     \
                                                                                        \
        int to_add = 0;                                                                 \
        if (!is_horizontal) to_add = max_bands;                                         \
        int32_t iter = j + to_add;\
        Band_Component bc = font->band.items[y].bc[x+iter];                         \
        if (is_horizontal)                                                              \
        {                                                                               \
            int glyph_h = (int)(gl->bbox.y2 - gl->bbox.y1);                             \
            int band_h = glyph_h/max_bands;                                             \
            int band_y = j * band_h + PADDING_Y;                                        \
            DrawRectangle(PADDING_X, band_y, size.x - PADDING_X*2, band_h, band_color); \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            int glyph_w = (int)(gl->bbox.x2 - gl->bbox.x1);                             \
            int band_w = glyph_w/max_bands;                                             \
            int band_x = j * band_w + PADDING_X;                                        \
            DrawRectangle(band_x, PADDING_Y, band_w, size.y - PADDING_Y*2, band_color); \
        }                                                                               \
                                                                                        \
        Vec2 b_loc = offset_to_abs((Vec2){x+iter, y}, bc.offset, TEXEL_WIDTH);               \
        for (int16_t i = 0;i < bc.length;++i)                                           \
        {                                                                               \
            Band_Component c_loc = font->band.items[b_loc.y].bc[b_loc.x+i];             \
            Curve_Component cc1 = font->curves.items[c_loc.y * TEXEL_WIDTH + c_loc.x];  \
            Curve_Component cc2 = font->curves.items[c_loc.y * TEXEL_WIDTH + c_loc.x+1];\
                                                                                        \
            Curve c = curve_from_points(cc1.x1, cc1.y1, cc1.x2, cc1.y2, cc2.x1, cc2.y1);\
                                                                                        \
            Vector2 p1 = Vector2Add(translate, (Vector2){(float)c.p1.x, (float)c.p1.y});\
            Vector2 c2 = Vector2Add(translate, (Vector2){(float)c.p2.x, (float)c.p2.y});\
            Vector2 p3 = Vector2Add(translate, (Vector2){(float)c.p3.x, (float)c.p3.y});\
                                                                                        \
            DrawCircleV(p1, 10.0f, BLUE);                                               \
            DrawCircleV(c2, 10.0f, BLUE);                                               \
            DrawCircleV(p3, 10.0f, BLUE);                                               \
            if (c.p2.x == c.p3.x && c.p2.y == c.p3.y)                                   \
            {                                                                           \
                DrawLineEx(p1, p3, 5.0f, WHITE);                                        \
            }                                                                           \
            else                                                                        \
            {                                                                           \
                DrawLineEx(p1, c2, 2.0f, LIGHTGRAY);                                    \
                DrawLineEx(c2, p3, 2.0f, LIGHTGRAY);                                    \
                DrawSplineSegmentBezierQuadratic(p1, c2, p3, 5.0, WHITE);               \
            }                                                                           \
        }                                                                               \
        Rectangle bounding_rec = (Rectangle){0, 0, size.x, size.y};                     \
        DrawRectangleLinesEx(bounding_rec, 2.0f, WHITE);                                \
        EndTextureMode();                                                               \
        Image img = LoadImageFromTexture(target.texture);                               \
        UnloadRenderTexture(target);                                                    \
        ImageFlipVertical(&img);                                                        \
        images[j] = img;                                                                \
    }                                                                                   \
    Image result = GenImageColor(                                                       \
        max_bands * size.x,                                                             \
        size.y,                                                                         \
        BLACK                                                                           \
    );                                                                                  \
                                                                                        \
    for (size_t i = 0;i < (size_t)max_bands;++i)                                        \
    {                                                                                   \
        Image img = images[i];                                                          \
        Rectangle src_rect = (Rectangle){0, 0, img.width, img.height};                  \
        Rectangle dest_rect = (Rectangle){(int)i*size.x, 0, img.width, img.height};     \
        ImageDraw(&result, img, src_rect, dest_rect, WHITE);                            \
        UnloadImage(img);                                                               \
    }                                                                                   \
    return result;                                                                      \

Image raster_horizontal_bands(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RasterHorizontalOrVerticalBands(true)
}

Image raster_vertical_bands(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RasterHorizontalOrVerticalBands(false);
}

void raster_curves(Curves_Packed* curves, Bounds bbox)
{
    Vector2 translate = (Vector2){-(float)bbox.x1 + PADDING_X, -(float)bbox.y1 + PADDING_Y}; // snaps the bounding box to 0,0
    Vector2 size = Vector2Add((Vector2){(float)bbox.x2, (float)bbox.y2}, translate);
    size = Vector2Add(size, (Vector2){2*PADDING_X, 2*PADDING_Y});
    RenderTexture2D target = LoadRenderTexture(size.x, size.y);
    BeginTextureMode(target);

    for (size_t i = 0;i < curves->count-1;++i)
    {
        Curve_Component cc1 = curves->items[i];
        Curve_Component cc2 = curves->items[i+1];

        Curve c = curve_from_points(cc1.x1, cc1.y1, cc1.x2, cc1.y2, cc2.x1, cc2.y1);

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

    EndTextureMode();
    Image result = LoadImageFromTexture(target.texture);
    UnloadRenderTexture(target);
    ImageFlipVertical(&result);
    ExportImage(result, "test.png");
    UnloadImage(result);
}

Image raster_glyph_curves(Slug_Font* font, Glyph* gl, Vector2 translate, Vector2 size)
{
    RenderTexture2D target = LoadRenderTexture(size.x, size.y);
    BeginTextureMode(target);
    {
        ClearBackground(BLACK);
        for (int32_t j = 0;j < gl->max_bands*2;++j)
        {
            int16_t x = gl->band_loc_x;
            int16_t y = gl->band_loc_y;
            Band_Component bc = font->band.items[y].bc[x+j];

            Vec2 b_loc = offset_to_abs((Vec2){x+j, y}, bc.offset, TEXEL_WIDTH);
            for (int16_t i = 0;i < bc.length;++i)
            {
                Band_Component c_loc = font->band.items[b_loc.y].bc[b_loc.x+i];
                Curve_Component cc1 = font->curves.items[c_loc.y * TEXEL_WIDTH + c_loc.x];
                Curve_Component cc2 = font->curves.items[c_loc.y * TEXEL_WIDTH + c_loc.x+1];

                Curve c = curve_from_points(cc1.x1, cc1.y1, cc1.x2, cc1.y2, cc2.x1, cc2.y1);

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

void raster_single_glyph_atlas(Slug_Font* font, Glyph* gl, const char* path)
{
    Image img = raster_glyph_to_image(font, gl);
    ExportImage(img, path);
    UnloadImage(img);
}

#endif

bool shader_compile_specific(uint32_t* return_handle, char* source, uint32_t kind)
{
    uint32_t shader = glCreateShader(kind);

    glShaderSource(shader, 1, &source, NULL);
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

typedef struct Slug_Vertex Slug_Vertex;
struct Slug_Vertex
{
    float pos_x, pos_y, norm_x, norm_y;
    float tex_x, tex_y, packed_loc, max_band_indecies;
    float jac_00, jac_01, jac_10, jac_11;
    float band_scale_x, band_scale_y, band_offset_x, band_offset_y;
    float r, g, b, a;
};

M4f m4f_translate(float x, float y, float z)
{
    M4f m = m4f_id();
    m.m[3][0] = x;
    m.m[3][1] = y;
    m.m[3][2] = z;
    return m;
}

M4f m4f_scale(float scale)
{
    M4f m = {0};
    m.m[0][0] = scale;
    m.m[1][1] = scale;
    m.m[2][2] = scale;
    m.m[3][3] = 1.0f;
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

typedef struct Render_State Render_State;
struct Render_State
{
    uint32_t text_shader;
    uint32_t text_vao, text_vbo;
    uint32_t band_texture, curve_texture;
};

#define MAX_TEXT 128
#define VERTECIES_PER_GLYPH 6

bool init_render_state(Render_State* rd, Slug_Font* font)
{
    bool result = shader_compile(&rd->text_shader, "./src/slug.glsl");
    if (result)
    {
        glGenTextures(1, &rd->band_texture);
        glBindTexture(GL_TEXTURE_2D, rd->band_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RG16UI, TEXEL_WIDTH, font->band.count, 0, GL_RG_INTEGER, GL_UNSIGNED_SHORT, font->band.items);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        int remainder = TEXEL_WIDTH - (font->curves.count % TEXEL_WIDTH);
        for (int i = 0;i < remainder;++i)
        {
            Curve_Component cc = {0};
            da_append(&font->curves, cc);
        }
        if (!(font->curves.count % TEXEL_WIDTH == 0))
        {
            printf("curves count is = %zu, remainder is = %d\n", font->curves.count, remainder);
            assert(false);
        }
        glGenTextures(1, &rd->curve_texture);
        glBindTexture(GL_TEXTURE_2D, rd->curve_texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16I, TEXEL_WIDTH, font->curves.count/TEXEL_WIDTH, 0, GL_RGBA_INTEGER, GL_SHORT, font->curves.items);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glGenVertexArrays(1, &rd->text_vao);
        glGenBuffers(1, &rd->text_vbo);
        glBindVertexArray(rd->text_vao);
        glBindBuffer(GL_ARRAY_BUFFER, rd->text_vbo);
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
    }

    return result;
}

void draw_text(Render_State* rd, Slug_Font* font, float x, float y, float size, char* text)
{
    size_t len = strlen(text);

    Slug_Vertex* verticies = calloc(len * VERTECIES_PER_GLYPH, sizeof(Slug_Vertex));

    int32_t vertex_count = 0;
    float cursor = x;

    float n = 0.70710678f;

    float scale = font->em_scale * size;
    for (size_t j = 0;j < len;++j)
    {
        char c = text[j];
        Glyph gl = font->glyphs.items[c - 32];
        if (c == ' ')
        {
            cursor += gl.advance * scale;
            continue;
        }

        float ex1 = (float)gl.bbox.x1;
        float ex2 = (float)gl.bbox.x2;
        float ey1 = (float)gl.bbox.y1;
        float ey2 = (float)gl.bbox.y2;

        float ox1 = ex1 * scale + cursor;
        float ox2 = ex2 * scale + cursor;
        float oy1 = ey1 * scale + y;
        float oy2 = ey2 * scale + y;

        Convert_Float_U32 packed_loc;
        Convert_Float_U32 packed_band_info;
        packed_loc.u = ((uint32_t)gl.band_loc_y << 16) | (uint32_t)gl.band_loc_x;
        packed_band_info.u = ((uint32_t)(gl.max_bands-1) << 16) | (uint32_t)(gl.max_bands-1);

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
            v->jac_00 = 1.0f; v->jac_01 = 0.0f;
            v->jac_10 = 0.0f; v->jac_11 = 1.0f;
            v->band_scale_x = ((float)gl.bbox.x2 - (float)gl.bbox.x1) / (float)gl.max_bands;
            v->band_scale_y = ((float)gl.bbox.y2 - (float)gl.bbox.y1) / (float)gl.max_bands;
            v->band_offset_x = (float)gl.bbox.x1;
            v->band_offset_y = (float)gl.bbox.y1;
            v->r = 1.0f; v->g = 1.0f; v->b = 1.0f; v->a = 1.0f;
            vertex_count += 1;
        }

        cursor += (float)gl.advance * scale;
    }

    M4f model = m4f_mul(m4f_translate(x, y, 0.0f), m4f_scale(scale));

    M4f projection = m4f_orthographic(0.0f, WINDOW_WIDTH, 0.0f, WINDOW_HEIGHT, 0.1f, 100.0f);

    M4f mvp = projection;//m4f_mul(model, projection);
    V2f viewport = (V2f){{WINDOW_WIDTH, WINDOW_HEIGHT}};
    glUseProgram(rd->text_shader);
    glUniformMatrix4fv(glGetUniformLocation(rd->text_shader, "mvp"), 1, false, mvp.c);
    glUniform2fv(glGetUniformLocation(rd->text_shader, "viewport"), 1, viewport.c);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, rd->curve_texture);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, rd->band_texture);

    glUniform1i(glGetUniformLocation(rd->text_shader, "curve_texture"), 0);
    glUniform1i(glGetUniformLocation(rd->text_shader, "band_texture"),  1);

    glBindVertexArray(rd->text_vao);
    glBindBuffer(GL_ARRAY_BUFFER, rd->text_vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vertex_count * sizeof(Slug_Vertex), verticies);


    glDrawArrays(GL_TRIANGLES, 0, vertex_count);

    free(verticies);
}

int main(int argc, char* argv[])
{
#if 0
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
#else
    (void)argv;
    (void)argc;
#endif

    char* input_path = ".\\out\\JetBrainsMonoNerdFontMono-ExtraBold.ttf"; //argv[1];
    // char* output_path = argv[2];

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
    for (size_t i = 32;i < 0x68/*ARRAY_SIZE(codepoints_to_process)*/;++i)
    {
        Glyph gl = {0};
        gl.cp = i;//codepoints_to_process[i];
        if (!process_codepoint(&font, &info, gl.cp, &gl))
        {
            fprintf(stderr, "Could not process codepoint 0x%x\n", gl.cp);
        }
        else
        {
            printf("processed codepoint %x\n", gl.cp);
            da_append(&font.glyphs, gl);
            processed_codepoints += 1;
        }
    }
    printf("Processed %d glyphs, curves %zu\n", processed_codepoints, font.curves.count);

    for (size_t i = 0;i < font.allocated_per_texture.count;++i)
    {
        printf("allocated in %zu = %d\n", i, font.allocated_per_texture.items[i]);
    }

    // SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_WINDOW_HIDDEN);
    // InitWindow(100, 100, "Dummy");
    //raster_glyph_atlas(&font, "out\\atlas.png");
    // for (size_t i = 0;i < font.glyphs.count; ++i)
    // {
    //     char buffer[1024] = {0};
    //     Glyph* gl = &font.glyphs.items[i];
    //     snprintf(buffer, 1024, "./out/osr_%02d.png", gl->cp);
    //     raster_single_glyph_atlas(&font, gl, buffer);
    // }
    printf("OK\n");

    RGFW_glHints* hints = RGFW_getGlobalHints_OpenGL();
    hints->debug = true;
    RGFW_setGlobalHints_OpenGL(hints);

    RGFW_window* window = RGFW_createWindow("Slug Font", 10, 10, WINDOW_WIDTH, WINDOW_HEIGHT, RGFW_windowAllowDND | RGFW_windowCenter | RGFW_windowOpenGL);
    if (!window)
    {
        fprintf(stderr, "window creation\n");
        return 1;
    }

    if (!gladLoadGLLoader((GLADloadproc)RGFW_getProcAddress_OpenGL))
    {
        fprintf(stderr, "Coult not load opengl\n");
        return 1;
    }

    Render_State rd = {0};
    if (!init_render_state(&rd, &font))
    {
        return 1;
    }

    while (RGFW_window_shouldClose(window) == RGFW_FALSE)
    {
        RGFW_event event;
        while (RGFW_window_checkEvent(window, &event))
        {
            if (event.type == RGFW_quit) break;
        }
        glClearColor(0.0, 0.0, 0.0, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        draw_text(&rd, &font, 90, 100, 50.0, "0123456789");
        // draw_text(&rd, &font, 90, 250, 150.0f, "Hello World!");
        // draw_text(&rd, &font, 90, 250 - 25.0f, 25.0f, "A complete success");
        // draw_text(&rd, &font, 90, 250 - 25.0f - 50.0f, 50.0f, "QC");

        RGFW_window_swapBuffers_OpenGL(window);
    }

    return 0;
}

#include "glad.c"
