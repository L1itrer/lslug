struct Vert_To_Frag {
    vec4 position; // clip-space vertex position
    vec4 color; // color
    vec2 texcoord; // em-space sample coords
    flat vec4 banding; // scale and offset
    flat ivec4 glyph; // data x coord, data y coord, band max x, band max y
};

uniform mat4 mvp;
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

out Vert_To_Frag vert;

vec2 slug_dilute(vec4 pos, vec4 tex, vec4 jac, mat4 m, vec2 dim, out vec2 vpos)
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
    vec2 p;
    vert.texcoord = slug_dilute(in_position, in_tex, in_jac, mvp, viewport, p);
#if 1
    vert.position.x = p.x * mvp[0].x + p.y * mvp[0].y + mvp[0].w;
    vert.position.y = p.x * mvp[1].x + p.y * mvp[1].y + mvp[1].w;
    // TODO: figura out coordinate systems
    vert.position.z = 1.0;//p.x * mvp[2].x + p.y * mvp[2].y + mvp[2].w;
    vert.position.w = p.x * mvp[3].x + p.y * mvp[3].y + mvp[3].w;
#else
    vert.position = vec4(in_position.xy, -1.0, 1.0) * mvp;
#endif

    gl_Position = vert.position;
    vert.color = in_color;
    vert.banding = in_bnd;


    ivec2 glyph = floatBitsToInt(in_tex.zw);
    vert.glyph = ivec4(glyph.x & 0xFFFF, glyph.x >> 16, glyph.y & 0xFFFF, glyph.y >> 16);
}

#endif

#if FRAGMENT_SHADER

// uniform isampler2D curve_texture;
// uniform usampler2D band_texture;

in Vert_To_Frag vert;
out vec4 out_color;

float slug_render(vec2 em_render_coord, ivec4 glyph, vec4 band_transform)
{
    vec2 em_per_pixel = fwidth(em_render_coord);
    vec2 pixels_per_em = 1.0 / em_per_pixel;

    ivec2 band_max = glyph.zw;
    band_max.y &= int(0x00FF);

    ivec2 idx_low_bound = ivec2(em_render_coord * band_transform.xy + band_transform.zw);
    ivec2 band_idx = clamp(idx_low_bound, ivec2(0), band_max);
    ivec2 glyph_loc = ivec2(glyph.xy);

    float xcov = 0.0;
    float xwgt = 0.0;

    //ivec2 h_band_data = texelFetch();

    return 1.0;
}

void main()
{
    float coverage = slug_render(vert.texcoord, vert.glyph, vert.banding);
    out_color = vert.color * coverage;
}

#endif
