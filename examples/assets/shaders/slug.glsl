struct Vert_To_Frag {
    vec4 position; // clip-space vertex position
    vec4 color; // color
    vec2 texcoord; // em-space sample coords
    flat vec4 banding; // scale and offset
    flat ivec4 glyph; // data x coord, data y coord, band max x, band max y
};

//uniform mat4 mvp;
uniform vec4 mvp[4]; // unfortunately opengl uses column-major matrices
uniform vec2 viewport;

#if VERTEX_SHADER

// xy = vertex coords, zw = normal vector
layout(location = 0) in vec4 in_position;

// xy = em-space coords, z = glyph data location (low and high 16 bits) in band texture as integer, w = max_band indexes
layout(location = 1) in vec4 in_tex;

// inverse Jacobian matrix entries. Literally 00, 01, 10, 11 encoded in the x y z w channels
layout(location = 2) in vec4 in_jac;

// band scale x, band scale y, band offset x, band offset y
layout(location = 3) in vec4 in_bnd;
layout(location = 4) in vec4 in_color; // rgba

out vec4 v_position;
out vec4 v_color;
out vec2 v_texcoord;
flat out vec4 v_banding;
flat out ivec4 v_glyph;

vec2 slug_dilute(vec4 pos, vec4 tex, vec4 jac, vec4 m[4], vec2 dim, out vec2 vpos)
{
    vec2 n = normalize(pos.zw);
    float s = dot(m[3].xy, pos.xy) + m[3].w;
    float t = dot(m[3].xy, n);

    float u = (s * dot(m[0].xy, n) - t * (dot(m[0].xy, pos.xy) + m[0].w)) * dim.x;
    float v = (s * dot(m[1].xy, n) - t * (dot(m[1].xy, pos.xy) + m[1].w)) * dim.y;

    float s2 = s * s;
    float st = s * t;
    float uv = u * u + v * v;
    vec2 d = pos.zw * (s2 * (st + sqrt(uv)) / (uv - st * st));

    vpos = pos.xy + d;
    return (vec2(tex.x + dot(d, jac.xy), tex.y + dot(d, jac.zw)));
}

void main()
{
    vec2 p;//= in_position.xy;
    v_texcoord = slug_dilute(in_position, in_tex, in_jac, mvp, viewport, p);
    //v_texcoord = in_tex.xy;
#if 1
    v_position.x = p.x * mvp[0].x + p.y * mvp[0].y + mvp[0].w;
    v_position.y = p.x * mvp[1].x + p.y * mvp[1].y + mvp[1].w;
    // TODO: figura out coordinate systems
    v_position.z = p.x * mvp[2].x + p.y * mvp[2].y + mvp[2].w;
    v_position.w = p.x * mvp[3].x + p.y * mvp[3].y + mvp[3].w;
#else
    v_position.x = p.x * mvp[0][0] + p.y * mvp[0][1] + mvp[0][3];
    v_position.y = p.x * mvp[1][0] + p.y * mvp[1][1] + mvp[1][3];
    // TODO: figura out coordinate systems
    v_position.z = p.x * mvp[2][0] + p.y * mvp[2][1] + mvp[2][3];
    v_position.w = p.x * mvp[3][0] + p.y * mvp[3][1] + mvp[3][3];
#endif

    gl_Position = v_position;
    v_color = in_color;
    v_banding = in_bnd;


    ivec2 glyph = floatBitsToInt(in_tex.zw);
    v_glyph = ivec4(glyph.x & 0xFFFF, glyph.x >> 16, glyph.y & 0xFFFF, glyph.y >> 16);
}

#endif

#if FRAGMENT_SHADER

uniform isampler2D curve_texture;
uniform usampler2D band_texture;


in vec4 v_position;
in vec4 v_color;
in vec2 v_texcoord;
flat in vec4 v_banding;
flat in ivec4 v_glyph;

out vec4 out_color;

// 2048
#define TEXEL_LINE_WIDTH_BITS 11

ivec2 calc_band_loc(ivec2 glyph_loc, uint offset_to_data)
{
    ivec2 band_loc = ivec2(glyph_loc.x + int(offset_to_data), glyph_loc.y);
    band_loc.y += band_loc.x >> TEXEL_LINE_WIDTH_BITS;
    band_loc.x &= (1 << TEXEL_LINE_WIDTH_BITS) - 1;
    return band_loc;
}

uint calc_root_code(float y1, float y2, float y3)
{
    uint i1 = floatBitsToUint(y1) >> 31U;
    uint i2 = floatBitsToUint(y2) >> 30U;
    uint i3 = floatBitsToUint(y3) >> 29U;

    uint shift = (i2 & 2U) | (i1 & ~2U);
    shift = (i3 & 4U) | (shift & ~4U);

    return ((0x2E74U >> shift) & 0x0101U);
}

vec2 solve_horiz_poly(vec2 p1, vec2 p2, vec2 p3)
{
    vec2 a = p1 - p2 * 2.0 + p3;
    vec2 b = p1 - p2;

    float ra = 1.0 / a.y;
    float rb = 0.5 / b.y;

    float d = sqrt(max(b.y * b.y - a.y * p1.y, 0.0));
    float t1 = (b.y - d) * ra;
    float t2 = (b.y + d) * ra;

    if (abs(a.y) < (1.0 / 65536.0))
    {
        t2 = p1.y * rb;
        t1 = t2;
    }

    return vec2(
        (a.x * t1 - b.x * 2.0) * t1 + p1.x,
        (a.x * t2 - b.x * 2.0) * t2 + p1.x
    );
}


vec2 solve_vert_poly(vec2 p1, vec2 p2, vec2 p3)
{
    vec2 a = p1 - p2 * 2.0 + p3;
    vec2 b = p1 - p2;

    float ra = 1.0 / a.x;
    float rb = 0.5 / b.x;

    float d = sqrt(max(b.x * b.x - a.x * p1.x, 0.0));
    float t1 = (b.x - d) * ra;
    float t2 = (b.x + d) * ra;

    if (abs(a.x) < (1.0 / 65536.0))
    {
        t2 = p1.x * rb;
        t1 = t2;
    }

    return vec2(
        (a.y * t1 - b.y * 2.0) * t1 + p1.y,
        (a.y * t2 - b.y * 2.0) * t2 + p1.y
    );
}

float saturate(float f)
{
    return clamp(f, 0.0, 1.0);
}

float slug_render(vec2 em_render_coord, ivec4 glyph, vec4 band_transform)
{
    vec2 em_per_pixel = fwidth(em_render_coord);
    vec2 pixels_per_em = 1.0 / em_per_pixel;

    ivec2 band_max = glyph.zw;
    band_max.y &= int(0x00FF);

    ivec2 idx_low_bound = ivec2((em_render_coord - band_transform.zw)/band_transform.xy);//ivec2(em_render_coord * band_transform.xy + band_transform.zw);
    ivec2 band_idx = clamp(idx_low_bound, ivec2(0), band_max);
    ivec2 glyph_loc = glyph.xy;

    //return float(band_idx.x)/float(band_max.x+1.0) + 0.1;
    //return float(band_idx.y)/float(band_max.y+1.0) + 0.1;

    float xcov = 0.0;
    float xwgt = 0.0;

    uvec2 h_band_data = uvec2(texelFetch(band_texture, ivec2(glyph_loc.x + band_idx.y, glyph_loc.y), 0).xy);
    ivec2 h_band_loc = calc_band_loc(ivec2(glyph_loc.x, glyph_loc.y), h_band_data.y);

    for (uint curve_idx = 0U; curve_idx < h_band_data.x;curve_idx += 1U)
    {
        ivec2 curve_loc = ivec2(texelFetch(band_texture, ivec2(h_band_loc.x + int(curve_idx), h_band_loc.y), 0).xy);

        vec4 p12 = vec4(texelFetch(curve_texture, curve_loc, 0));
        vec2 p3 = vec2(texelFetch(curve_texture, ivec2(curve_loc.x + 1, curve_loc.y), 0).xy) - em_render_coord;
        vec2 p1 = p12.xy - em_render_coord;
        vec2 p2 = p12.zw - em_render_coord;

        if ((max(max(p1.x, p2.x), p3.x) * pixels_per_em.x) < -0.5) break;

        uint code = calc_root_code(p1.y, p2.y, p3.y);

        if (code != 0U)
        {
            vec2 r = solve_horiz_poly(p1, p2, p3) * pixels_per_em.x;

            if ((code & 1U) != 0U)
            {
                xcov += saturate(r.x + 0.5);
                xwgt = max(xwgt, saturate(1.0 - abs(r.x) * 2.0));
            }

            if (code > 1U)
            {
                xcov -= saturate(r.y + 0.5);
                xwgt = max(xwgt, saturate(1.0 - abs(r.y) * 2.0));
            }
        }
    }

    float ycov = 0.0;
    float ywgt = 0.0;

    uvec2 v_band_data = texelFetch(band_texture, ivec2(glyph_loc.x + band_max.y + 1 + band_idx.x, glyph_loc.y), 0).xy;
    ivec2 v_band_loc = calc_band_loc(ivec2(glyph_loc.x, glyph_loc.y), v_band_data.y);

    for (uint curve_idx = 0U; curve_idx < v_band_data.x;curve_idx += 1U)
    {
        ivec2 curve_loc = ivec2(texelFetch(band_texture, ivec2(v_band_loc.x + int(curve_idx), v_band_loc.y), 0).xy);
        vec4 p12 = vec4(texelFetch(curve_texture, curve_loc, 0));
        vec2 p3 = vec2(texelFetch(curve_texture, ivec2(curve_loc.x + 1, curve_loc.y), 0).xy) - em_render_coord;

        vec2 p1 = p12.xy - em_render_coord;
        vec2 p2 = p12.zw - em_render_coord;

        if ((max(max(p1.y, p2.y), p3.y) * pixels_per_em.y) < -0.5) break;

        uint code = calc_root_code(p1.x, p2.x, p3.x);

        if (code != 0U)
        {
            vec2 r = solve_vert_poly(p1, p2, p3) * pixels_per_em.y;
            if ((code & 1U) != 0U)
            {
                ycov -= saturate(r.x + 0.5);
                ywgt = max(ywgt, saturate(1.0 - abs(r.x) * 2.0));
            }
            if (code > 1U)
            {
                ycov += saturate(r.y + 0.5);
                ywgt = max(ywgt, saturate(1.0 - abs(r.y) * 2.0));
            }
        }
    }

    return max(abs(xcov * xwgt + ycov * ywgt) / max(xwgt + ywgt, 1.0 / 65536.0), min(abs(xcov), abs(ycov)));
}

void main()
{
    float coverage = slug_render(v_texcoord, v_glyph, v_banding);
    out_color = v_color * coverage;
}

#endif
