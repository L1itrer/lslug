#ifndef LA_H_
#define LA_H_

#include <math.h>
#include <stdbool.h>

#ifndef LADEF
#define LADEF static inline
#endif // LADEF

#ifdef LA_WARN_DEPRECATED
#    ifndef LA_DEPRECATED
#        if defined(__GNUC__) || defined(__clang__)
#            define LA_DEPRECATED(message) __attribute__((deprecated(message)))
#        elif defined(_MSC_VER)
#            define LA_DEPRECATED(message) __declspec(deprecated(message))
#        else
#            define LA_DEPRECATED(...)
#        endif
#    endif /* LA_DEPRECATED */
#else
#    define LA_DEPRECATED(...)
#endif /* LA_WARN_DEPRECATED */

LADEF float lerpf(float a, float b, float t);
LADEF double lerp(double a, double b, double t);
LADEF int mini(int a, int b);
LADEF unsigned int minu(unsigned int a, unsigned int b);
LADEF int maxi(int a, int b);
LADEF unsigned int maxu(unsigned int a, unsigned int b);
LADEF float clampf(float x, float a, float b);
LADEF double clampd(double x, double a, double b);
LADEF int clampi(int x, int a, int b);
LADEF unsigned int clampu(unsigned int x, unsigned int a, unsigned int b);

typedef union {
    struct { float x, y; };
    float c[2];
} V2f;

typedef union {
    struct {
        float _11, _12;
        float _21, _22;
    };
    V2f v[2];
    float m[2][2];
    float c[4];
} M2f;

typedef union {
    struct { double x, y; };
    double c[2];
} V2d;

typedef union {
    struct {
        double _11, _12;
        double _21, _22;
    };
    V2d v[2];
    double m[2][2];
    double c[4];
} M2d;

typedef union {
    struct { int x, y; };
    int c[2];
} V2i;

typedef union {
    struct {
        int _11, _12;
        int _21, _22;
    };
    V2i v[2];
    int m[2][2];
    int c[4];
} M2i;

typedef union {
    struct { unsigned int x, y; };
    unsigned int c[2];
} V2u;

typedef union {
    struct {
        unsigned int _11, _12;
        unsigned int _21, _22;
    };
    V2u v[2];
    unsigned int m[2][2];
    unsigned int c[4];
} M2u;

typedef union {
    struct { float x, y, z; };
    struct { V2f xy; float __pad1; };
    struct { float __pad2; V2f yz; };
    float c[3];
} V3f;

typedef union {
    struct {
        float _11, _12, _13;
        float _21, _22, _23;
        float _31, _32, _33;
    };
    V3f v[3];
    float m[3][3];
    float c[9];
} M3f;

typedef union {
    struct { double x, y, z; };
    struct { V2d xy; double __pad1; };
    struct { double __pad2; V2d yz; };
    double c[3];
} V3d;

typedef union {
    struct {
        double _11, _12, _13;
        double _21, _22, _23;
        double _31, _32, _33;
    };
    V3d v[3];
    double m[3][3];
    double c[9];
} M3d;

typedef union {
    struct { int x, y, z; };
    struct { V2i xy; int __pad1; };
    struct { int __pad2; V2i yz; };
    int c[3];
} V3i;

typedef union {
    struct {
        int _11, _12, _13;
        int _21, _22, _23;
        int _31, _32, _33;
    };
    V3i v[3];
    int m[3][3];
    int c[9];
} M3i;

typedef union {
    struct { unsigned int x, y, z; };
    struct { V2u xy; unsigned int __pad1; };
    struct { unsigned int __pad2; V2u yz; };
    unsigned int c[3];
} V3u;

typedef union {
    struct {
        unsigned int _11, _12, _13;
        unsigned int _21, _22, _23;
        unsigned int _31, _32, _33;
    };
    V3u v[3];
    unsigned int m[3][3];
    unsigned int c[9];
} M3u;

typedef union {
    struct { float x, y, z, w; };
    struct { V2f xy; V2f zw; };
    struct { float __pad1; V2f yz; float __pad2; };
    struct { V3f xyz; float __pad3; };
    struct { float __pad4; V3f yzw; };
    float c[4];
} V4f;

typedef union {
    struct {
        float _11, _12, _13, _14;
        float _21, _22, _23, _24;
        float _31, _32, _33, _34;
        float _41, _42, _43, _44;
    };
    V4f v[4];
    float m[4][4];
    float c[16];
} M4f;

typedef union {
    struct { double x, y, z, w; };
    struct { V2d xy; V2d zw; };
    struct { double __pad1; V2d yz; double __pad2; };
    struct { V3d xyz; double __pad3; };
    struct { double __pad4; V3d yzw; };
    double c[4];
} V4d;

typedef union {
    struct {
        double _11, _12, _13, _14;
        double _21, _22, _23, _24;
        double _31, _32, _33, _34;
        double _41, _42, _43, _44;
    };
    V4d v[4];
    double m[4][4];
    double c[16];
} M4d;

typedef union {
    struct { int x, y, z, w; };
    struct { V2i xy; V2i zw; };
    struct { int __pad1; V2i yz; int __pad2; };
    struct { V3i xyz; int __pad3; };
    struct { int __pad4; V3i yzw; };
    int c[4];
} V4i;

typedef union {
    struct {
        int _11, _12, _13, _14;
        int _21, _22, _23, _24;
        int _31, _32, _33, _34;
        int _41, _42, _43, _44;
    };
    V4i v[4];
    int m[4][4];
    int c[16];
} M4i;

typedef union {
    struct { unsigned int x, y, z, w; };
    struct { V2u xy; V2u zw; };
    struct { unsigned int __pad1; V2u yz; unsigned int __pad2; };
    struct { V3u xyz; unsigned int __pad3; };
    struct { unsigned int __pad4; V3u yzw; };
    unsigned int c[4];
} V4u;

typedef union {
    struct {
        unsigned int _11, _12, _13, _14;
        unsigned int _21, _22, _23, _24;
        unsigned int _31, _32, _33, _34;
        unsigned int _41, _42, _43, _44;
    };
    V4u v[4];
    unsigned int m[4][4];
    unsigned int c[16];
} M4u;

#define V2f_Fmt "v2f(%f, %f)"
#define V2f_Arg(v) (v).x, (v).y
LADEF V2f v2f(float x, float y);
LADEF V2f v2ff(float x);

LADEF V2f v2d_2f(V2d a);
LA_DEPRECATED("Use v2d_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f2d(V2d a);
LADEF V2f v2i_2f(V2i a);
LA_DEPRECATED("Use v2i_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f2i(V2i a);
LADEF V2f v2u_2f(V2u a);
LA_DEPRECATED("Use v2u_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f2u(V2u a);
LADEF V2f v3f_2f(V3f a);
LA_DEPRECATED("Use v3f_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f3f(V3f a);
LADEF V2f v3d_2f(V3d a);
LA_DEPRECATED("Use v3d_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f3d(V3d a);
LADEF V2f v3i_2f(V3i a);
LA_DEPRECATED("Use v3i_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f3i(V3i a);
LADEF V2f v3u_2f(V3u a);
LA_DEPRECATED("Use v3u_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f3u(V3u a);
LADEF V2f v4f_2f(V4f a);
LA_DEPRECATED("Use v4f_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f4f(V4f a);
LADEF V2f v4d_2f(V4d a);
LA_DEPRECATED("Use v4d_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f4d(V4d a);
LADEF V2f v4i_2f(V4i a);
LA_DEPRECATED("Use v4i_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f4i(V4i a);
LADEF V2f v4u_2f(V4u a);
LA_DEPRECATED("Use v4u_2f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2f v2f4u(V4u a);

LADEF V2f v2f_sum(V2f a, V2f b);
LADEF V2f v2f_add(V2f a, V2f b);
LADEF V2f v2f_sub(V2f a, V2f b);
LADEF V2f v2f_mul(V2f a, V2f b);
LADEF V2f v2f_div(V2f a, V2f b);
LADEF V2f v2f_mod(V2f a, V2f b);
LADEF V2f v2f_sqrt(V2f a);
LADEF V2f v2f_pow(V2f base, V2f exp);
LADEF V2f v2f_sin(V2f a);
LADEF V2f v2f_cos(V2f a);
LADEF V2f v2f_min(V2f a, V2f b);
LADEF V2f v2f_max(V2f a, V2f b);
LADEF V2f v2f_lerp(V2f a, V2f b, V2f t);
LADEF V2f v2f_floor(V2f a);
LADEF V2f v2f_ceil(V2f a);
LADEF V2f v2f_clamp(V2f x, V2f a, V2f b);
LADEF float v2f_sqrlen(V2f a);
LADEF float v2f_len(V2f a);
LADEF float v2f_dot(V2f a, V2f b);
LADEF V2f v2f_norm(V2f a, float eps, V2f fallback);
LADEF bool v2f_eq(V2f a, V2f b, float eps);
LADEF V2f v2f_reflect(V2f i, V2f n);
LADEF M2f m2f_id(void);
LADEF M2f m2f_zero(void);
LADEF M2f m2f_mul(M2f a, M2f b);
LADEF V2f m2f_mul_vec(M2f m, V2f v);
LADEF M2f m2f_rot(float angle);

#define V2d_Fmt "v2d(%lf, %lf)"
#define V2d_Arg(v) (v).x, (v).y
LADEF V2d v2d(double x, double y);
LADEF V2d v2dd(double x);

LADEF V2d v2f_2d(V2f a);
LA_DEPRECATED("Use v2f_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d2f(V2f a);
LADEF V2d v2i_2d(V2i a);
LA_DEPRECATED("Use v2i_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d2i(V2i a);
LADEF V2d v2u_2d(V2u a);
LA_DEPRECATED("Use v2u_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d2u(V2u a);
LADEF V2d v3f_2d(V3f a);
LA_DEPRECATED("Use v3f_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d3f(V3f a);
LADEF V2d v3d_2d(V3d a);
LA_DEPRECATED("Use v3d_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d3d(V3d a);
LADEF V2d v3i_2d(V3i a);
LA_DEPRECATED("Use v3i_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d3i(V3i a);
LADEF V2d v3u_2d(V3u a);
LA_DEPRECATED("Use v3u_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d3u(V3u a);
LADEF V2d v4f_2d(V4f a);
LA_DEPRECATED("Use v4f_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d4f(V4f a);
LADEF V2d v4d_2d(V4d a);
LA_DEPRECATED("Use v4d_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d4d(V4d a);
LADEF V2d v4i_2d(V4i a);
LA_DEPRECATED("Use v4i_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d4i(V4i a);
LADEF V2d v4u_2d(V4u a);
LA_DEPRECATED("Use v4u_2d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2d v2d4u(V4u a);

LADEF V2d v2d_sum(V2d a, V2d b);
LADEF V2d v2d_add(V2d a, V2d b);
LADEF V2d v2d_sub(V2d a, V2d b);
LADEF V2d v2d_mul(V2d a, V2d b);
LADEF V2d v2d_div(V2d a, V2d b);
LADEF V2d v2d_mod(V2d a, V2d b);
LADEF V2d v2d_sqrt(V2d a);
LADEF V2d v2d_pow(V2d base, V2d exp);
LADEF V2d v2d_sin(V2d a);
LADEF V2d v2d_cos(V2d a);
LADEF V2d v2d_min(V2d a, V2d b);
LADEF V2d v2d_max(V2d a, V2d b);
LADEF V2d v2d_lerp(V2d a, V2d b, V2d t);
LADEF V2d v2d_floor(V2d a);
LADEF V2d v2d_ceil(V2d a);
LADEF V2d v2d_clamp(V2d x, V2d a, V2d b);
LADEF double v2d_sqrlen(V2d a);
LADEF double v2d_len(V2d a);
LADEF double v2d_dot(V2d a, V2d b);
LADEF V2d v2d_norm(V2d a, double eps, V2d fallback);
LADEF bool v2d_eq(V2d a, V2d b, double eps);
LADEF V2d v2d_reflect(V2d i, V2d n);
LADEF M2d m2d_id(void);
LADEF M2d m2d_zero(void);
LADEF M2d m2d_mul(M2d a, M2d b);
LADEF V2d m2d_mul_vec(M2d m, V2d v);
LADEF M2d m2d_rot(double angle);

#define V2i_Fmt "v2i(%d, %d)"
#define V2i_Arg(v) (v).x, (v).y
LADEF V2i v2i(int x, int y);
LADEF V2i v2ii(int x);

LADEF V2i v2f_2i(V2f a);
LA_DEPRECATED("Use v2f_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i2f(V2f a);
LADEF V2i v2d_2i(V2d a);
LA_DEPRECATED("Use v2d_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i2d(V2d a);
LADEF V2i v2u_2i(V2u a);
LA_DEPRECATED("Use v2u_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i2u(V2u a);
LADEF V2i v3f_2i(V3f a);
LA_DEPRECATED("Use v3f_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i3f(V3f a);
LADEF V2i v3d_2i(V3d a);
LA_DEPRECATED("Use v3d_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i3d(V3d a);
LADEF V2i v3i_2i(V3i a);
LA_DEPRECATED("Use v3i_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i3i(V3i a);
LADEF V2i v3u_2i(V3u a);
LA_DEPRECATED("Use v3u_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i3u(V3u a);
LADEF V2i v4f_2i(V4f a);
LA_DEPRECATED("Use v4f_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i4f(V4f a);
LADEF V2i v4d_2i(V4d a);
LA_DEPRECATED("Use v4d_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i4d(V4d a);
LADEF V2i v4i_2i(V4i a);
LA_DEPRECATED("Use v4i_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i4i(V4i a);
LADEF V2i v4u_2i(V4u a);
LA_DEPRECATED("Use v4u_2i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2i v2i4u(V4u a);

LADEF V2i v2i_sum(V2i a, V2i b);
LADEF V2i v2i_add(V2i a, V2i b);
LADEF V2i v2i_sub(V2i a, V2i b);
LADEF V2i v2i_mul(V2i a, V2i b);
LADEF V2i v2i_div(V2i a, V2i b);
LADEF V2i v2i_mod(V2i a, V2i b);
LADEF V2i v2i_min(V2i a, V2i b);
LADEF V2i v2i_max(V2i a, V2i b);
LADEF V2i v2i_clamp(V2i x, V2i a, V2i b);
LADEF int v2i_sqrlen(V2i a);
LADEF int v2i_dot(V2i a, V2i b);
LADEF bool v2i_eq(V2i a, V2i b);
LADEF V2i v2i_reflect(V2i i, V2i n);
LADEF M2i m2i_id(void);
LADEF M2i m2i_zero(void);
LADEF M2i m2i_mul(M2i a, M2i b);
LADEF V2i m2i_mul_vec(M2i m, V2i v);

#define V2u_Fmt "v2u(%u, %u)"
#define V2u_Arg(v) (v).x, (v).y
LADEF V2u v2u(unsigned int x, unsigned int y);
LADEF V2u v2uu(unsigned int x);

LADEF V2u v2f_2u(V2f a);
LA_DEPRECATED("Use v2f_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u2f(V2f a);
LADEF V2u v2d_2u(V2d a);
LA_DEPRECATED("Use v2d_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u2d(V2d a);
LADEF V2u v2i_2u(V2i a);
LA_DEPRECATED("Use v2i_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u2i(V2i a);
LADEF V2u v3f_2u(V3f a);
LA_DEPRECATED("Use v3f_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u3f(V3f a);
LADEF V2u v3d_2u(V3d a);
LA_DEPRECATED("Use v3d_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u3d(V3d a);
LADEF V2u v3i_2u(V3i a);
LA_DEPRECATED("Use v3i_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u3i(V3i a);
LADEF V2u v3u_2u(V3u a);
LA_DEPRECATED("Use v3u_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u3u(V3u a);
LADEF V2u v4f_2u(V4f a);
LA_DEPRECATED("Use v4f_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u4f(V4f a);
LADEF V2u v4d_2u(V4d a);
LA_DEPRECATED("Use v4d_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u4d(V4d a);
LADEF V2u v4i_2u(V4i a);
LA_DEPRECATED("Use v4i_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u4i(V4i a);
LADEF V2u v4u_2u(V4u a);
LA_DEPRECATED("Use v4u_2u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V2u v2u4u(V4u a);

LADEF V2u v2u_sum(V2u a, V2u b);
LADEF V2u v2u_add(V2u a, V2u b);
LADEF V2u v2u_sub(V2u a, V2u b);
LADEF V2u v2u_mul(V2u a, V2u b);
LADEF V2u v2u_div(V2u a, V2u b);
LADEF V2u v2u_mod(V2u a, V2u b);
LADEF V2u v2u_min(V2u a, V2u b);
LADEF V2u v2u_max(V2u a, V2u b);
LADEF V2u v2u_clamp(V2u x, V2u a, V2u b);
LADEF unsigned int v2u_sqrlen(V2u a);
LADEF unsigned int v2u_dot(V2u a, V2u b);
LADEF bool v2u_eq(V2u a, V2u b);
LADEF V2u v2u_reflect(V2u i, V2u n);
LADEF M2u m2u_id(void);
LADEF M2u m2u_zero(void);
LADEF M2u m2u_mul(M2u a, M2u b);
LADEF V2u m2u_mul_vec(M2u m, V2u v);

#define V3f_Fmt "v3f(%f, %f, %f)"
#define V3f_Arg(v) (v).x, (v).y, (v).z
LADEF V3f v3f(float x, float y, float z);
LADEF V3f v3ff(float x);

LADEF V3f v2f_3f(V2f a);
LA_DEPRECATED("Use v2f_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f2f(V2f a);
LADEF V3f v2d_3f(V2d a);
LA_DEPRECATED("Use v2d_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f2d(V2d a);
LADEF V3f v2i_3f(V2i a);
LA_DEPRECATED("Use v2i_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f2i(V2i a);
LADEF V3f v2u_3f(V2u a);
LA_DEPRECATED("Use v2u_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f2u(V2u a);
LADEF V3f v3d_3f(V3d a);
LA_DEPRECATED("Use v3d_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f3d(V3d a);
LADEF V3f v3i_3f(V3i a);
LA_DEPRECATED("Use v3i_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f3i(V3i a);
LADEF V3f v3u_3f(V3u a);
LA_DEPRECATED("Use v3u_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f3u(V3u a);
LADEF V3f v4f_3f(V4f a);
LA_DEPRECATED("Use v4f_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f4f(V4f a);
LADEF V3f v4d_3f(V4d a);
LA_DEPRECATED("Use v4d_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f4d(V4d a);
LADEF V3f v4i_3f(V4i a);
LA_DEPRECATED("Use v4i_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f4i(V4i a);
LADEF V3f v4u_3f(V4u a);
LA_DEPRECATED("Use v4u_3f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3f v3f4u(V4u a);

LADEF V3f v3f_sum(V3f a, V3f b);
LADEF V3f v3f_add(V3f a, V3f b);
LADEF V3f v3f_sub(V3f a, V3f b);
LADEF V3f v3f_mul(V3f a, V3f b);
LADEF V3f v3f_div(V3f a, V3f b);
LADEF V3f v3f_mod(V3f a, V3f b);
LADEF V3f v3f_sqrt(V3f a);
LADEF V3f v3f_pow(V3f base, V3f exp);
LADEF V3f v3f_sin(V3f a);
LADEF V3f v3f_cos(V3f a);
LADEF V3f v3f_min(V3f a, V3f b);
LADEF V3f v3f_max(V3f a, V3f b);
LADEF V3f v3f_lerp(V3f a, V3f b, V3f t);
LADEF V3f v3f_floor(V3f a);
LADEF V3f v3f_ceil(V3f a);
LADEF V3f v3f_clamp(V3f x, V3f a, V3f b);
LADEF float v3f_sqrlen(V3f a);
LADEF float v3f_len(V3f a);
LADEF float v3f_dot(V3f a, V3f b);
LADEF V3f v3f_norm(V3f a, float eps, V3f fallback);
LADEF V3f v3f_cross(V3f a, V3f b);
LADEF bool v3f_eq(V3f a, V3f b, float eps);
LADEF V3f v3f_reflect(V3f i, V3f n);
LADEF M3f m3f_id(void);
LADEF M3f m3f_zero(void);
LADEF M3f m3f_mul(M3f a, M3f b);
LADEF V3f m3f_mul_vec(M3f m, V3f v);
LADEF M3f m3f_rot_x(float angle);
LADEF M3f m3f_rot_y(float angle);
LADEF M3f m3f_rot_z(float angle);

#define V3d_Fmt "v3d(%lf, %lf, %lf)"
#define V3d_Arg(v) (v).x, (v).y, (v).z
LADEF V3d v3d(double x, double y, double z);
LADEF V3d v3dd(double x);

LADEF V3d v2f_3d(V2f a);
LA_DEPRECATED("Use v2f_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d2f(V2f a);
LADEF V3d v2d_3d(V2d a);
LA_DEPRECATED("Use v2d_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d2d(V2d a);
LADEF V3d v2i_3d(V2i a);
LA_DEPRECATED("Use v2i_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d2i(V2i a);
LADEF V3d v2u_3d(V2u a);
LA_DEPRECATED("Use v2u_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d2u(V2u a);
LADEF V3d v3f_3d(V3f a);
LA_DEPRECATED("Use v3f_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d3f(V3f a);
LADEF V3d v3i_3d(V3i a);
LA_DEPRECATED("Use v3i_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d3i(V3i a);
LADEF V3d v3u_3d(V3u a);
LA_DEPRECATED("Use v3u_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d3u(V3u a);
LADEF V3d v4f_3d(V4f a);
LA_DEPRECATED("Use v4f_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d4f(V4f a);
LADEF V3d v4d_3d(V4d a);
LA_DEPRECATED("Use v4d_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d4d(V4d a);
LADEF V3d v4i_3d(V4i a);
LA_DEPRECATED("Use v4i_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d4i(V4i a);
LADEF V3d v4u_3d(V4u a);
LA_DEPRECATED("Use v4u_3d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3d v3d4u(V4u a);

LADEF V3d v3d_sum(V3d a, V3d b);
LADEF V3d v3d_add(V3d a, V3d b);
LADEF V3d v3d_sub(V3d a, V3d b);
LADEF V3d v3d_mul(V3d a, V3d b);
LADEF V3d v3d_div(V3d a, V3d b);
LADEF V3d v3d_mod(V3d a, V3d b);
LADEF V3d v3d_sqrt(V3d a);
LADEF V3d v3d_pow(V3d base, V3d exp);
LADEF V3d v3d_sin(V3d a);
LADEF V3d v3d_cos(V3d a);
LADEF V3d v3d_min(V3d a, V3d b);
LADEF V3d v3d_max(V3d a, V3d b);
LADEF V3d v3d_lerp(V3d a, V3d b, V3d t);
LADEF V3d v3d_floor(V3d a);
LADEF V3d v3d_ceil(V3d a);
LADEF V3d v3d_clamp(V3d x, V3d a, V3d b);
LADEF double v3d_sqrlen(V3d a);
LADEF double v3d_len(V3d a);
LADEF double v3d_dot(V3d a, V3d b);
LADEF V3d v3d_norm(V3d a, double eps, V3d fallback);
LADEF V3d v3d_cross(V3d a, V3d b);
LADEF bool v3d_eq(V3d a, V3d b, double eps);
LADEF V3d v3d_reflect(V3d i, V3d n);
LADEF M3d m3d_id(void);
LADEF M3d m3d_zero(void);
LADEF M3d m3d_mul(M3d a, M3d b);
LADEF V3d m3d_mul_vec(M3d m, V3d v);
LADEF M3d m3d_rot_x(double angle);
LADEF M3d m3d_rot_y(double angle);
LADEF M3d m3d_rot_z(double angle);

#define V3i_Fmt "v3i(%d, %d, %d)"
#define V3i_Arg(v) (v).x, (v).y, (v).z
LADEF V3i v3i(int x, int y, int z);
LADEF V3i v3ii(int x);

LADEF V3i v2f_3i(V2f a);
LA_DEPRECATED("Use v2f_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i2f(V2f a);
LADEF V3i v2d_3i(V2d a);
LA_DEPRECATED("Use v2d_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i2d(V2d a);
LADEF V3i v2i_3i(V2i a);
LA_DEPRECATED("Use v2i_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i2i(V2i a);
LADEF V3i v2u_3i(V2u a);
LA_DEPRECATED("Use v2u_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i2u(V2u a);
LADEF V3i v3f_3i(V3f a);
LA_DEPRECATED("Use v3f_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i3f(V3f a);
LADEF V3i v3d_3i(V3d a);
LA_DEPRECATED("Use v3d_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i3d(V3d a);
LADEF V3i v3u_3i(V3u a);
LA_DEPRECATED("Use v3u_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i3u(V3u a);
LADEF V3i v4f_3i(V4f a);
LA_DEPRECATED("Use v4f_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i4f(V4f a);
LADEF V3i v4d_3i(V4d a);
LA_DEPRECATED("Use v4d_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i4d(V4d a);
LADEF V3i v4i_3i(V4i a);
LA_DEPRECATED("Use v4i_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i4i(V4i a);
LADEF V3i v4u_3i(V4u a);
LA_DEPRECATED("Use v4u_3i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3i v3i4u(V4u a);

LADEF V3i v3i_sum(V3i a, V3i b);
LADEF V3i v3i_add(V3i a, V3i b);
LADEF V3i v3i_sub(V3i a, V3i b);
LADEF V3i v3i_mul(V3i a, V3i b);
LADEF V3i v3i_div(V3i a, V3i b);
LADEF V3i v3i_mod(V3i a, V3i b);
LADEF V3i v3i_min(V3i a, V3i b);
LADEF V3i v3i_max(V3i a, V3i b);
LADEF V3i v3i_clamp(V3i x, V3i a, V3i b);
LADEF int v3i_sqrlen(V3i a);
LADEF int v3i_dot(V3i a, V3i b);
LADEF V3i v3i_cross(V3i a, V3i b);
LADEF bool v3i_eq(V3i a, V3i b);
LADEF V3i v3i_reflect(V3i i, V3i n);
LADEF M3i m3i_id(void);
LADEF M3i m3i_zero(void);
LADEF M3i m3i_mul(M3i a, M3i b);
LADEF V3i m3i_mul_vec(M3i m, V3i v);

#define V3u_Fmt "v3u(%u, %u, %u)"
#define V3u_Arg(v) (v).x, (v).y, (v).z
LADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z);
LADEF V3u v3uu(unsigned int x);

LADEF V3u v2f_3u(V2f a);
LA_DEPRECATED("Use v2f_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u2f(V2f a);
LADEF V3u v2d_3u(V2d a);
LA_DEPRECATED("Use v2d_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u2d(V2d a);
LADEF V3u v2i_3u(V2i a);
LA_DEPRECATED("Use v2i_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u2i(V2i a);
LADEF V3u v2u_3u(V2u a);
LA_DEPRECATED("Use v2u_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u2u(V2u a);
LADEF V3u v3f_3u(V3f a);
LA_DEPRECATED("Use v3f_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u3f(V3f a);
LADEF V3u v3d_3u(V3d a);
LA_DEPRECATED("Use v3d_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u3d(V3d a);
LADEF V3u v3i_3u(V3i a);
LA_DEPRECATED("Use v3i_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u3i(V3i a);
LADEF V3u v4f_3u(V4f a);
LA_DEPRECATED("Use v4f_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u4f(V4f a);
LADEF V3u v4d_3u(V4d a);
LA_DEPRECATED("Use v4d_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u4d(V4d a);
LADEF V3u v4i_3u(V4i a);
LA_DEPRECATED("Use v4i_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u4i(V4i a);
LADEF V3u v4u_3u(V4u a);
LA_DEPRECATED("Use v4u_3u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V3u v3u4u(V4u a);

LADEF V3u v3u_sum(V3u a, V3u b);
LADEF V3u v3u_add(V3u a, V3u b);
LADEF V3u v3u_sub(V3u a, V3u b);
LADEF V3u v3u_mul(V3u a, V3u b);
LADEF V3u v3u_div(V3u a, V3u b);
LADEF V3u v3u_mod(V3u a, V3u b);
LADEF V3u v3u_min(V3u a, V3u b);
LADEF V3u v3u_max(V3u a, V3u b);
LADEF V3u v3u_clamp(V3u x, V3u a, V3u b);
LADEF unsigned int v3u_sqrlen(V3u a);
LADEF unsigned int v3u_dot(V3u a, V3u b);
LADEF V3u v3u_cross(V3u a, V3u b);
LADEF bool v3u_eq(V3u a, V3u b);
LADEF V3u v3u_reflect(V3u i, V3u n);
LADEF M3u m3u_id(void);
LADEF M3u m3u_zero(void);
LADEF M3u m3u_mul(M3u a, M3u b);
LADEF V3u m3u_mul_vec(M3u m, V3u v);

#define V4f_Fmt "v4f(%f, %f, %f, %f)"
#define V4f_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4f v4f(float x, float y, float z, float w);
LADEF V4f v4ff(float x);

LADEF V4f v2f_4f(V2f a);
LA_DEPRECATED("Use v2f_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f2f(V2f a);
LADEF V4f v2d_4f(V2d a);
LA_DEPRECATED("Use v2d_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f2d(V2d a);
LADEF V4f v2i_4f(V2i a);
LA_DEPRECATED("Use v2i_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f2i(V2i a);
LADEF V4f v2u_4f(V2u a);
LA_DEPRECATED("Use v2u_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f2u(V2u a);
LADEF V4f v3f_4f(V3f a);
LA_DEPRECATED("Use v3f_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f3f(V3f a);
LADEF V4f v3d_4f(V3d a);
LA_DEPRECATED("Use v3d_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f3d(V3d a);
LADEF V4f v3i_4f(V3i a);
LA_DEPRECATED("Use v3i_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f3i(V3i a);
LADEF V4f v3u_4f(V3u a);
LA_DEPRECATED("Use v3u_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f3u(V3u a);
LADEF V4f v4d_4f(V4d a);
LA_DEPRECATED("Use v4d_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f4d(V4d a);
LADEF V4f v4i_4f(V4i a);
LA_DEPRECATED("Use v4i_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f4i(V4i a);
LADEF V4f v4u_4f(V4u a);
LA_DEPRECATED("Use v4u_4f instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4f v4f4u(V4u a);

LADEF V4f v4f_sum(V4f a, V4f b);
LADEF V4f v4f_add(V4f a, V4f b);
LADEF V4f v4f_sub(V4f a, V4f b);
LADEF V4f v4f_mul(V4f a, V4f b);
LADEF V4f v4f_div(V4f a, V4f b);
LADEF V4f v4f_mod(V4f a, V4f b);
LADEF V4f v4f_sqrt(V4f a);
LADEF V4f v4f_pow(V4f base, V4f exp);
LADEF V4f v4f_sin(V4f a);
LADEF V4f v4f_cos(V4f a);
LADEF V4f v4f_min(V4f a, V4f b);
LADEF V4f v4f_max(V4f a, V4f b);
LADEF V4f v4f_lerp(V4f a, V4f b, V4f t);
LADEF V4f v4f_floor(V4f a);
LADEF V4f v4f_ceil(V4f a);
LADEF V4f v4f_clamp(V4f x, V4f a, V4f b);
LADEF float v4f_sqrlen(V4f a);
LADEF float v4f_len(V4f a);
LADEF float v4f_dot(V4f a, V4f b);
LADEF V4f v4f_norm(V4f a, float eps, V4f fallback);
LADEF bool v4f_eq(V4f a, V4f b, float eps);
LADEF V4f v4f_reflect(V4f i, V4f n);
LADEF M4f m4f_id(void);
LADEF M4f m4f_zero(void);
LADEF M4f m4f_mul(M4f a, M4f b);
LADEF V4f m4f_mul_vec(M4f m, V4f v);
LADEF M4f m4f_rot_x(float angle);
LADEF M4f m4f_rot_y(float angle);
LADEF M4f m4f_rot_z(float angle);

#define V4d_Fmt "v4d(%lf, %lf, %lf, %lf)"
#define V4d_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4d v4d(double x, double y, double z, double w);
LADEF V4d v4dd(double x);

LADEF V4d v2f_4d(V2f a);
LA_DEPRECATED("Use v2f_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d2f(V2f a);
LADEF V4d v2d_4d(V2d a);
LA_DEPRECATED("Use v2d_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d2d(V2d a);
LADEF V4d v2i_4d(V2i a);
LA_DEPRECATED("Use v2i_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d2i(V2i a);
LADEF V4d v2u_4d(V2u a);
LA_DEPRECATED("Use v2u_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d2u(V2u a);
LADEF V4d v3f_4d(V3f a);
LA_DEPRECATED("Use v3f_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d3f(V3f a);
LADEF V4d v3d_4d(V3d a);
LA_DEPRECATED("Use v3d_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d3d(V3d a);
LADEF V4d v3i_4d(V3i a);
LA_DEPRECATED("Use v3i_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d3i(V3i a);
LADEF V4d v3u_4d(V3u a);
LA_DEPRECATED("Use v3u_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d3u(V3u a);
LADEF V4d v4f_4d(V4f a);
LA_DEPRECATED("Use v4f_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d4f(V4f a);
LADEF V4d v4i_4d(V4i a);
LA_DEPRECATED("Use v4i_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d4i(V4i a);
LADEF V4d v4u_4d(V4u a);
LA_DEPRECATED("Use v4u_4d instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4d v4d4u(V4u a);

LADEF V4d v4d_sum(V4d a, V4d b);
LADEF V4d v4d_add(V4d a, V4d b);
LADEF V4d v4d_sub(V4d a, V4d b);
LADEF V4d v4d_mul(V4d a, V4d b);
LADEF V4d v4d_div(V4d a, V4d b);
LADEF V4d v4d_mod(V4d a, V4d b);
LADEF V4d v4d_sqrt(V4d a);
LADEF V4d v4d_pow(V4d base, V4d exp);
LADEF V4d v4d_sin(V4d a);
LADEF V4d v4d_cos(V4d a);
LADEF V4d v4d_min(V4d a, V4d b);
LADEF V4d v4d_max(V4d a, V4d b);
LADEF V4d v4d_lerp(V4d a, V4d b, V4d t);
LADEF V4d v4d_floor(V4d a);
LADEF V4d v4d_ceil(V4d a);
LADEF V4d v4d_clamp(V4d x, V4d a, V4d b);
LADEF double v4d_sqrlen(V4d a);
LADEF double v4d_len(V4d a);
LADEF double v4d_dot(V4d a, V4d b);
LADEF V4d v4d_norm(V4d a, double eps, V4d fallback);
LADEF bool v4d_eq(V4d a, V4d b, double eps);
LADEF V4d v4d_reflect(V4d i, V4d n);
LADEF M4d m4d_id(void);
LADEF M4d m4d_zero(void);
LADEF M4d m4d_mul(M4d a, M4d b);
LADEF V4d m4d_mul_vec(M4d m, V4d v);
LADEF M4d m4d_rot_x(double angle);
LADEF M4d m4d_rot_y(double angle);
LADEF M4d m4d_rot_z(double angle);

#define V4i_Fmt "v4i(%d, %d, %d, %d)"
#define V4i_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4i v4i(int x, int y, int z, int w);
LADEF V4i v4ii(int x);

LADEF V4i v2f_4i(V2f a);
LA_DEPRECATED("Use v2f_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i2f(V2f a);
LADEF V4i v2d_4i(V2d a);
LA_DEPRECATED("Use v2d_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i2d(V2d a);
LADEF V4i v2i_4i(V2i a);
LA_DEPRECATED("Use v2i_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i2i(V2i a);
LADEF V4i v2u_4i(V2u a);
LA_DEPRECATED("Use v2u_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i2u(V2u a);
LADEF V4i v3f_4i(V3f a);
LA_DEPRECATED("Use v3f_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i3f(V3f a);
LADEF V4i v3d_4i(V3d a);
LA_DEPRECATED("Use v3d_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i3d(V3d a);
LADEF V4i v3i_4i(V3i a);
LA_DEPRECATED("Use v3i_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i3i(V3i a);
LADEF V4i v3u_4i(V3u a);
LA_DEPRECATED("Use v3u_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i3u(V3u a);
LADEF V4i v4f_4i(V4f a);
LA_DEPRECATED("Use v4f_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i4f(V4f a);
LADEF V4i v4d_4i(V4d a);
LA_DEPRECATED("Use v4d_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i4d(V4d a);
LADEF V4i v4u_4i(V4u a);
LA_DEPRECATED("Use v4u_4i instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4i v4i4u(V4u a);

LADEF V4i v4i_sum(V4i a, V4i b);
LADEF V4i v4i_add(V4i a, V4i b);
LADEF V4i v4i_sub(V4i a, V4i b);
LADEF V4i v4i_mul(V4i a, V4i b);
LADEF V4i v4i_div(V4i a, V4i b);
LADEF V4i v4i_mod(V4i a, V4i b);
LADEF V4i v4i_min(V4i a, V4i b);
LADEF V4i v4i_max(V4i a, V4i b);
LADEF V4i v4i_clamp(V4i x, V4i a, V4i b);
LADEF int v4i_sqrlen(V4i a);
LADEF int v4i_dot(V4i a, V4i b);
LADEF bool v4i_eq(V4i a, V4i b);
LADEF V4i v4i_reflect(V4i i, V4i n);
LADEF M4i m4i_id(void);
LADEF M4i m4i_zero(void);
LADEF M4i m4i_mul(M4i a, M4i b);
LADEF V4i m4i_mul_vec(M4i m, V4i v);

#define V4u_Fmt "v4u(%u, %u, %u, %u)"
#define V4u_Arg(v) (v).x, (v).y, (v).z, (v).w
LADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w);
LADEF V4u v4uu(unsigned int x);

LADEF V4u v2f_4u(V2f a);
LA_DEPRECATED("Use v2f_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u2f(V2f a);
LADEF V4u v2d_4u(V2d a);
LA_DEPRECATED("Use v2d_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u2d(V2d a);
LADEF V4u v2i_4u(V2i a);
LA_DEPRECATED("Use v2i_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u2i(V2i a);
LADEF V4u v2u_4u(V2u a);
LA_DEPRECATED("Use v2u_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u2u(V2u a);
LADEF V4u v3f_4u(V3f a);
LA_DEPRECATED("Use v3f_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u3f(V3f a);
LADEF V4u v3d_4u(V3d a);
LA_DEPRECATED("Use v3d_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u3d(V3d a);
LADEF V4u v3i_4u(V3i a);
LA_DEPRECATED("Use v3i_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u3i(V3i a);
LADEF V4u v3u_4u(V3u a);
LA_DEPRECATED("Use v3u_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u3u(V3u a);
LADEF V4u v4f_4u(V4f a);
LA_DEPRECATED("Use v4f_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u4f(V4f a);
LADEF V4u v4d_4u(V4d a);
LA_DEPRECATED("Use v4d_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u4d(V4d a);
LADEF V4u v4i_4u(V4i a);
LA_DEPRECATED("Use v4i_4u instead to maintain consistent naming convention where the prefix encodes the type of the first argument.")
LADEF V4u v4u4i(V4i a);

LADEF V4u v4u_sum(V4u a, V4u b);
LADEF V4u v4u_add(V4u a, V4u b);
LADEF V4u v4u_sub(V4u a, V4u b);
LADEF V4u v4u_mul(V4u a, V4u b);
LADEF V4u v4u_div(V4u a, V4u b);
LADEF V4u v4u_mod(V4u a, V4u b);
LADEF V4u v4u_min(V4u a, V4u b);
LADEF V4u v4u_max(V4u a, V4u b);
LADEF V4u v4u_clamp(V4u x, V4u a, V4u b);
LADEF unsigned int v4u_sqrlen(V4u a);
LADEF unsigned int v4u_dot(V4u a, V4u b);
LADEF bool v4u_eq(V4u a, V4u b);
LADEF V4u v4u_reflect(V4u i, V4u n);
LADEF M4u m4u_id(void);
LADEF M4u m4u_zero(void);
LADEF M4u m4u_mul(M4u a, M4u b);
LADEF V4u m4u_mul_vec(M4u m, V4u v);

LADEF V2f v2f_xx(V2f v);
LADEF V2f v2f_yx(V2f v);
LADEF V2f v2f_xy(V2f v);
LADEF V2f v2f_yy(V2f v);
LADEF V2f v3f_xx(V3f v);
LADEF V2f v3f_yx(V3f v);
LADEF V2f v3f_zx(V3f v);
LADEF V2f v3f_xy(V3f v);
LADEF V2f v3f_yy(V3f v);
LADEF V2f v3f_zy(V3f v);
LADEF V2f v3f_xz(V3f v);
LADEF V2f v3f_yz(V3f v);
LADEF V2f v3f_zz(V3f v);
LADEF V2f v4f_xx(V4f v);
LADEF V2f v4f_yx(V4f v);
LADEF V2f v4f_zx(V4f v);
LADEF V2f v4f_wx(V4f v);
LADEF V2f v4f_xy(V4f v);
LADEF V2f v4f_yy(V4f v);
LADEF V2f v4f_zy(V4f v);
LADEF V2f v4f_wy(V4f v);
LADEF V2f v4f_xz(V4f v);
LADEF V2f v4f_yz(V4f v);
LADEF V2f v4f_zz(V4f v);
LADEF V2f v4f_wz(V4f v);
LADEF V2f v4f_xw(V4f v);
LADEF V2f v4f_yw(V4f v);
LADEF V2f v4f_zw(V4f v);
LADEF V2f v4f_ww(V4f v);

LADEF V3f v2f_xxx(V2f v);
LADEF V3f v2f_yxx(V2f v);
LADEF V3f v2f_xyx(V2f v);
LADEF V3f v2f_yyx(V2f v);
LADEF V3f v2f_xxy(V2f v);
LADEF V3f v2f_yxy(V2f v);
LADEF V3f v2f_xyy(V2f v);
LADEF V3f v2f_yyy(V2f v);
LADEF V3f v3f_xxx(V3f v);
LADEF V3f v3f_yxx(V3f v);
LADEF V3f v3f_zxx(V3f v);
LADEF V3f v3f_xyx(V3f v);
LADEF V3f v3f_yyx(V3f v);
LADEF V3f v3f_zyx(V3f v);
LADEF V3f v3f_xzx(V3f v);
LADEF V3f v3f_yzx(V3f v);
LADEF V3f v3f_zzx(V3f v);
LADEF V3f v3f_xxy(V3f v);
LADEF V3f v3f_yxy(V3f v);
LADEF V3f v3f_zxy(V3f v);
LADEF V3f v3f_xyy(V3f v);
LADEF V3f v3f_yyy(V3f v);
LADEF V3f v3f_zyy(V3f v);
LADEF V3f v3f_xzy(V3f v);
LADEF V3f v3f_yzy(V3f v);
LADEF V3f v3f_zzy(V3f v);
LADEF V3f v3f_xxz(V3f v);
LADEF V3f v3f_yxz(V3f v);
LADEF V3f v3f_zxz(V3f v);
LADEF V3f v3f_xyz(V3f v);
LADEF V3f v3f_yyz(V3f v);
LADEF V3f v3f_zyz(V3f v);
LADEF V3f v3f_xzz(V3f v);
LADEF V3f v3f_yzz(V3f v);
LADEF V3f v3f_zzz(V3f v);
LADEF V3f v4f_xxx(V4f v);
LADEF V3f v4f_yxx(V4f v);
LADEF V3f v4f_zxx(V4f v);
LADEF V3f v4f_wxx(V4f v);
LADEF V3f v4f_xyx(V4f v);
LADEF V3f v4f_yyx(V4f v);
LADEF V3f v4f_zyx(V4f v);
LADEF V3f v4f_wyx(V4f v);
LADEF V3f v4f_xzx(V4f v);
LADEF V3f v4f_yzx(V4f v);
LADEF V3f v4f_zzx(V4f v);
LADEF V3f v4f_wzx(V4f v);
LADEF V3f v4f_xwx(V4f v);
LADEF V3f v4f_ywx(V4f v);
LADEF V3f v4f_zwx(V4f v);
LADEF V3f v4f_wwx(V4f v);
LADEF V3f v4f_xxy(V4f v);
LADEF V3f v4f_yxy(V4f v);
LADEF V3f v4f_zxy(V4f v);
LADEF V3f v4f_wxy(V4f v);
LADEF V3f v4f_xyy(V4f v);
LADEF V3f v4f_yyy(V4f v);
LADEF V3f v4f_zyy(V4f v);
LADEF V3f v4f_wyy(V4f v);
LADEF V3f v4f_xzy(V4f v);
LADEF V3f v4f_yzy(V4f v);
LADEF V3f v4f_zzy(V4f v);
LADEF V3f v4f_wzy(V4f v);
LADEF V3f v4f_xwy(V4f v);
LADEF V3f v4f_ywy(V4f v);
LADEF V3f v4f_zwy(V4f v);
LADEF V3f v4f_wwy(V4f v);
LADEF V3f v4f_xxz(V4f v);
LADEF V3f v4f_yxz(V4f v);
LADEF V3f v4f_zxz(V4f v);
LADEF V3f v4f_wxz(V4f v);
LADEF V3f v4f_xyz(V4f v);
LADEF V3f v4f_yyz(V4f v);
LADEF V3f v4f_zyz(V4f v);
LADEF V3f v4f_wyz(V4f v);
LADEF V3f v4f_xzz(V4f v);
LADEF V3f v4f_yzz(V4f v);
LADEF V3f v4f_zzz(V4f v);
LADEF V3f v4f_wzz(V4f v);
LADEF V3f v4f_xwz(V4f v);
LADEF V3f v4f_ywz(V4f v);
LADEF V3f v4f_zwz(V4f v);
LADEF V3f v4f_wwz(V4f v);
LADEF V3f v4f_xxw(V4f v);
LADEF V3f v4f_yxw(V4f v);
LADEF V3f v4f_zxw(V4f v);
LADEF V3f v4f_wxw(V4f v);
LADEF V3f v4f_xyw(V4f v);
LADEF V3f v4f_yyw(V4f v);
LADEF V3f v4f_zyw(V4f v);
LADEF V3f v4f_wyw(V4f v);
LADEF V3f v4f_xzw(V4f v);
LADEF V3f v4f_yzw(V4f v);
LADEF V3f v4f_zzw(V4f v);
LADEF V3f v4f_wzw(V4f v);
LADEF V3f v4f_xww(V4f v);
LADEF V3f v4f_yww(V4f v);
LADEF V3f v4f_zww(V4f v);
LADEF V3f v4f_www(V4f v);

LADEF V4f v2f_xxxx(V2f v);
LADEF V4f v2f_yxxx(V2f v);
LADEF V4f v2f_xyxx(V2f v);
LADEF V4f v2f_yyxx(V2f v);
LADEF V4f v2f_xxyx(V2f v);
LADEF V4f v2f_yxyx(V2f v);
LADEF V4f v2f_xyyx(V2f v);
LADEF V4f v2f_yyyx(V2f v);
LADEF V4f v2f_xxxy(V2f v);
LADEF V4f v2f_yxxy(V2f v);
LADEF V4f v2f_xyxy(V2f v);
LADEF V4f v2f_yyxy(V2f v);
LADEF V4f v2f_xxyy(V2f v);
LADEF V4f v2f_yxyy(V2f v);
LADEF V4f v2f_xyyy(V2f v);
LADEF V4f v2f_yyyy(V2f v);
LADEF V4f v3f_xxxx(V3f v);
LADEF V4f v3f_yxxx(V3f v);
LADEF V4f v3f_zxxx(V3f v);
LADEF V4f v3f_xyxx(V3f v);
LADEF V4f v3f_yyxx(V3f v);
LADEF V4f v3f_zyxx(V3f v);
LADEF V4f v3f_xzxx(V3f v);
LADEF V4f v3f_yzxx(V3f v);
LADEF V4f v3f_zzxx(V3f v);
LADEF V4f v3f_xxyx(V3f v);
LADEF V4f v3f_yxyx(V3f v);
LADEF V4f v3f_zxyx(V3f v);
LADEF V4f v3f_xyyx(V3f v);
LADEF V4f v3f_yyyx(V3f v);
LADEF V4f v3f_zyyx(V3f v);
LADEF V4f v3f_xzyx(V3f v);
LADEF V4f v3f_yzyx(V3f v);
LADEF V4f v3f_zzyx(V3f v);
LADEF V4f v3f_xxzx(V3f v);
LADEF V4f v3f_yxzx(V3f v);
LADEF V4f v3f_zxzx(V3f v);
LADEF V4f v3f_xyzx(V3f v);
LADEF V4f v3f_yyzx(V3f v);
LADEF V4f v3f_zyzx(V3f v);
LADEF V4f v3f_xzzx(V3f v);
LADEF V4f v3f_yzzx(V3f v);
LADEF V4f v3f_zzzx(V3f v);
LADEF V4f v3f_xxxy(V3f v);
LADEF V4f v3f_yxxy(V3f v);
LADEF V4f v3f_zxxy(V3f v);
LADEF V4f v3f_xyxy(V3f v);
LADEF V4f v3f_yyxy(V3f v);
LADEF V4f v3f_zyxy(V3f v);
LADEF V4f v3f_xzxy(V3f v);
LADEF V4f v3f_yzxy(V3f v);
LADEF V4f v3f_zzxy(V3f v);
LADEF V4f v3f_xxyy(V3f v);
LADEF V4f v3f_yxyy(V3f v);
LADEF V4f v3f_zxyy(V3f v);
LADEF V4f v3f_xyyy(V3f v);
LADEF V4f v3f_yyyy(V3f v);
LADEF V4f v3f_zyyy(V3f v);
LADEF V4f v3f_xzyy(V3f v);
LADEF V4f v3f_yzyy(V3f v);
LADEF V4f v3f_zzyy(V3f v);
LADEF V4f v3f_xxzy(V3f v);
LADEF V4f v3f_yxzy(V3f v);
LADEF V4f v3f_zxzy(V3f v);
LADEF V4f v3f_xyzy(V3f v);
LADEF V4f v3f_yyzy(V3f v);
LADEF V4f v3f_zyzy(V3f v);
LADEF V4f v3f_xzzy(V3f v);
LADEF V4f v3f_yzzy(V3f v);
LADEF V4f v3f_zzzy(V3f v);
LADEF V4f v3f_xxxz(V3f v);
LADEF V4f v3f_yxxz(V3f v);
LADEF V4f v3f_zxxz(V3f v);
LADEF V4f v3f_xyxz(V3f v);
LADEF V4f v3f_yyxz(V3f v);
LADEF V4f v3f_zyxz(V3f v);
LADEF V4f v3f_xzxz(V3f v);
LADEF V4f v3f_yzxz(V3f v);
LADEF V4f v3f_zzxz(V3f v);
LADEF V4f v3f_xxyz(V3f v);
LADEF V4f v3f_yxyz(V3f v);
LADEF V4f v3f_zxyz(V3f v);
LADEF V4f v3f_xyyz(V3f v);
LADEF V4f v3f_yyyz(V3f v);
LADEF V4f v3f_zyyz(V3f v);
LADEF V4f v3f_xzyz(V3f v);
LADEF V4f v3f_yzyz(V3f v);
LADEF V4f v3f_zzyz(V3f v);
LADEF V4f v3f_xxzz(V3f v);
LADEF V4f v3f_yxzz(V3f v);
LADEF V4f v3f_zxzz(V3f v);
LADEF V4f v3f_xyzz(V3f v);
LADEF V4f v3f_yyzz(V3f v);
LADEF V4f v3f_zyzz(V3f v);
LADEF V4f v3f_xzzz(V3f v);
LADEF V4f v3f_yzzz(V3f v);
LADEF V4f v3f_zzzz(V3f v);
LADEF V4f v4f_xxxx(V4f v);
LADEF V4f v4f_yxxx(V4f v);
LADEF V4f v4f_zxxx(V4f v);
LADEF V4f v4f_wxxx(V4f v);
LADEF V4f v4f_xyxx(V4f v);
LADEF V4f v4f_yyxx(V4f v);
LADEF V4f v4f_zyxx(V4f v);
LADEF V4f v4f_wyxx(V4f v);
LADEF V4f v4f_xzxx(V4f v);
LADEF V4f v4f_yzxx(V4f v);
LADEF V4f v4f_zzxx(V4f v);
LADEF V4f v4f_wzxx(V4f v);
LADEF V4f v4f_xwxx(V4f v);
LADEF V4f v4f_ywxx(V4f v);
LADEF V4f v4f_zwxx(V4f v);
LADEF V4f v4f_wwxx(V4f v);
LADEF V4f v4f_xxyx(V4f v);
LADEF V4f v4f_yxyx(V4f v);
LADEF V4f v4f_zxyx(V4f v);
LADEF V4f v4f_wxyx(V4f v);
LADEF V4f v4f_xyyx(V4f v);
LADEF V4f v4f_yyyx(V4f v);
LADEF V4f v4f_zyyx(V4f v);
LADEF V4f v4f_wyyx(V4f v);
LADEF V4f v4f_xzyx(V4f v);
LADEF V4f v4f_yzyx(V4f v);
LADEF V4f v4f_zzyx(V4f v);
LADEF V4f v4f_wzyx(V4f v);
LADEF V4f v4f_xwyx(V4f v);
LADEF V4f v4f_ywyx(V4f v);
LADEF V4f v4f_zwyx(V4f v);
LADEF V4f v4f_wwyx(V4f v);
LADEF V4f v4f_xxzx(V4f v);
LADEF V4f v4f_yxzx(V4f v);
LADEF V4f v4f_zxzx(V4f v);
LADEF V4f v4f_wxzx(V4f v);
LADEF V4f v4f_xyzx(V4f v);
LADEF V4f v4f_yyzx(V4f v);
LADEF V4f v4f_zyzx(V4f v);
LADEF V4f v4f_wyzx(V4f v);
LADEF V4f v4f_xzzx(V4f v);
LADEF V4f v4f_yzzx(V4f v);
LADEF V4f v4f_zzzx(V4f v);
LADEF V4f v4f_wzzx(V4f v);
LADEF V4f v4f_xwzx(V4f v);
LADEF V4f v4f_ywzx(V4f v);
LADEF V4f v4f_zwzx(V4f v);
LADEF V4f v4f_wwzx(V4f v);
LADEF V4f v4f_xxwx(V4f v);
LADEF V4f v4f_yxwx(V4f v);
LADEF V4f v4f_zxwx(V4f v);
LADEF V4f v4f_wxwx(V4f v);
LADEF V4f v4f_xywx(V4f v);
LADEF V4f v4f_yywx(V4f v);
LADEF V4f v4f_zywx(V4f v);
LADEF V4f v4f_wywx(V4f v);
LADEF V4f v4f_xzwx(V4f v);
LADEF V4f v4f_yzwx(V4f v);
LADEF V4f v4f_zzwx(V4f v);
LADEF V4f v4f_wzwx(V4f v);
LADEF V4f v4f_xwwx(V4f v);
LADEF V4f v4f_ywwx(V4f v);
LADEF V4f v4f_zwwx(V4f v);
LADEF V4f v4f_wwwx(V4f v);
LADEF V4f v4f_xxxy(V4f v);
LADEF V4f v4f_yxxy(V4f v);
LADEF V4f v4f_zxxy(V4f v);
LADEF V4f v4f_wxxy(V4f v);
LADEF V4f v4f_xyxy(V4f v);
LADEF V4f v4f_yyxy(V4f v);
LADEF V4f v4f_zyxy(V4f v);
LADEF V4f v4f_wyxy(V4f v);
LADEF V4f v4f_xzxy(V4f v);
LADEF V4f v4f_yzxy(V4f v);
LADEF V4f v4f_zzxy(V4f v);
LADEF V4f v4f_wzxy(V4f v);
LADEF V4f v4f_xwxy(V4f v);
LADEF V4f v4f_ywxy(V4f v);
LADEF V4f v4f_zwxy(V4f v);
LADEF V4f v4f_wwxy(V4f v);
LADEF V4f v4f_xxyy(V4f v);
LADEF V4f v4f_yxyy(V4f v);
LADEF V4f v4f_zxyy(V4f v);
LADEF V4f v4f_wxyy(V4f v);
LADEF V4f v4f_xyyy(V4f v);
LADEF V4f v4f_yyyy(V4f v);
LADEF V4f v4f_zyyy(V4f v);
LADEF V4f v4f_wyyy(V4f v);
LADEF V4f v4f_xzyy(V4f v);
LADEF V4f v4f_yzyy(V4f v);
LADEF V4f v4f_zzyy(V4f v);
LADEF V4f v4f_wzyy(V4f v);
LADEF V4f v4f_xwyy(V4f v);
LADEF V4f v4f_ywyy(V4f v);
LADEF V4f v4f_zwyy(V4f v);
LADEF V4f v4f_wwyy(V4f v);
LADEF V4f v4f_xxzy(V4f v);
LADEF V4f v4f_yxzy(V4f v);
LADEF V4f v4f_zxzy(V4f v);
LADEF V4f v4f_wxzy(V4f v);
LADEF V4f v4f_xyzy(V4f v);
LADEF V4f v4f_yyzy(V4f v);
LADEF V4f v4f_zyzy(V4f v);
LADEF V4f v4f_wyzy(V4f v);
LADEF V4f v4f_xzzy(V4f v);
LADEF V4f v4f_yzzy(V4f v);
LADEF V4f v4f_zzzy(V4f v);
LADEF V4f v4f_wzzy(V4f v);
LADEF V4f v4f_xwzy(V4f v);
LADEF V4f v4f_ywzy(V4f v);
LADEF V4f v4f_zwzy(V4f v);
LADEF V4f v4f_wwzy(V4f v);
LADEF V4f v4f_xxwy(V4f v);
LADEF V4f v4f_yxwy(V4f v);
LADEF V4f v4f_zxwy(V4f v);
LADEF V4f v4f_wxwy(V4f v);
LADEF V4f v4f_xywy(V4f v);
LADEF V4f v4f_yywy(V4f v);
LADEF V4f v4f_zywy(V4f v);
LADEF V4f v4f_wywy(V4f v);
LADEF V4f v4f_xzwy(V4f v);
LADEF V4f v4f_yzwy(V4f v);
LADEF V4f v4f_zzwy(V4f v);
LADEF V4f v4f_wzwy(V4f v);
LADEF V4f v4f_xwwy(V4f v);
LADEF V4f v4f_ywwy(V4f v);
LADEF V4f v4f_zwwy(V4f v);
LADEF V4f v4f_wwwy(V4f v);
LADEF V4f v4f_xxxz(V4f v);
LADEF V4f v4f_yxxz(V4f v);
LADEF V4f v4f_zxxz(V4f v);
LADEF V4f v4f_wxxz(V4f v);
LADEF V4f v4f_xyxz(V4f v);
LADEF V4f v4f_yyxz(V4f v);
LADEF V4f v4f_zyxz(V4f v);
LADEF V4f v4f_wyxz(V4f v);
LADEF V4f v4f_xzxz(V4f v);
LADEF V4f v4f_yzxz(V4f v);
LADEF V4f v4f_zzxz(V4f v);
LADEF V4f v4f_wzxz(V4f v);
LADEF V4f v4f_xwxz(V4f v);
LADEF V4f v4f_ywxz(V4f v);
LADEF V4f v4f_zwxz(V4f v);
LADEF V4f v4f_wwxz(V4f v);
LADEF V4f v4f_xxyz(V4f v);
LADEF V4f v4f_yxyz(V4f v);
LADEF V4f v4f_zxyz(V4f v);
LADEF V4f v4f_wxyz(V4f v);
LADEF V4f v4f_xyyz(V4f v);
LADEF V4f v4f_yyyz(V4f v);
LADEF V4f v4f_zyyz(V4f v);
LADEF V4f v4f_wyyz(V4f v);
LADEF V4f v4f_xzyz(V4f v);
LADEF V4f v4f_yzyz(V4f v);
LADEF V4f v4f_zzyz(V4f v);
LADEF V4f v4f_wzyz(V4f v);
LADEF V4f v4f_xwyz(V4f v);
LADEF V4f v4f_ywyz(V4f v);
LADEF V4f v4f_zwyz(V4f v);
LADEF V4f v4f_wwyz(V4f v);
LADEF V4f v4f_xxzz(V4f v);
LADEF V4f v4f_yxzz(V4f v);
LADEF V4f v4f_zxzz(V4f v);
LADEF V4f v4f_wxzz(V4f v);
LADEF V4f v4f_xyzz(V4f v);
LADEF V4f v4f_yyzz(V4f v);
LADEF V4f v4f_zyzz(V4f v);
LADEF V4f v4f_wyzz(V4f v);
LADEF V4f v4f_xzzz(V4f v);
LADEF V4f v4f_yzzz(V4f v);
LADEF V4f v4f_zzzz(V4f v);
LADEF V4f v4f_wzzz(V4f v);
LADEF V4f v4f_xwzz(V4f v);
LADEF V4f v4f_ywzz(V4f v);
LADEF V4f v4f_zwzz(V4f v);
LADEF V4f v4f_wwzz(V4f v);
LADEF V4f v4f_xxwz(V4f v);
LADEF V4f v4f_yxwz(V4f v);
LADEF V4f v4f_zxwz(V4f v);
LADEF V4f v4f_wxwz(V4f v);
LADEF V4f v4f_xywz(V4f v);
LADEF V4f v4f_yywz(V4f v);
LADEF V4f v4f_zywz(V4f v);
LADEF V4f v4f_wywz(V4f v);
LADEF V4f v4f_xzwz(V4f v);
LADEF V4f v4f_yzwz(V4f v);
LADEF V4f v4f_zzwz(V4f v);
LADEF V4f v4f_wzwz(V4f v);
LADEF V4f v4f_xwwz(V4f v);
LADEF V4f v4f_ywwz(V4f v);
LADEF V4f v4f_zwwz(V4f v);
LADEF V4f v4f_wwwz(V4f v);
LADEF V4f v4f_xxxw(V4f v);
LADEF V4f v4f_yxxw(V4f v);
LADEF V4f v4f_zxxw(V4f v);
LADEF V4f v4f_wxxw(V4f v);
LADEF V4f v4f_xyxw(V4f v);
LADEF V4f v4f_yyxw(V4f v);
LADEF V4f v4f_zyxw(V4f v);
LADEF V4f v4f_wyxw(V4f v);
LADEF V4f v4f_xzxw(V4f v);
LADEF V4f v4f_yzxw(V4f v);
LADEF V4f v4f_zzxw(V4f v);
LADEF V4f v4f_wzxw(V4f v);
LADEF V4f v4f_xwxw(V4f v);
LADEF V4f v4f_ywxw(V4f v);
LADEF V4f v4f_zwxw(V4f v);
LADEF V4f v4f_wwxw(V4f v);
LADEF V4f v4f_xxyw(V4f v);
LADEF V4f v4f_yxyw(V4f v);
LADEF V4f v4f_zxyw(V4f v);
LADEF V4f v4f_wxyw(V4f v);
LADEF V4f v4f_xyyw(V4f v);
LADEF V4f v4f_yyyw(V4f v);
LADEF V4f v4f_zyyw(V4f v);
LADEF V4f v4f_wyyw(V4f v);
LADEF V4f v4f_xzyw(V4f v);
LADEF V4f v4f_yzyw(V4f v);
LADEF V4f v4f_zzyw(V4f v);
LADEF V4f v4f_wzyw(V4f v);
LADEF V4f v4f_xwyw(V4f v);
LADEF V4f v4f_ywyw(V4f v);
LADEF V4f v4f_zwyw(V4f v);
LADEF V4f v4f_wwyw(V4f v);
LADEF V4f v4f_xxzw(V4f v);
LADEF V4f v4f_yxzw(V4f v);
LADEF V4f v4f_zxzw(V4f v);
LADEF V4f v4f_wxzw(V4f v);
LADEF V4f v4f_xyzw(V4f v);
LADEF V4f v4f_yyzw(V4f v);
LADEF V4f v4f_zyzw(V4f v);
LADEF V4f v4f_wyzw(V4f v);
LADEF V4f v4f_xzzw(V4f v);
LADEF V4f v4f_yzzw(V4f v);
LADEF V4f v4f_zzzw(V4f v);
LADEF V4f v4f_wzzw(V4f v);
LADEF V4f v4f_xwzw(V4f v);
LADEF V4f v4f_ywzw(V4f v);
LADEF V4f v4f_zwzw(V4f v);
LADEF V4f v4f_wwzw(V4f v);
LADEF V4f v4f_xxww(V4f v);
LADEF V4f v4f_yxww(V4f v);
LADEF V4f v4f_zxww(V4f v);
LADEF V4f v4f_wxww(V4f v);
LADEF V4f v4f_xyww(V4f v);
LADEF V4f v4f_yyww(V4f v);
LADEF V4f v4f_zyww(V4f v);
LADEF V4f v4f_wyww(V4f v);
LADEF V4f v4f_xzww(V4f v);
LADEF V4f v4f_yzww(V4f v);
LADEF V4f v4f_zzww(V4f v);
LADEF V4f v4f_wzww(V4f v);
LADEF V4f v4f_xwww(V4f v);
LADEF V4f v4f_ywww(V4f v);
LADEF V4f v4f_zwww(V4f v);
LADEF V4f v4f_wwww(V4f v);

LADEF V2d v2d_xx(V2d v);
LADEF V2d v2d_yx(V2d v);
LADEF V2d v2d_xy(V2d v);
LADEF V2d v2d_yy(V2d v);
LADEF V2d v3d_xx(V3d v);
LADEF V2d v3d_yx(V3d v);
LADEF V2d v3d_zx(V3d v);
LADEF V2d v3d_xy(V3d v);
LADEF V2d v3d_yy(V3d v);
LADEF V2d v3d_zy(V3d v);
LADEF V2d v3d_xz(V3d v);
LADEF V2d v3d_yz(V3d v);
LADEF V2d v3d_zz(V3d v);
LADEF V2d v4d_xx(V4d v);
LADEF V2d v4d_yx(V4d v);
LADEF V2d v4d_zx(V4d v);
LADEF V2d v4d_wx(V4d v);
LADEF V2d v4d_xy(V4d v);
LADEF V2d v4d_yy(V4d v);
LADEF V2d v4d_zy(V4d v);
LADEF V2d v4d_wy(V4d v);
LADEF V2d v4d_xz(V4d v);
LADEF V2d v4d_yz(V4d v);
LADEF V2d v4d_zz(V4d v);
LADEF V2d v4d_wz(V4d v);
LADEF V2d v4d_xw(V4d v);
LADEF V2d v4d_yw(V4d v);
LADEF V2d v4d_zw(V4d v);
LADEF V2d v4d_ww(V4d v);

LADEF V3d v2d_xxx(V2d v);
LADEF V3d v2d_yxx(V2d v);
LADEF V3d v2d_xyx(V2d v);
LADEF V3d v2d_yyx(V2d v);
LADEF V3d v2d_xxy(V2d v);
LADEF V3d v2d_yxy(V2d v);
LADEF V3d v2d_xyy(V2d v);
LADEF V3d v2d_yyy(V2d v);
LADEF V3d v3d_xxx(V3d v);
LADEF V3d v3d_yxx(V3d v);
LADEF V3d v3d_zxx(V3d v);
LADEF V3d v3d_xyx(V3d v);
LADEF V3d v3d_yyx(V3d v);
LADEF V3d v3d_zyx(V3d v);
LADEF V3d v3d_xzx(V3d v);
LADEF V3d v3d_yzx(V3d v);
LADEF V3d v3d_zzx(V3d v);
LADEF V3d v3d_xxy(V3d v);
LADEF V3d v3d_yxy(V3d v);
LADEF V3d v3d_zxy(V3d v);
LADEF V3d v3d_xyy(V3d v);
LADEF V3d v3d_yyy(V3d v);
LADEF V3d v3d_zyy(V3d v);
LADEF V3d v3d_xzy(V3d v);
LADEF V3d v3d_yzy(V3d v);
LADEF V3d v3d_zzy(V3d v);
LADEF V3d v3d_xxz(V3d v);
LADEF V3d v3d_yxz(V3d v);
LADEF V3d v3d_zxz(V3d v);
LADEF V3d v3d_xyz(V3d v);
LADEF V3d v3d_yyz(V3d v);
LADEF V3d v3d_zyz(V3d v);
LADEF V3d v3d_xzz(V3d v);
LADEF V3d v3d_yzz(V3d v);
LADEF V3d v3d_zzz(V3d v);
LADEF V3d v4d_xxx(V4d v);
LADEF V3d v4d_yxx(V4d v);
LADEF V3d v4d_zxx(V4d v);
LADEF V3d v4d_wxx(V4d v);
LADEF V3d v4d_xyx(V4d v);
LADEF V3d v4d_yyx(V4d v);
LADEF V3d v4d_zyx(V4d v);
LADEF V3d v4d_wyx(V4d v);
LADEF V3d v4d_xzx(V4d v);
LADEF V3d v4d_yzx(V4d v);
LADEF V3d v4d_zzx(V4d v);
LADEF V3d v4d_wzx(V4d v);
LADEF V3d v4d_xwx(V4d v);
LADEF V3d v4d_ywx(V4d v);
LADEF V3d v4d_zwx(V4d v);
LADEF V3d v4d_wwx(V4d v);
LADEF V3d v4d_xxy(V4d v);
LADEF V3d v4d_yxy(V4d v);
LADEF V3d v4d_zxy(V4d v);
LADEF V3d v4d_wxy(V4d v);
LADEF V3d v4d_xyy(V4d v);
LADEF V3d v4d_yyy(V4d v);
LADEF V3d v4d_zyy(V4d v);
LADEF V3d v4d_wyy(V4d v);
LADEF V3d v4d_xzy(V4d v);
LADEF V3d v4d_yzy(V4d v);
LADEF V3d v4d_zzy(V4d v);
LADEF V3d v4d_wzy(V4d v);
LADEF V3d v4d_xwy(V4d v);
LADEF V3d v4d_ywy(V4d v);
LADEF V3d v4d_zwy(V4d v);
LADEF V3d v4d_wwy(V4d v);
LADEF V3d v4d_xxz(V4d v);
LADEF V3d v4d_yxz(V4d v);
LADEF V3d v4d_zxz(V4d v);
LADEF V3d v4d_wxz(V4d v);
LADEF V3d v4d_xyz(V4d v);
LADEF V3d v4d_yyz(V4d v);
LADEF V3d v4d_zyz(V4d v);
LADEF V3d v4d_wyz(V4d v);
LADEF V3d v4d_xzz(V4d v);
LADEF V3d v4d_yzz(V4d v);
LADEF V3d v4d_zzz(V4d v);
LADEF V3d v4d_wzz(V4d v);
LADEF V3d v4d_xwz(V4d v);
LADEF V3d v4d_ywz(V4d v);
LADEF V3d v4d_zwz(V4d v);
LADEF V3d v4d_wwz(V4d v);
LADEF V3d v4d_xxw(V4d v);
LADEF V3d v4d_yxw(V4d v);
LADEF V3d v4d_zxw(V4d v);
LADEF V3d v4d_wxw(V4d v);
LADEF V3d v4d_xyw(V4d v);
LADEF V3d v4d_yyw(V4d v);
LADEF V3d v4d_zyw(V4d v);
LADEF V3d v4d_wyw(V4d v);
LADEF V3d v4d_xzw(V4d v);
LADEF V3d v4d_yzw(V4d v);
LADEF V3d v4d_zzw(V4d v);
LADEF V3d v4d_wzw(V4d v);
LADEF V3d v4d_xww(V4d v);
LADEF V3d v4d_yww(V4d v);
LADEF V3d v4d_zww(V4d v);
LADEF V3d v4d_www(V4d v);

LADEF V4d v2d_xxxx(V2d v);
LADEF V4d v2d_yxxx(V2d v);
LADEF V4d v2d_xyxx(V2d v);
LADEF V4d v2d_yyxx(V2d v);
LADEF V4d v2d_xxyx(V2d v);
LADEF V4d v2d_yxyx(V2d v);
LADEF V4d v2d_xyyx(V2d v);
LADEF V4d v2d_yyyx(V2d v);
LADEF V4d v2d_xxxy(V2d v);
LADEF V4d v2d_yxxy(V2d v);
LADEF V4d v2d_xyxy(V2d v);
LADEF V4d v2d_yyxy(V2d v);
LADEF V4d v2d_xxyy(V2d v);
LADEF V4d v2d_yxyy(V2d v);
LADEF V4d v2d_xyyy(V2d v);
LADEF V4d v2d_yyyy(V2d v);
LADEF V4d v3d_xxxx(V3d v);
LADEF V4d v3d_yxxx(V3d v);
LADEF V4d v3d_zxxx(V3d v);
LADEF V4d v3d_xyxx(V3d v);
LADEF V4d v3d_yyxx(V3d v);
LADEF V4d v3d_zyxx(V3d v);
LADEF V4d v3d_xzxx(V3d v);
LADEF V4d v3d_yzxx(V3d v);
LADEF V4d v3d_zzxx(V3d v);
LADEF V4d v3d_xxyx(V3d v);
LADEF V4d v3d_yxyx(V3d v);
LADEF V4d v3d_zxyx(V3d v);
LADEF V4d v3d_xyyx(V3d v);
LADEF V4d v3d_yyyx(V3d v);
LADEF V4d v3d_zyyx(V3d v);
LADEF V4d v3d_xzyx(V3d v);
LADEF V4d v3d_yzyx(V3d v);
LADEF V4d v3d_zzyx(V3d v);
LADEF V4d v3d_xxzx(V3d v);
LADEF V4d v3d_yxzx(V3d v);
LADEF V4d v3d_zxzx(V3d v);
LADEF V4d v3d_xyzx(V3d v);
LADEF V4d v3d_yyzx(V3d v);
LADEF V4d v3d_zyzx(V3d v);
LADEF V4d v3d_xzzx(V3d v);
LADEF V4d v3d_yzzx(V3d v);
LADEF V4d v3d_zzzx(V3d v);
LADEF V4d v3d_xxxy(V3d v);
LADEF V4d v3d_yxxy(V3d v);
LADEF V4d v3d_zxxy(V3d v);
LADEF V4d v3d_xyxy(V3d v);
LADEF V4d v3d_yyxy(V3d v);
LADEF V4d v3d_zyxy(V3d v);
LADEF V4d v3d_xzxy(V3d v);
LADEF V4d v3d_yzxy(V3d v);
LADEF V4d v3d_zzxy(V3d v);
LADEF V4d v3d_xxyy(V3d v);
LADEF V4d v3d_yxyy(V3d v);
LADEF V4d v3d_zxyy(V3d v);
LADEF V4d v3d_xyyy(V3d v);
LADEF V4d v3d_yyyy(V3d v);
LADEF V4d v3d_zyyy(V3d v);
LADEF V4d v3d_xzyy(V3d v);
LADEF V4d v3d_yzyy(V3d v);
LADEF V4d v3d_zzyy(V3d v);
LADEF V4d v3d_xxzy(V3d v);
LADEF V4d v3d_yxzy(V3d v);
LADEF V4d v3d_zxzy(V3d v);
LADEF V4d v3d_xyzy(V3d v);
LADEF V4d v3d_yyzy(V3d v);
LADEF V4d v3d_zyzy(V3d v);
LADEF V4d v3d_xzzy(V3d v);
LADEF V4d v3d_yzzy(V3d v);
LADEF V4d v3d_zzzy(V3d v);
LADEF V4d v3d_xxxz(V3d v);
LADEF V4d v3d_yxxz(V3d v);
LADEF V4d v3d_zxxz(V3d v);
LADEF V4d v3d_xyxz(V3d v);
LADEF V4d v3d_yyxz(V3d v);
LADEF V4d v3d_zyxz(V3d v);
LADEF V4d v3d_xzxz(V3d v);
LADEF V4d v3d_yzxz(V3d v);
LADEF V4d v3d_zzxz(V3d v);
LADEF V4d v3d_xxyz(V3d v);
LADEF V4d v3d_yxyz(V3d v);
LADEF V4d v3d_zxyz(V3d v);
LADEF V4d v3d_xyyz(V3d v);
LADEF V4d v3d_yyyz(V3d v);
LADEF V4d v3d_zyyz(V3d v);
LADEF V4d v3d_xzyz(V3d v);
LADEF V4d v3d_yzyz(V3d v);
LADEF V4d v3d_zzyz(V3d v);
LADEF V4d v3d_xxzz(V3d v);
LADEF V4d v3d_yxzz(V3d v);
LADEF V4d v3d_zxzz(V3d v);
LADEF V4d v3d_xyzz(V3d v);
LADEF V4d v3d_yyzz(V3d v);
LADEF V4d v3d_zyzz(V3d v);
LADEF V4d v3d_xzzz(V3d v);
LADEF V4d v3d_yzzz(V3d v);
LADEF V4d v3d_zzzz(V3d v);
LADEF V4d v4d_xxxx(V4d v);
LADEF V4d v4d_yxxx(V4d v);
LADEF V4d v4d_zxxx(V4d v);
LADEF V4d v4d_wxxx(V4d v);
LADEF V4d v4d_xyxx(V4d v);
LADEF V4d v4d_yyxx(V4d v);
LADEF V4d v4d_zyxx(V4d v);
LADEF V4d v4d_wyxx(V4d v);
LADEF V4d v4d_xzxx(V4d v);
LADEF V4d v4d_yzxx(V4d v);
LADEF V4d v4d_zzxx(V4d v);
LADEF V4d v4d_wzxx(V4d v);
LADEF V4d v4d_xwxx(V4d v);
LADEF V4d v4d_ywxx(V4d v);
LADEF V4d v4d_zwxx(V4d v);
LADEF V4d v4d_wwxx(V4d v);
LADEF V4d v4d_xxyx(V4d v);
LADEF V4d v4d_yxyx(V4d v);
LADEF V4d v4d_zxyx(V4d v);
LADEF V4d v4d_wxyx(V4d v);
LADEF V4d v4d_xyyx(V4d v);
LADEF V4d v4d_yyyx(V4d v);
LADEF V4d v4d_zyyx(V4d v);
LADEF V4d v4d_wyyx(V4d v);
LADEF V4d v4d_xzyx(V4d v);
LADEF V4d v4d_yzyx(V4d v);
LADEF V4d v4d_zzyx(V4d v);
LADEF V4d v4d_wzyx(V4d v);
LADEF V4d v4d_xwyx(V4d v);
LADEF V4d v4d_ywyx(V4d v);
LADEF V4d v4d_zwyx(V4d v);
LADEF V4d v4d_wwyx(V4d v);
LADEF V4d v4d_xxzx(V4d v);
LADEF V4d v4d_yxzx(V4d v);
LADEF V4d v4d_zxzx(V4d v);
LADEF V4d v4d_wxzx(V4d v);
LADEF V4d v4d_xyzx(V4d v);
LADEF V4d v4d_yyzx(V4d v);
LADEF V4d v4d_zyzx(V4d v);
LADEF V4d v4d_wyzx(V4d v);
LADEF V4d v4d_xzzx(V4d v);
LADEF V4d v4d_yzzx(V4d v);
LADEF V4d v4d_zzzx(V4d v);
LADEF V4d v4d_wzzx(V4d v);
LADEF V4d v4d_xwzx(V4d v);
LADEF V4d v4d_ywzx(V4d v);
LADEF V4d v4d_zwzx(V4d v);
LADEF V4d v4d_wwzx(V4d v);
LADEF V4d v4d_xxwx(V4d v);
LADEF V4d v4d_yxwx(V4d v);
LADEF V4d v4d_zxwx(V4d v);
LADEF V4d v4d_wxwx(V4d v);
LADEF V4d v4d_xywx(V4d v);
LADEF V4d v4d_yywx(V4d v);
LADEF V4d v4d_zywx(V4d v);
LADEF V4d v4d_wywx(V4d v);
LADEF V4d v4d_xzwx(V4d v);
LADEF V4d v4d_yzwx(V4d v);
LADEF V4d v4d_zzwx(V4d v);
LADEF V4d v4d_wzwx(V4d v);
LADEF V4d v4d_xwwx(V4d v);
LADEF V4d v4d_ywwx(V4d v);
LADEF V4d v4d_zwwx(V4d v);
LADEF V4d v4d_wwwx(V4d v);
LADEF V4d v4d_xxxy(V4d v);
LADEF V4d v4d_yxxy(V4d v);
LADEF V4d v4d_zxxy(V4d v);
LADEF V4d v4d_wxxy(V4d v);
LADEF V4d v4d_xyxy(V4d v);
LADEF V4d v4d_yyxy(V4d v);
LADEF V4d v4d_zyxy(V4d v);
LADEF V4d v4d_wyxy(V4d v);
LADEF V4d v4d_xzxy(V4d v);
LADEF V4d v4d_yzxy(V4d v);
LADEF V4d v4d_zzxy(V4d v);
LADEF V4d v4d_wzxy(V4d v);
LADEF V4d v4d_xwxy(V4d v);
LADEF V4d v4d_ywxy(V4d v);
LADEF V4d v4d_zwxy(V4d v);
LADEF V4d v4d_wwxy(V4d v);
LADEF V4d v4d_xxyy(V4d v);
LADEF V4d v4d_yxyy(V4d v);
LADEF V4d v4d_zxyy(V4d v);
LADEF V4d v4d_wxyy(V4d v);
LADEF V4d v4d_xyyy(V4d v);
LADEF V4d v4d_yyyy(V4d v);
LADEF V4d v4d_zyyy(V4d v);
LADEF V4d v4d_wyyy(V4d v);
LADEF V4d v4d_xzyy(V4d v);
LADEF V4d v4d_yzyy(V4d v);
LADEF V4d v4d_zzyy(V4d v);
LADEF V4d v4d_wzyy(V4d v);
LADEF V4d v4d_xwyy(V4d v);
LADEF V4d v4d_ywyy(V4d v);
LADEF V4d v4d_zwyy(V4d v);
LADEF V4d v4d_wwyy(V4d v);
LADEF V4d v4d_xxzy(V4d v);
LADEF V4d v4d_yxzy(V4d v);
LADEF V4d v4d_zxzy(V4d v);
LADEF V4d v4d_wxzy(V4d v);
LADEF V4d v4d_xyzy(V4d v);
LADEF V4d v4d_yyzy(V4d v);
LADEF V4d v4d_zyzy(V4d v);
LADEF V4d v4d_wyzy(V4d v);
LADEF V4d v4d_xzzy(V4d v);
LADEF V4d v4d_yzzy(V4d v);
LADEF V4d v4d_zzzy(V4d v);
LADEF V4d v4d_wzzy(V4d v);
LADEF V4d v4d_xwzy(V4d v);
LADEF V4d v4d_ywzy(V4d v);
LADEF V4d v4d_zwzy(V4d v);
LADEF V4d v4d_wwzy(V4d v);
LADEF V4d v4d_xxwy(V4d v);
LADEF V4d v4d_yxwy(V4d v);
LADEF V4d v4d_zxwy(V4d v);
LADEF V4d v4d_wxwy(V4d v);
LADEF V4d v4d_xywy(V4d v);
LADEF V4d v4d_yywy(V4d v);
LADEF V4d v4d_zywy(V4d v);
LADEF V4d v4d_wywy(V4d v);
LADEF V4d v4d_xzwy(V4d v);
LADEF V4d v4d_yzwy(V4d v);
LADEF V4d v4d_zzwy(V4d v);
LADEF V4d v4d_wzwy(V4d v);
LADEF V4d v4d_xwwy(V4d v);
LADEF V4d v4d_ywwy(V4d v);
LADEF V4d v4d_zwwy(V4d v);
LADEF V4d v4d_wwwy(V4d v);
LADEF V4d v4d_xxxz(V4d v);
LADEF V4d v4d_yxxz(V4d v);
LADEF V4d v4d_zxxz(V4d v);
LADEF V4d v4d_wxxz(V4d v);
LADEF V4d v4d_xyxz(V4d v);
LADEF V4d v4d_yyxz(V4d v);
LADEF V4d v4d_zyxz(V4d v);
LADEF V4d v4d_wyxz(V4d v);
LADEF V4d v4d_xzxz(V4d v);
LADEF V4d v4d_yzxz(V4d v);
LADEF V4d v4d_zzxz(V4d v);
LADEF V4d v4d_wzxz(V4d v);
LADEF V4d v4d_xwxz(V4d v);
LADEF V4d v4d_ywxz(V4d v);
LADEF V4d v4d_zwxz(V4d v);
LADEF V4d v4d_wwxz(V4d v);
LADEF V4d v4d_xxyz(V4d v);
LADEF V4d v4d_yxyz(V4d v);
LADEF V4d v4d_zxyz(V4d v);
LADEF V4d v4d_wxyz(V4d v);
LADEF V4d v4d_xyyz(V4d v);
LADEF V4d v4d_yyyz(V4d v);
LADEF V4d v4d_zyyz(V4d v);
LADEF V4d v4d_wyyz(V4d v);
LADEF V4d v4d_xzyz(V4d v);
LADEF V4d v4d_yzyz(V4d v);
LADEF V4d v4d_zzyz(V4d v);
LADEF V4d v4d_wzyz(V4d v);
LADEF V4d v4d_xwyz(V4d v);
LADEF V4d v4d_ywyz(V4d v);
LADEF V4d v4d_zwyz(V4d v);
LADEF V4d v4d_wwyz(V4d v);
LADEF V4d v4d_xxzz(V4d v);
LADEF V4d v4d_yxzz(V4d v);
LADEF V4d v4d_zxzz(V4d v);
LADEF V4d v4d_wxzz(V4d v);
LADEF V4d v4d_xyzz(V4d v);
LADEF V4d v4d_yyzz(V4d v);
LADEF V4d v4d_zyzz(V4d v);
LADEF V4d v4d_wyzz(V4d v);
LADEF V4d v4d_xzzz(V4d v);
LADEF V4d v4d_yzzz(V4d v);
LADEF V4d v4d_zzzz(V4d v);
LADEF V4d v4d_wzzz(V4d v);
LADEF V4d v4d_xwzz(V4d v);
LADEF V4d v4d_ywzz(V4d v);
LADEF V4d v4d_zwzz(V4d v);
LADEF V4d v4d_wwzz(V4d v);
LADEF V4d v4d_xxwz(V4d v);
LADEF V4d v4d_yxwz(V4d v);
LADEF V4d v4d_zxwz(V4d v);
LADEF V4d v4d_wxwz(V4d v);
LADEF V4d v4d_xywz(V4d v);
LADEF V4d v4d_yywz(V4d v);
LADEF V4d v4d_zywz(V4d v);
LADEF V4d v4d_wywz(V4d v);
LADEF V4d v4d_xzwz(V4d v);
LADEF V4d v4d_yzwz(V4d v);
LADEF V4d v4d_zzwz(V4d v);
LADEF V4d v4d_wzwz(V4d v);
LADEF V4d v4d_xwwz(V4d v);
LADEF V4d v4d_ywwz(V4d v);
LADEF V4d v4d_zwwz(V4d v);
LADEF V4d v4d_wwwz(V4d v);
LADEF V4d v4d_xxxw(V4d v);
LADEF V4d v4d_yxxw(V4d v);
LADEF V4d v4d_zxxw(V4d v);
LADEF V4d v4d_wxxw(V4d v);
LADEF V4d v4d_xyxw(V4d v);
LADEF V4d v4d_yyxw(V4d v);
LADEF V4d v4d_zyxw(V4d v);
LADEF V4d v4d_wyxw(V4d v);
LADEF V4d v4d_xzxw(V4d v);
LADEF V4d v4d_yzxw(V4d v);
LADEF V4d v4d_zzxw(V4d v);
LADEF V4d v4d_wzxw(V4d v);
LADEF V4d v4d_xwxw(V4d v);
LADEF V4d v4d_ywxw(V4d v);
LADEF V4d v4d_zwxw(V4d v);
LADEF V4d v4d_wwxw(V4d v);
LADEF V4d v4d_xxyw(V4d v);
LADEF V4d v4d_yxyw(V4d v);
LADEF V4d v4d_zxyw(V4d v);
LADEF V4d v4d_wxyw(V4d v);
LADEF V4d v4d_xyyw(V4d v);
LADEF V4d v4d_yyyw(V4d v);
LADEF V4d v4d_zyyw(V4d v);
LADEF V4d v4d_wyyw(V4d v);
LADEF V4d v4d_xzyw(V4d v);
LADEF V4d v4d_yzyw(V4d v);
LADEF V4d v4d_zzyw(V4d v);
LADEF V4d v4d_wzyw(V4d v);
LADEF V4d v4d_xwyw(V4d v);
LADEF V4d v4d_ywyw(V4d v);
LADEF V4d v4d_zwyw(V4d v);
LADEF V4d v4d_wwyw(V4d v);
LADEF V4d v4d_xxzw(V4d v);
LADEF V4d v4d_yxzw(V4d v);
LADEF V4d v4d_zxzw(V4d v);
LADEF V4d v4d_wxzw(V4d v);
LADEF V4d v4d_xyzw(V4d v);
LADEF V4d v4d_yyzw(V4d v);
LADEF V4d v4d_zyzw(V4d v);
LADEF V4d v4d_wyzw(V4d v);
LADEF V4d v4d_xzzw(V4d v);
LADEF V4d v4d_yzzw(V4d v);
LADEF V4d v4d_zzzw(V4d v);
LADEF V4d v4d_wzzw(V4d v);
LADEF V4d v4d_xwzw(V4d v);
LADEF V4d v4d_ywzw(V4d v);
LADEF V4d v4d_zwzw(V4d v);
LADEF V4d v4d_wwzw(V4d v);
LADEF V4d v4d_xxww(V4d v);
LADEF V4d v4d_yxww(V4d v);
LADEF V4d v4d_zxww(V4d v);
LADEF V4d v4d_wxww(V4d v);
LADEF V4d v4d_xyww(V4d v);
LADEF V4d v4d_yyww(V4d v);
LADEF V4d v4d_zyww(V4d v);
LADEF V4d v4d_wyww(V4d v);
LADEF V4d v4d_xzww(V4d v);
LADEF V4d v4d_yzww(V4d v);
LADEF V4d v4d_zzww(V4d v);
LADEF V4d v4d_wzww(V4d v);
LADEF V4d v4d_xwww(V4d v);
LADEF V4d v4d_ywww(V4d v);
LADEF V4d v4d_zwww(V4d v);
LADEF V4d v4d_wwww(V4d v);

LADEF V2i v2i_xx(V2i v);
LADEF V2i v2i_yx(V2i v);
LADEF V2i v2i_xy(V2i v);
LADEF V2i v2i_yy(V2i v);
LADEF V2i v3i_xx(V3i v);
LADEF V2i v3i_yx(V3i v);
LADEF V2i v3i_zx(V3i v);
LADEF V2i v3i_xy(V3i v);
LADEF V2i v3i_yy(V3i v);
LADEF V2i v3i_zy(V3i v);
LADEF V2i v3i_xz(V3i v);
LADEF V2i v3i_yz(V3i v);
LADEF V2i v3i_zz(V3i v);
LADEF V2i v4i_xx(V4i v);
LADEF V2i v4i_yx(V4i v);
LADEF V2i v4i_zx(V4i v);
LADEF V2i v4i_wx(V4i v);
LADEF V2i v4i_xy(V4i v);
LADEF V2i v4i_yy(V4i v);
LADEF V2i v4i_zy(V4i v);
LADEF V2i v4i_wy(V4i v);
LADEF V2i v4i_xz(V4i v);
LADEF V2i v4i_yz(V4i v);
LADEF V2i v4i_zz(V4i v);
LADEF V2i v4i_wz(V4i v);
LADEF V2i v4i_xw(V4i v);
LADEF V2i v4i_yw(V4i v);
LADEF V2i v4i_zw(V4i v);
LADEF V2i v4i_ww(V4i v);

LADEF V3i v2i_xxx(V2i v);
LADEF V3i v2i_yxx(V2i v);
LADEF V3i v2i_xyx(V2i v);
LADEF V3i v2i_yyx(V2i v);
LADEF V3i v2i_xxy(V2i v);
LADEF V3i v2i_yxy(V2i v);
LADEF V3i v2i_xyy(V2i v);
LADEF V3i v2i_yyy(V2i v);
LADEF V3i v3i_xxx(V3i v);
LADEF V3i v3i_yxx(V3i v);
LADEF V3i v3i_zxx(V3i v);
LADEF V3i v3i_xyx(V3i v);
LADEF V3i v3i_yyx(V3i v);
LADEF V3i v3i_zyx(V3i v);
LADEF V3i v3i_xzx(V3i v);
LADEF V3i v3i_yzx(V3i v);
LADEF V3i v3i_zzx(V3i v);
LADEF V3i v3i_xxy(V3i v);
LADEF V3i v3i_yxy(V3i v);
LADEF V3i v3i_zxy(V3i v);
LADEF V3i v3i_xyy(V3i v);
LADEF V3i v3i_yyy(V3i v);
LADEF V3i v3i_zyy(V3i v);
LADEF V3i v3i_xzy(V3i v);
LADEF V3i v3i_yzy(V3i v);
LADEF V3i v3i_zzy(V3i v);
LADEF V3i v3i_xxz(V3i v);
LADEF V3i v3i_yxz(V3i v);
LADEF V3i v3i_zxz(V3i v);
LADEF V3i v3i_xyz(V3i v);
LADEF V3i v3i_yyz(V3i v);
LADEF V3i v3i_zyz(V3i v);
LADEF V3i v3i_xzz(V3i v);
LADEF V3i v3i_yzz(V3i v);
LADEF V3i v3i_zzz(V3i v);
LADEF V3i v4i_xxx(V4i v);
LADEF V3i v4i_yxx(V4i v);
LADEF V3i v4i_zxx(V4i v);
LADEF V3i v4i_wxx(V4i v);
LADEF V3i v4i_xyx(V4i v);
LADEF V3i v4i_yyx(V4i v);
LADEF V3i v4i_zyx(V4i v);
LADEF V3i v4i_wyx(V4i v);
LADEF V3i v4i_xzx(V4i v);
LADEF V3i v4i_yzx(V4i v);
LADEF V3i v4i_zzx(V4i v);
LADEF V3i v4i_wzx(V4i v);
LADEF V3i v4i_xwx(V4i v);
LADEF V3i v4i_ywx(V4i v);
LADEF V3i v4i_zwx(V4i v);
LADEF V3i v4i_wwx(V4i v);
LADEF V3i v4i_xxy(V4i v);
LADEF V3i v4i_yxy(V4i v);
LADEF V3i v4i_zxy(V4i v);
LADEF V3i v4i_wxy(V4i v);
LADEF V3i v4i_xyy(V4i v);
LADEF V3i v4i_yyy(V4i v);
LADEF V3i v4i_zyy(V4i v);
LADEF V3i v4i_wyy(V4i v);
LADEF V3i v4i_xzy(V4i v);
LADEF V3i v4i_yzy(V4i v);
LADEF V3i v4i_zzy(V4i v);
LADEF V3i v4i_wzy(V4i v);
LADEF V3i v4i_xwy(V4i v);
LADEF V3i v4i_ywy(V4i v);
LADEF V3i v4i_zwy(V4i v);
LADEF V3i v4i_wwy(V4i v);
LADEF V3i v4i_xxz(V4i v);
LADEF V3i v4i_yxz(V4i v);
LADEF V3i v4i_zxz(V4i v);
LADEF V3i v4i_wxz(V4i v);
LADEF V3i v4i_xyz(V4i v);
LADEF V3i v4i_yyz(V4i v);
LADEF V3i v4i_zyz(V4i v);
LADEF V3i v4i_wyz(V4i v);
LADEF V3i v4i_xzz(V4i v);
LADEF V3i v4i_yzz(V4i v);
LADEF V3i v4i_zzz(V4i v);
LADEF V3i v4i_wzz(V4i v);
LADEF V3i v4i_xwz(V4i v);
LADEF V3i v4i_ywz(V4i v);
LADEF V3i v4i_zwz(V4i v);
LADEF V3i v4i_wwz(V4i v);
LADEF V3i v4i_xxw(V4i v);
LADEF V3i v4i_yxw(V4i v);
LADEF V3i v4i_zxw(V4i v);
LADEF V3i v4i_wxw(V4i v);
LADEF V3i v4i_xyw(V4i v);
LADEF V3i v4i_yyw(V4i v);
LADEF V3i v4i_zyw(V4i v);
LADEF V3i v4i_wyw(V4i v);
LADEF V3i v4i_xzw(V4i v);
LADEF V3i v4i_yzw(V4i v);
LADEF V3i v4i_zzw(V4i v);
LADEF V3i v4i_wzw(V4i v);
LADEF V3i v4i_xww(V4i v);
LADEF V3i v4i_yww(V4i v);
LADEF V3i v4i_zww(V4i v);
LADEF V3i v4i_www(V4i v);

LADEF V4i v2i_xxxx(V2i v);
LADEF V4i v2i_yxxx(V2i v);
LADEF V4i v2i_xyxx(V2i v);
LADEF V4i v2i_yyxx(V2i v);
LADEF V4i v2i_xxyx(V2i v);
LADEF V4i v2i_yxyx(V2i v);
LADEF V4i v2i_xyyx(V2i v);
LADEF V4i v2i_yyyx(V2i v);
LADEF V4i v2i_xxxy(V2i v);
LADEF V4i v2i_yxxy(V2i v);
LADEF V4i v2i_xyxy(V2i v);
LADEF V4i v2i_yyxy(V2i v);
LADEF V4i v2i_xxyy(V2i v);
LADEF V4i v2i_yxyy(V2i v);
LADEF V4i v2i_xyyy(V2i v);
LADEF V4i v2i_yyyy(V2i v);
LADEF V4i v3i_xxxx(V3i v);
LADEF V4i v3i_yxxx(V3i v);
LADEF V4i v3i_zxxx(V3i v);
LADEF V4i v3i_xyxx(V3i v);
LADEF V4i v3i_yyxx(V3i v);
LADEF V4i v3i_zyxx(V3i v);
LADEF V4i v3i_xzxx(V3i v);
LADEF V4i v3i_yzxx(V3i v);
LADEF V4i v3i_zzxx(V3i v);
LADEF V4i v3i_xxyx(V3i v);
LADEF V4i v3i_yxyx(V3i v);
LADEF V4i v3i_zxyx(V3i v);
LADEF V4i v3i_xyyx(V3i v);
LADEF V4i v3i_yyyx(V3i v);
LADEF V4i v3i_zyyx(V3i v);
LADEF V4i v3i_xzyx(V3i v);
LADEF V4i v3i_yzyx(V3i v);
LADEF V4i v3i_zzyx(V3i v);
LADEF V4i v3i_xxzx(V3i v);
LADEF V4i v3i_yxzx(V3i v);
LADEF V4i v3i_zxzx(V3i v);
LADEF V4i v3i_xyzx(V3i v);
LADEF V4i v3i_yyzx(V3i v);
LADEF V4i v3i_zyzx(V3i v);
LADEF V4i v3i_xzzx(V3i v);
LADEF V4i v3i_yzzx(V3i v);
LADEF V4i v3i_zzzx(V3i v);
LADEF V4i v3i_xxxy(V3i v);
LADEF V4i v3i_yxxy(V3i v);
LADEF V4i v3i_zxxy(V3i v);
LADEF V4i v3i_xyxy(V3i v);
LADEF V4i v3i_yyxy(V3i v);
LADEF V4i v3i_zyxy(V3i v);
LADEF V4i v3i_xzxy(V3i v);
LADEF V4i v3i_yzxy(V3i v);
LADEF V4i v3i_zzxy(V3i v);
LADEF V4i v3i_xxyy(V3i v);
LADEF V4i v3i_yxyy(V3i v);
LADEF V4i v3i_zxyy(V3i v);
LADEF V4i v3i_xyyy(V3i v);
LADEF V4i v3i_yyyy(V3i v);
LADEF V4i v3i_zyyy(V3i v);
LADEF V4i v3i_xzyy(V3i v);
LADEF V4i v3i_yzyy(V3i v);
LADEF V4i v3i_zzyy(V3i v);
LADEF V4i v3i_xxzy(V3i v);
LADEF V4i v3i_yxzy(V3i v);
LADEF V4i v3i_zxzy(V3i v);
LADEF V4i v3i_xyzy(V3i v);
LADEF V4i v3i_yyzy(V3i v);
LADEF V4i v3i_zyzy(V3i v);
LADEF V4i v3i_xzzy(V3i v);
LADEF V4i v3i_yzzy(V3i v);
LADEF V4i v3i_zzzy(V3i v);
LADEF V4i v3i_xxxz(V3i v);
LADEF V4i v3i_yxxz(V3i v);
LADEF V4i v3i_zxxz(V3i v);
LADEF V4i v3i_xyxz(V3i v);
LADEF V4i v3i_yyxz(V3i v);
LADEF V4i v3i_zyxz(V3i v);
LADEF V4i v3i_xzxz(V3i v);
LADEF V4i v3i_yzxz(V3i v);
LADEF V4i v3i_zzxz(V3i v);
LADEF V4i v3i_xxyz(V3i v);
LADEF V4i v3i_yxyz(V3i v);
LADEF V4i v3i_zxyz(V3i v);
LADEF V4i v3i_xyyz(V3i v);
LADEF V4i v3i_yyyz(V3i v);
LADEF V4i v3i_zyyz(V3i v);
LADEF V4i v3i_xzyz(V3i v);
LADEF V4i v3i_yzyz(V3i v);
LADEF V4i v3i_zzyz(V3i v);
LADEF V4i v3i_xxzz(V3i v);
LADEF V4i v3i_yxzz(V3i v);
LADEF V4i v3i_zxzz(V3i v);
LADEF V4i v3i_xyzz(V3i v);
LADEF V4i v3i_yyzz(V3i v);
LADEF V4i v3i_zyzz(V3i v);
LADEF V4i v3i_xzzz(V3i v);
LADEF V4i v3i_yzzz(V3i v);
LADEF V4i v3i_zzzz(V3i v);
LADEF V4i v4i_xxxx(V4i v);
LADEF V4i v4i_yxxx(V4i v);
LADEF V4i v4i_zxxx(V4i v);
LADEF V4i v4i_wxxx(V4i v);
LADEF V4i v4i_xyxx(V4i v);
LADEF V4i v4i_yyxx(V4i v);
LADEF V4i v4i_zyxx(V4i v);
LADEF V4i v4i_wyxx(V4i v);
LADEF V4i v4i_xzxx(V4i v);
LADEF V4i v4i_yzxx(V4i v);
LADEF V4i v4i_zzxx(V4i v);
LADEF V4i v4i_wzxx(V4i v);
LADEF V4i v4i_xwxx(V4i v);
LADEF V4i v4i_ywxx(V4i v);
LADEF V4i v4i_zwxx(V4i v);
LADEF V4i v4i_wwxx(V4i v);
LADEF V4i v4i_xxyx(V4i v);
LADEF V4i v4i_yxyx(V4i v);
LADEF V4i v4i_zxyx(V4i v);
LADEF V4i v4i_wxyx(V4i v);
LADEF V4i v4i_xyyx(V4i v);
LADEF V4i v4i_yyyx(V4i v);
LADEF V4i v4i_zyyx(V4i v);
LADEF V4i v4i_wyyx(V4i v);
LADEF V4i v4i_xzyx(V4i v);
LADEF V4i v4i_yzyx(V4i v);
LADEF V4i v4i_zzyx(V4i v);
LADEF V4i v4i_wzyx(V4i v);
LADEF V4i v4i_xwyx(V4i v);
LADEF V4i v4i_ywyx(V4i v);
LADEF V4i v4i_zwyx(V4i v);
LADEF V4i v4i_wwyx(V4i v);
LADEF V4i v4i_xxzx(V4i v);
LADEF V4i v4i_yxzx(V4i v);
LADEF V4i v4i_zxzx(V4i v);
LADEF V4i v4i_wxzx(V4i v);
LADEF V4i v4i_xyzx(V4i v);
LADEF V4i v4i_yyzx(V4i v);
LADEF V4i v4i_zyzx(V4i v);
LADEF V4i v4i_wyzx(V4i v);
LADEF V4i v4i_xzzx(V4i v);
LADEF V4i v4i_yzzx(V4i v);
LADEF V4i v4i_zzzx(V4i v);
LADEF V4i v4i_wzzx(V4i v);
LADEF V4i v4i_xwzx(V4i v);
LADEF V4i v4i_ywzx(V4i v);
LADEF V4i v4i_zwzx(V4i v);
LADEF V4i v4i_wwzx(V4i v);
LADEF V4i v4i_xxwx(V4i v);
LADEF V4i v4i_yxwx(V4i v);
LADEF V4i v4i_zxwx(V4i v);
LADEF V4i v4i_wxwx(V4i v);
LADEF V4i v4i_xywx(V4i v);
LADEF V4i v4i_yywx(V4i v);
LADEF V4i v4i_zywx(V4i v);
LADEF V4i v4i_wywx(V4i v);
LADEF V4i v4i_xzwx(V4i v);
LADEF V4i v4i_yzwx(V4i v);
LADEF V4i v4i_zzwx(V4i v);
LADEF V4i v4i_wzwx(V4i v);
LADEF V4i v4i_xwwx(V4i v);
LADEF V4i v4i_ywwx(V4i v);
LADEF V4i v4i_zwwx(V4i v);
LADEF V4i v4i_wwwx(V4i v);
LADEF V4i v4i_xxxy(V4i v);
LADEF V4i v4i_yxxy(V4i v);
LADEF V4i v4i_zxxy(V4i v);
LADEF V4i v4i_wxxy(V4i v);
LADEF V4i v4i_xyxy(V4i v);
LADEF V4i v4i_yyxy(V4i v);
LADEF V4i v4i_zyxy(V4i v);
LADEF V4i v4i_wyxy(V4i v);
LADEF V4i v4i_xzxy(V4i v);
LADEF V4i v4i_yzxy(V4i v);
LADEF V4i v4i_zzxy(V4i v);
LADEF V4i v4i_wzxy(V4i v);
LADEF V4i v4i_xwxy(V4i v);
LADEF V4i v4i_ywxy(V4i v);
LADEF V4i v4i_zwxy(V4i v);
LADEF V4i v4i_wwxy(V4i v);
LADEF V4i v4i_xxyy(V4i v);
LADEF V4i v4i_yxyy(V4i v);
LADEF V4i v4i_zxyy(V4i v);
LADEF V4i v4i_wxyy(V4i v);
LADEF V4i v4i_xyyy(V4i v);
LADEF V4i v4i_yyyy(V4i v);
LADEF V4i v4i_zyyy(V4i v);
LADEF V4i v4i_wyyy(V4i v);
LADEF V4i v4i_xzyy(V4i v);
LADEF V4i v4i_yzyy(V4i v);
LADEF V4i v4i_zzyy(V4i v);
LADEF V4i v4i_wzyy(V4i v);
LADEF V4i v4i_xwyy(V4i v);
LADEF V4i v4i_ywyy(V4i v);
LADEF V4i v4i_zwyy(V4i v);
LADEF V4i v4i_wwyy(V4i v);
LADEF V4i v4i_xxzy(V4i v);
LADEF V4i v4i_yxzy(V4i v);
LADEF V4i v4i_zxzy(V4i v);
LADEF V4i v4i_wxzy(V4i v);
LADEF V4i v4i_xyzy(V4i v);
LADEF V4i v4i_yyzy(V4i v);
LADEF V4i v4i_zyzy(V4i v);
LADEF V4i v4i_wyzy(V4i v);
LADEF V4i v4i_xzzy(V4i v);
LADEF V4i v4i_yzzy(V4i v);
LADEF V4i v4i_zzzy(V4i v);
LADEF V4i v4i_wzzy(V4i v);
LADEF V4i v4i_xwzy(V4i v);
LADEF V4i v4i_ywzy(V4i v);
LADEF V4i v4i_zwzy(V4i v);
LADEF V4i v4i_wwzy(V4i v);
LADEF V4i v4i_xxwy(V4i v);
LADEF V4i v4i_yxwy(V4i v);
LADEF V4i v4i_zxwy(V4i v);
LADEF V4i v4i_wxwy(V4i v);
LADEF V4i v4i_xywy(V4i v);
LADEF V4i v4i_yywy(V4i v);
LADEF V4i v4i_zywy(V4i v);
LADEF V4i v4i_wywy(V4i v);
LADEF V4i v4i_xzwy(V4i v);
LADEF V4i v4i_yzwy(V4i v);
LADEF V4i v4i_zzwy(V4i v);
LADEF V4i v4i_wzwy(V4i v);
LADEF V4i v4i_xwwy(V4i v);
LADEF V4i v4i_ywwy(V4i v);
LADEF V4i v4i_zwwy(V4i v);
LADEF V4i v4i_wwwy(V4i v);
LADEF V4i v4i_xxxz(V4i v);
LADEF V4i v4i_yxxz(V4i v);
LADEF V4i v4i_zxxz(V4i v);
LADEF V4i v4i_wxxz(V4i v);
LADEF V4i v4i_xyxz(V4i v);
LADEF V4i v4i_yyxz(V4i v);
LADEF V4i v4i_zyxz(V4i v);
LADEF V4i v4i_wyxz(V4i v);
LADEF V4i v4i_xzxz(V4i v);
LADEF V4i v4i_yzxz(V4i v);
LADEF V4i v4i_zzxz(V4i v);
LADEF V4i v4i_wzxz(V4i v);
LADEF V4i v4i_xwxz(V4i v);
LADEF V4i v4i_ywxz(V4i v);
LADEF V4i v4i_zwxz(V4i v);
LADEF V4i v4i_wwxz(V4i v);
LADEF V4i v4i_xxyz(V4i v);
LADEF V4i v4i_yxyz(V4i v);
LADEF V4i v4i_zxyz(V4i v);
LADEF V4i v4i_wxyz(V4i v);
LADEF V4i v4i_xyyz(V4i v);
LADEF V4i v4i_yyyz(V4i v);
LADEF V4i v4i_zyyz(V4i v);
LADEF V4i v4i_wyyz(V4i v);
LADEF V4i v4i_xzyz(V4i v);
LADEF V4i v4i_yzyz(V4i v);
LADEF V4i v4i_zzyz(V4i v);
LADEF V4i v4i_wzyz(V4i v);
LADEF V4i v4i_xwyz(V4i v);
LADEF V4i v4i_ywyz(V4i v);
LADEF V4i v4i_zwyz(V4i v);
LADEF V4i v4i_wwyz(V4i v);
LADEF V4i v4i_xxzz(V4i v);
LADEF V4i v4i_yxzz(V4i v);
LADEF V4i v4i_zxzz(V4i v);
LADEF V4i v4i_wxzz(V4i v);
LADEF V4i v4i_xyzz(V4i v);
LADEF V4i v4i_yyzz(V4i v);
LADEF V4i v4i_zyzz(V4i v);
LADEF V4i v4i_wyzz(V4i v);
LADEF V4i v4i_xzzz(V4i v);
LADEF V4i v4i_yzzz(V4i v);
LADEF V4i v4i_zzzz(V4i v);
LADEF V4i v4i_wzzz(V4i v);
LADEF V4i v4i_xwzz(V4i v);
LADEF V4i v4i_ywzz(V4i v);
LADEF V4i v4i_zwzz(V4i v);
LADEF V4i v4i_wwzz(V4i v);
LADEF V4i v4i_xxwz(V4i v);
LADEF V4i v4i_yxwz(V4i v);
LADEF V4i v4i_zxwz(V4i v);
LADEF V4i v4i_wxwz(V4i v);
LADEF V4i v4i_xywz(V4i v);
LADEF V4i v4i_yywz(V4i v);
LADEF V4i v4i_zywz(V4i v);
LADEF V4i v4i_wywz(V4i v);
LADEF V4i v4i_xzwz(V4i v);
LADEF V4i v4i_yzwz(V4i v);
LADEF V4i v4i_zzwz(V4i v);
LADEF V4i v4i_wzwz(V4i v);
LADEF V4i v4i_xwwz(V4i v);
LADEF V4i v4i_ywwz(V4i v);
LADEF V4i v4i_zwwz(V4i v);
LADEF V4i v4i_wwwz(V4i v);
LADEF V4i v4i_xxxw(V4i v);
LADEF V4i v4i_yxxw(V4i v);
LADEF V4i v4i_zxxw(V4i v);
LADEF V4i v4i_wxxw(V4i v);
LADEF V4i v4i_xyxw(V4i v);
LADEF V4i v4i_yyxw(V4i v);
LADEF V4i v4i_zyxw(V4i v);
LADEF V4i v4i_wyxw(V4i v);
LADEF V4i v4i_xzxw(V4i v);
LADEF V4i v4i_yzxw(V4i v);
LADEF V4i v4i_zzxw(V4i v);
LADEF V4i v4i_wzxw(V4i v);
LADEF V4i v4i_xwxw(V4i v);
LADEF V4i v4i_ywxw(V4i v);
LADEF V4i v4i_zwxw(V4i v);
LADEF V4i v4i_wwxw(V4i v);
LADEF V4i v4i_xxyw(V4i v);
LADEF V4i v4i_yxyw(V4i v);
LADEF V4i v4i_zxyw(V4i v);
LADEF V4i v4i_wxyw(V4i v);
LADEF V4i v4i_xyyw(V4i v);
LADEF V4i v4i_yyyw(V4i v);
LADEF V4i v4i_zyyw(V4i v);
LADEF V4i v4i_wyyw(V4i v);
LADEF V4i v4i_xzyw(V4i v);
LADEF V4i v4i_yzyw(V4i v);
LADEF V4i v4i_zzyw(V4i v);
LADEF V4i v4i_wzyw(V4i v);
LADEF V4i v4i_xwyw(V4i v);
LADEF V4i v4i_ywyw(V4i v);
LADEF V4i v4i_zwyw(V4i v);
LADEF V4i v4i_wwyw(V4i v);
LADEF V4i v4i_xxzw(V4i v);
LADEF V4i v4i_yxzw(V4i v);
LADEF V4i v4i_zxzw(V4i v);
LADEF V4i v4i_wxzw(V4i v);
LADEF V4i v4i_xyzw(V4i v);
LADEF V4i v4i_yyzw(V4i v);
LADEF V4i v4i_zyzw(V4i v);
LADEF V4i v4i_wyzw(V4i v);
LADEF V4i v4i_xzzw(V4i v);
LADEF V4i v4i_yzzw(V4i v);
LADEF V4i v4i_zzzw(V4i v);
LADEF V4i v4i_wzzw(V4i v);
LADEF V4i v4i_xwzw(V4i v);
LADEF V4i v4i_ywzw(V4i v);
LADEF V4i v4i_zwzw(V4i v);
LADEF V4i v4i_wwzw(V4i v);
LADEF V4i v4i_xxww(V4i v);
LADEF V4i v4i_yxww(V4i v);
LADEF V4i v4i_zxww(V4i v);
LADEF V4i v4i_wxww(V4i v);
LADEF V4i v4i_xyww(V4i v);
LADEF V4i v4i_yyww(V4i v);
LADEF V4i v4i_zyww(V4i v);
LADEF V4i v4i_wyww(V4i v);
LADEF V4i v4i_xzww(V4i v);
LADEF V4i v4i_yzww(V4i v);
LADEF V4i v4i_zzww(V4i v);
LADEF V4i v4i_wzww(V4i v);
LADEF V4i v4i_xwww(V4i v);
LADEF V4i v4i_ywww(V4i v);
LADEF V4i v4i_zwww(V4i v);
LADEF V4i v4i_wwww(V4i v);

LADEF V2u v2u_xx(V2u v);
LADEF V2u v2u_yx(V2u v);
LADEF V2u v2u_xy(V2u v);
LADEF V2u v2u_yy(V2u v);
LADEF V2u v3u_xx(V3u v);
LADEF V2u v3u_yx(V3u v);
LADEF V2u v3u_zx(V3u v);
LADEF V2u v3u_xy(V3u v);
LADEF V2u v3u_yy(V3u v);
LADEF V2u v3u_zy(V3u v);
LADEF V2u v3u_xz(V3u v);
LADEF V2u v3u_yz(V3u v);
LADEF V2u v3u_zz(V3u v);
LADEF V2u v4u_xx(V4u v);
LADEF V2u v4u_yx(V4u v);
LADEF V2u v4u_zx(V4u v);
LADEF V2u v4u_wx(V4u v);
LADEF V2u v4u_xy(V4u v);
LADEF V2u v4u_yy(V4u v);
LADEF V2u v4u_zy(V4u v);
LADEF V2u v4u_wy(V4u v);
LADEF V2u v4u_xz(V4u v);
LADEF V2u v4u_yz(V4u v);
LADEF V2u v4u_zz(V4u v);
LADEF V2u v4u_wz(V4u v);
LADEF V2u v4u_xw(V4u v);
LADEF V2u v4u_yw(V4u v);
LADEF V2u v4u_zw(V4u v);
LADEF V2u v4u_ww(V4u v);

LADEF V3u v2u_xxx(V2u v);
LADEF V3u v2u_yxx(V2u v);
LADEF V3u v2u_xyx(V2u v);
LADEF V3u v2u_yyx(V2u v);
LADEF V3u v2u_xxy(V2u v);
LADEF V3u v2u_yxy(V2u v);
LADEF V3u v2u_xyy(V2u v);
LADEF V3u v2u_yyy(V2u v);
LADEF V3u v3u_xxx(V3u v);
LADEF V3u v3u_yxx(V3u v);
LADEF V3u v3u_zxx(V3u v);
LADEF V3u v3u_xyx(V3u v);
LADEF V3u v3u_yyx(V3u v);
LADEF V3u v3u_zyx(V3u v);
LADEF V3u v3u_xzx(V3u v);
LADEF V3u v3u_yzx(V3u v);
LADEF V3u v3u_zzx(V3u v);
LADEF V3u v3u_xxy(V3u v);
LADEF V3u v3u_yxy(V3u v);
LADEF V3u v3u_zxy(V3u v);
LADEF V3u v3u_xyy(V3u v);
LADEF V3u v3u_yyy(V3u v);
LADEF V3u v3u_zyy(V3u v);
LADEF V3u v3u_xzy(V3u v);
LADEF V3u v3u_yzy(V3u v);
LADEF V3u v3u_zzy(V3u v);
LADEF V3u v3u_xxz(V3u v);
LADEF V3u v3u_yxz(V3u v);
LADEF V3u v3u_zxz(V3u v);
LADEF V3u v3u_xyz(V3u v);
LADEF V3u v3u_yyz(V3u v);
LADEF V3u v3u_zyz(V3u v);
LADEF V3u v3u_xzz(V3u v);
LADEF V3u v3u_yzz(V3u v);
LADEF V3u v3u_zzz(V3u v);
LADEF V3u v4u_xxx(V4u v);
LADEF V3u v4u_yxx(V4u v);
LADEF V3u v4u_zxx(V4u v);
LADEF V3u v4u_wxx(V4u v);
LADEF V3u v4u_xyx(V4u v);
LADEF V3u v4u_yyx(V4u v);
LADEF V3u v4u_zyx(V4u v);
LADEF V3u v4u_wyx(V4u v);
LADEF V3u v4u_xzx(V4u v);
LADEF V3u v4u_yzx(V4u v);
LADEF V3u v4u_zzx(V4u v);
LADEF V3u v4u_wzx(V4u v);
LADEF V3u v4u_xwx(V4u v);
LADEF V3u v4u_ywx(V4u v);
LADEF V3u v4u_zwx(V4u v);
LADEF V3u v4u_wwx(V4u v);
LADEF V3u v4u_xxy(V4u v);
LADEF V3u v4u_yxy(V4u v);
LADEF V3u v4u_zxy(V4u v);
LADEF V3u v4u_wxy(V4u v);
LADEF V3u v4u_xyy(V4u v);
LADEF V3u v4u_yyy(V4u v);
LADEF V3u v4u_zyy(V4u v);
LADEF V3u v4u_wyy(V4u v);
LADEF V3u v4u_xzy(V4u v);
LADEF V3u v4u_yzy(V4u v);
LADEF V3u v4u_zzy(V4u v);
LADEF V3u v4u_wzy(V4u v);
LADEF V3u v4u_xwy(V4u v);
LADEF V3u v4u_ywy(V4u v);
LADEF V3u v4u_zwy(V4u v);
LADEF V3u v4u_wwy(V4u v);
LADEF V3u v4u_xxz(V4u v);
LADEF V3u v4u_yxz(V4u v);
LADEF V3u v4u_zxz(V4u v);
LADEF V3u v4u_wxz(V4u v);
LADEF V3u v4u_xyz(V4u v);
LADEF V3u v4u_yyz(V4u v);
LADEF V3u v4u_zyz(V4u v);
LADEF V3u v4u_wyz(V4u v);
LADEF V3u v4u_xzz(V4u v);
LADEF V3u v4u_yzz(V4u v);
LADEF V3u v4u_zzz(V4u v);
LADEF V3u v4u_wzz(V4u v);
LADEF V3u v4u_xwz(V4u v);
LADEF V3u v4u_ywz(V4u v);
LADEF V3u v4u_zwz(V4u v);
LADEF V3u v4u_wwz(V4u v);
LADEF V3u v4u_xxw(V4u v);
LADEF V3u v4u_yxw(V4u v);
LADEF V3u v4u_zxw(V4u v);
LADEF V3u v4u_wxw(V4u v);
LADEF V3u v4u_xyw(V4u v);
LADEF V3u v4u_yyw(V4u v);
LADEF V3u v4u_zyw(V4u v);
LADEF V3u v4u_wyw(V4u v);
LADEF V3u v4u_xzw(V4u v);
LADEF V3u v4u_yzw(V4u v);
LADEF V3u v4u_zzw(V4u v);
LADEF V3u v4u_wzw(V4u v);
LADEF V3u v4u_xww(V4u v);
LADEF V3u v4u_yww(V4u v);
LADEF V3u v4u_zww(V4u v);
LADEF V3u v4u_www(V4u v);

LADEF V4u v2u_xxxx(V2u v);
LADEF V4u v2u_yxxx(V2u v);
LADEF V4u v2u_xyxx(V2u v);
LADEF V4u v2u_yyxx(V2u v);
LADEF V4u v2u_xxyx(V2u v);
LADEF V4u v2u_yxyx(V2u v);
LADEF V4u v2u_xyyx(V2u v);
LADEF V4u v2u_yyyx(V2u v);
LADEF V4u v2u_xxxy(V2u v);
LADEF V4u v2u_yxxy(V2u v);
LADEF V4u v2u_xyxy(V2u v);
LADEF V4u v2u_yyxy(V2u v);
LADEF V4u v2u_xxyy(V2u v);
LADEF V4u v2u_yxyy(V2u v);
LADEF V4u v2u_xyyy(V2u v);
LADEF V4u v2u_yyyy(V2u v);
LADEF V4u v3u_xxxx(V3u v);
LADEF V4u v3u_yxxx(V3u v);
LADEF V4u v3u_zxxx(V3u v);
LADEF V4u v3u_xyxx(V3u v);
LADEF V4u v3u_yyxx(V3u v);
LADEF V4u v3u_zyxx(V3u v);
LADEF V4u v3u_xzxx(V3u v);
LADEF V4u v3u_yzxx(V3u v);
LADEF V4u v3u_zzxx(V3u v);
LADEF V4u v3u_xxyx(V3u v);
LADEF V4u v3u_yxyx(V3u v);
LADEF V4u v3u_zxyx(V3u v);
LADEF V4u v3u_xyyx(V3u v);
LADEF V4u v3u_yyyx(V3u v);
LADEF V4u v3u_zyyx(V3u v);
LADEF V4u v3u_xzyx(V3u v);
LADEF V4u v3u_yzyx(V3u v);
LADEF V4u v3u_zzyx(V3u v);
LADEF V4u v3u_xxzx(V3u v);
LADEF V4u v3u_yxzx(V3u v);
LADEF V4u v3u_zxzx(V3u v);
LADEF V4u v3u_xyzx(V3u v);
LADEF V4u v3u_yyzx(V3u v);
LADEF V4u v3u_zyzx(V3u v);
LADEF V4u v3u_xzzx(V3u v);
LADEF V4u v3u_yzzx(V3u v);
LADEF V4u v3u_zzzx(V3u v);
LADEF V4u v3u_xxxy(V3u v);
LADEF V4u v3u_yxxy(V3u v);
LADEF V4u v3u_zxxy(V3u v);
LADEF V4u v3u_xyxy(V3u v);
LADEF V4u v3u_yyxy(V3u v);
LADEF V4u v3u_zyxy(V3u v);
LADEF V4u v3u_xzxy(V3u v);
LADEF V4u v3u_yzxy(V3u v);
LADEF V4u v3u_zzxy(V3u v);
LADEF V4u v3u_xxyy(V3u v);
LADEF V4u v3u_yxyy(V3u v);
LADEF V4u v3u_zxyy(V3u v);
LADEF V4u v3u_xyyy(V3u v);
LADEF V4u v3u_yyyy(V3u v);
LADEF V4u v3u_zyyy(V3u v);
LADEF V4u v3u_xzyy(V3u v);
LADEF V4u v3u_yzyy(V3u v);
LADEF V4u v3u_zzyy(V3u v);
LADEF V4u v3u_xxzy(V3u v);
LADEF V4u v3u_yxzy(V3u v);
LADEF V4u v3u_zxzy(V3u v);
LADEF V4u v3u_xyzy(V3u v);
LADEF V4u v3u_yyzy(V3u v);
LADEF V4u v3u_zyzy(V3u v);
LADEF V4u v3u_xzzy(V3u v);
LADEF V4u v3u_yzzy(V3u v);
LADEF V4u v3u_zzzy(V3u v);
LADEF V4u v3u_xxxz(V3u v);
LADEF V4u v3u_yxxz(V3u v);
LADEF V4u v3u_zxxz(V3u v);
LADEF V4u v3u_xyxz(V3u v);
LADEF V4u v3u_yyxz(V3u v);
LADEF V4u v3u_zyxz(V3u v);
LADEF V4u v3u_xzxz(V3u v);
LADEF V4u v3u_yzxz(V3u v);
LADEF V4u v3u_zzxz(V3u v);
LADEF V4u v3u_xxyz(V3u v);
LADEF V4u v3u_yxyz(V3u v);
LADEF V4u v3u_zxyz(V3u v);
LADEF V4u v3u_xyyz(V3u v);
LADEF V4u v3u_yyyz(V3u v);
LADEF V4u v3u_zyyz(V3u v);
LADEF V4u v3u_xzyz(V3u v);
LADEF V4u v3u_yzyz(V3u v);
LADEF V4u v3u_zzyz(V3u v);
LADEF V4u v3u_xxzz(V3u v);
LADEF V4u v3u_yxzz(V3u v);
LADEF V4u v3u_zxzz(V3u v);
LADEF V4u v3u_xyzz(V3u v);
LADEF V4u v3u_yyzz(V3u v);
LADEF V4u v3u_zyzz(V3u v);
LADEF V4u v3u_xzzz(V3u v);
LADEF V4u v3u_yzzz(V3u v);
LADEF V4u v3u_zzzz(V3u v);
LADEF V4u v4u_xxxx(V4u v);
LADEF V4u v4u_yxxx(V4u v);
LADEF V4u v4u_zxxx(V4u v);
LADEF V4u v4u_wxxx(V4u v);
LADEF V4u v4u_xyxx(V4u v);
LADEF V4u v4u_yyxx(V4u v);
LADEF V4u v4u_zyxx(V4u v);
LADEF V4u v4u_wyxx(V4u v);
LADEF V4u v4u_xzxx(V4u v);
LADEF V4u v4u_yzxx(V4u v);
LADEF V4u v4u_zzxx(V4u v);
LADEF V4u v4u_wzxx(V4u v);
LADEF V4u v4u_xwxx(V4u v);
LADEF V4u v4u_ywxx(V4u v);
LADEF V4u v4u_zwxx(V4u v);
LADEF V4u v4u_wwxx(V4u v);
LADEF V4u v4u_xxyx(V4u v);
LADEF V4u v4u_yxyx(V4u v);
LADEF V4u v4u_zxyx(V4u v);
LADEF V4u v4u_wxyx(V4u v);
LADEF V4u v4u_xyyx(V4u v);
LADEF V4u v4u_yyyx(V4u v);
LADEF V4u v4u_zyyx(V4u v);
LADEF V4u v4u_wyyx(V4u v);
LADEF V4u v4u_xzyx(V4u v);
LADEF V4u v4u_yzyx(V4u v);
LADEF V4u v4u_zzyx(V4u v);
LADEF V4u v4u_wzyx(V4u v);
LADEF V4u v4u_xwyx(V4u v);
LADEF V4u v4u_ywyx(V4u v);
LADEF V4u v4u_zwyx(V4u v);
LADEF V4u v4u_wwyx(V4u v);
LADEF V4u v4u_xxzx(V4u v);
LADEF V4u v4u_yxzx(V4u v);
LADEF V4u v4u_zxzx(V4u v);
LADEF V4u v4u_wxzx(V4u v);
LADEF V4u v4u_xyzx(V4u v);
LADEF V4u v4u_yyzx(V4u v);
LADEF V4u v4u_zyzx(V4u v);
LADEF V4u v4u_wyzx(V4u v);
LADEF V4u v4u_xzzx(V4u v);
LADEF V4u v4u_yzzx(V4u v);
LADEF V4u v4u_zzzx(V4u v);
LADEF V4u v4u_wzzx(V4u v);
LADEF V4u v4u_xwzx(V4u v);
LADEF V4u v4u_ywzx(V4u v);
LADEF V4u v4u_zwzx(V4u v);
LADEF V4u v4u_wwzx(V4u v);
LADEF V4u v4u_xxwx(V4u v);
LADEF V4u v4u_yxwx(V4u v);
LADEF V4u v4u_zxwx(V4u v);
LADEF V4u v4u_wxwx(V4u v);
LADEF V4u v4u_xywx(V4u v);
LADEF V4u v4u_yywx(V4u v);
LADEF V4u v4u_zywx(V4u v);
LADEF V4u v4u_wywx(V4u v);
LADEF V4u v4u_xzwx(V4u v);
LADEF V4u v4u_yzwx(V4u v);
LADEF V4u v4u_zzwx(V4u v);
LADEF V4u v4u_wzwx(V4u v);
LADEF V4u v4u_xwwx(V4u v);
LADEF V4u v4u_ywwx(V4u v);
LADEF V4u v4u_zwwx(V4u v);
LADEF V4u v4u_wwwx(V4u v);
LADEF V4u v4u_xxxy(V4u v);
LADEF V4u v4u_yxxy(V4u v);
LADEF V4u v4u_zxxy(V4u v);
LADEF V4u v4u_wxxy(V4u v);
LADEF V4u v4u_xyxy(V4u v);
LADEF V4u v4u_yyxy(V4u v);
LADEF V4u v4u_zyxy(V4u v);
LADEF V4u v4u_wyxy(V4u v);
LADEF V4u v4u_xzxy(V4u v);
LADEF V4u v4u_yzxy(V4u v);
LADEF V4u v4u_zzxy(V4u v);
LADEF V4u v4u_wzxy(V4u v);
LADEF V4u v4u_xwxy(V4u v);
LADEF V4u v4u_ywxy(V4u v);
LADEF V4u v4u_zwxy(V4u v);
LADEF V4u v4u_wwxy(V4u v);
LADEF V4u v4u_xxyy(V4u v);
LADEF V4u v4u_yxyy(V4u v);
LADEF V4u v4u_zxyy(V4u v);
LADEF V4u v4u_wxyy(V4u v);
LADEF V4u v4u_xyyy(V4u v);
LADEF V4u v4u_yyyy(V4u v);
LADEF V4u v4u_zyyy(V4u v);
LADEF V4u v4u_wyyy(V4u v);
LADEF V4u v4u_xzyy(V4u v);
LADEF V4u v4u_yzyy(V4u v);
LADEF V4u v4u_zzyy(V4u v);
LADEF V4u v4u_wzyy(V4u v);
LADEF V4u v4u_xwyy(V4u v);
LADEF V4u v4u_ywyy(V4u v);
LADEF V4u v4u_zwyy(V4u v);
LADEF V4u v4u_wwyy(V4u v);
LADEF V4u v4u_xxzy(V4u v);
LADEF V4u v4u_yxzy(V4u v);
LADEF V4u v4u_zxzy(V4u v);
LADEF V4u v4u_wxzy(V4u v);
LADEF V4u v4u_xyzy(V4u v);
LADEF V4u v4u_yyzy(V4u v);
LADEF V4u v4u_zyzy(V4u v);
LADEF V4u v4u_wyzy(V4u v);
LADEF V4u v4u_xzzy(V4u v);
LADEF V4u v4u_yzzy(V4u v);
LADEF V4u v4u_zzzy(V4u v);
LADEF V4u v4u_wzzy(V4u v);
LADEF V4u v4u_xwzy(V4u v);
LADEF V4u v4u_ywzy(V4u v);
LADEF V4u v4u_zwzy(V4u v);
LADEF V4u v4u_wwzy(V4u v);
LADEF V4u v4u_xxwy(V4u v);
LADEF V4u v4u_yxwy(V4u v);
LADEF V4u v4u_zxwy(V4u v);
LADEF V4u v4u_wxwy(V4u v);
LADEF V4u v4u_xywy(V4u v);
LADEF V4u v4u_yywy(V4u v);
LADEF V4u v4u_zywy(V4u v);
LADEF V4u v4u_wywy(V4u v);
LADEF V4u v4u_xzwy(V4u v);
LADEF V4u v4u_yzwy(V4u v);
LADEF V4u v4u_zzwy(V4u v);
LADEF V4u v4u_wzwy(V4u v);
LADEF V4u v4u_xwwy(V4u v);
LADEF V4u v4u_ywwy(V4u v);
LADEF V4u v4u_zwwy(V4u v);
LADEF V4u v4u_wwwy(V4u v);
LADEF V4u v4u_xxxz(V4u v);
LADEF V4u v4u_yxxz(V4u v);
LADEF V4u v4u_zxxz(V4u v);
LADEF V4u v4u_wxxz(V4u v);
LADEF V4u v4u_xyxz(V4u v);
LADEF V4u v4u_yyxz(V4u v);
LADEF V4u v4u_zyxz(V4u v);
LADEF V4u v4u_wyxz(V4u v);
LADEF V4u v4u_xzxz(V4u v);
LADEF V4u v4u_yzxz(V4u v);
LADEF V4u v4u_zzxz(V4u v);
LADEF V4u v4u_wzxz(V4u v);
LADEF V4u v4u_xwxz(V4u v);
LADEF V4u v4u_ywxz(V4u v);
LADEF V4u v4u_zwxz(V4u v);
LADEF V4u v4u_wwxz(V4u v);
LADEF V4u v4u_xxyz(V4u v);
LADEF V4u v4u_yxyz(V4u v);
LADEF V4u v4u_zxyz(V4u v);
LADEF V4u v4u_wxyz(V4u v);
LADEF V4u v4u_xyyz(V4u v);
LADEF V4u v4u_yyyz(V4u v);
LADEF V4u v4u_zyyz(V4u v);
LADEF V4u v4u_wyyz(V4u v);
LADEF V4u v4u_xzyz(V4u v);
LADEF V4u v4u_yzyz(V4u v);
LADEF V4u v4u_zzyz(V4u v);
LADEF V4u v4u_wzyz(V4u v);
LADEF V4u v4u_xwyz(V4u v);
LADEF V4u v4u_ywyz(V4u v);
LADEF V4u v4u_zwyz(V4u v);
LADEF V4u v4u_wwyz(V4u v);
LADEF V4u v4u_xxzz(V4u v);
LADEF V4u v4u_yxzz(V4u v);
LADEF V4u v4u_zxzz(V4u v);
LADEF V4u v4u_wxzz(V4u v);
LADEF V4u v4u_xyzz(V4u v);
LADEF V4u v4u_yyzz(V4u v);
LADEF V4u v4u_zyzz(V4u v);
LADEF V4u v4u_wyzz(V4u v);
LADEF V4u v4u_xzzz(V4u v);
LADEF V4u v4u_yzzz(V4u v);
LADEF V4u v4u_zzzz(V4u v);
LADEF V4u v4u_wzzz(V4u v);
LADEF V4u v4u_xwzz(V4u v);
LADEF V4u v4u_ywzz(V4u v);
LADEF V4u v4u_zwzz(V4u v);
LADEF V4u v4u_wwzz(V4u v);
LADEF V4u v4u_xxwz(V4u v);
LADEF V4u v4u_yxwz(V4u v);
LADEF V4u v4u_zxwz(V4u v);
LADEF V4u v4u_wxwz(V4u v);
LADEF V4u v4u_xywz(V4u v);
LADEF V4u v4u_yywz(V4u v);
LADEF V4u v4u_zywz(V4u v);
LADEF V4u v4u_wywz(V4u v);
LADEF V4u v4u_xzwz(V4u v);
LADEF V4u v4u_yzwz(V4u v);
LADEF V4u v4u_zzwz(V4u v);
LADEF V4u v4u_wzwz(V4u v);
LADEF V4u v4u_xwwz(V4u v);
LADEF V4u v4u_ywwz(V4u v);
LADEF V4u v4u_zwwz(V4u v);
LADEF V4u v4u_wwwz(V4u v);
LADEF V4u v4u_xxxw(V4u v);
LADEF V4u v4u_yxxw(V4u v);
LADEF V4u v4u_zxxw(V4u v);
LADEF V4u v4u_wxxw(V4u v);
LADEF V4u v4u_xyxw(V4u v);
LADEF V4u v4u_yyxw(V4u v);
LADEF V4u v4u_zyxw(V4u v);
LADEF V4u v4u_wyxw(V4u v);
LADEF V4u v4u_xzxw(V4u v);
LADEF V4u v4u_yzxw(V4u v);
LADEF V4u v4u_zzxw(V4u v);
LADEF V4u v4u_wzxw(V4u v);
LADEF V4u v4u_xwxw(V4u v);
LADEF V4u v4u_ywxw(V4u v);
LADEF V4u v4u_zwxw(V4u v);
LADEF V4u v4u_wwxw(V4u v);
LADEF V4u v4u_xxyw(V4u v);
LADEF V4u v4u_yxyw(V4u v);
LADEF V4u v4u_zxyw(V4u v);
LADEF V4u v4u_wxyw(V4u v);
LADEF V4u v4u_xyyw(V4u v);
LADEF V4u v4u_yyyw(V4u v);
LADEF V4u v4u_zyyw(V4u v);
LADEF V4u v4u_wyyw(V4u v);
LADEF V4u v4u_xzyw(V4u v);
LADEF V4u v4u_yzyw(V4u v);
LADEF V4u v4u_zzyw(V4u v);
LADEF V4u v4u_wzyw(V4u v);
LADEF V4u v4u_xwyw(V4u v);
LADEF V4u v4u_ywyw(V4u v);
LADEF V4u v4u_zwyw(V4u v);
LADEF V4u v4u_wwyw(V4u v);
LADEF V4u v4u_xxzw(V4u v);
LADEF V4u v4u_yxzw(V4u v);
LADEF V4u v4u_zxzw(V4u v);
LADEF V4u v4u_wxzw(V4u v);
LADEF V4u v4u_xyzw(V4u v);
LADEF V4u v4u_yyzw(V4u v);
LADEF V4u v4u_zyzw(V4u v);
LADEF V4u v4u_wyzw(V4u v);
LADEF V4u v4u_xzzw(V4u v);
LADEF V4u v4u_yzzw(V4u v);
LADEF V4u v4u_zzzw(V4u v);
LADEF V4u v4u_wzzw(V4u v);
LADEF V4u v4u_xwzw(V4u v);
LADEF V4u v4u_ywzw(V4u v);
LADEF V4u v4u_zwzw(V4u v);
LADEF V4u v4u_wwzw(V4u v);
LADEF V4u v4u_xxww(V4u v);
LADEF V4u v4u_yxww(V4u v);
LADEF V4u v4u_zxww(V4u v);
LADEF V4u v4u_wxww(V4u v);
LADEF V4u v4u_xyww(V4u v);
LADEF V4u v4u_yyww(V4u v);
LADEF V4u v4u_zyww(V4u v);
LADEF V4u v4u_wyww(V4u v);
LADEF V4u v4u_xzww(V4u v);
LADEF V4u v4u_yzww(V4u v);
LADEF V4u v4u_zzww(V4u v);
LADEF V4u v4u_wzww(V4u v);
LADEF V4u v4u_xwww(V4u v);
LADEF V4u v4u_ywww(V4u v);
LADEF V4u v4u_zwww(V4u v);
LADEF V4u v4u_wwww(V4u v);

#endif // LA_H_

#ifdef LA_IMPLEMENTATION

LADEF float lerpf(float a, float b, float t)
{
    return a + (b - a) * t;
}

LADEF double lerp(double a, double b, double t)
{
    return a + (b - a) * t;
}

LADEF int mini(int a, int b)
{
    return a < b ? a : b;
}

LADEF unsigned int minu(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

LADEF int maxi(int a, int b)
{
    return a > b ? a : b;
}

LADEF unsigned int maxu(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

LADEF float clampf(float x, float a, float b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF double clampd(double x, double a, double b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF int clampi(int x, int a, int b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF unsigned int clampu(unsigned int x, unsigned int a, unsigned int b)
{
    if (x < a) x = a;
    if (x > b) x = b;
    return x;
}

LADEF V2f v2f(float x, float y)
{
    V2f v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2f v2ff(float x)
{
    return v2f(x, x);
}


LADEF V2f v2d_2f(V2d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f2d(V2d a) { return v2d_2f(a); }

LADEF V2f v2i_2f(V2i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f2i(V2i a) { return v2i_2f(a); }

LADEF V2f v2u_2f(V2u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f2u(V2u a) { return v2u_2f(a); }

LADEF V2f v3f_2f(V3f a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f3f(V3f a) { return v3f_2f(a); }

LADEF V2f v3d_2f(V3d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f3d(V3d a) { return v3d_2f(a); }

LADEF V2f v3i_2f(V3i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f3i(V3i a) { return v3i_2f(a); }

LADEF V2f v3u_2f(V3u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f3u(V3u a) { return v3u_2f(a); }

LADEF V2f v4f_2f(V4f a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f4f(V4f a) { return v4f_2f(a); }

LADEF V2f v4d_2f(V4d a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f4d(V4d a) { return v4d_2f(a); }

LADEF V2f v4i_2f(V4i a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f4i(V4i a) { return v4i_2f(a); }

LADEF V2f v4u_2f(V4u a)
{
    V2f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    return result;
}
LADEF V2f v2f4u(V4u a) { return v4u_2f(a); }

LADEF V2f v2f_sum(V2f a, V2f b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2f v2f_add(V2f a, V2f b)
{
    return v2f_sum(a, b);
}

LADEF V2f v2f_sub(V2f a, V2f b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2f v2f_mul(V2f a, V2f b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2f v2f_div(V2f a, V2f b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2f v2f_mod(V2f a, V2f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    return a;
}

LADEF V2f v2f_sqrt(V2f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    return a;
}

LADEF V2f v2f_pow(V2f base, V2f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    return base;
}

LADEF V2f v2f_sin(V2f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    return a;
}

LADEF V2f v2f_cos(V2f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    return a;
}

LADEF V2f v2f_min(V2f a, V2f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    return a;
}

LADEF V2f v2f_max(V2f a, V2f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    return a;
}

LADEF V2f v2f_lerp(V2f a, V2f b, V2f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    return a;
}

LADEF V2f v2f_floor(V2f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    return a;
}

LADEF V2f v2f_ceil(V2f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    return a;
}

LADEF V2f v2f_clamp(V2f x, V2f a, V2f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    return x;
}

LADEF float v2f_sqrlen(V2f a)
{
    return v2f_dot(a, a);
}

LADEF float v2f_len(V2f a)
{
    return sqrtf(v2f_sqrlen(a));
}

LADEF float v2f_dot(V2f a, V2f b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2f v2f_norm(V2f a, float eps, V2f fallback)
{
    float l = v2f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v2f_div(a, v2ff(l));
}

LADEF bool v2f_eq(V2f a, V2f b, float eps)
{
    if (fabsf(b.x - a.x) > eps) return false;
    if (fabsf(b.y - a.y) > eps) return false;
    return true;
}

LADEF V2f v2f_reflect(V2f i, V2f n)
{
    V2f r = n;
    r = v2f_mul(r, v2ff(v2f_dot(n, i)));
    r = v2f_mul(r, v2ff(2));
    r = v2f_sub(i, r);
    return r;
}

LADEF M2f m2f_id(void)
{
    M2f m = m2f_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2f m2f_zero(void)
{
    M2f m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2f m2f_mul(M2f a, M2f b)
{
    M2f m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2f m2f_mul_vec(M2f m, V2f v)
{
    V2f r;
    r.x = v2f_dot(m.v[0], v);
    r.y = v2f_dot(m.v[1], v);
    return r;
}

LADEF M2f m2f_rot(float angle)
{
    M2f m;
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
}

LADEF V2d v2d(double x, double y)
{
    V2d v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2d v2dd(double x)
{
    return v2d(x, x);
}

LADEF V2d v2f_2d(V2f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d2f(V2f a) { return v2f_2d(a); }


LADEF V2d v2i_2d(V2i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d2i(V2i a) { return v2i_2d(a); }

LADEF V2d v2u_2d(V2u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d2u(V2u a) { return v2u_2d(a); }

LADEF V2d v3f_2d(V3f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d3f(V3f a) { return v3f_2d(a); }

LADEF V2d v3d_2d(V3d a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d3d(V3d a) { return v3d_2d(a); }

LADEF V2d v3i_2d(V3i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d3i(V3i a) { return v3i_2d(a); }

LADEF V2d v3u_2d(V3u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d3u(V3u a) { return v3u_2d(a); }

LADEF V2d v4f_2d(V4f a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d4f(V4f a) { return v4f_2d(a); }

LADEF V2d v4d_2d(V4d a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d4d(V4d a) { return v4d_2d(a); }

LADEF V2d v4i_2d(V4i a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d4i(V4i a) { return v4i_2d(a); }

LADEF V2d v4u_2d(V4u a)
{
    V2d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    return result;
}
LADEF V2d v2d4u(V4u a) { return v4u_2d(a); }

LADEF V2d v2d_sum(V2d a, V2d b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2d v2d_add(V2d a, V2d b)
{
    return v2d_sum(a, b);
}

LADEF V2d v2d_sub(V2d a, V2d b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2d v2d_mul(V2d a, V2d b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2d v2d_div(V2d a, V2d b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2d v2d_mod(V2d a, V2d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    return a;
}

LADEF V2d v2d_sqrt(V2d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    return a;
}

LADEF V2d v2d_pow(V2d base, V2d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    return base;
}

LADEF V2d v2d_sin(V2d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    return a;
}

LADEF V2d v2d_cos(V2d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    return a;
}

LADEF V2d v2d_min(V2d a, V2d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    return a;
}

LADEF V2d v2d_max(V2d a, V2d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    return a;
}

LADEF V2d v2d_lerp(V2d a, V2d b, V2d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    return a;
}

LADEF V2d v2d_floor(V2d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    return a;
}

LADEF V2d v2d_ceil(V2d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    return a;
}

LADEF V2d v2d_clamp(V2d x, V2d a, V2d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    return x;
}

LADEF double v2d_sqrlen(V2d a)
{
    return v2d_dot(a, a);
}

LADEF double v2d_len(V2d a)
{
    return sqrt(v2d_sqrlen(a));
}

LADEF double v2d_dot(V2d a, V2d b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF V2d v2d_norm(V2d a, double eps, V2d fallback)
{
    double l = v2d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v2d_div(a, v2dd(l));
}

LADEF bool v2d_eq(V2d a, V2d b, double eps)
{
    if (fabs(b.x - a.x) > eps) return false;
    if (fabs(b.y - a.y) > eps) return false;
    return true;
}

LADEF V2d v2d_reflect(V2d i, V2d n)
{
    V2d r = n;
    r = v2d_mul(r, v2dd(v2d_dot(n, i)));
    r = v2d_mul(r, v2dd(2));
    r = v2d_sub(i, r);
    return r;
}

LADEF M2d m2d_id(void)
{
    M2d m = m2d_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2d m2d_zero(void)
{
    M2d m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2d m2d_mul(M2d a, M2d b)
{
    M2d m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2d m2d_mul_vec(M2d m, V2d v)
{
    V2d r;
    r.x = v2d_dot(m.v[0], v);
    r.y = v2d_dot(m.v[1], v);
    return r;
}

LADEF M2d m2d_rot(double angle)
{
    M2d m;
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
}

LADEF V2i v2i(int x, int y)
{
    V2i v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2i v2ii(int x)
{
    return v2i(x, x);
}

LADEF V2i v2f_2i(V2f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i2f(V2f a) { return v2f_2i(a); }

LADEF V2i v2d_2i(V2d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i2d(V2d a) { return v2d_2i(a); }


LADEF V2i v2u_2i(V2u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i2u(V2u a) { return v2u_2i(a); }

LADEF V2i v3f_2i(V3f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i3f(V3f a) { return v3f_2i(a); }

LADEF V2i v3d_2i(V3d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i3d(V3d a) { return v3d_2i(a); }

LADEF V2i v3i_2i(V3i a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i3i(V3i a) { return v3i_2i(a); }

LADEF V2i v3u_2i(V3u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i3u(V3u a) { return v3u_2i(a); }

LADEF V2i v4f_2i(V4f a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i4f(V4f a) { return v4f_2i(a); }

LADEF V2i v4d_2i(V4d a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i4d(V4d a) { return v4d_2i(a); }

LADEF V2i v4i_2i(V4i a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i4i(V4i a) { return v4i_2i(a); }

LADEF V2i v4u_2i(V4u a)
{
    V2i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    return result;
}
LADEF V2i v2i4u(V4u a) { return v4u_2i(a); }

LADEF V2i v2i_sum(V2i a, V2i b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2i v2i_add(V2i a, V2i b)
{
    return v2i_sum(a, b);
}

LADEF V2i v2i_sub(V2i a, V2i b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2i v2i_mul(V2i a, V2i b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2i v2i_div(V2i a, V2i b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2i v2i_mod(V2i a, V2i b)
{
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

LADEF V2i v2i_min(V2i a, V2i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    return a;
}

LADEF V2i v2i_max(V2i a, V2i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    return a;
}

LADEF V2i v2i_clamp(V2i x, V2i a, V2i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    return x;
}

LADEF int v2i_sqrlen(V2i a)
{
    return v2i_dot(a, a);
}

LADEF int v2i_dot(V2i a, V2i b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF bool v2i_eq(V2i a, V2i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    return true;
}

LADEF V2i v2i_reflect(V2i i, V2i n)
{
    V2i r = n;
    r = v2i_mul(r, v2ii(v2i_dot(n, i)));
    r = v2i_mul(r, v2ii(2));
    r = v2i_sub(i, r);
    return r;
}

LADEF M2i m2i_id(void)
{
    M2i m = m2i_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2i m2i_zero(void)
{
    M2i m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2i m2i_mul(M2i a, M2i b)
{
    M2i m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2i m2i_mul_vec(M2i m, V2i v)
{
    V2i r;
    r.x = v2i_dot(m.v[0], v);
    r.y = v2i_dot(m.v[1], v);
    return r;
}

LADEF V2u v2u(unsigned int x, unsigned int y)
{
    V2u v;
    v.x = x;
    v.y = y;
    return v;
}

LADEF V2u v2uu(unsigned int x)
{
    return v2u(x, x);
}

LADEF V2u v2f_2u(V2f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u2f(V2f a) { return v2f_2u(a); }

LADEF V2u v2d_2u(V2d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u2d(V2d a) { return v2d_2u(a); }

LADEF V2u v2i_2u(V2i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u2i(V2i a) { return v2i_2u(a); }


LADEF V2u v3f_2u(V3f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u3f(V3f a) { return v3f_2u(a); }

LADEF V2u v3d_2u(V3d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u3d(V3d a) { return v3d_2u(a); }

LADEF V2u v3i_2u(V3i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u3i(V3i a) { return v3i_2u(a); }

LADEF V2u v3u_2u(V3u a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u3u(V3u a) { return v3u_2u(a); }

LADEF V2u v4f_2u(V4f a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u4f(V4f a) { return v4f_2u(a); }

LADEF V2u v4d_2u(V4d a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u4d(V4d a) { return v4d_2u(a); }

LADEF V2u v4i_2u(V4i a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u4i(V4i a) { return v4i_2u(a); }

LADEF V2u v4u_2u(V4u a)
{
    V2u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    return result;
}
LADEF V2u v2u4u(V4u a) { return v4u_2u(a); }

LADEF V2u v2u_sum(V2u a, V2u b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}

LADEF V2u v2u_add(V2u a, V2u b)
{
    return v2u_sum(a, b);
}

LADEF V2u v2u_sub(V2u a, V2u b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}

LADEF V2u v2u_mul(V2u a, V2u b)
{
    a.x *= b.x;
    a.y *= b.y;
    return a;
}

LADEF V2u v2u_div(V2u a, V2u b)
{
    a.x /= b.x;
    a.y /= b.y;
    return a;
}

LADEF V2u v2u_mod(V2u a, V2u b)
{
    a.x %= b.x;
    a.y %= b.y;
    return a;
}

LADEF V2u v2u_min(V2u a, V2u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    return a;
}

LADEF V2u v2u_max(V2u a, V2u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    return a;
}

LADEF V2u v2u_clamp(V2u x, V2u a, V2u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    return x;
}

LADEF unsigned int v2u_sqrlen(V2u a)
{
    return v2u_dot(a, a);
}

LADEF unsigned int v2u_dot(V2u a, V2u b)
{
    return a.x*b.x + a.y*b.y;
}

LADEF bool v2u_eq(V2u a, V2u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    return true;
}

LADEF V2u v2u_reflect(V2u i, V2u n)
{
    V2u r = n;
    r = v2u_mul(r, v2uu(v2u_dot(n, i)));
    r = v2u_mul(r, v2uu(2));
    r = v2u_sub(i, r);
    return r;
}

LADEF M2u m2u_id(void)
{
    M2u m = m2u_zero();
    m._11 = 1;
    m._22 = 1;
    return m;
}

LADEF M2u m2u_zero(void)
{
    M2u m = {
        ._11=0,._12=0,
        ._21=0,._22=0,
    };
    return m;
}

LADEF M2u m2u_mul(M2u a, M2u b)
{
    M2u m;
    m._11 = a._11*b._11 + a._12*b._21;
    m._12 = a._11*b._12 + a._12*b._22;
    m._21 = a._21*b._11 + a._22*b._21;
    m._22 = a._21*b._12 + a._22*b._22;
    return m;
}

LADEF V2u m2u_mul_vec(M2u m, V2u v)
{
    V2u r;
    r.x = v2u_dot(m.v[0], v);
    r.y = v2u_dot(m.v[1], v);
    return r;
}

LADEF V3f v3f(float x, float y, float z)
{
    V3f v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3f v3ff(float x)
{
    return v3f(x, x, x);
}

LADEF V3f v2f_3f(V2f a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}
LADEF V3f v3f2f(V2f a) { return v2f_3f(a); }

LADEF V3f v2d_3f(V2d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}
LADEF V3f v3f2d(V2d a) { return v2d_3f(a); }

LADEF V3f v2i_3f(V2i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}
LADEF V3f v3f2i(V2i a) { return v2i_3f(a); }

LADEF V3f v2u_3f(V2u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    return result;
}
LADEF V3f v3f2u(V2u a) { return v2u_3f(a); }


LADEF V3f v3d_3f(V3d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f3d(V3d a) { return v3d_3f(a); }

LADEF V3f v3i_3f(V3i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f3i(V3i a) { return v3i_3f(a); }

LADEF V3f v3u_3f(V3u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f3u(V3u a) { return v3u_3f(a); }

LADEF V3f v4f_3f(V4f a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f4f(V4f a) { return v4f_3f(a); }

LADEF V3f v4d_3f(V4d a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f4d(V4d a) { return v4d_3f(a); }

LADEF V3f v4i_3f(V4i a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f4i(V4i a) { return v4i_3f(a); }

LADEF V3f v4u_3f(V4u a)
{
    V3f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    return result;
}
LADEF V3f v3f4u(V4u a) { return v4u_3f(a); }

LADEF V3f v3f_sum(V3f a, V3f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3f v3f_add(V3f a, V3f b)
{
    return v3f_sum(a, b);
}

LADEF V3f v3f_sub(V3f a, V3f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3f v3f_mul(V3f a, V3f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3f v3f_div(V3f a, V3f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3f v3f_mod(V3f a, V3f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    a.z = fmodf(a.z, b.z);
    return a;
}

LADEF V3f v3f_sqrt(V3f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    return a;
}

LADEF V3f v3f_pow(V3f base, V3f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    return base;
}

LADEF V3f v3f_sin(V3f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    return a;
}

LADEF V3f v3f_cos(V3f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    return a;
}

LADEF V3f v3f_min(V3f a, V3f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    return a;
}

LADEF V3f v3f_max(V3f a, V3f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    return a;
}

LADEF V3f v3f_lerp(V3f a, V3f b, V3f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    return a;
}

LADEF V3f v3f_floor(V3f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    return a;
}

LADEF V3f v3f_ceil(V3f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    return a;
}

LADEF V3f v3f_clamp(V3f x, V3f a, V3f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    x.z = clampf(x.z, a.z, b.z);
    return x;
}

LADEF float v3f_sqrlen(V3f a)
{
    return v3f_dot(a, a);
}

LADEF float v3f_len(V3f a)
{
    return sqrtf(v3f_sqrlen(a));
}

LADEF float v3f_dot(V3f a, V3f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3f v3f_norm(V3f a, float eps, V3f fallback)
{
    float l = v3f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v3f_div(a, v3ff(l));
}

LADEF V3f v3f_cross(V3f a, V3f b)
{
    V3f n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3f_eq(V3f a, V3f b, float eps)
{
    if (fabsf(b.x - a.x) > eps) return false;
    if (fabsf(b.y - a.y) > eps) return false;
    if (fabsf(b.z - a.z) > eps) return false;
    return true;
}

LADEF V3f v3f_reflect(V3f i, V3f n)
{
    V3f r = n;
    r = v3f_mul(r, v3ff(v3f_dot(n, i)));
    r = v3f_mul(r, v3ff(2));
    r = v3f_sub(i, r);
    return r;
}

LADEF M3f m3f_id(void)
{
    M3f m = m3f_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3f m3f_zero(void)
{
    M3f m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3f m3f_mul(M3f a, M3f b)
{
    M3f m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3f m3f_mul_vec(M3f m, V3f v)
{
    V3f r;
    r.x = v3f_dot(m.v[0], v);
    r.y = v3f_dot(m.v[1], v);
    r.z = v3f_dot(m.v[2], v);
    return r;
}

LADEF M3f m3f_rot_x(float angle)
{
    M3f m = m3f_id();
    m._22 = cosf(angle);
    m._23 = -sinf(angle);
    m._32 = sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M3f m3f_rot_y(float angle)
{
    M3f m = m3f_id();
    m._11 = cosf(angle);
    m._13 = sinf(angle);
    m._31 = -sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M3f m3f_rot_z(float angle)
{
    M3f m = m3f_id();
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
}

LADEF V3d v3d(double x, double y, double z)
{
    V3d v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3d v3dd(double x)
{
    return v3d(x, x, x);
}

LADEF V3d v2f_3d(V2f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}
LADEF V3d v3d2f(V2f a) { return v2f_3d(a); }

LADEF V3d v2d_3d(V2d a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}
LADEF V3d v3d2d(V2d a) { return v2d_3d(a); }

LADEF V3d v2i_3d(V2i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}
LADEF V3d v3d2i(V2i a) { return v2i_3d(a); }

LADEF V3d v2u_3d(V2u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    return result;
}
LADEF V3d v3d2u(V2u a) { return v2u_3d(a); }

LADEF V3d v3f_3d(V3f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d3f(V3f a) { return v3f_3d(a); }


LADEF V3d v3i_3d(V3i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d3i(V3i a) { return v3i_3d(a); }

LADEF V3d v3u_3d(V3u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d3u(V3u a) { return v3u_3d(a); }

LADEF V3d v4f_3d(V4f a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d4f(V4f a) { return v4f_3d(a); }

LADEF V3d v4d_3d(V4d a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d4d(V4d a) { return v4d_3d(a); }

LADEF V3d v4i_3d(V4i a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d4i(V4i a) { return v4i_3d(a); }

LADEF V3d v4u_3d(V4u a)
{
    V3d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    return result;
}
LADEF V3d v3d4u(V4u a) { return v4u_3d(a); }

LADEF V3d v3d_sum(V3d a, V3d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3d v3d_add(V3d a, V3d b)
{
    return v3d_sum(a, b);
}

LADEF V3d v3d_sub(V3d a, V3d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3d v3d_mul(V3d a, V3d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3d v3d_div(V3d a, V3d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3d v3d_mod(V3d a, V3d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    a.z = fmod(a.z, b.z);
    return a;
}

LADEF V3d v3d_sqrt(V3d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    return a;
}

LADEF V3d v3d_pow(V3d base, V3d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    return base;
}

LADEF V3d v3d_sin(V3d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    return a;
}

LADEF V3d v3d_cos(V3d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    return a;
}

LADEF V3d v3d_min(V3d a, V3d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    return a;
}

LADEF V3d v3d_max(V3d a, V3d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    return a;
}

LADEF V3d v3d_lerp(V3d a, V3d b, V3d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    return a;
}

LADEF V3d v3d_floor(V3d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    return a;
}

LADEF V3d v3d_ceil(V3d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    return a;
}

LADEF V3d v3d_clamp(V3d x, V3d a, V3d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    x.z = clampd(x.z, a.z, b.z);
    return x;
}

LADEF double v3d_sqrlen(V3d a)
{
    return v3d_dot(a, a);
}

LADEF double v3d_len(V3d a)
{
    return sqrt(v3d_sqrlen(a));
}

LADEF double v3d_dot(V3d a, V3d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3d v3d_norm(V3d a, double eps, V3d fallback)
{
    double l = v3d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v3d_div(a, v3dd(l));
}

LADEF V3d v3d_cross(V3d a, V3d b)
{
    V3d n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3d_eq(V3d a, V3d b, double eps)
{
    if (fabs(b.x - a.x) > eps) return false;
    if (fabs(b.y - a.y) > eps) return false;
    if (fabs(b.z - a.z) > eps) return false;
    return true;
}

LADEF V3d v3d_reflect(V3d i, V3d n)
{
    V3d r = n;
    r = v3d_mul(r, v3dd(v3d_dot(n, i)));
    r = v3d_mul(r, v3dd(2));
    r = v3d_sub(i, r);
    return r;
}

LADEF M3d m3d_id(void)
{
    M3d m = m3d_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3d m3d_zero(void)
{
    M3d m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3d m3d_mul(M3d a, M3d b)
{
    M3d m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3d m3d_mul_vec(M3d m, V3d v)
{
    V3d r;
    r.x = v3d_dot(m.v[0], v);
    r.y = v3d_dot(m.v[1], v);
    r.z = v3d_dot(m.v[2], v);
    return r;
}

LADEF M3d m3d_rot_x(double angle)
{
    M3d m = m3d_id();
    m._22 = cos(angle);
    m._23 = -sin(angle);
    m._32 = sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M3d m3d_rot_y(double angle)
{
    M3d m = m3d_id();
    m._11 = cos(angle);
    m._13 = sin(angle);
    m._31 = -sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M3d m3d_rot_z(double angle)
{
    M3d m = m3d_id();
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
}

LADEF V3i v3i(int x, int y, int z)
{
    V3i v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3i v3ii(int x)
{
    return v3i(x, x, x);
}

LADEF V3i v2f_3i(V2f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}
LADEF V3i v3i2f(V2f a) { return v2f_3i(a); }

LADEF V3i v2d_3i(V2d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}
LADEF V3i v3i2d(V2d a) { return v2d_3i(a); }

LADEF V3i v2i_3i(V2i a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}
LADEF V3i v3i2i(V2i a) { return v2i_3i(a); }

LADEF V3i v2u_3i(V2u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    return result;
}
LADEF V3i v3i2u(V2u a) { return v2u_3i(a); }

LADEF V3i v3f_3i(V3f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i3f(V3f a) { return v3f_3i(a); }

LADEF V3i v3d_3i(V3d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i3d(V3d a) { return v3d_3i(a); }


LADEF V3i v3u_3i(V3u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i3u(V3u a) { return v3u_3i(a); }

LADEF V3i v4f_3i(V4f a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i4f(V4f a) { return v4f_3i(a); }

LADEF V3i v4d_3i(V4d a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i4d(V4d a) { return v4d_3i(a); }

LADEF V3i v4i_3i(V4i a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i4i(V4i a) { return v4i_3i(a); }

LADEF V3i v4u_3i(V4u a)
{
    V3i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    return result;
}
LADEF V3i v3i4u(V4u a) { return v4u_3i(a); }

LADEF V3i v3i_sum(V3i a, V3i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3i v3i_add(V3i a, V3i b)
{
    return v3i_sum(a, b);
}

LADEF V3i v3i_sub(V3i a, V3i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3i v3i_mul(V3i a, V3i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3i v3i_div(V3i a, V3i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3i v3i_mod(V3i a, V3i b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    return a;
}

LADEF V3i v3i_min(V3i a, V3i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    a.z = mini(a.z, b.z);
    return a;
}

LADEF V3i v3i_max(V3i a, V3i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    a.z = maxi(a.z, b.z);
    return a;
}

LADEF V3i v3i_clamp(V3i x, V3i a, V3i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    x.z = clampi(x.z, a.z, b.z);
    return x;
}

LADEF int v3i_sqrlen(V3i a)
{
    return v3i_dot(a, a);
}

LADEF int v3i_dot(V3i a, V3i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3i v3i_cross(V3i a, V3i b)
{
    V3i n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3i_eq(V3i a, V3i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    return true;
}

LADEF V3i v3i_reflect(V3i i, V3i n)
{
    V3i r = n;
    r = v3i_mul(r, v3ii(v3i_dot(n, i)));
    r = v3i_mul(r, v3ii(2));
    r = v3i_sub(i, r);
    return r;
}

LADEF M3i m3i_id(void)
{
    M3i m = m3i_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3i m3i_zero(void)
{
    M3i m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3i m3i_mul(M3i a, M3i b)
{
    M3i m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3i m3i_mul_vec(M3i m, V3i v)
{
    V3i r;
    r.x = v3i_dot(m.v[0], v);
    r.y = v3i_dot(m.v[1], v);
    r.z = v3i_dot(m.v[2], v);
    return r;
}

LADEF V3u v3u(unsigned int x, unsigned int y, unsigned int z)
{
    V3u v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

LADEF V3u v3uu(unsigned int x)
{
    return v3u(x, x, x);
}

LADEF V3u v2f_3u(V2f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}
LADEF V3u v3u2f(V2f a) { return v2f_3u(a); }

LADEF V3u v2d_3u(V2d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}
LADEF V3u v3u2d(V2d a) { return v2d_3u(a); }

LADEF V3u v2i_3u(V2i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}
LADEF V3u v3u2i(V2i a) { return v2i_3u(a); }

LADEF V3u v2u_3u(V2u a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    return result;
}
LADEF V3u v3u2u(V2u a) { return v2u_3u(a); }

LADEF V3u v3f_3u(V3f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u3f(V3f a) { return v3f_3u(a); }

LADEF V3u v3d_3u(V3d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u3d(V3d a) { return v3d_3u(a); }

LADEF V3u v3i_3u(V3i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u3i(V3i a) { return v3i_3u(a); }


LADEF V3u v4f_3u(V4f a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u4f(V4f a) { return v4f_3u(a); }

LADEF V3u v4d_3u(V4d a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u4d(V4d a) { return v4d_3u(a); }

LADEF V3u v4i_3u(V4i a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u4i(V4i a) { return v4i_3u(a); }

LADEF V3u v4u_3u(V4u a)
{
    V3u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    return result;
}
LADEF V3u v3u4u(V4u a) { return v4u_3u(a); }

LADEF V3u v3u_sum(V3u a, V3u b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

LADEF V3u v3u_add(V3u a, V3u b)
{
    return v3u_sum(a, b);
}

LADEF V3u v3u_sub(V3u a, V3u b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

LADEF V3u v3u_mul(V3u a, V3u b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    return a;
}

LADEF V3u v3u_div(V3u a, V3u b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    return a;
}

LADEF V3u v3u_mod(V3u a, V3u b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    return a;
}

LADEF V3u v3u_min(V3u a, V3u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    a.z = minu(a.z, b.z);
    return a;
}

LADEF V3u v3u_max(V3u a, V3u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    a.z = maxu(a.z, b.z);
    return a;
}

LADEF V3u v3u_clamp(V3u x, V3u a, V3u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    x.z = clampu(x.z, a.z, b.z);
    return x;
}

LADEF unsigned int v3u_sqrlen(V3u a)
{
    return v3u_dot(a, a);
}

LADEF unsigned int v3u_dot(V3u a, V3u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

LADEF V3u v3u_cross(V3u a, V3u b)
{
    V3u n;
    n.x = a.y * b.z - a.z * b.y;
    n.y = a.z * b.x - a.x * b.z;
    n.z = a.x * b.y - a.y * b.x;
    return n;
}

LADEF bool v3u_eq(V3u a, V3u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    return true;
}

LADEF V3u v3u_reflect(V3u i, V3u n)
{
    V3u r = n;
    r = v3u_mul(r, v3uu(v3u_dot(n, i)));
    r = v3u_mul(r, v3uu(2));
    r = v3u_sub(i, r);
    return r;
}

LADEF M3u m3u_id(void)
{
    M3u m = m3u_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    return m;
}

LADEF M3u m3u_zero(void)
{
    M3u m = {
        ._11=0,._12=0,._13=0,
        ._21=0,._22=0,._23=0,
        ._31=0,._32=0,._33=0,
    };
    return m;
}

LADEF M3u m3u_mul(M3u a, M3u b)
{
    M3u m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33;
    return m;
}

LADEF V3u m3u_mul_vec(M3u m, V3u v)
{
    V3u r;
    r.x = v3u_dot(m.v[0], v);
    r.y = v3u_dot(m.v[1], v);
    r.z = v3u_dot(m.v[2], v);
    return r;
}

LADEF V4f v4f(float x, float y, float z, float w)
{
    V4f v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4f v4ff(float x)
{
    return v4f(x, x, x, x);
}

LADEF V4f v2f_4f(V2f a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f2f(V2f a) { return v2f_4f(a); }

LADEF V4f v2d_4f(V2d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f2d(V2d a) { return v2d_4f(a); }

LADEF V4f v2i_4f(V2i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f2i(V2i a) { return v2i_4f(a); }

LADEF V4f v2u_4f(V2u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = 0.0f;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f2u(V2u a) { return v2u_4f(a); }

LADEF V4f v3f_4f(V3f a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f3f(V3f a) { return v3f_4f(a); }

LADEF V4f v3d_4f(V3d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f3d(V3d a) { return v3d_4f(a); }

LADEF V4f v3i_4f(V3i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f3i(V3i a) { return v3i_4f(a); }

LADEF V4f v3u_4f(V3u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = 0.0f;
    return result;
}
LADEF V4f v4f3u(V3u a) { return v3u_4f(a); }


LADEF V4f v4d_4f(V4d a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}
LADEF V4f v4f4d(V4d a) { return v4d_4f(a); }

LADEF V4f v4i_4f(V4i a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}
LADEF V4f v4f4i(V4i a) { return v4i_4f(a); }

LADEF V4f v4u_4f(V4u a)
{
    V4f result;
    result.x = (float) a.x;
    result.y = (float) a.y;
    result.z = (float) a.z;
    result.w = (float) a.w;
    return result;
}
LADEF V4f v4f4u(V4u a) { return v4u_4f(a); }

LADEF V4f v4f_sum(V4f a, V4f b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4f v4f_add(V4f a, V4f b)
{
    return v4f_sum(a, b);
}

LADEF V4f v4f_sub(V4f a, V4f b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4f v4f_mul(V4f a, V4f b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4f v4f_div(V4f a, V4f b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4f v4f_mod(V4f a, V4f b)
{
    a.x = fmodf(a.x, b.x);
    a.y = fmodf(a.y, b.y);
    a.z = fmodf(a.z, b.z);
    a.w = fmodf(a.w, b.w);
    return a;
}

LADEF V4f v4f_sqrt(V4f a)
{
    a.x = sqrtf(a.x);
    a.y = sqrtf(a.y);
    a.z = sqrtf(a.z);
    a.w = sqrtf(a.w);
    return a;
}

LADEF V4f v4f_pow(V4f base, V4f exp)
{
    base.x = powf(base.x, exp.x);
    base.y = powf(base.y, exp.y);
    base.z = powf(base.z, exp.z);
    base.w = powf(base.w, exp.w);
    return base;
}

LADEF V4f v4f_sin(V4f a)
{
    a.x = sinf(a.x);
    a.y = sinf(a.y);
    a.z = sinf(a.z);
    a.w = sinf(a.w);
    return a;
}

LADEF V4f v4f_cos(V4f a)
{
    a.x = cosf(a.x);
    a.y = cosf(a.y);
    a.z = cosf(a.z);
    a.w = cosf(a.w);
    return a;
}

LADEF V4f v4f_min(V4f a, V4f b)
{
    a.x = fminf(a.x, b.x);
    a.y = fminf(a.y, b.y);
    a.z = fminf(a.z, b.z);
    a.w = fminf(a.w, b.w);
    return a;
}

LADEF V4f v4f_max(V4f a, V4f b)
{
    a.x = fmaxf(a.x, b.x);
    a.y = fmaxf(a.y, b.y);
    a.z = fmaxf(a.z, b.z);
    a.w = fmaxf(a.w, b.w);
    return a;
}

LADEF V4f v4f_lerp(V4f a, V4f b, V4f t)
{
    a.x = lerpf(a.x, b.x, t.x);
    a.y = lerpf(a.y, b.y, t.y);
    a.z = lerpf(a.z, b.z, t.z);
    a.w = lerpf(a.w, b.w, t.w);
    return a;
}

LADEF V4f v4f_floor(V4f a)
{
    a.x = floorf(a.x);
    a.y = floorf(a.y);
    a.z = floorf(a.z);
    a.w = floorf(a.w);
    return a;
}

LADEF V4f v4f_ceil(V4f a)
{
    a.x = ceilf(a.x);
    a.y = ceilf(a.y);
    a.z = ceilf(a.z);
    a.w = ceilf(a.w);
    return a;
}

LADEF V4f v4f_clamp(V4f x, V4f a, V4f b)
{
    x.x = clampf(x.x, a.x, b.x);
    x.y = clampf(x.y, a.y, b.y);
    x.z = clampf(x.z, a.z, b.z);
    x.w = clampf(x.w, a.w, b.w);
    return x;
}

LADEF float v4f_sqrlen(V4f a)
{
    return v4f_dot(a, a);
}

LADEF float v4f_len(V4f a)
{
    return sqrtf(v4f_sqrlen(a));
}

LADEF float v4f_dot(V4f a, V4f b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4f v4f_norm(V4f a, float eps, V4f fallback)
{
    float l = v4f_len(a);
    if (fabsf(l) <= eps) return fallback;
    return v4f_div(a, v4ff(l));
}

LADEF bool v4f_eq(V4f a, V4f b, float eps)
{
    if (fabsf(b.x - a.x) > eps) return false;
    if (fabsf(b.y - a.y) > eps) return false;
    if (fabsf(b.z - a.z) > eps) return false;
    if (fabsf(b.w - a.w) > eps) return false;
    return true;
}

LADEF V4f v4f_reflect(V4f i, V4f n)
{
    V4f r = n;
    r = v4f_mul(r, v4ff(v4f_dot(n, i)));
    r = v4f_mul(r, v4ff(2));
    r = v4f_sub(i, r);
    return r;
}

LADEF M4f m4f_id(void)
{
    M4f m = m4f_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4f m4f_zero(void)
{
    M4f m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4f m4f_mul(M4f a, M4f b)
{
    M4f m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4f m4f_mul_vec(M4f m, V4f v)
{
    V4f r;
    r.x = v4f_dot(m.v[0], v);
    r.y = v4f_dot(m.v[1], v);
    r.z = v4f_dot(m.v[2], v);
    r.w = v4f_dot(m.v[3], v);
    return r;
}

LADEF M4f m4f_rot_x(float angle)
{
    M4f m = m4f_id();
    m._22 = cosf(angle);
    m._23 = -sinf(angle);
    m._32 = sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M4f m4f_rot_y(float angle)
{
    M4f m = m4f_id();
    m._11 = cosf(angle);
    m._13 = sinf(angle);
    m._31 = -sinf(angle);
    m._33 = cosf(angle);
    return m;
}

LADEF M4f m4f_rot_z(float angle)
{
    M4f m = m4f_id();
    m._11 = cosf(angle);
    m._12 = -sinf(angle);
    m._21 = sinf(angle);
    m._22 = cosf(angle);
    return m;
}

LADEF V4d v4d(double x, double y, double z, double w)
{
    V4d v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4d v4dd(double x)
{
    return v4d(x, x, x, x);
}

LADEF V4d v2f_4d(V2f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d2f(V2f a) { return v2f_4d(a); }

LADEF V4d v2d_4d(V2d a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d2d(V2d a) { return v2d_4d(a); }

LADEF V4d v2i_4d(V2i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d2i(V2i a) { return v2i_4d(a); }

LADEF V4d v2u_4d(V2u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = 0.0;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d2u(V2u a) { return v2u_4d(a); }

LADEF V4d v3f_4d(V3f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d3f(V3f a) { return v3f_4d(a); }

LADEF V4d v3d_4d(V3d a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d3d(V3d a) { return v3d_4d(a); }

LADEF V4d v3i_4d(V3i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d3i(V3i a) { return v3i_4d(a); }

LADEF V4d v3u_4d(V3u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = 0.0;
    return result;
}
LADEF V4d v4d3u(V3u a) { return v3u_4d(a); }

LADEF V4d v4f_4d(V4f a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}
LADEF V4d v4d4f(V4f a) { return v4f_4d(a); }


LADEF V4d v4i_4d(V4i a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}
LADEF V4d v4d4i(V4i a) { return v4i_4d(a); }

LADEF V4d v4u_4d(V4u a)
{
    V4d result;
    result.x = (double) a.x;
    result.y = (double) a.y;
    result.z = (double) a.z;
    result.w = (double) a.w;
    return result;
}
LADEF V4d v4d4u(V4u a) { return v4u_4d(a); }

LADEF V4d v4d_sum(V4d a, V4d b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4d v4d_add(V4d a, V4d b)
{
    return v4d_sum(a, b);
}

LADEF V4d v4d_sub(V4d a, V4d b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4d v4d_mul(V4d a, V4d b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4d v4d_div(V4d a, V4d b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4d v4d_mod(V4d a, V4d b)
{
    a.x = fmod(a.x, b.x);
    a.y = fmod(a.y, b.y);
    a.z = fmod(a.z, b.z);
    a.w = fmod(a.w, b.w);
    return a;
}

LADEF V4d v4d_sqrt(V4d a)
{
    a.x = sqrt(a.x);
    a.y = sqrt(a.y);
    a.z = sqrt(a.z);
    a.w = sqrt(a.w);
    return a;
}

LADEF V4d v4d_pow(V4d base, V4d exp)
{
    base.x = pow(base.x, exp.x);
    base.y = pow(base.y, exp.y);
    base.z = pow(base.z, exp.z);
    base.w = pow(base.w, exp.w);
    return base;
}

LADEF V4d v4d_sin(V4d a)
{
    a.x = sin(a.x);
    a.y = sin(a.y);
    a.z = sin(a.z);
    a.w = sin(a.w);
    return a;
}

LADEF V4d v4d_cos(V4d a)
{
    a.x = cos(a.x);
    a.y = cos(a.y);
    a.z = cos(a.z);
    a.w = cos(a.w);
    return a;
}

LADEF V4d v4d_min(V4d a, V4d b)
{
    a.x = fmin(a.x, b.x);
    a.y = fmin(a.y, b.y);
    a.z = fmin(a.z, b.z);
    a.w = fmin(a.w, b.w);
    return a;
}

LADEF V4d v4d_max(V4d a, V4d b)
{
    a.x = fmax(a.x, b.x);
    a.y = fmax(a.y, b.y);
    a.z = fmax(a.z, b.z);
    a.w = fmax(a.w, b.w);
    return a;
}

LADEF V4d v4d_lerp(V4d a, V4d b, V4d t)
{
    a.x = lerp(a.x, b.x, t.x);
    a.y = lerp(a.y, b.y, t.y);
    a.z = lerp(a.z, b.z, t.z);
    a.w = lerp(a.w, b.w, t.w);
    return a;
}

LADEF V4d v4d_floor(V4d a)
{
    a.x = floor(a.x);
    a.y = floor(a.y);
    a.z = floor(a.z);
    a.w = floor(a.w);
    return a;
}

LADEF V4d v4d_ceil(V4d a)
{
    a.x = ceil(a.x);
    a.y = ceil(a.y);
    a.z = ceil(a.z);
    a.w = ceil(a.w);
    return a;
}

LADEF V4d v4d_clamp(V4d x, V4d a, V4d b)
{
    x.x = clampd(x.x, a.x, b.x);
    x.y = clampd(x.y, a.y, b.y);
    x.z = clampd(x.z, a.z, b.z);
    x.w = clampd(x.w, a.w, b.w);
    return x;
}

LADEF double v4d_sqrlen(V4d a)
{
    return v4d_dot(a, a);
}

LADEF double v4d_len(V4d a)
{
    return sqrt(v4d_sqrlen(a));
}

LADEF double v4d_dot(V4d a, V4d b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF V4d v4d_norm(V4d a, double eps, V4d fallback)
{
    double l = v4d_len(a);
    if (fabs(l) <= eps) return fallback;
    return v4d_div(a, v4dd(l));
}

LADEF bool v4d_eq(V4d a, V4d b, double eps)
{
    if (fabs(b.x - a.x) > eps) return false;
    if (fabs(b.y - a.y) > eps) return false;
    if (fabs(b.z - a.z) > eps) return false;
    if (fabs(b.w - a.w) > eps) return false;
    return true;
}

LADEF V4d v4d_reflect(V4d i, V4d n)
{
    V4d r = n;
    r = v4d_mul(r, v4dd(v4d_dot(n, i)));
    r = v4d_mul(r, v4dd(2));
    r = v4d_sub(i, r);
    return r;
}

LADEF M4d m4d_id(void)
{
    M4d m = m4d_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4d m4d_zero(void)
{
    M4d m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4d m4d_mul(M4d a, M4d b)
{
    M4d m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4d m4d_mul_vec(M4d m, V4d v)
{
    V4d r;
    r.x = v4d_dot(m.v[0], v);
    r.y = v4d_dot(m.v[1], v);
    r.z = v4d_dot(m.v[2], v);
    r.w = v4d_dot(m.v[3], v);
    return r;
}

LADEF M4d m4d_rot_x(double angle)
{
    M4d m = m4d_id();
    m._22 = cos(angle);
    m._23 = -sin(angle);
    m._32 = sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M4d m4d_rot_y(double angle)
{
    M4d m = m4d_id();
    m._11 = cos(angle);
    m._13 = sin(angle);
    m._31 = -sin(angle);
    m._33 = cos(angle);
    return m;
}

LADEF M4d m4d_rot_z(double angle)
{
    M4d m = m4d_id();
    m._11 = cos(angle);
    m._12 = -sin(angle);
    m._21 = sin(angle);
    m._22 = cos(angle);
    return m;
}

LADEF V4i v4i(int x, int y, int z, int w)
{
    V4i v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4i v4ii(int x)
{
    return v4i(x, x, x, x);
}

LADEF V4i v2f_4i(V2f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}
LADEF V4i v4i2f(V2f a) { return v2f_4i(a); }

LADEF V4i v2d_4i(V2d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}
LADEF V4i v4i2d(V2d a) { return v2d_4i(a); }

LADEF V4i v2i_4i(V2i a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}
LADEF V4i v4i2i(V2i a) { return v2i_4i(a); }

LADEF V4i v2u_4i(V2u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = 0;
    result.w = 0;
    return result;
}
LADEF V4i v4i2u(V2u a) { return v2u_4i(a); }

LADEF V4i v3f_4i(V3f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}
LADEF V4i v4i3f(V3f a) { return v3f_4i(a); }

LADEF V4i v3d_4i(V3d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}
LADEF V4i v4i3d(V3d a) { return v3d_4i(a); }

LADEF V4i v3i_4i(V3i a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}
LADEF V4i v4i3i(V3i a) { return v3i_4i(a); }

LADEF V4i v3u_4i(V3u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = 0;
    return result;
}
LADEF V4i v4i3u(V3u a) { return v3u_4i(a); }

LADEF V4i v4f_4i(V4f a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}
LADEF V4i v4i4f(V4f a) { return v4f_4i(a); }

LADEF V4i v4d_4i(V4d a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}
LADEF V4i v4i4d(V4d a) { return v4d_4i(a); }


LADEF V4i v4u_4i(V4u a)
{
    V4i result;
    result.x = (int) a.x;
    result.y = (int) a.y;
    result.z = (int) a.z;
    result.w = (int) a.w;
    return result;
}
LADEF V4i v4i4u(V4u a) { return v4u_4i(a); }

LADEF V4i v4i_sum(V4i a, V4i b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4i v4i_add(V4i a, V4i b)
{
    return v4i_sum(a, b);
}

LADEF V4i v4i_sub(V4i a, V4i b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4i v4i_mul(V4i a, V4i b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4i v4i_div(V4i a, V4i b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4i v4i_mod(V4i a, V4i b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    a.w %= b.w;
    return a;
}

LADEF V4i v4i_min(V4i a, V4i b)
{
    a.x = mini(a.x, b.x);
    a.y = mini(a.y, b.y);
    a.z = mini(a.z, b.z);
    a.w = mini(a.w, b.w);
    return a;
}

LADEF V4i v4i_max(V4i a, V4i b)
{
    a.x = maxi(a.x, b.x);
    a.y = maxi(a.y, b.y);
    a.z = maxi(a.z, b.z);
    a.w = maxi(a.w, b.w);
    return a;
}

LADEF V4i v4i_clamp(V4i x, V4i a, V4i b)
{
    x.x = clampi(x.x, a.x, b.x);
    x.y = clampi(x.y, a.y, b.y);
    x.z = clampi(x.z, a.z, b.z);
    x.w = clampi(x.w, a.w, b.w);
    return x;
}

LADEF int v4i_sqrlen(V4i a)
{
    return v4i_dot(a, a);
}

LADEF int v4i_dot(V4i a, V4i b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF bool v4i_eq(V4i a, V4i b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    if (a.w != b.w) return false;
    return true;
}

LADEF V4i v4i_reflect(V4i i, V4i n)
{
    V4i r = n;
    r = v4i_mul(r, v4ii(v4i_dot(n, i)));
    r = v4i_mul(r, v4ii(2));
    r = v4i_sub(i, r);
    return r;
}

LADEF M4i m4i_id(void)
{
    M4i m = m4i_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4i m4i_zero(void)
{
    M4i m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4i m4i_mul(M4i a, M4i b)
{
    M4i m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4i m4i_mul_vec(M4i m, V4i v)
{
    V4i r;
    r.x = v4i_dot(m.v[0], v);
    r.y = v4i_dot(m.v[1], v);
    r.z = v4i_dot(m.v[2], v);
    r.w = v4i_dot(m.v[3], v);
    return r;
}

LADEF V4u v4u(unsigned int x, unsigned int y, unsigned int z, unsigned int w)
{
    V4u v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = w;
    return v;
}

LADEF V4u v4uu(unsigned int x)
{
    return v4u(x, x, x, x);
}

LADEF V4u v2f_4u(V2f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}
LADEF V4u v4u2f(V2f a) { return v2f_4u(a); }

LADEF V4u v2d_4u(V2d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}
LADEF V4u v4u2d(V2d a) { return v2d_4u(a); }

LADEF V4u v2i_4u(V2i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}
LADEF V4u v4u2i(V2i a) { return v2i_4u(a); }

LADEF V4u v2u_4u(V2u a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = 0u;
    result.w = 0u;
    return result;
}
LADEF V4u v4u2u(V2u a) { return v2u_4u(a); }

LADEF V4u v3f_4u(V3f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}
LADEF V4u v4u3f(V3f a) { return v3f_4u(a); }

LADEF V4u v3d_4u(V3d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}
LADEF V4u v4u3d(V3d a) { return v3d_4u(a); }

LADEF V4u v3i_4u(V3i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}
LADEF V4u v4u3i(V3i a) { return v3i_4u(a); }

LADEF V4u v3u_4u(V3u a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = 0u;
    return result;
}
LADEF V4u v4u3u(V3u a) { return v3u_4u(a); }

LADEF V4u v4f_4u(V4f a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}
LADEF V4u v4u4f(V4f a) { return v4f_4u(a); }

LADEF V4u v4d_4u(V4d a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}
LADEF V4u v4u4d(V4d a) { return v4d_4u(a); }

LADEF V4u v4i_4u(V4i a)
{
    V4u result;
    result.x = (unsigned int) a.x;
    result.y = (unsigned int) a.y;
    result.z = (unsigned int) a.z;
    result.w = (unsigned int) a.w;
    return result;
}
LADEF V4u v4u4i(V4i a) { return v4i_4u(a); }


LADEF V4u v4u_sum(V4u a, V4u b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    a.w += b.w;
    return a;
}

LADEF V4u v4u_add(V4u a, V4u b)
{
    return v4u_sum(a, b);
}

LADEF V4u v4u_sub(V4u a, V4u b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    a.w -= b.w;
    return a;
}

LADEF V4u v4u_mul(V4u a, V4u b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
    a.w *= b.w;
    return a;
}

LADEF V4u v4u_div(V4u a, V4u b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
    a.w /= b.w;
    return a;
}

LADEF V4u v4u_mod(V4u a, V4u b)
{
    a.x %= b.x;
    a.y %= b.y;
    a.z %= b.z;
    a.w %= b.w;
    return a;
}

LADEF V4u v4u_min(V4u a, V4u b)
{
    a.x = minu(a.x, b.x);
    a.y = minu(a.y, b.y);
    a.z = minu(a.z, b.z);
    a.w = minu(a.w, b.w);
    return a;
}

LADEF V4u v4u_max(V4u a, V4u b)
{
    a.x = maxu(a.x, b.x);
    a.y = maxu(a.y, b.y);
    a.z = maxu(a.z, b.z);
    a.w = maxu(a.w, b.w);
    return a;
}

LADEF V4u v4u_clamp(V4u x, V4u a, V4u b)
{
    x.x = clampu(x.x, a.x, b.x);
    x.y = clampu(x.y, a.y, b.y);
    x.z = clampu(x.z, a.z, b.z);
    x.w = clampu(x.w, a.w, b.w);
    return x;
}

LADEF unsigned int v4u_sqrlen(V4u a)
{
    return v4u_dot(a, a);
}

LADEF unsigned int v4u_dot(V4u a, V4u b)
{
    return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

LADEF bool v4u_eq(V4u a, V4u b)
{
    if (a.x != b.x) return false;
    if (a.y != b.y) return false;
    if (a.z != b.z) return false;
    if (a.w != b.w) return false;
    return true;
}

LADEF V4u v4u_reflect(V4u i, V4u n)
{
    V4u r = n;
    r = v4u_mul(r, v4uu(v4u_dot(n, i)));
    r = v4u_mul(r, v4uu(2));
    r = v4u_sub(i, r);
    return r;
}

LADEF M4u m4u_id(void)
{
    M4u m = m4u_zero();
    m._11 = 1;
    m._22 = 1;
    m._33 = 1;
    m._44 = 1;
    return m;
}

LADEF M4u m4u_zero(void)
{
    M4u m = {
        ._11=0,._12=0,._13=0,._14=0,
        ._21=0,._22=0,._23=0,._24=0,
        ._31=0,._32=0,._33=0,._34=0,
        ._41=0,._42=0,._43=0,._44=0,
    };
    return m;
}

LADEF M4u m4u_mul(M4u a, M4u b)
{
    M4u m;
    m._11 = a._11*b._11 + a._12*b._21 + a._13*b._31 + a._14*b._41;
    m._12 = a._11*b._12 + a._12*b._22 + a._13*b._32 + a._14*b._42;
    m._13 = a._11*b._13 + a._12*b._23 + a._13*b._33 + a._14*b._43;
    m._14 = a._11*b._14 + a._12*b._24 + a._13*b._34 + a._14*b._44;
    m._21 = a._21*b._11 + a._22*b._21 + a._23*b._31 + a._24*b._41;
    m._22 = a._21*b._12 + a._22*b._22 + a._23*b._32 + a._24*b._42;
    m._23 = a._21*b._13 + a._22*b._23 + a._23*b._33 + a._24*b._43;
    m._24 = a._21*b._14 + a._22*b._24 + a._23*b._34 + a._24*b._44;
    m._31 = a._31*b._11 + a._32*b._21 + a._33*b._31 + a._34*b._41;
    m._32 = a._31*b._12 + a._32*b._22 + a._33*b._32 + a._34*b._42;
    m._33 = a._31*b._13 + a._32*b._23 + a._33*b._33 + a._34*b._43;
    m._34 = a._31*b._14 + a._32*b._24 + a._33*b._34 + a._34*b._44;
    m._41 = a._41*b._11 + a._42*b._21 + a._43*b._31 + a._44*b._41;
    m._42 = a._41*b._12 + a._42*b._22 + a._43*b._32 + a._44*b._42;
    m._43 = a._41*b._13 + a._42*b._23 + a._43*b._33 + a._44*b._43;
    m._44 = a._41*b._14 + a._42*b._24 + a._43*b._34 + a._44*b._44;
    return m;
}

LADEF V4u m4u_mul_vec(M4u m, V4u v)
{
    V4u r;
    r.x = v4u_dot(m.v[0], v);
    r.y = v4u_dot(m.v[1], v);
    r.z = v4u_dot(m.v[2], v);
    r.w = v4u_dot(m.v[3], v);
    return r;
}

LADEF V2f v2f_xx(V2f v) { return (V2f) {.c={v.x,v.x}}; }
LADEF V2f v2f_yx(V2f v) { return (V2f) {.c={v.y,v.x}}; }
LADEF V2f v2f_xy(V2f v) { return v; }
LADEF V2f v2f_yy(V2f v) { return (V2f) {.c={v.y,v.y}}; }
LADEF V2f v3f_xx(V3f v) { return (V2f) {.c={v.x,v.x}}; }
LADEF V2f v3f_yx(V3f v) { return (V2f) {.c={v.y,v.x}}; }
LADEF V2f v3f_zx(V3f v) { return (V2f) {.c={v.z,v.x}}; }
LADEF V2f v3f_xy(V3f v) { return (V2f) {.c={v.x,v.y}}; }
LADEF V2f v3f_yy(V3f v) { return (V2f) {.c={v.y,v.y}}; }
LADEF V2f v3f_zy(V3f v) { return (V2f) {.c={v.z,v.y}}; }
LADEF V2f v3f_xz(V3f v) { return (V2f) {.c={v.x,v.z}}; }
LADEF V2f v3f_yz(V3f v) { return (V2f) {.c={v.y,v.z}}; }
LADEF V2f v3f_zz(V3f v) { return (V2f) {.c={v.z,v.z}}; }
LADEF V2f v4f_xx(V4f v) { return (V2f) {.c={v.x,v.x}}; }
LADEF V2f v4f_yx(V4f v) { return (V2f) {.c={v.y,v.x}}; }
LADEF V2f v4f_zx(V4f v) { return (V2f) {.c={v.z,v.x}}; }
LADEF V2f v4f_wx(V4f v) { return (V2f) {.c={v.w,v.x}}; }
LADEF V2f v4f_xy(V4f v) { return (V2f) {.c={v.x,v.y}}; }
LADEF V2f v4f_yy(V4f v) { return (V2f) {.c={v.y,v.y}}; }
LADEF V2f v4f_zy(V4f v) { return (V2f) {.c={v.z,v.y}}; }
LADEF V2f v4f_wy(V4f v) { return (V2f) {.c={v.w,v.y}}; }
LADEF V2f v4f_xz(V4f v) { return (V2f) {.c={v.x,v.z}}; }
LADEF V2f v4f_yz(V4f v) { return (V2f) {.c={v.y,v.z}}; }
LADEF V2f v4f_zz(V4f v) { return (V2f) {.c={v.z,v.z}}; }
LADEF V2f v4f_wz(V4f v) { return (V2f) {.c={v.w,v.z}}; }
LADEF V2f v4f_xw(V4f v) { return (V2f) {.c={v.x,v.w}}; }
LADEF V2f v4f_yw(V4f v) { return (V2f) {.c={v.y,v.w}}; }
LADEF V2f v4f_zw(V4f v) { return (V2f) {.c={v.z,v.w}}; }
LADEF V2f v4f_ww(V4f v) { return (V2f) {.c={v.w,v.w}}; }

LADEF V3f v2f_xxx(V2f v) { return (V3f) {.c={v.x,v.x,v.x}}; }
LADEF V3f v2f_yxx(V2f v) { return (V3f) {.c={v.y,v.x,v.x}}; }
LADEF V3f v2f_xyx(V2f v) { return (V3f) {.c={v.x,v.y,v.x}}; }
LADEF V3f v2f_yyx(V2f v) { return (V3f) {.c={v.y,v.y,v.x}}; }
LADEF V3f v2f_xxy(V2f v) { return (V3f) {.c={v.x,v.x,v.y}}; }
LADEF V3f v2f_yxy(V2f v) { return (V3f) {.c={v.y,v.x,v.y}}; }
LADEF V3f v2f_xyy(V2f v) { return (V3f) {.c={v.x,v.y,v.y}}; }
LADEF V3f v2f_yyy(V2f v) { return (V3f) {.c={v.y,v.y,v.y}}; }
LADEF V3f v3f_xxx(V3f v) { return (V3f) {.c={v.x,v.x,v.x}}; }
LADEF V3f v3f_yxx(V3f v) { return (V3f) {.c={v.y,v.x,v.x}}; }
LADEF V3f v3f_zxx(V3f v) { return (V3f) {.c={v.z,v.x,v.x}}; }
LADEF V3f v3f_xyx(V3f v) { return (V3f) {.c={v.x,v.y,v.x}}; }
LADEF V3f v3f_yyx(V3f v) { return (V3f) {.c={v.y,v.y,v.x}}; }
LADEF V3f v3f_zyx(V3f v) { return (V3f) {.c={v.z,v.y,v.x}}; }
LADEF V3f v3f_xzx(V3f v) { return (V3f) {.c={v.x,v.z,v.x}}; }
LADEF V3f v3f_yzx(V3f v) { return (V3f) {.c={v.y,v.z,v.x}}; }
LADEF V3f v3f_zzx(V3f v) { return (V3f) {.c={v.z,v.z,v.x}}; }
LADEF V3f v3f_xxy(V3f v) { return (V3f) {.c={v.x,v.x,v.y}}; }
LADEF V3f v3f_yxy(V3f v) { return (V3f) {.c={v.y,v.x,v.y}}; }
LADEF V3f v3f_zxy(V3f v) { return (V3f) {.c={v.z,v.x,v.y}}; }
LADEF V3f v3f_xyy(V3f v) { return (V3f) {.c={v.x,v.y,v.y}}; }
LADEF V3f v3f_yyy(V3f v) { return (V3f) {.c={v.y,v.y,v.y}}; }
LADEF V3f v3f_zyy(V3f v) { return (V3f) {.c={v.z,v.y,v.y}}; }
LADEF V3f v3f_xzy(V3f v) { return (V3f) {.c={v.x,v.z,v.y}}; }
LADEF V3f v3f_yzy(V3f v) { return (V3f) {.c={v.y,v.z,v.y}}; }
LADEF V3f v3f_zzy(V3f v) { return (V3f) {.c={v.z,v.z,v.y}}; }
LADEF V3f v3f_xxz(V3f v) { return (V3f) {.c={v.x,v.x,v.z}}; }
LADEF V3f v3f_yxz(V3f v) { return (V3f) {.c={v.y,v.x,v.z}}; }
LADEF V3f v3f_zxz(V3f v) { return (V3f) {.c={v.z,v.x,v.z}}; }
LADEF V3f v3f_xyz(V3f v) { return v; }
LADEF V3f v3f_yyz(V3f v) { return (V3f) {.c={v.y,v.y,v.z}}; }
LADEF V3f v3f_zyz(V3f v) { return (V3f) {.c={v.z,v.y,v.z}}; }
LADEF V3f v3f_xzz(V3f v) { return (V3f) {.c={v.x,v.z,v.z}}; }
LADEF V3f v3f_yzz(V3f v) { return (V3f) {.c={v.y,v.z,v.z}}; }
LADEF V3f v3f_zzz(V3f v) { return (V3f) {.c={v.z,v.z,v.z}}; }
LADEF V3f v4f_xxx(V4f v) { return (V3f) {.c={v.x,v.x,v.x}}; }
LADEF V3f v4f_yxx(V4f v) { return (V3f) {.c={v.y,v.x,v.x}}; }
LADEF V3f v4f_zxx(V4f v) { return (V3f) {.c={v.z,v.x,v.x}}; }
LADEF V3f v4f_wxx(V4f v) { return (V3f) {.c={v.w,v.x,v.x}}; }
LADEF V3f v4f_xyx(V4f v) { return (V3f) {.c={v.x,v.y,v.x}}; }
LADEF V3f v4f_yyx(V4f v) { return (V3f) {.c={v.y,v.y,v.x}}; }
LADEF V3f v4f_zyx(V4f v) { return (V3f) {.c={v.z,v.y,v.x}}; }
LADEF V3f v4f_wyx(V4f v) { return (V3f) {.c={v.w,v.y,v.x}}; }
LADEF V3f v4f_xzx(V4f v) { return (V3f) {.c={v.x,v.z,v.x}}; }
LADEF V3f v4f_yzx(V4f v) { return (V3f) {.c={v.y,v.z,v.x}}; }
LADEF V3f v4f_zzx(V4f v) { return (V3f) {.c={v.z,v.z,v.x}}; }
LADEF V3f v4f_wzx(V4f v) { return (V3f) {.c={v.w,v.z,v.x}}; }
LADEF V3f v4f_xwx(V4f v) { return (V3f) {.c={v.x,v.w,v.x}}; }
LADEF V3f v4f_ywx(V4f v) { return (V3f) {.c={v.y,v.w,v.x}}; }
LADEF V3f v4f_zwx(V4f v) { return (V3f) {.c={v.z,v.w,v.x}}; }
LADEF V3f v4f_wwx(V4f v) { return (V3f) {.c={v.w,v.w,v.x}}; }
LADEF V3f v4f_xxy(V4f v) { return (V3f) {.c={v.x,v.x,v.y}}; }
LADEF V3f v4f_yxy(V4f v) { return (V3f) {.c={v.y,v.x,v.y}}; }
LADEF V3f v4f_zxy(V4f v) { return (V3f) {.c={v.z,v.x,v.y}}; }
LADEF V3f v4f_wxy(V4f v) { return (V3f) {.c={v.w,v.x,v.y}}; }
LADEF V3f v4f_xyy(V4f v) { return (V3f) {.c={v.x,v.y,v.y}}; }
LADEF V3f v4f_yyy(V4f v) { return (V3f) {.c={v.y,v.y,v.y}}; }
LADEF V3f v4f_zyy(V4f v) { return (V3f) {.c={v.z,v.y,v.y}}; }
LADEF V3f v4f_wyy(V4f v) { return (V3f) {.c={v.w,v.y,v.y}}; }
LADEF V3f v4f_xzy(V4f v) { return (V3f) {.c={v.x,v.z,v.y}}; }
LADEF V3f v4f_yzy(V4f v) { return (V3f) {.c={v.y,v.z,v.y}}; }
LADEF V3f v4f_zzy(V4f v) { return (V3f) {.c={v.z,v.z,v.y}}; }
LADEF V3f v4f_wzy(V4f v) { return (V3f) {.c={v.w,v.z,v.y}}; }
LADEF V3f v4f_xwy(V4f v) { return (V3f) {.c={v.x,v.w,v.y}}; }
LADEF V3f v4f_ywy(V4f v) { return (V3f) {.c={v.y,v.w,v.y}}; }
LADEF V3f v4f_zwy(V4f v) { return (V3f) {.c={v.z,v.w,v.y}}; }
LADEF V3f v4f_wwy(V4f v) { return (V3f) {.c={v.w,v.w,v.y}}; }
LADEF V3f v4f_xxz(V4f v) { return (V3f) {.c={v.x,v.x,v.z}}; }
LADEF V3f v4f_yxz(V4f v) { return (V3f) {.c={v.y,v.x,v.z}}; }
LADEF V3f v4f_zxz(V4f v) { return (V3f) {.c={v.z,v.x,v.z}}; }
LADEF V3f v4f_wxz(V4f v) { return (V3f) {.c={v.w,v.x,v.z}}; }
LADEF V3f v4f_xyz(V4f v) { return (V3f) {.c={v.x,v.y,v.z}}; }
LADEF V3f v4f_yyz(V4f v) { return (V3f) {.c={v.y,v.y,v.z}}; }
LADEF V3f v4f_zyz(V4f v) { return (V3f) {.c={v.z,v.y,v.z}}; }
LADEF V3f v4f_wyz(V4f v) { return (V3f) {.c={v.w,v.y,v.z}}; }
LADEF V3f v4f_xzz(V4f v) { return (V3f) {.c={v.x,v.z,v.z}}; }
LADEF V3f v4f_yzz(V4f v) { return (V3f) {.c={v.y,v.z,v.z}}; }
LADEF V3f v4f_zzz(V4f v) { return (V3f) {.c={v.z,v.z,v.z}}; }
LADEF V3f v4f_wzz(V4f v) { return (V3f) {.c={v.w,v.z,v.z}}; }
LADEF V3f v4f_xwz(V4f v) { return (V3f) {.c={v.x,v.w,v.z}}; }
LADEF V3f v4f_ywz(V4f v) { return (V3f) {.c={v.y,v.w,v.z}}; }
LADEF V3f v4f_zwz(V4f v) { return (V3f) {.c={v.z,v.w,v.z}}; }
LADEF V3f v4f_wwz(V4f v) { return (V3f) {.c={v.w,v.w,v.z}}; }
LADEF V3f v4f_xxw(V4f v) { return (V3f) {.c={v.x,v.x,v.w}}; }
LADEF V3f v4f_yxw(V4f v) { return (V3f) {.c={v.y,v.x,v.w}}; }
LADEF V3f v4f_zxw(V4f v) { return (V3f) {.c={v.z,v.x,v.w}}; }
LADEF V3f v4f_wxw(V4f v) { return (V3f) {.c={v.w,v.x,v.w}}; }
LADEF V3f v4f_xyw(V4f v) { return (V3f) {.c={v.x,v.y,v.w}}; }
LADEF V3f v4f_yyw(V4f v) { return (V3f) {.c={v.y,v.y,v.w}}; }
LADEF V3f v4f_zyw(V4f v) { return (V3f) {.c={v.z,v.y,v.w}}; }
LADEF V3f v4f_wyw(V4f v) { return (V3f) {.c={v.w,v.y,v.w}}; }
LADEF V3f v4f_xzw(V4f v) { return (V3f) {.c={v.x,v.z,v.w}}; }
LADEF V3f v4f_yzw(V4f v) { return (V3f) {.c={v.y,v.z,v.w}}; }
LADEF V3f v4f_zzw(V4f v) { return (V3f) {.c={v.z,v.z,v.w}}; }
LADEF V3f v4f_wzw(V4f v) { return (V3f) {.c={v.w,v.z,v.w}}; }
LADEF V3f v4f_xww(V4f v) { return (V3f) {.c={v.x,v.w,v.w}}; }
LADEF V3f v4f_yww(V4f v) { return (V3f) {.c={v.y,v.w,v.w}}; }
LADEF V3f v4f_zww(V4f v) { return (V3f) {.c={v.z,v.w,v.w}}; }
LADEF V3f v4f_www(V4f v) { return (V3f) {.c={v.w,v.w,v.w}}; }

LADEF V4f v2f_xxxx(V2f v) { return (V4f) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4f v2f_yxxx(V2f v) { return (V4f) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4f v2f_xyxx(V2f v) { return (V4f) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4f v2f_yyxx(V2f v) { return (V4f) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4f v2f_xxyx(V2f v) { return (V4f) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4f v2f_yxyx(V2f v) { return (V4f) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4f v2f_xyyx(V2f v) { return (V4f) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4f v2f_yyyx(V2f v) { return (V4f) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4f v2f_xxxy(V2f v) { return (V4f) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4f v2f_yxxy(V2f v) { return (V4f) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4f v2f_xyxy(V2f v) { return (V4f) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4f v2f_yyxy(V2f v) { return (V4f) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4f v2f_xxyy(V2f v) { return (V4f) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4f v2f_yxyy(V2f v) { return (V4f) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4f v2f_xyyy(V2f v) { return (V4f) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4f v2f_yyyy(V2f v) { return (V4f) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4f v3f_xxxx(V3f v) { return (V4f) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4f v3f_yxxx(V3f v) { return (V4f) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4f v3f_zxxx(V3f v) { return (V4f) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4f v3f_xyxx(V3f v) { return (V4f) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4f v3f_yyxx(V3f v) { return (V4f) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4f v3f_zyxx(V3f v) { return (V4f) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4f v3f_xzxx(V3f v) { return (V4f) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4f v3f_yzxx(V3f v) { return (V4f) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4f v3f_zzxx(V3f v) { return (V4f) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4f v3f_xxyx(V3f v) { return (V4f) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4f v3f_yxyx(V3f v) { return (V4f) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4f v3f_zxyx(V3f v) { return (V4f) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4f v3f_xyyx(V3f v) { return (V4f) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4f v3f_yyyx(V3f v) { return (V4f) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4f v3f_zyyx(V3f v) { return (V4f) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4f v3f_xzyx(V3f v) { return (V4f) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4f v3f_yzyx(V3f v) { return (V4f) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4f v3f_zzyx(V3f v) { return (V4f) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4f v3f_xxzx(V3f v) { return (V4f) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4f v3f_yxzx(V3f v) { return (V4f) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4f v3f_zxzx(V3f v) { return (V4f) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4f v3f_xyzx(V3f v) { return (V4f) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4f v3f_yyzx(V3f v) { return (V4f) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4f v3f_zyzx(V3f v) { return (V4f) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4f v3f_xzzx(V3f v) { return (V4f) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4f v3f_yzzx(V3f v) { return (V4f) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4f v3f_zzzx(V3f v) { return (V4f) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4f v3f_xxxy(V3f v) { return (V4f) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4f v3f_yxxy(V3f v) { return (V4f) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4f v3f_zxxy(V3f v) { return (V4f) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4f v3f_xyxy(V3f v) { return (V4f) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4f v3f_yyxy(V3f v) { return (V4f) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4f v3f_zyxy(V3f v) { return (V4f) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4f v3f_xzxy(V3f v) { return (V4f) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4f v3f_yzxy(V3f v) { return (V4f) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4f v3f_zzxy(V3f v) { return (V4f) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4f v3f_xxyy(V3f v) { return (V4f) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4f v3f_yxyy(V3f v) { return (V4f) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4f v3f_zxyy(V3f v) { return (V4f) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4f v3f_xyyy(V3f v) { return (V4f) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4f v3f_yyyy(V3f v) { return (V4f) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4f v3f_zyyy(V3f v) { return (V4f) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4f v3f_xzyy(V3f v) { return (V4f) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4f v3f_yzyy(V3f v) { return (V4f) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4f v3f_zzyy(V3f v) { return (V4f) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4f v3f_xxzy(V3f v) { return (V4f) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4f v3f_yxzy(V3f v) { return (V4f) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4f v3f_zxzy(V3f v) { return (V4f) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4f v3f_xyzy(V3f v) { return (V4f) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4f v3f_yyzy(V3f v) { return (V4f) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4f v3f_zyzy(V3f v) { return (V4f) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4f v3f_xzzy(V3f v) { return (V4f) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4f v3f_yzzy(V3f v) { return (V4f) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4f v3f_zzzy(V3f v) { return (V4f) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4f v3f_xxxz(V3f v) { return (V4f) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4f v3f_yxxz(V3f v) { return (V4f) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4f v3f_zxxz(V3f v) { return (V4f) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4f v3f_xyxz(V3f v) { return (V4f) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4f v3f_yyxz(V3f v) { return (V4f) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4f v3f_zyxz(V3f v) { return (V4f) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4f v3f_xzxz(V3f v) { return (V4f) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4f v3f_yzxz(V3f v) { return (V4f) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4f v3f_zzxz(V3f v) { return (V4f) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4f v3f_xxyz(V3f v) { return (V4f) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4f v3f_yxyz(V3f v) { return (V4f) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4f v3f_zxyz(V3f v) { return (V4f) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4f v3f_xyyz(V3f v) { return (V4f) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4f v3f_yyyz(V3f v) { return (V4f) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4f v3f_zyyz(V3f v) { return (V4f) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4f v3f_xzyz(V3f v) { return (V4f) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4f v3f_yzyz(V3f v) { return (V4f) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4f v3f_zzyz(V3f v) { return (V4f) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4f v3f_xxzz(V3f v) { return (V4f) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4f v3f_yxzz(V3f v) { return (V4f) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4f v3f_zxzz(V3f v) { return (V4f) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4f v3f_xyzz(V3f v) { return (V4f) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4f v3f_yyzz(V3f v) { return (V4f) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4f v3f_zyzz(V3f v) { return (V4f) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4f v3f_xzzz(V3f v) { return (V4f) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4f v3f_yzzz(V3f v) { return (V4f) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4f v3f_zzzz(V3f v) { return (V4f) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4f v4f_xxxx(V4f v) { return (V4f) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4f v4f_yxxx(V4f v) { return (V4f) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4f v4f_zxxx(V4f v) { return (V4f) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4f v4f_wxxx(V4f v) { return (V4f) {.c={v.w,v.x,v.x,v.x}}; }
LADEF V4f v4f_xyxx(V4f v) { return (V4f) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4f v4f_yyxx(V4f v) { return (V4f) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4f v4f_zyxx(V4f v) { return (V4f) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4f v4f_wyxx(V4f v) { return (V4f) {.c={v.w,v.y,v.x,v.x}}; }
LADEF V4f v4f_xzxx(V4f v) { return (V4f) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4f v4f_yzxx(V4f v) { return (V4f) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4f v4f_zzxx(V4f v) { return (V4f) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4f v4f_wzxx(V4f v) { return (V4f) {.c={v.w,v.z,v.x,v.x}}; }
LADEF V4f v4f_xwxx(V4f v) { return (V4f) {.c={v.x,v.w,v.x,v.x}}; }
LADEF V4f v4f_ywxx(V4f v) { return (V4f) {.c={v.y,v.w,v.x,v.x}}; }
LADEF V4f v4f_zwxx(V4f v) { return (V4f) {.c={v.z,v.w,v.x,v.x}}; }
LADEF V4f v4f_wwxx(V4f v) { return (V4f) {.c={v.w,v.w,v.x,v.x}}; }
LADEF V4f v4f_xxyx(V4f v) { return (V4f) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4f v4f_yxyx(V4f v) { return (V4f) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4f v4f_zxyx(V4f v) { return (V4f) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4f v4f_wxyx(V4f v) { return (V4f) {.c={v.w,v.x,v.y,v.x}}; }
LADEF V4f v4f_xyyx(V4f v) { return (V4f) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4f v4f_yyyx(V4f v) { return (V4f) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4f v4f_zyyx(V4f v) { return (V4f) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4f v4f_wyyx(V4f v) { return (V4f) {.c={v.w,v.y,v.y,v.x}}; }
LADEF V4f v4f_xzyx(V4f v) { return (V4f) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4f v4f_yzyx(V4f v) { return (V4f) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4f v4f_zzyx(V4f v) { return (V4f) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4f v4f_wzyx(V4f v) { return (V4f) {.c={v.w,v.z,v.y,v.x}}; }
LADEF V4f v4f_xwyx(V4f v) { return (V4f) {.c={v.x,v.w,v.y,v.x}}; }
LADEF V4f v4f_ywyx(V4f v) { return (V4f) {.c={v.y,v.w,v.y,v.x}}; }
LADEF V4f v4f_zwyx(V4f v) { return (V4f) {.c={v.z,v.w,v.y,v.x}}; }
LADEF V4f v4f_wwyx(V4f v) { return (V4f) {.c={v.w,v.w,v.y,v.x}}; }
LADEF V4f v4f_xxzx(V4f v) { return (V4f) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4f v4f_yxzx(V4f v) { return (V4f) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4f v4f_zxzx(V4f v) { return (V4f) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4f v4f_wxzx(V4f v) { return (V4f) {.c={v.w,v.x,v.z,v.x}}; }
LADEF V4f v4f_xyzx(V4f v) { return (V4f) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4f v4f_yyzx(V4f v) { return (V4f) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4f v4f_zyzx(V4f v) { return (V4f) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4f v4f_wyzx(V4f v) { return (V4f) {.c={v.w,v.y,v.z,v.x}}; }
LADEF V4f v4f_xzzx(V4f v) { return (V4f) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4f v4f_yzzx(V4f v) { return (V4f) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4f v4f_zzzx(V4f v) { return (V4f) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4f v4f_wzzx(V4f v) { return (V4f) {.c={v.w,v.z,v.z,v.x}}; }
LADEF V4f v4f_xwzx(V4f v) { return (V4f) {.c={v.x,v.w,v.z,v.x}}; }
LADEF V4f v4f_ywzx(V4f v) { return (V4f) {.c={v.y,v.w,v.z,v.x}}; }
LADEF V4f v4f_zwzx(V4f v) { return (V4f) {.c={v.z,v.w,v.z,v.x}}; }
LADEF V4f v4f_wwzx(V4f v) { return (V4f) {.c={v.w,v.w,v.z,v.x}}; }
LADEF V4f v4f_xxwx(V4f v) { return (V4f) {.c={v.x,v.x,v.w,v.x}}; }
LADEF V4f v4f_yxwx(V4f v) { return (V4f) {.c={v.y,v.x,v.w,v.x}}; }
LADEF V4f v4f_zxwx(V4f v) { return (V4f) {.c={v.z,v.x,v.w,v.x}}; }
LADEF V4f v4f_wxwx(V4f v) { return (V4f) {.c={v.w,v.x,v.w,v.x}}; }
LADEF V4f v4f_xywx(V4f v) { return (V4f) {.c={v.x,v.y,v.w,v.x}}; }
LADEF V4f v4f_yywx(V4f v) { return (V4f) {.c={v.y,v.y,v.w,v.x}}; }
LADEF V4f v4f_zywx(V4f v) { return (V4f) {.c={v.z,v.y,v.w,v.x}}; }
LADEF V4f v4f_wywx(V4f v) { return (V4f) {.c={v.w,v.y,v.w,v.x}}; }
LADEF V4f v4f_xzwx(V4f v) { return (V4f) {.c={v.x,v.z,v.w,v.x}}; }
LADEF V4f v4f_yzwx(V4f v) { return (V4f) {.c={v.y,v.z,v.w,v.x}}; }
LADEF V4f v4f_zzwx(V4f v) { return (V4f) {.c={v.z,v.z,v.w,v.x}}; }
LADEF V4f v4f_wzwx(V4f v) { return (V4f) {.c={v.w,v.z,v.w,v.x}}; }
LADEF V4f v4f_xwwx(V4f v) { return (V4f) {.c={v.x,v.w,v.w,v.x}}; }
LADEF V4f v4f_ywwx(V4f v) { return (V4f) {.c={v.y,v.w,v.w,v.x}}; }
LADEF V4f v4f_zwwx(V4f v) { return (V4f) {.c={v.z,v.w,v.w,v.x}}; }
LADEF V4f v4f_wwwx(V4f v) { return (V4f) {.c={v.w,v.w,v.w,v.x}}; }
LADEF V4f v4f_xxxy(V4f v) { return (V4f) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4f v4f_yxxy(V4f v) { return (V4f) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4f v4f_zxxy(V4f v) { return (V4f) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4f v4f_wxxy(V4f v) { return (V4f) {.c={v.w,v.x,v.x,v.y}}; }
LADEF V4f v4f_xyxy(V4f v) { return (V4f) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4f v4f_yyxy(V4f v) { return (V4f) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4f v4f_zyxy(V4f v) { return (V4f) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4f v4f_wyxy(V4f v) { return (V4f) {.c={v.w,v.y,v.x,v.y}}; }
LADEF V4f v4f_xzxy(V4f v) { return (V4f) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4f v4f_yzxy(V4f v) { return (V4f) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4f v4f_zzxy(V4f v) { return (V4f) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4f v4f_wzxy(V4f v) { return (V4f) {.c={v.w,v.z,v.x,v.y}}; }
LADEF V4f v4f_xwxy(V4f v) { return (V4f) {.c={v.x,v.w,v.x,v.y}}; }
LADEF V4f v4f_ywxy(V4f v) { return (V4f) {.c={v.y,v.w,v.x,v.y}}; }
LADEF V4f v4f_zwxy(V4f v) { return (V4f) {.c={v.z,v.w,v.x,v.y}}; }
LADEF V4f v4f_wwxy(V4f v) { return (V4f) {.c={v.w,v.w,v.x,v.y}}; }
LADEF V4f v4f_xxyy(V4f v) { return (V4f) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4f v4f_yxyy(V4f v) { return (V4f) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4f v4f_zxyy(V4f v) { return (V4f) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4f v4f_wxyy(V4f v) { return (V4f) {.c={v.w,v.x,v.y,v.y}}; }
LADEF V4f v4f_xyyy(V4f v) { return (V4f) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4f v4f_yyyy(V4f v) { return (V4f) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4f v4f_zyyy(V4f v) { return (V4f) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4f v4f_wyyy(V4f v) { return (V4f) {.c={v.w,v.y,v.y,v.y}}; }
LADEF V4f v4f_xzyy(V4f v) { return (V4f) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4f v4f_yzyy(V4f v) { return (V4f) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4f v4f_zzyy(V4f v) { return (V4f) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4f v4f_wzyy(V4f v) { return (V4f) {.c={v.w,v.z,v.y,v.y}}; }
LADEF V4f v4f_xwyy(V4f v) { return (V4f) {.c={v.x,v.w,v.y,v.y}}; }
LADEF V4f v4f_ywyy(V4f v) { return (V4f) {.c={v.y,v.w,v.y,v.y}}; }
LADEF V4f v4f_zwyy(V4f v) { return (V4f) {.c={v.z,v.w,v.y,v.y}}; }
LADEF V4f v4f_wwyy(V4f v) { return (V4f) {.c={v.w,v.w,v.y,v.y}}; }
LADEF V4f v4f_xxzy(V4f v) { return (V4f) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4f v4f_yxzy(V4f v) { return (V4f) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4f v4f_zxzy(V4f v) { return (V4f) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4f v4f_wxzy(V4f v) { return (V4f) {.c={v.w,v.x,v.z,v.y}}; }
LADEF V4f v4f_xyzy(V4f v) { return (V4f) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4f v4f_yyzy(V4f v) { return (V4f) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4f v4f_zyzy(V4f v) { return (V4f) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4f v4f_wyzy(V4f v) { return (V4f) {.c={v.w,v.y,v.z,v.y}}; }
LADEF V4f v4f_xzzy(V4f v) { return (V4f) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4f v4f_yzzy(V4f v) { return (V4f) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4f v4f_zzzy(V4f v) { return (V4f) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4f v4f_wzzy(V4f v) { return (V4f) {.c={v.w,v.z,v.z,v.y}}; }
LADEF V4f v4f_xwzy(V4f v) { return (V4f) {.c={v.x,v.w,v.z,v.y}}; }
LADEF V4f v4f_ywzy(V4f v) { return (V4f) {.c={v.y,v.w,v.z,v.y}}; }
LADEF V4f v4f_zwzy(V4f v) { return (V4f) {.c={v.z,v.w,v.z,v.y}}; }
LADEF V4f v4f_wwzy(V4f v) { return (V4f) {.c={v.w,v.w,v.z,v.y}}; }
LADEF V4f v4f_xxwy(V4f v) { return (V4f) {.c={v.x,v.x,v.w,v.y}}; }
LADEF V4f v4f_yxwy(V4f v) { return (V4f) {.c={v.y,v.x,v.w,v.y}}; }
LADEF V4f v4f_zxwy(V4f v) { return (V4f) {.c={v.z,v.x,v.w,v.y}}; }
LADEF V4f v4f_wxwy(V4f v) { return (V4f) {.c={v.w,v.x,v.w,v.y}}; }
LADEF V4f v4f_xywy(V4f v) { return (V4f) {.c={v.x,v.y,v.w,v.y}}; }
LADEF V4f v4f_yywy(V4f v) { return (V4f) {.c={v.y,v.y,v.w,v.y}}; }
LADEF V4f v4f_zywy(V4f v) { return (V4f) {.c={v.z,v.y,v.w,v.y}}; }
LADEF V4f v4f_wywy(V4f v) { return (V4f) {.c={v.w,v.y,v.w,v.y}}; }
LADEF V4f v4f_xzwy(V4f v) { return (V4f) {.c={v.x,v.z,v.w,v.y}}; }
LADEF V4f v4f_yzwy(V4f v) { return (V4f) {.c={v.y,v.z,v.w,v.y}}; }
LADEF V4f v4f_zzwy(V4f v) { return (V4f) {.c={v.z,v.z,v.w,v.y}}; }
LADEF V4f v4f_wzwy(V4f v) { return (V4f) {.c={v.w,v.z,v.w,v.y}}; }
LADEF V4f v4f_xwwy(V4f v) { return (V4f) {.c={v.x,v.w,v.w,v.y}}; }
LADEF V4f v4f_ywwy(V4f v) { return (V4f) {.c={v.y,v.w,v.w,v.y}}; }
LADEF V4f v4f_zwwy(V4f v) { return (V4f) {.c={v.z,v.w,v.w,v.y}}; }
LADEF V4f v4f_wwwy(V4f v) { return (V4f) {.c={v.w,v.w,v.w,v.y}}; }
LADEF V4f v4f_xxxz(V4f v) { return (V4f) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4f v4f_yxxz(V4f v) { return (V4f) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4f v4f_zxxz(V4f v) { return (V4f) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4f v4f_wxxz(V4f v) { return (V4f) {.c={v.w,v.x,v.x,v.z}}; }
LADEF V4f v4f_xyxz(V4f v) { return (V4f) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4f v4f_yyxz(V4f v) { return (V4f) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4f v4f_zyxz(V4f v) { return (V4f) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4f v4f_wyxz(V4f v) { return (V4f) {.c={v.w,v.y,v.x,v.z}}; }
LADEF V4f v4f_xzxz(V4f v) { return (V4f) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4f v4f_yzxz(V4f v) { return (V4f) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4f v4f_zzxz(V4f v) { return (V4f) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4f v4f_wzxz(V4f v) { return (V4f) {.c={v.w,v.z,v.x,v.z}}; }
LADEF V4f v4f_xwxz(V4f v) { return (V4f) {.c={v.x,v.w,v.x,v.z}}; }
LADEF V4f v4f_ywxz(V4f v) { return (V4f) {.c={v.y,v.w,v.x,v.z}}; }
LADEF V4f v4f_zwxz(V4f v) { return (V4f) {.c={v.z,v.w,v.x,v.z}}; }
LADEF V4f v4f_wwxz(V4f v) { return (V4f) {.c={v.w,v.w,v.x,v.z}}; }
LADEF V4f v4f_xxyz(V4f v) { return (V4f) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4f v4f_yxyz(V4f v) { return (V4f) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4f v4f_zxyz(V4f v) { return (V4f) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4f v4f_wxyz(V4f v) { return (V4f) {.c={v.w,v.x,v.y,v.z}}; }
LADEF V4f v4f_xyyz(V4f v) { return (V4f) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4f v4f_yyyz(V4f v) { return (V4f) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4f v4f_zyyz(V4f v) { return (V4f) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4f v4f_wyyz(V4f v) { return (V4f) {.c={v.w,v.y,v.y,v.z}}; }
LADEF V4f v4f_xzyz(V4f v) { return (V4f) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4f v4f_yzyz(V4f v) { return (V4f) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4f v4f_zzyz(V4f v) { return (V4f) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4f v4f_wzyz(V4f v) { return (V4f) {.c={v.w,v.z,v.y,v.z}}; }
LADEF V4f v4f_xwyz(V4f v) { return (V4f) {.c={v.x,v.w,v.y,v.z}}; }
LADEF V4f v4f_ywyz(V4f v) { return (V4f) {.c={v.y,v.w,v.y,v.z}}; }
LADEF V4f v4f_zwyz(V4f v) { return (V4f) {.c={v.z,v.w,v.y,v.z}}; }
LADEF V4f v4f_wwyz(V4f v) { return (V4f) {.c={v.w,v.w,v.y,v.z}}; }
LADEF V4f v4f_xxzz(V4f v) { return (V4f) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4f v4f_yxzz(V4f v) { return (V4f) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4f v4f_zxzz(V4f v) { return (V4f) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4f v4f_wxzz(V4f v) { return (V4f) {.c={v.w,v.x,v.z,v.z}}; }
LADEF V4f v4f_xyzz(V4f v) { return (V4f) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4f v4f_yyzz(V4f v) { return (V4f) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4f v4f_zyzz(V4f v) { return (V4f) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4f v4f_wyzz(V4f v) { return (V4f) {.c={v.w,v.y,v.z,v.z}}; }
LADEF V4f v4f_xzzz(V4f v) { return (V4f) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4f v4f_yzzz(V4f v) { return (V4f) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4f v4f_zzzz(V4f v) { return (V4f) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4f v4f_wzzz(V4f v) { return (V4f) {.c={v.w,v.z,v.z,v.z}}; }
LADEF V4f v4f_xwzz(V4f v) { return (V4f) {.c={v.x,v.w,v.z,v.z}}; }
LADEF V4f v4f_ywzz(V4f v) { return (V4f) {.c={v.y,v.w,v.z,v.z}}; }
LADEF V4f v4f_zwzz(V4f v) { return (V4f) {.c={v.z,v.w,v.z,v.z}}; }
LADEF V4f v4f_wwzz(V4f v) { return (V4f) {.c={v.w,v.w,v.z,v.z}}; }
LADEF V4f v4f_xxwz(V4f v) { return (V4f) {.c={v.x,v.x,v.w,v.z}}; }
LADEF V4f v4f_yxwz(V4f v) { return (V4f) {.c={v.y,v.x,v.w,v.z}}; }
LADEF V4f v4f_zxwz(V4f v) { return (V4f) {.c={v.z,v.x,v.w,v.z}}; }
LADEF V4f v4f_wxwz(V4f v) { return (V4f) {.c={v.w,v.x,v.w,v.z}}; }
LADEF V4f v4f_xywz(V4f v) { return (V4f) {.c={v.x,v.y,v.w,v.z}}; }
LADEF V4f v4f_yywz(V4f v) { return (V4f) {.c={v.y,v.y,v.w,v.z}}; }
LADEF V4f v4f_zywz(V4f v) { return (V4f) {.c={v.z,v.y,v.w,v.z}}; }
LADEF V4f v4f_wywz(V4f v) { return (V4f) {.c={v.w,v.y,v.w,v.z}}; }
LADEF V4f v4f_xzwz(V4f v) { return (V4f) {.c={v.x,v.z,v.w,v.z}}; }
LADEF V4f v4f_yzwz(V4f v) { return (V4f) {.c={v.y,v.z,v.w,v.z}}; }
LADEF V4f v4f_zzwz(V4f v) { return (V4f) {.c={v.z,v.z,v.w,v.z}}; }
LADEF V4f v4f_wzwz(V4f v) { return (V4f) {.c={v.w,v.z,v.w,v.z}}; }
LADEF V4f v4f_xwwz(V4f v) { return (V4f) {.c={v.x,v.w,v.w,v.z}}; }
LADEF V4f v4f_ywwz(V4f v) { return (V4f) {.c={v.y,v.w,v.w,v.z}}; }
LADEF V4f v4f_zwwz(V4f v) { return (V4f) {.c={v.z,v.w,v.w,v.z}}; }
LADEF V4f v4f_wwwz(V4f v) { return (V4f) {.c={v.w,v.w,v.w,v.z}}; }
LADEF V4f v4f_xxxw(V4f v) { return (V4f) {.c={v.x,v.x,v.x,v.w}}; }
LADEF V4f v4f_yxxw(V4f v) { return (V4f) {.c={v.y,v.x,v.x,v.w}}; }
LADEF V4f v4f_zxxw(V4f v) { return (V4f) {.c={v.z,v.x,v.x,v.w}}; }
LADEF V4f v4f_wxxw(V4f v) { return (V4f) {.c={v.w,v.x,v.x,v.w}}; }
LADEF V4f v4f_xyxw(V4f v) { return (V4f) {.c={v.x,v.y,v.x,v.w}}; }
LADEF V4f v4f_yyxw(V4f v) { return (V4f) {.c={v.y,v.y,v.x,v.w}}; }
LADEF V4f v4f_zyxw(V4f v) { return (V4f) {.c={v.z,v.y,v.x,v.w}}; }
LADEF V4f v4f_wyxw(V4f v) { return (V4f) {.c={v.w,v.y,v.x,v.w}}; }
LADEF V4f v4f_xzxw(V4f v) { return (V4f) {.c={v.x,v.z,v.x,v.w}}; }
LADEF V4f v4f_yzxw(V4f v) { return (V4f) {.c={v.y,v.z,v.x,v.w}}; }
LADEF V4f v4f_zzxw(V4f v) { return (V4f) {.c={v.z,v.z,v.x,v.w}}; }
LADEF V4f v4f_wzxw(V4f v) { return (V4f) {.c={v.w,v.z,v.x,v.w}}; }
LADEF V4f v4f_xwxw(V4f v) { return (V4f) {.c={v.x,v.w,v.x,v.w}}; }
LADEF V4f v4f_ywxw(V4f v) { return (V4f) {.c={v.y,v.w,v.x,v.w}}; }
LADEF V4f v4f_zwxw(V4f v) { return (V4f) {.c={v.z,v.w,v.x,v.w}}; }
LADEF V4f v4f_wwxw(V4f v) { return (V4f) {.c={v.w,v.w,v.x,v.w}}; }
LADEF V4f v4f_xxyw(V4f v) { return (V4f) {.c={v.x,v.x,v.y,v.w}}; }
LADEF V4f v4f_yxyw(V4f v) { return (V4f) {.c={v.y,v.x,v.y,v.w}}; }
LADEF V4f v4f_zxyw(V4f v) { return (V4f) {.c={v.z,v.x,v.y,v.w}}; }
LADEF V4f v4f_wxyw(V4f v) { return (V4f) {.c={v.w,v.x,v.y,v.w}}; }
LADEF V4f v4f_xyyw(V4f v) { return (V4f) {.c={v.x,v.y,v.y,v.w}}; }
LADEF V4f v4f_yyyw(V4f v) { return (V4f) {.c={v.y,v.y,v.y,v.w}}; }
LADEF V4f v4f_zyyw(V4f v) { return (V4f) {.c={v.z,v.y,v.y,v.w}}; }
LADEF V4f v4f_wyyw(V4f v) { return (V4f) {.c={v.w,v.y,v.y,v.w}}; }
LADEF V4f v4f_xzyw(V4f v) { return (V4f) {.c={v.x,v.z,v.y,v.w}}; }
LADEF V4f v4f_yzyw(V4f v) { return (V4f) {.c={v.y,v.z,v.y,v.w}}; }
LADEF V4f v4f_zzyw(V4f v) { return (V4f) {.c={v.z,v.z,v.y,v.w}}; }
LADEF V4f v4f_wzyw(V4f v) { return (V4f) {.c={v.w,v.z,v.y,v.w}}; }
LADEF V4f v4f_xwyw(V4f v) { return (V4f) {.c={v.x,v.w,v.y,v.w}}; }
LADEF V4f v4f_ywyw(V4f v) { return (V4f) {.c={v.y,v.w,v.y,v.w}}; }
LADEF V4f v4f_zwyw(V4f v) { return (V4f) {.c={v.z,v.w,v.y,v.w}}; }
LADEF V4f v4f_wwyw(V4f v) { return (V4f) {.c={v.w,v.w,v.y,v.w}}; }
LADEF V4f v4f_xxzw(V4f v) { return (V4f) {.c={v.x,v.x,v.z,v.w}}; }
LADEF V4f v4f_yxzw(V4f v) { return (V4f) {.c={v.y,v.x,v.z,v.w}}; }
LADEF V4f v4f_zxzw(V4f v) { return (V4f) {.c={v.z,v.x,v.z,v.w}}; }
LADEF V4f v4f_wxzw(V4f v) { return (V4f) {.c={v.w,v.x,v.z,v.w}}; }
LADEF V4f v4f_xyzw(V4f v) { return v; }
LADEF V4f v4f_yyzw(V4f v) { return (V4f) {.c={v.y,v.y,v.z,v.w}}; }
LADEF V4f v4f_zyzw(V4f v) { return (V4f) {.c={v.z,v.y,v.z,v.w}}; }
LADEF V4f v4f_wyzw(V4f v) { return (V4f) {.c={v.w,v.y,v.z,v.w}}; }
LADEF V4f v4f_xzzw(V4f v) { return (V4f) {.c={v.x,v.z,v.z,v.w}}; }
LADEF V4f v4f_yzzw(V4f v) { return (V4f) {.c={v.y,v.z,v.z,v.w}}; }
LADEF V4f v4f_zzzw(V4f v) { return (V4f) {.c={v.z,v.z,v.z,v.w}}; }
LADEF V4f v4f_wzzw(V4f v) { return (V4f) {.c={v.w,v.z,v.z,v.w}}; }
LADEF V4f v4f_xwzw(V4f v) { return (V4f) {.c={v.x,v.w,v.z,v.w}}; }
LADEF V4f v4f_ywzw(V4f v) { return (V4f) {.c={v.y,v.w,v.z,v.w}}; }
LADEF V4f v4f_zwzw(V4f v) { return (V4f) {.c={v.z,v.w,v.z,v.w}}; }
LADEF V4f v4f_wwzw(V4f v) { return (V4f) {.c={v.w,v.w,v.z,v.w}}; }
LADEF V4f v4f_xxww(V4f v) { return (V4f) {.c={v.x,v.x,v.w,v.w}}; }
LADEF V4f v4f_yxww(V4f v) { return (V4f) {.c={v.y,v.x,v.w,v.w}}; }
LADEF V4f v4f_zxww(V4f v) { return (V4f) {.c={v.z,v.x,v.w,v.w}}; }
LADEF V4f v4f_wxww(V4f v) { return (V4f) {.c={v.w,v.x,v.w,v.w}}; }
LADEF V4f v4f_xyww(V4f v) { return (V4f) {.c={v.x,v.y,v.w,v.w}}; }
LADEF V4f v4f_yyww(V4f v) { return (V4f) {.c={v.y,v.y,v.w,v.w}}; }
LADEF V4f v4f_zyww(V4f v) { return (V4f) {.c={v.z,v.y,v.w,v.w}}; }
LADEF V4f v4f_wyww(V4f v) { return (V4f) {.c={v.w,v.y,v.w,v.w}}; }
LADEF V4f v4f_xzww(V4f v) { return (V4f) {.c={v.x,v.z,v.w,v.w}}; }
LADEF V4f v4f_yzww(V4f v) { return (V4f) {.c={v.y,v.z,v.w,v.w}}; }
LADEF V4f v4f_zzww(V4f v) { return (V4f) {.c={v.z,v.z,v.w,v.w}}; }
LADEF V4f v4f_wzww(V4f v) { return (V4f) {.c={v.w,v.z,v.w,v.w}}; }
LADEF V4f v4f_xwww(V4f v) { return (V4f) {.c={v.x,v.w,v.w,v.w}}; }
LADEF V4f v4f_ywww(V4f v) { return (V4f) {.c={v.y,v.w,v.w,v.w}}; }
LADEF V4f v4f_zwww(V4f v) { return (V4f) {.c={v.z,v.w,v.w,v.w}}; }
LADEF V4f v4f_wwww(V4f v) { return (V4f) {.c={v.w,v.w,v.w,v.w}}; }

LADEF V2d v2d_xx(V2d v) { return (V2d) {.c={v.x,v.x}}; }
LADEF V2d v2d_yx(V2d v) { return (V2d) {.c={v.y,v.x}}; }
LADEF V2d v2d_xy(V2d v) { return v; }
LADEF V2d v2d_yy(V2d v) { return (V2d) {.c={v.y,v.y}}; }
LADEF V2d v3d_xx(V3d v) { return (V2d) {.c={v.x,v.x}}; }
LADEF V2d v3d_yx(V3d v) { return (V2d) {.c={v.y,v.x}}; }
LADEF V2d v3d_zx(V3d v) { return (V2d) {.c={v.z,v.x}}; }
LADEF V2d v3d_xy(V3d v) { return (V2d) {.c={v.x,v.y}}; }
LADEF V2d v3d_yy(V3d v) { return (V2d) {.c={v.y,v.y}}; }
LADEF V2d v3d_zy(V3d v) { return (V2d) {.c={v.z,v.y}}; }
LADEF V2d v3d_xz(V3d v) { return (V2d) {.c={v.x,v.z}}; }
LADEF V2d v3d_yz(V3d v) { return (V2d) {.c={v.y,v.z}}; }
LADEF V2d v3d_zz(V3d v) { return (V2d) {.c={v.z,v.z}}; }
LADEF V2d v4d_xx(V4d v) { return (V2d) {.c={v.x,v.x}}; }
LADEF V2d v4d_yx(V4d v) { return (V2d) {.c={v.y,v.x}}; }
LADEF V2d v4d_zx(V4d v) { return (V2d) {.c={v.z,v.x}}; }
LADEF V2d v4d_wx(V4d v) { return (V2d) {.c={v.w,v.x}}; }
LADEF V2d v4d_xy(V4d v) { return (V2d) {.c={v.x,v.y}}; }
LADEF V2d v4d_yy(V4d v) { return (V2d) {.c={v.y,v.y}}; }
LADEF V2d v4d_zy(V4d v) { return (V2d) {.c={v.z,v.y}}; }
LADEF V2d v4d_wy(V4d v) { return (V2d) {.c={v.w,v.y}}; }
LADEF V2d v4d_xz(V4d v) { return (V2d) {.c={v.x,v.z}}; }
LADEF V2d v4d_yz(V4d v) { return (V2d) {.c={v.y,v.z}}; }
LADEF V2d v4d_zz(V4d v) { return (V2d) {.c={v.z,v.z}}; }
LADEF V2d v4d_wz(V4d v) { return (V2d) {.c={v.w,v.z}}; }
LADEF V2d v4d_xw(V4d v) { return (V2d) {.c={v.x,v.w}}; }
LADEF V2d v4d_yw(V4d v) { return (V2d) {.c={v.y,v.w}}; }
LADEF V2d v4d_zw(V4d v) { return (V2d) {.c={v.z,v.w}}; }
LADEF V2d v4d_ww(V4d v) { return (V2d) {.c={v.w,v.w}}; }

LADEF V3d v2d_xxx(V2d v) { return (V3d) {.c={v.x,v.x,v.x}}; }
LADEF V3d v2d_yxx(V2d v) { return (V3d) {.c={v.y,v.x,v.x}}; }
LADEF V3d v2d_xyx(V2d v) { return (V3d) {.c={v.x,v.y,v.x}}; }
LADEF V3d v2d_yyx(V2d v) { return (V3d) {.c={v.y,v.y,v.x}}; }
LADEF V3d v2d_xxy(V2d v) { return (V3d) {.c={v.x,v.x,v.y}}; }
LADEF V3d v2d_yxy(V2d v) { return (V3d) {.c={v.y,v.x,v.y}}; }
LADEF V3d v2d_xyy(V2d v) { return (V3d) {.c={v.x,v.y,v.y}}; }
LADEF V3d v2d_yyy(V2d v) { return (V3d) {.c={v.y,v.y,v.y}}; }
LADEF V3d v3d_xxx(V3d v) { return (V3d) {.c={v.x,v.x,v.x}}; }
LADEF V3d v3d_yxx(V3d v) { return (V3d) {.c={v.y,v.x,v.x}}; }
LADEF V3d v3d_zxx(V3d v) { return (V3d) {.c={v.z,v.x,v.x}}; }
LADEF V3d v3d_xyx(V3d v) { return (V3d) {.c={v.x,v.y,v.x}}; }
LADEF V3d v3d_yyx(V3d v) { return (V3d) {.c={v.y,v.y,v.x}}; }
LADEF V3d v3d_zyx(V3d v) { return (V3d) {.c={v.z,v.y,v.x}}; }
LADEF V3d v3d_xzx(V3d v) { return (V3d) {.c={v.x,v.z,v.x}}; }
LADEF V3d v3d_yzx(V3d v) { return (V3d) {.c={v.y,v.z,v.x}}; }
LADEF V3d v3d_zzx(V3d v) { return (V3d) {.c={v.z,v.z,v.x}}; }
LADEF V3d v3d_xxy(V3d v) { return (V3d) {.c={v.x,v.x,v.y}}; }
LADEF V3d v3d_yxy(V3d v) { return (V3d) {.c={v.y,v.x,v.y}}; }
LADEF V3d v3d_zxy(V3d v) { return (V3d) {.c={v.z,v.x,v.y}}; }
LADEF V3d v3d_xyy(V3d v) { return (V3d) {.c={v.x,v.y,v.y}}; }
LADEF V3d v3d_yyy(V3d v) { return (V3d) {.c={v.y,v.y,v.y}}; }
LADEF V3d v3d_zyy(V3d v) { return (V3d) {.c={v.z,v.y,v.y}}; }
LADEF V3d v3d_xzy(V3d v) { return (V3d) {.c={v.x,v.z,v.y}}; }
LADEF V3d v3d_yzy(V3d v) { return (V3d) {.c={v.y,v.z,v.y}}; }
LADEF V3d v3d_zzy(V3d v) { return (V3d) {.c={v.z,v.z,v.y}}; }
LADEF V3d v3d_xxz(V3d v) { return (V3d) {.c={v.x,v.x,v.z}}; }
LADEF V3d v3d_yxz(V3d v) { return (V3d) {.c={v.y,v.x,v.z}}; }
LADEF V3d v3d_zxz(V3d v) { return (V3d) {.c={v.z,v.x,v.z}}; }
LADEF V3d v3d_xyz(V3d v) { return v; }
LADEF V3d v3d_yyz(V3d v) { return (V3d) {.c={v.y,v.y,v.z}}; }
LADEF V3d v3d_zyz(V3d v) { return (V3d) {.c={v.z,v.y,v.z}}; }
LADEF V3d v3d_xzz(V3d v) { return (V3d) {.c={v.x,v.z,v.z}}; }
LADEF V3d v3d_yzz(V3d v) { return (V3d) {.c={v.y,v.z,v.z}}; }
LADEF V3d v3d_zzz(V3d v) { return (V3d) {.c={v.z,v.z,v.z}}; }
LADEF V3d v4d_xxx(V4d v) { return (V3d) {.c={v.x,v.x,v.x}}; }
LADEF V3d v4d_yxx(V4d v) { return (V3d) {.c={v.y,v.x,v.x}}; }
LADEF V3d v4d_zxx(V4d v) { return (V3d) {.c={v.z,v.x,v.x}}; }
LADEF V3d v4d_wxx(V4d v) { return (V3d) {.c={v.w,v.x,v.x}}; }
LADEF V3d v4d_xyx(V4d v) { return (V3d) {.c={v.x,v.y,v.x}}; }
LADEF V3d v4d_yyx(V4d v) { return (V3d) {.c={v.y,v.y,v.x}}; }
LADEF V3d v4d_zyx(V4d v) { return (V3d) {.c={v.z,v.y,v.x}}; }
LADEF V3d v4d_wyx(V4d v) { return (V3d) {.c={v.w,v.y,v.x}}; }
LADEF V3d v4d_xzx(V4d v) { return (V3d) {.c={v.x,v.z,v.x}}; }
LADEF V3d v4d_yzx(V4d v) { return (V3d) {.c={v.y,v.z,v.x}}; }
LADEF V3d v4d_zzx(V4d v) { return (V3d) {.c={v.z,v.z,v.x}}; }
LADEF V3d v4d_wzx(V4d v) { return (V3d) {.c={v.w,v.z,v.x}}; }
LADEF V3d v4d_xwx(V4d v) { return (V3d) {.c={v.x,v.w,v.x}}; }
LADEF V3d v4d_ywx(V4d v) { return (V3d) {.c={v.y,v.w,v.x}}; }
LADEF V3d v4d_zwx(V4d v) { return (V3d) {.c={v.z,v.w,v.x}}; }
LADEF V3d v4d_wwx(V4d v) { return (V3d) {.c={v.w,v.w,v.x}}; }
LADEF V3d v4d_xxy(V4d v) { return (V3d) {.c={v.x,v.x,v.y}}; }
LADEF V3d v4d_yxy(V4d v) { return (V3d) {.c={v.y,v.x,v.y}}; }
LADEF V3d v4d_zxy(V4d v) { return (V3d) {.c={v.z,v.x,v.y}}; }
LADEF V3d v4d_wxy(V4d v) { return (V3d) {.c={v.w,v.x,v.y}}; }
LADEF V3d v4d_xyy(V4d v) { return (V3d) {.c={v.x,v.y,v.y}}; }
LADEF V3d v4d_yyy(V4d v) { return (V3d) {.c={v.y,v.y,v.y}}; }
LADEF V3d v4d_zyy(V4d v) { return (V3d) {.c={v.z,v.y,v.y}}; }
LADEF V3d v4d_wyy(V4d v) { return (V3d) {.c={v.w,v.y,v.y}}; }
LADEF V3d v4d_xzy(V4d v) { return (V3d) {.c={v.x,v.z,v.y}}; }
LADEF V3d v4d_yzy(V4d v) { return (V3d) {.c={v.y,v.z,v.y}}; }
LADEF V3d v4d_zzy(V4d v) { return (V3d) {.c={v.z,v.z,v.y}}; }
LADEF V3d v4d_wzy(V4d v) { return (V3d) {.c={v.w,v.z,v.y}}; }
LADEF V3d v4d_xwy(V4d v) { return (V3d) {.c={v.x,v.w,v.y}}; }
LADEF V3d v4d_ywy(V4d v) { return (V3d) {.c={v.y,v.w,v.y}}; }
LADEF V3d v4d_zwy(V4d v) { return (V3d) {.c={v.z,v.w,v.y}}; }
LADEF V3d v4d_wwy(V4d v) { return (V3d) {.c={v.w,v.w,v.y}}; }
LADEF V3d v4d_xxz(V4d v) { return (V3d) {.c={v.x,v.x,v.z}}; }
LADEF V3d v4d_yxz(V4d v) { return (V3d) {.c={v.y,v.x,v.z}}; }
LADEF V3d v4d_zxz(V4d v) { return (V3d) {.c={v.z,v.x,v.z}}; }
LADEF V3d v4d_wxz(V4d v) { return (V3d) {.c={v.w,v.x,v.z}}; }
LADEF V3d v4d_xyz(V4d v) { return (V3d) {.c={v.x,v.y,v.z}}; }
LADEF V3d v4d_yyz(V4d v) { return (V3d) {.c={v.y,v.y,v.z}}; }
LADEF V3d v4d_zyz(V4d v) { return (V3d) {.c={v.z,v.y,v.z}}; }
LADEF V3d v4d_wyz(V4d v) { return (V3d) {.c={v.w,v.y,v.z}}; }
LADEF V3d v4d_xzz(V4d v) { return (V3d) {.c={v.x,v.z,v.z}}; }
LADEF V3d v4d_yzz(V4d v) { return (V3d) {.c={v.y,v.z,v.z}}; }
LADEF V3d v4d_zzz(V4d v) { return (V3d) {.c={v.z,v.z,v.z}}; }
LADEF V3d v4d_wzz(V4d v) { return (V3d) {.c={v.w,v.z,v.z}}; }
LADEF V3d v4d_xwz(V4d v) { return (V3d) {.c={v.x,v.w,v.z}}; }
LADEF V3d v4d_ywz(V4d v) { return (V3d) {.c={v.y,v.w,v.z}}; }
LADEF V3d v4d_zwz(V4d v) { return (V3d) {.c={v.z,v.w,v.z}}; }
LADEF V3d v4d_wwz(V4d v) { return (V3d) {.c={v.w,v.w,v.z}}; }
LADEF V3d v4d_xxw(V4d v) { return (V3d) {.c={v.x,v.x,v.w}}; }
LADEF V3d v4d_yxw(V4d v) { return (V3d) {.c={v.y,v.x,v.w}}; }
LADEF V3d v4d_zxw(V4d v) { return (V3d) {.c={v.z,v.x,v.w}}; }
LADEF V3d v4d_wxw(V4d v) { return (V3d) {.c={v.w,v.x,v.w}}; }
LADEF V3d v4d_xyw(V4d v) { return (V3d) {.c={v.x,v.y,v.w}}; }
LADEF V3d v4d_yyw(V4d v) { return (V3d) {.c={v.y,v.y,v.w}}; }
LADEF V3d v4d_zyw(V4d v) { return (V3d) {.c={v.z,v.y,v.w}}; }
LADEF V3d v4d_wyw(V4d v) { return (V3d) {.c={v.w,v.y,v.w}}; }
LADEF V3d v4d_xzw(V4d v) { return (V3d) {.c={v.x,v.z,v.w}}; }
LADEF V3d v4d_yzw(V4d v) { return (V3d) {.c={v.y,v.z,v.w}}; }
LADEF V3d v4d_zzw(V4d v) { return (V3d) {.c={v.z,v.z,v.w}}; }
LADEF V3d v4d_wzw(V4d v) { return (V3d) {.c={v.w,v.z,v.w}}; }
LADEF V3d v4d_xww(V4d v) { return (V3d) {.c={v.x,v.w,v.w}}; }
LADEF V3d v4d_yww(V4d v) { return (V3d) {.c={v.y,v.w,v.w}}; }
LADEF V3d v4d_zww(V4d v) { return (V3d) {.c={v.z,v.w,v.w}}; }
LADEF V3d v4d_www(V4d v) { return (V3d) {.c={v.w,v.w,v.w}}; }

LADEF V4d v2d_xxxx(V2d v) { return (V4d) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4d v2d_yxxx(V2d v) { return (V4d) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4d v2d_xyxx(V2d v) { return (V4d) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4d v2d_yyxx(V2d v) { return (V4d) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4d v2d_xxyx(V2d v) { return (V4d) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4d v2d_yxyx(V2d v) { return (V4d) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4d v2d_xyyx(V2d v) { return (V4d) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4d v2d_yyyx(V2d v) { return (V4d) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4d v2d_xxxy(V2d v) { return (V4d) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4d v2d_yxxy(V2d v) { return (V4d) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4d v2d_xyxy(V2d v) { return (V4d) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4d v2d_yyxy(V2d v) { return (V4d) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4d v2d_xxyy(V2d v) { return (V4d) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4d v2d_yxyy(V2d v) { return (V4d) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4d v2d_xyyy(V2d v) { return (V4d) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4d v2d_yyyy(V2d v) { return (V4d) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4d v3d_xxxx(V3d v) { return (V4d) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4d v3d_yxxx(V3d v) { return (V4d) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4d v3d_zxxx(V3d v) { return (V4d) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4d v3d_xyxx(V3d v) { return (V4d) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4d v3d_yyxx(V3d v) { return (V4d) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4d v3d_zyxx(V3d v) { return (V4d) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4d v3d_xzxx(V3d v) { return (V4d) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4d v3d_yzxx(V3d v) { return (V4d) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4d v3d_zzxx(V3d v) { return (V4d) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4d v3d_xxyx(V3d v) { return (V4d) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4d v3d_yxyx(V3d v) { return (V4d) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4d v3d_zxyx(V3d v) { return (V4d) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4d v3d_xyyx(V3d v) { return (V4d) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4d v3d_yyyx(V3d v) { return (V4d) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4d v3d_zyyx(V3d v) { return (V4d) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4d v3d_xzyx(V3d v) { return (V4d) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4d v3d_yzyx(V3d v) { return (V4d) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4d v3d_zzyx(V3d v) { return (V4d) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4d v3d_xxzx(V3d v) { return (V4d) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4d v3d_yxzx(V3d v) { return (V4d) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4d v3d_zxzx(V3d v) { return (V4d) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4d v3d_xyzx(V3d v) { return (V4d) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4d v3d_yyzx(V3d v) { return (V4d) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4d v3d_zyzx(V3d v) { return (V4d) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4d v3d_xzzx(V3d v) { return (V4d) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4d v3d_yzzx(V3d v) { return (V4d) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4d v3d_zzzx(V3d v) { return (V4d) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4d v3d_xxxy(V3d v) { return (V4d) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4d v3d_yxxy(V3d v) { return (V4d) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4d v3d_zxxy(V3d v) { return (V4d) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4d v3d_xyxy(V3d v) { return (V4d) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4d v3d_yyxy(V3d v) { return (V4d) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4d v3d_zyxy(V3d v) { return (V4d) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4d v3d_xzxy(V3d v) { return (V4d) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4d v3d_yzxy(V3d v) { return (V4d) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4d v3d_zzxy(V3d v) { return (V4d) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4d v3d_xxyy(V3d v) { return (V4d) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4d v3d_yxyy(V3d v) { return (V4d) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4d v3d_zxyy(V3d v) { return (V4d) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4d v3d_xyyy(V3d v) { return (V4d) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4d v3d_yyyy(V3d v) { return (V4d) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4d v3d_zyyy(V3d v) { return (V4d) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4d v3d_xzyy(V3d v) { return (V4d) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4d v3d_yzyy(V3d v) { return (V4d) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4d v3d_zzyy(V3d v) { return (V4d) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4d v3d_xxzy(V3d v) { return (V4d) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4d v3d_yxzy(V3d v) { return (V4d) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4d v3d_zxzy(V3d v) { return (V4d) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4d v3d_xyzy(V3d v) { return (V4d) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4d v3d_yyzy(V3d v) { return (V4d) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4d v3d_zyzy(V3d v) { return (V4d) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4d v3d_xzzy(V3d v) { return (V4d) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4d v3d_yzzy(V3d v) { return (V4d) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4d v3d_zzzy(V3d v) { return (V4d) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4d v3d_xxxz(V3d v) { return (V4d) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4d v3d_yxxz(V3d v) { return (V4d) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4d v3d_zxxz(V3d v) { return (V4d) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4d v3d_xyxz(V3d v) { return (V4d) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4d v3d_yyxz(V3d v) { return (V4d) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4d v3d_zyxz(V3d v) { return (V4d) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4d v3d_xzxz(V3d v) { return (V4d) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4d v3d_yzxz(V3d v) { return (V4d) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4d v3d_zzxz(V3d v) { return (V4d) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4d v3d_xxyz(V3d v) { return (V4d) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4d v3d_yxyz(V3d v) { return (V4d) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4d v3d_zxyz(V3d v) { return (V4d) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4d v3d_xyyz(V3d v) { return (V4d) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4d v3d_yyyz(V3d v) { return (V4d) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4d v3d_zyyz(V3d v) { return (V4d) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4d v3d_xzyz(V3d v) { return (V4d) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4d v3d_yzyz(V3d v) { return (V4d) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4d v3d_zzyz(V3d v) { return (V4d) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4d v3d_xxzz(V3d v) { return (V4d) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4d v3d_yxzz(V3d v) { return (V4d) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4d v3d_zxzz(V3d v) { return (V4d) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4d v3d_xyzz(V3d v) { return (V4d) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4d v3d_yyzz(V3d v) { return (V4d) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4d v3d_zyzz(V3d v) { return (V4d) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4d v3d_xzzz(V3d v) { return (V4d) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4d v3d_yzzz(V3d v) { return (V4d) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4d v3d_zzzz(V3d v) { return (V4d) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4d v4d_xxxx(V4d v) { return (V4d) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4d v4d_yxxx(V4d v) { return (V4d) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4d v4d_zxxx(V4d v) { return (V4d) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4d v4d_wxxx(V4d v) { return (V4d) {.c={v.w,v.x,v.x,v.x}}; }
LADEF V4d v4d_xyxx(V4d v) { return (V4d) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4d v4d_yyxx(V4d v) { return (V4d) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4d v4d_zyxx(V4d v) { return (V4d) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4d v4d_wyxx(V4d v) { return (V4d) {.c={v.w,v.y,v.x,v.x}}; }
LADEF V4d v4d_xzxx(V4d v) { return (V4d) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4d v4d_yzxx(V4d v) { return (V4d) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4d v4d_zzxx(V4d v) { return (V4d) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4d v4d_wzxx(V4d v) { return (V4d) {.c={v.w,v.z,v.x,v.x}}; }
LADEF V4d v4d_xwxx(V4d v) { return (V4d) {.c={v.x,v.w,v.x,v.x}}; }
LADEF V4d v4d_ywxx(V4d v) { return (V4d) {.c={v.y,v.w,v.x,v.x}}; }
LADEF V4d v4d_zwxx(V4d v) { return (V4d) {.c={v.z,v.w,v.x,v.x}}; }
LADEF V4d v4d_wwxx(V4d v) { return (V4d) {.c={v.w,v.w,v.x,v.x}}; }
LADEF V4d v4d_xxyx(V4d v) { return (V4d) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4d v4d_yxyx(V4d v) { return (V4d) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4d v4d_zxyx(V4d v) { return (V4d) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4d v4d_wxyx(V4d v) { return (V4d) {.c={v.w,v.x,v.y,v.x}}; }
LADEF V4d v4d_xyyx(V4d v) { return (V4d) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4d v4d_yyyx(V4d v) { return (V4d) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4d v4d_zyyx(V4d v) { return (V4d) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4d v4d_wyyx(V4d v) { return (V4d) {.c={v.w,v.y,v.y,v.x}}; }
LADEF V4d v4d_xzyx(V4d v) { return (V4d) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4d v4d_yzyx(V4d v) { return (V4d) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4d v4d_zzyx(V4d v) { return (V4d) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4d v4d_wzyx(V4d v) { return (V4d) {.c={v.w,v.z,v.y,v.x}}; }
LADEF V4d v4d_xwyx(V4d v) { return (V4d) {.c={v.x,v.w,v.y,v.x}}; }
LADEF V4d v4d_ywyx(V4d v) { return (V4d) {.c={v.y,v.w,v.y,v.x}}; }
LADEF V4d v4d_zwyx(V4d v) { return (V4d) {.c={v.z,v.w,v.y,v.x}}; }
LADEF V4d v4d_wwyx(V4d v) { return (V4d) {.c={v.w,v.w,v.y,v.x}}; }
LADEF V4d v4d_xxzx(V4d v) { return (V4d) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4d v4d_yxzx(V4d v) { return (V4d) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4d v4d_zxzx(V4d v) { return (V4d) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4d v4d_wxzx(V4d v) { return (V4d) {.c={v.w,v.x,v.z,v.x}}; }
LADEF V4d v4d_xyzx(V4d v) { return (V4d) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4d v4d_yyzx(V4d v) { return (V4d) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4d v4d_zyzx(V4d v) { return (V4d) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4d v4d_wyzx(V4d v) { return (V4d) {.c={v.w,v.y,v.z,v.x}}; }
LADEF V4d v4d_xzzx(V4d v) { return (V4d) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4d v4d_yzzx(V4d v) { return (V4d) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4d v4d_zzzx(V4d v) { return (V4d) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4d v4d_wzzx(V4d v) { return (V4d) {.c={v.w,v.z,v.z,v.x}}; }
LADEF V4d v4d_xwzx(V4d v) { return (V4d) {.c={v.x,v.w,v.z,v.x}}; }
LADEF V4d v4d_ywzx(V4d v) { return (V4d) {.c={v.y,v.w,v.z,v.x}}; }
LADEF V4d v4d_zwzx(V4d v) { return (V4d) {.c={v.z,v.w,v.z,v.x}}; }
LADEF V4d v4d_wwzx(V4d v) { return (V4d) {.c={v.w,v.w,v.z,v.x}}; }
LADEF V4d v4d_xxwx(V4d v) { return (V4d) {.c={v.x,v.x,v.w,v.x}}; }
LADEF V4d v4d_yxwx(V4d v) { return (V4d) {.c={v.y,v.x,v.w,v.x}}; }
LADEF V4d v4d_zxwx(V4d v) { return (V4d) {.c={v.z,v.x,v.w,v.x}}; }
LADEF V4d v4d_wxwx(V4d v) { return (V4d) {.c={v.w,v.x,v.w,v.x}}; }
LADEF V4d v4d_xywx(V4d v) { return (V4d) {.c={v.x,v.y,v.w,v.x}}; }
LADEF V4d v4d_yywx(V4d v) { return (V4d) {.c={v.y,v.y,v.w,v.x}}; }
LADEF V4d v4d_zywx(V4d v) { return (V4d) {.c={v.z,v.y,v.w,v.x}}; }
LADEF V4d v4d_wywx(V4d v) { return (V4d) {.c={v.w,v.y,v.w,v.x}}; }
LADEF V4d v4d_xzwx(V4d v) { return (V4d) {.c={v.x,v.z,v.w,v.x}}; }
LADEF V4d v4d_yzwx(V4d v) { return (V4d) {.c={v.y,v.z,v.w,v.x}}; }
LADEF V4d v4d_zzwx(V4d v) { return (V4d) {.c={v.z,v.z,v.w,v.x}}; }
LADEF V4d v4d_wzwx(V4d v) { return (V4d) {.c={v.w,v.z,v.w,v.x}}; }
LADEF V4d v4d_xwwx(V4d v) { return (V4d) {.c={v.x,v.w,v.w,v.x}}; }
LADEF V4d v4d_ywwx(V4d v) { return (V4d) {.c={v.y,v.w,v.w,v.x}}; }
LADEF V4d v4d_zwwx(V4d v) { return (V4d) {.c={v.z,v.w,v.w,v.x}}; }
LADEF V4d v4d_wwwx(V4d v) { return (V4d) {.c={v.w,v.w,v.w,v.x}}; }
LADEF V4d v4d_xxxy(V4d v) { return (V4d) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4d v4d_yxxy(V4d v) { return (V4d) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4d v4d_zxxy(V4d v) { return (V4d) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4d v4d_wxxy(V4d v) { return (V4d) {.c={v.w,v.x,v.x,v.y}}; }
LADEF V4d v4d_xyxy(V4d v) { return (V4d) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4d v4d_yyxy(V4d v) { return (V4d) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4d v4d_zyxy(V4d v) { return (V4d) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4d v4d_wyxy(V4d v) { return (V4d) {.c={v.w,v.y,v.x,v.y}}; }
LADEF V4d v4d_xzxy(V4d v) { return (V4d) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4d v4d_yzxy(V4d v) { return (V4d) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4d v4d_zzxy(V4d v) { return (V4d) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4d v4d_wzxy(V4d v) { return (V4d) {.c={v.w,v.z,v.x,v.y}}; }
LADEF V4d v4d_xwxy(V4d v) { return (V4d) {.c={v.x,v.w,v.x,v.y}}; }
LADEF V4d v4d_ywxy(V4d v) { return (V4d) {.c={v.y,v.w,v.x,v.y}}; }
LADEF V4d v4d_zwxy(V4d v) { return (V4d) {.c={v.z,v.w,v.x,v.y}}; }
LADEF V4d v4d_wwxy(V4d v) { return (V4d) {.c={v.w,v.w,v.x,v.y}}; }
LADEF V4d v4d_xxyy(V4d v) { return (V4d) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4d v4d_yxyy(V4d v) { return (V4d) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4d v4d_zxyy(V4d v) { return (V4d) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4d v4d_wxyy(V4d v) { return (V4d) {.c={v.w,v.x,v.y,v.y}}; }
LADEF V4d v4d_xyyy(V4d v) { return (V4d) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4d v4d_yyyy(V4d v) { return (V4d) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4d v4d_zyyy(V4d v) { return (V4d) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4d v4d_wyyy(V4d v) { return (V4d) {.c={v.w,v.y,v.y,v.y}}; }
LADEF V4d v4d_xzyy(V4d v) { return (V4d) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4d v4d_yzyy(V4d v) { return (V4d) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4d v4d_zzyy(V4d v) { return (V4d) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4d v4d_wzyy(V4d v) { return (V4d) {.c={v.w,v.z,v.y,v.y}}; }
LADEF V4d v4d_xwyy(V4d v) { return (V4d) {.c={v.x,v.w,v.y,v.y}}; }
LADEF V4d v4d_ywyy(V4d v) { return (V4d) {.c={v.y,v.w,v.y,v.y}}; }
LADEF V4d v4d_zwyy(V4d v) { return (V4d) {.c={v.z,v.w,v.y,v.y}}; }
LADEF V4d v4d_wwyy(V4d v) { return (V4d) {.c={v.w,v.w,v.y,v.y}}; }
LADEF V4d v4d_xxzy(V4d v) { return (V4d) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4d v4d_yxzy(V4d v) { return (V4d) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4d v4d_zxzy(V4d v) { return (V4d) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4d v4d_wxzy(V4d v) { return (V4d) {.c={v.w,v.x,v.z,v.y}}; }
LADEF V4d v4d_xyzy(V4d v) { return (V4d) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4d v4d_yyzy(V4d v) { return (V4d) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4d v4d_zyzy(V4d v) { return (V4d) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4d v4d_wyzy(V4d v) { return (V4d) {.c={v.w,v.y,v.z,v.y}}; }
LADEF V4d v4d_xzzy(V4d v) { return (V4d) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4d v4d_yzzy(V4d v) { return (V4d) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4d v4d_zzzy(V4d v) { return (V4d) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4d v4d_wzzy(V4d v) { return (V4d) {.c={v.w,v.z,v.z,v.y}}; }
LADEF V4d v4d_xwzy(V4d v) { return (V4d) {.c={v.x,v.w,v.z,v.y}}; }
LADEF V4d v4d_ywzy(V4d v) { return (V4d) {.c={v.y,v.w,v.z,v.y}}; }
LADEF V4d v4d_zwzy(V4d v) { return (V4d) {.c={v.z,v.w,v.z,v.y}}; }
LADEF V4d v4d_wwzy(V4d v) { return (V4d) {.c={v.w,v.w,v.z,v.y}}; }
LADEF V4d v4d_xxwy(V4d v) { return (V4d) {.c={v.x,v.x,v.w,v.y}}; }
LADEF V4d v4d_yxwy(V4d v) { return (V4d) {.c={v.y,v.x,v.w,v.y}}; }
LADEF V4d v4d_zxwy(V4d v) { return (V4d) {.c={v.z,v.x,v.w,v.y}}; }
LADEF V4d v4d_wxwy(V4d v) { return (V4d) {.c={v.w,v.x,v.w,v.y}}; }
LADEF V4d v4d_xywy(V4d v) { return (V4d) {.c={v.x,v.y,v.w,v.y}}; }
LADEF V4d v4d_yywy(V4d v) { return (V4d) {.c={v.y,v.y,v.w,v.y}}; }
LADEF V4d v4d_zywy(V4d v) { return (V4d) {.c={v.z,v.y,v.w,v.y}}; }
LADEF V4d v4d_wywy(V4d v) { return (V4d) {.c={v.w,v.y,v.w,v.y}}; }
LADEF V4d v4d_xzwy(V4d v) { return (V4d) {.c={v.x,v.z,v.w,v.y}}; }
LADEF V4d v4d_yzwy(V4d v) { return (V4d) {.c={v.y,v.z,v.w,v.y}}; }
LADEF V4d v4d_zzwy(V4d v) { return (V4d) {.c={v.z,v.z,v.w,v.y}}; }
LADEF V4d v4d_wzwy(V4d v) { return (V4d) {.c={v.w,v.z,v.w,v.y}}; }
LADEF V4d v4d_xwwy(V4d v) { return (V4d) {.c={v.x,v.w,v.w,v.y}}; }
LADEF V4d v4d_ywwy(V4d v) { return (V4d) {.c={v.y,v.w,v.w,v.y}}; }
LADEF V4d v4d_zwwy(V4d v) { return (V4d) {.c={v.z,v.w,v.w,v.y}}; }
LADEF V4d v4d_wwwy(V4d v) { return (V4d) {.c={v.w,v.w,v.w,v.y}}; }
LADEF V4d v4d_xxxz(V4d v) { return (V4d) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4d v4d_yxxz(V4d v) { return (V4d) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4d v4d_zxxz(V4d v) { return (V4d) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4d v4d_wxxz(V4d v) { return (V4d) {.c={v.w,v.x,v.x,v.z}}; }
LADEF V4d v4d_xyxz(V4d v) { return (V4d) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4d v4d_yyxz(V4d v) { return (V4d) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4d v4d_zyxz(V4d v) { return (V4d) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4d v4d_wyxz(V4d v) { return (V4d) {.c={v.w,v.y,v.x,v.z}}; }
LADEF V4d v4d_xzxz(V4d v) { return (V4d) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4d v4d_yzxz(V4d v) { return (V4d) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4d v4d_zzxz(V4d v) { return (V4d) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4d v4d_wzxz(V4d v) { return (V4d) {.c={v.w,v.z,v.x,v.z}}; }
LADEF V4d v4d_xwxz(V4d v) { return (V4d) {.c={v.x,v.w,v.x,v.z}}; }
LADEF V4d v4d_ywxz(V4d v) { return (V4d) {.c={v.y,v.w,v.x,v.z}}; }
LADEF V4d v4d_zwxz(V4d v) { return (V4d) {.c={v.z,v.w,v.x,v.z}}; }
LADEF V4d v4d_wwxz(V4d v) { return (V4d) {.c={v.w,v.w,v.x,v.z}}; }
LADEF V4d v4d_xxyz(V4d v) { return (V4d) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4d v4d_yxyz(V4d v) { return (V4d) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4d v4d_zxyz(V4d v) { return (V4d) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4d v4d_wxyz(V4d v) { return (V4d) {.c={v.w,v.x,v.y,v.z}}; }
LADEF V4d v4d_xyyz(V4d v) { return (V4d) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4d v4d_yyyz(V4d v) { return (V4d) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4d v4d_zyyz(V4d v) { return (V4d) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4d v4d_wyyz(V4d v) { return (V4d) {.c={v.w,v.y,v.y,v.z}}; }
LADEF V4d v4d_xzyz(V4d v) { return (V4d) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4d v4d_yzyz(V4d v) { return (V4d) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4d v4d_zzyz(V4d v) { return (V4d) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4d v4d_wzyz(V4d v) { return (V4d) {.c={v.w,v.z,v.y,v.z}}; }
LADEF V4d v4d_xwyz(V4d v) { return (V4d) {.c={v.x,v.w,v.y,v.z}}; }
LADEF V4d v4d_ywyz(V4d v) { return (V4d) {.c={v.y,v.w,v.y,v.z}}; }
LADEF V4d v4d_zwyz(V4d v) { return (V4d) {.c={v.z,v.w,v.y,v.z}}; }
LADEF V4d v4d_wwyz(V4d v) { return (V4d) {.c={v.w,v.w,v.y,v.z}}; }
LADEF V4d v4d_xxzz(V4d v) { return (V4d) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4d v4d_yxzz(V4d v) { return (V4d) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4d v4d_zxzz(V4d v) { return (V4d) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4d v4d_wxzz(V4d v) { return (V4d) {.c={v.w,v.x,v.z,v.z}}; }
LADEF V4d v4d_xyzz(V4d v) { return (V4d) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4d v4d_yyzz(V4d v) { return (V4d) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4d v4d_zyzz(V4d v) { return (V4d) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4d v4d_wyzz(V4d v) { return (V4d) {.c={v.w,v.y,v.z,v.z}}; }
LADEF V4d v4d_xzzz(V4d v) { return (V4d) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4d v4d_yzzz(V4d v) { return (V4d) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4d v4d_zzzz(V4d v) { return (V4d) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4d v4d_wzzz(V4d v) { return (V4d) {.c={v.w,v.z,v.z,v.z}}; }
LADEF V4d v4d_xwzz(V4d v) { return (V4d) {.c={v.x,v.w,v.z,v.z}}; }
LADEF V4d v4d_ywzz(V4d v) { return (V4d) {.c={v.y,v.w,v.z,v.z}}; }
LADEF V4d v4d_zwzz(V4d v) { return (V4d) {.c={v.z,v.w,v.z,v.z}}; }
LADEF V4d v4d_wwzz(V4d v) { return (V4d) {.c={v.w,v.w,v.z,v.z}}; }
LADEF V4d v4d_xxwz(V4d v) { return (V4d) {.c={v.x,v.x,v.w,v.z}}; }
LADEF V4d v4d_yxwz(V4d v) { return (V4d) {.c={v.y,v.x,v.w,v.z}}; }
LADEF V4d v4d_zxwz(V4d v) { return (V4d) {.c={v.z,v.x,v.w,v.z}}; }
LADEF V4d v4d_wxwz(V4d v) { return (V4d) {.c={v.w,v.x,v.w,v.z}}; }
LADEF V4d v4d_xywz(V4d v) { return (V4d) {.c={v.x,v.y,v.w,v.z}}; }
LADEF V4d v4d_yywz(V4d v) { return (V4d) {.c={v.y,v.y,v.w,v.z}}; }
LADEF V4d v4d_zywz(V4d v) { return (V4d) {.c={v.z,v.y,v.w,v.z}}; }
LADEF V4d v4d_wywz(V4d v) { return (V4d) {.c={v.w,v.y,v.w,v.z}}; }
LADEF V4d v4d_xzwz(V4d v) { return (V4d) {.c={v.x,v.z,v.w,v.z}}; }
LADEF V4d v4d_yzwz(V4d v) { return (V4d) {.c={v.y,v.z,v.w,v.z}}; }
LADEF V4d v4d_zzwz(V4d v) { return (V4d) {.c={v.z,v.z,v.w,v.z}}; }
LADEF V4d v4d_wzwz(V4d v) { return (V4d) {.c={v.w,v.z,v.w,v.z}}; }
LADEF V4d v4d_xwwz(V4d v) { return (V4d) {.c={v.x,v.w,v.w,v.z}}; }
LADEF V4d v4d_ywwz(V4d v) { return (V4d) {.c={v.y,v.w,v.w,v.z}}; }
LADEF V4d v4d_zwwz(V4d v) { return (V4d) {.c={v.z,v.w,v.w,v.z}}; }
LADEF V4d v4d_wwwz(V4d v) { return (V4d) {.c={v.w,v.w,v.w,v.z}}; }
LADEF V4d v4d_xxxw(V4d v) { return (V4d) {.c={v.x,v.x,v.x,v.w}}; }
LADEF V4d v4d_yxxw(V4d v) { return (V4d) {.c={v.y,v.x,v.x,v.w}}; }
LADEF V4d v4d_zxxw(V4d v) { return (V4d) {.c={v.z,v.x,v.x,v.w}}; }
LADEF V4d v4d_wxxw(V4d v) { return (V4d) {.c={v.w,v.x,v.x,v.w}}; }
LADEF V4d v4d_xyxw(V4d v) { return (V4d) {.c={v.x,v.y,v.x,v.w}}; }
LADEF V4d v4d_yyxw(V4d v) { return (V4d) {.c={v.y,v.y,v.x,v.w}}; }
LADEF V4d v4d_zyxw(V4d v) { return (V4d) {.c={v.z,v.y,v.x,v.w}}; }
LADEF V4d v4d_wyxw(V4d v) { return (V4d) {.c={v.w,v.y,v.x,v.w}}; }
LADEF V4d v4d_xzxw(V4d v) { return (V4d) {.c={v.x,v.z,v.x,v.w}}; }
LADEF V4d v4d_yzxw(V4d v) { return (V4d) {.c={v.y,v.z,v.x,v.w}}; }
LADEF V4d v4d_zzxw(V4d v) { return (V4d) {.c={v.z,v.z,v.x,v.w}}; }
LADEF V4d v4d_wzxw(V4d v) { return (V4d) {.c={v.w,v.z,v.x,v.w}}; }
LADEF V4d v4d_xwxw(V4d v) { return (V4d) {.c={v.x,v.w,v.x,v.w}}; }
LADEF V4d v4d_ywxw(V4d v) { return (V4d) {.c={v.y,v.w,v.x,v.w}}; }
LADEF V4d v4d_zwxw(V4d v) { return (V4d) {.c={v.z,v.w,v.x,v.w}}; }
LADEF V4d v4d_wwxw(V4d v) { return (V4d) {.c={v.w,v.w,v.x,v.w}}; }
LADEF V4d v4d_xxyw(V4d v) { return (V4d) {.c={v.x,v.x,v.y,v.w}}; }
LADEF V4d v4d_yxyw(V4d v) { return (V4d) {.c={v.y,v.x,v.y,v.w}}; }
LADEF V4d v4d_zxyw(V4d v) { return (V4d) {.c={v.z,v.x,v.y,v.w}}; }
LADEF V4d v4d_wxyw(V4d v) { return (V4d) {.c={v.w,v.x,v.y,v.w}}; }
LADEF V4d v4d_xyyw(V4d v) { return (V4d) {.c={v.x,v.y,v.y,v.w}}; }
LADEF V4d v4d_yyyw(V4d v) { return (V4d) {.c={v.y,v.y,v.y,v.w}}; }
LADEF V4d v4d_zyyw(V4d v) { return (V4d) {.c={v.z,v.y,v.y,v.w}}; }
LADEF V4d v4d_wyyw(V4d v) { return (V4d) {.c={v.w,v.y,v.y,v.w}}; }
LADEF V4d v4d_xzyw(V4d v) { return (V4d) {.c={v.x,v.z,v.y,v.w}}; }
LADEF V4d v4d_yzyw(V4d v) { return (V4d) {.c={v.y,v.z,v.y,v.w}}; }
LADEF V4d v4d_zzyw(V4d v) { return (V4d) {.c={v.z,v.z,v.y,v.w}}; }
LADEF V4d v4d_wzyw(V4d v) { return (V4d) {.c={v.w,v.z,v.y,v.w}}; }
LADEF V4d v4d_xwyw(V4d v) { return (V4d) {.c={v.x,v.w,v.y,v.w}}; }
LADEF V4d v4d_ywyw(V4d v) { return (V4d) {.c={v.y,v.w,v.y,v.w}}; }
LADEF V4d v4d_zwyw(V4d v) { return (V4d) {.c={v.z,v.w,v.y,v.w}}; }
LADEF V4d v4d_wwyw(V4d v) { return (V4d) {.c={v.w,v.w,v.y,v.w}}; }
LADEF V4d v4d_xxzw(V4d v) { return (V4d) {.c={v.x,v.x,v.z,v.w}}; }
LADEF V4d v4d_yxzw(V4d v) { return (V4d) {.c={v.y,v.x,v.z,v.w}}; }
LADEF V4d v4d_zxzw(V4d v) { return (V4d) {.c={v.z,v.x,v.z,v.w}}; }
LADEF V4d v4d_wxzw(V4d v) { return (V4d) {.c={v.w,v.x,v.z,v.w}}; }
LADEF V4d v4d_xyzw(V4d v) { return v; }
LADEF V4d v4d_yyzw(V4d v) { return (V4d) {.c={v.y,v.y,v.z,v.w}}; }
LADEF V4d v4d_zyzw(V4d v) { return (V4d) {.c={v.z,v.y,v.z,v.w}}; }
LADEF V4d v4d_wyzw(V4d v) { return (V4d) {.c={v.w,v.y,v.z,v.w}}; }
LADEF V4d v4d_xzzw(V4d v) { return (V4d) {.c={v.x,v.z,v.z,v.w}}; }
LADEF V4d v4d_yzzw(V4d v) { return (V4d) {.c={v.y,v.z,v.z,v.w}}; }
LADEF V4d v4d_zzzw(V4d v) { return (V4d) {.c={v.z,v.z,v.z,v.w}}; }
LADEF V4d v4d_wzzw(V4d v) { return (V4d) {.c={v.w,v.z,v.z,v.w}}; }
LADEF V4d v4d_xwzw(V4d v) { return (V4d) {.c={v.x,v.w,v.z,v.w}}; }
LADEF V4d v4d_ywzw(V4d v) { return (V4d) {.c={v.y,v.w,v.z,v.w}}; }
LADEF V4d v4d_zwzw(V4d v) { return (V4d) {.c={v.z,v.w,v.z,v.w}}; }
LADEF V4d v4d_wwzw(V4d v) { return (V4d) {.c={v.w,v.w,v.z,v.w}}; }
LADEF V4d v4d_xxww(V4d v) { return (V4d) {.c={v.x,v.x,v.w,v.w}}; }
LADEF V4d v4d_yxww(V4d v) { return (V4d) {.c={v.y,v.x,v.w,v.w}}; }
LADEF V4d v4d_zxww(V4d v) { return (V4d) {.c={v.z,v.x,v.w,v.w}}; }
LADEF V4d v4d_wxww(V4d v) { return (V4d) {.c={v.w,v.x,v.w,v.w}}; }
LADEF V4d v4d_xyww(V4d v) { return (V4d) {.c={v.x,v.y,v.w,v.w}}; }
LADEF V4d v4d_yyww(V4d v) { return (V4d) {.c={v.y,v.y,v.w,v.w}}; }
LADEF V4d v4d_zyww(V4d v) { return (V4d) {.c={v.z,v.y,v.w,v.w}}; }
LADEF V4d v4d_wyww(V4d v) { return (V4d) {.c={v.w,v.y,v.w,v.w}}; }
LADEF V4d v4d_xzww(V4d v) { return (V4d) {.c={v.x,v.z,v.w,v.w}}; }
LADEF V4d v4d_yzww(V4d v) { return (V4d) {.c={v.y,v.z,v.w,v.w}}; }
LADEF V4d v4d_zzww(V4d v) { return (V4d) {.c={v.z,v.z,v.w,v.w}}; }
LADEF V4d v4d_wzww(V4d v) { return (V4d) {.c={v.w,v.z,v.w,v.w}}; }
LADEF V4d v4d_xwww(V4d v) { return (V4d) {.c={v.x,v.w,v.w,v.w}}; }
LADEF V4d v4d_ywww(V4d v) { return (V4d) {.c={v.y,v.w,v.w,v.w}}; }
LADEF V4d v4d_zwww(V4d v) { return (V4d) {.c={v.z,v.w,v.w,v.w}}; }
LADEF V4d v4d_wwww(V4d v) { return (V4d) {.c={v.w,v.w,v.w,v.w}}; }

LADEF V2i v2i_xx(V2i v) { return (V2i) {.c={v.x,v.x}}; }
LADEF V2i v2i_yx(V2i v) { return (V2i) {.c={v.y,v.x}}; }
LADEF V2i v2i_xy(V2i v) { return v; }
LADEF V2i v2i_yy(V2i v) { return (V2i) {.c={v.y,v.y}}; }
LADEF V2i v3i_xx(V3i v) { return (V2i) {.c={v.x,v.x}}; }
LADEF V2i v3i_yx(V3i v) { return (V2i) {.c={v.y,v.x}}; }
LADEF V2i v3i_zx(V3i v) { return (V2i) {.c={v.z,v.x}}; }
LADEF V2i v3i_xy(V3i v) { return (V2i) {.c={v.x,v.y}}; }
LADEF V2i v3i_yy(V3i v) { return (V2i) {.c={v.y,v.y}}; }
LADEF V2i v3i_zy(V3i v) { return (V2i) {.c={v.z,v.y}}; }
LADEF V2i v3i_xz(V3i v) { return (V2i) {.c={v.x,v.z}}; }
LADEF V2i v3i_yz(V3i v) { return (V2i) {.c={v.y,v.z}}; }
LADEF V2i v3i_zz(V3i v) { return (V2i) {.c={v.z,v.z}}; }
LADEF V2i v4i_xx(V4i v) { return (V2i) {.c={v.x,v.x}}; }
LADEF V2i v4i_yx(V4i v) { return (V2i) {.c={v.y,v.x}}; }
LADEF V2i v4i_zx(V4i v) { return (V2i) {.c={v.z,v.x}}; }
LADEF V2i v4i_wx(V4i v) { return (V2i) {.c={v.w,v.x}}; }
LADEF V2i v4i_xy(V4i v) { return (V2i) {.c={v.x,v.y}}; }
LADEF V2i v4i_yy(V4i v) { return (V2i) {.c={v.y,v.y}}; }
LADEF V2i v4i_zy(V4i v) { return (V2i) {.c={v.z,v.y}}; }
LADEF V2i v4i_wy(V4i v) { return (V2i) {.c={v.w,v.y}}; }
LADEF V2i v4i_xz(V4i v) { return (V2i) {.c={v.x,v.z}}; }
LADEF V2i v4i_yz(V4i v) { return (V2i) {.c={v.y,v.z}}; }
LADEF V2i v4i_zz(V4i v) { return (V2i) {.c={v.z,v.z}}; }
LADEF V2i v4i_wz(V4i v) { return (V2i) {.c={v.w,v.z}}; }
LADEF V2i v4i_xw(V4i v) { return (V2i) {.c={v.x,v.w}}; }
LADEF V2i v4i_yw(V4i v) { return (V2i) {.c={v.y,v.w}}; }
LADEF V2i v4i_zw(V4i v) { return (V2i) {.c={v.z,v.w}}; }
LADEF V2i v4i_ww(V4i v) { return (V2i) {.c={v.w,v.w}}; }

LADEF V3i v2i_xxx(V2i v) { return (V3i) {.c={v.x,v.x,v.x}}; }
LADEF V3i v2i_yxx(V2i v) { return (V3i) {.c={v.y,v.x,v.x}}; }
LADEF V3i v2i_xyx(V2i v) { return (V3i) {.c={v.x,v.y,v.x}}; }
LADEF V3i v2i_yyx(V2i v) { return (V3i) {.c={v.y,v.y,v.x}}; }
LADEF V3i v2i_xxy(V2i v) { return (V3i) {.c={v.x,v.x,v.y}}; }
LADEF V3i v2i_yxy(V2i v) { return (V3i) {.c={v.y,v.x,v.y}}; }
LADEF V3i v2i_xyy(V2i v) { return (V3i) {.c={v.x,v.y,v.y}}; }
LADEF V3i v2i_yyy(V2i v) { return (V3i) {.c={v.y,v.y,v.y}}; }
LADEF V3i v3i_xxx(V3i v) { return (V3i) {.c={v.x,v.x,v.x}}; }
LADEF V3i v3i_yxx(V3i v) { return (V3i) {.c={v.y,v.x,v.x}}; }
LADEF V3i v3i_zxx(V3i v) { return (V3i) {.c={v.z,v.x,v.x}}; }
LADEF V3i v3i_xyx(V3i v) { return (V3i) {.c={v.x,v.y,v.x}}; }
LADEF V3i v3i_yyx(V3i v) { return (V3i) {.c={v.y,v.y,v.x}}; }
LADEF V3i v3i_zyx(V3i v) { return (V3i) {.c={v.z,v.y,v.x}}; }
LADEF V3i v3i_xzx(V3i v) { return (V3i) {.c={v.x,v.z,v.x}}; }
LADEF V3i v3i_yzx(V3i v) { return (V3i) {.c={v.y,v.z,v.x}}; }
LADEF V3i v3i_zzx(V3i v) { return (V3i) {.c={v.z,v.z,v.x}}; }
LADEF V3i v3i_xxy(V3i v) { return (V3i) {.c={v.x,v.x,v.y}}; }
LADEF V3i v3i_yxy(V3i v) { return (V3i) {.c={v.y,v.x,v.y}}; }
LADEF V3i v3i_zxy(V3i v) { return (V3i) {.c={v.z,v.x,v.y}}; }
LADEF V3i v3i_xyy(V3i v) { return (V3i) {.c={v.x,v.y,v.y}}; }
LADEF V3i v3i_yyy(V3i v) { return (V3i) {.c={v.y,v.y,v.y}}; }
LADEF V3i v3i_zyy(V3i v) { return (V3i) {.c={v.z,v.y,v.y}}; }
LADEF V3i v3i_xzy(V3i v) { return (V3i) {.c={v.x,v.z,v.y}}; }
LADEF V3i v3i_yzy(V3i v) { return (V3i) {.c={v.y,v.z,v.y}}; }
LADEF V3i v3i_zzy(V3i v) { return (V3i) {.c={v.z,v.z,v.y}}; }
LADEF V3i v3i_xxz(V3i v) { return (V3i) {.c={v.x,v.x,v.z}}; }
LADEF V3i v3i_yxz(V3i v) { return (V3i) {.c={v.y,v.x,v.z}}; }
LADEF V3i v3i_zxz(V3i v) { return (V3i) {.c={v.z,v.x,v.z}}; }
LADEF V3i v3i_xyz(V3i v) { return v; }
LADEF V3i v3i_yyz(V3i v) { return (V3i) {.c={v.y,v.y,v.z}}; }
LADEF V3i v3i_zyz(V3i v) { return (V3i) {.c={v.z,v.y,v.z}}; }
LADEF V3i v3i_xzz(V3i v) { return (V3i) {.c={v.x,v.z,v.z}}; }
LADEF V3i v3i_yzz(V3i v) { return (V3i) {.c={v.y,v.z,v.z}}; }
LADEF V3i v3i_zzz(V3i v) { return (V3i) {.c={v.z,v.z,v.z}}; }
LADEF V3i v4i_xxx(V4i v) { return (V3i) {.c={v.x,v.x,v.x}}; }
LADEF V3i v4i_yxx(V4i v) { return (V3i) {.c={v.y,v.x,v.x}}; }
LADEF V3i v4i_zxx(V4i v) { return (V3i) {.c={v.z,v.x,v.x}}; }
LADEF V3i v4i_wxx(V4i v) { return (V3i) {.c={v.w,v.x,v.x}}; }
LADEF V3i v4i_xyx(V4i v) { return (V3i) {.c={v.x,v.y,v.x}}; }
LADEF V3i v4i_yyx(V4i v) { return (V3i) {.c={v.y,v.y,v.x}}; }
LADEF V3i v4i_zyx(V4i v) { return (V3i) {.c={v.z,v.y,v.x}}; }
LADEF V3i v4i_wyx(V4i v) { return (V3i) {.c={v.w,v.y,v.x}}; }
LADEF V3i v4i_xzx(V4i v) { return (V3i) {.c={v.x,v.z,v.x}}; }
LADEF V3i v4i_yzx(V4i v) { return (V3i) {.c={v.y,v.z,v.x}}; }
LADEF V3i v4i_zzx(V4i v) { return (V3i) {.c={v.z,v.z,v.x}}; }
LADEF V3i v4i_wzx(V4i v) { return (V3i) {.c={v.w,v.z,v.x}}; }
LADEF V3i v4i_xwx(V4i v) { return (V3i) {.c={v.x,v.w,v.x}}; }
LADEF V3i v4i_ywx(V4i v) { return (V3i) {.c={v.y,v.w,v.x}}; }
LADEF V3i v4i_zwx(V4i v) { return (V3i) {.c={v.z,v.w,v.x}}; }
LADEF V3i v4i_wwx(V4i v) { return (V3i) {.c={v.w,v.w,v.x}}; }
LADEF V3i v4i_xxy(V4i v) { return (V3i) {.c={v.x,v.x,v.y}}; }
LADEF V3i v4i_yxy(V4i v) { return (V3i) {.c={v.y,v.x,v.y}}; }
LADEF V3i v4i_zxy(V4i v) { return (V3i) {.c={v.z,v.x,v.y}}; }
LADEF V3i v4i_wxy(V4i v) { return (V3i) {.c={v.w,v.x,v.y}}; }
LADEF V3i v4i_xyy(V4i v) { return (V3i) {.c={v.x,v.y,v.y}}; }
LADEF V3i v4i_yyy(V4i v) { return (V3i) {.c={v.y,v.y,v.y}}; }
LADEF V3i v4i_zyy(V4i v) { return (V3i) {.c={v.z,v.y,v.y}}; }
LADEF V3i v4i_wyy(V4i v) { return (V3i) {.c={v.w,v.y,v.y}}; }
LADEF V3i v4i_xzy(V4i v) { return (V3i) {.c={v.x,v.z,v.y}}; }
LADEF V3i v4i_yzy(V4i v) { return (V3i) {.c={v.y,v.z,v.y}}; }
LADEF V3i v4i_zzy(V4i v) { return (V3i) {.c={v.z,v.z,v.y}}; }
LADEF V3i v4i_wzy(V4i v) { return (V3i) {.c={v.w,v.z,v.y}}; }
LADEF V3i v4i_xwy(V4i v) { return (V3i) {.c={v.x,v.w,v.y}}; }
LADEF V3i v4i_ywy(V4i v) { return (V3i) {.c={v.y,v.w,v.y}}; }
LADEF V3i v4i_zwy(V4i v) { return (V3i) {.c={v.z,v.w,v.y}}; }
LADEF V3i v4i_wwy(V4i v) { return (V3i) {.c={v.w,v.w,v.y}}; }
LADEF V3i v4i_xxz(V4i v) { return (V3i) {.c={v.x,v.x,v.z}}; }
LADEF V3i v4i_yxz(V4i v) { return (V3i) {.c={v.y,v.x,v.z}}; }
LADEF V3i v4i_zxz(V4i v) { return (V3i) {.c={v.z,v.x,v.z}}; }
LADEF V3i v4i_wxz(V4i v) { return (V3i) {.c={v.w,v.x,v.z}}; }
LADEF V3i v4i_xyz(V4i v) { return (V3i) {.c={v.x,v.y,v.z}}; }
LADEF V3i v4i_yyz(V4i v) { return (V3i) {.c={v.y,v.y,v.z}}; }
LADEF V3i v4i_zyz(V4i v) { return (V3i) {.c={v.z,v.y,v.z}}; }
LADEF V3i v4i_wyz(V4i v) { return (V3i) {.c={v.w,v.y,v.z}}; }
LADEF V3i v4i_xzz(V4i v) { return (V3i) {.c={v.x,v.z,v.z}}; }
LADEF V3i v4i_yzz(V4i v) { return (V3i) {.c={v.y,v.z,v.z}}; }
LADEF V3i v4i_zzz(V4i v) { return (V3i) {.c={v.z,v.z,v.z}}; }
LADEF V3i v4i_wzz(V4i v) { return (V3i) {.c={v.w,v.z,v.z}}; }
LADEF V3i v4i_xwz(V4i v) { return (V3i) {.c={v.x,v.w,v.z}}; }
LADEF V3i v4i_ywz(V4i v) { return (V3i) {.c={v.y,v.w,v.z}}; }
LADEF V3i v4i_zwz(V4i v) { return (V3i) {.c={v.z,v.w,v.z}}; }
LADEF V3i v4i_wwz(V4i v) { return (V3i) {.c={v.w,v.w,v.z}}; }
LADEF V3i v4i_xxw(V4i v) { return (V3i) {.c={v.x,v.x,v.w}}; }
LADEF V3i v4i_yxw(V4i v) { return (V3i) {.c={v.y,v.x,v.w}}; }
LADEF V3i v4i_zxw(V4i v) { return (V3i) {.c={v.z,v.x,v.w}}; }
LADEF V3i v4i_wxw(V4i v) { return (V3i) {.c={v.w,v.x,v.w}}; }
LADEF V3i v4i_xyw(V4i v) { return (V3i) {.c={v.x,v.y,v.w}}; }
LADEF V3i v4i_yyw(V4i v) { return (V3i) {.c={v.y,v.y,v.w}}; }
LADEF V3i v4i_zyw(V4i v) { return (V3i) {.c={v.z,v.y,v.w}}; }
LADEF V3i v4i_wyw(V4i v) { return (V3i) {.c={v.w,v.y,v.w}}; }
LADEF V3i v4i_xzw(V4i v) { return (V3i) {.c={v.x,v.z,v.w}}; }
LADEF V3i v4i_yzw(V4i v) { return (V3i) {.c={v.y,v.z,v.w}}; }
LADEF V3i v4i_zzw(V4i v) { return (V3i) {.c={v.z,v.z,v.w}}; }
LADEF V3i v4i_wzw(V4i v) { return (V3i) {.c={v.w,v.z,v.w}}; }
LADEF V3i v4i_xww(V4i v) { return (V3i) {.c={v.x,v.w,v.w}}; }
LADEF V3i v4i_yww(V4i v) { return (V3i) {.c={v.y,v.w,v.w}}; }
LADEF V3i v4i_zww(V4i v) { return (V3i) {.c={v.z,v.w,v.w}}; }
LADEF V3i v4i_www(V4i v) { return (V3i) {.c={v.w,v.w,v.w}}; }

LADEF V4i v2i_xxxx(V2i v) { return (V4i) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4i v2i_yxxx(V2i v) { return (V4i) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4i v2i_xyxx(V2i v) { return (V4i) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4i v2i_yyxx(V2i v) { return (V4i) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4i v2i_xxyx(V2i v) { return (V4i) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4i v2i_yxyx(V2i v) { return (V4i) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4i v2i_xyyx(V2i v) { return (V4i) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4i v2i_yyyx(V2i v) { return (V4i) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4i v2i_xxxy(V2i v) { return (V4i) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4i v2i_yxxy(V2i v) { return (V4i) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4i v2i_xyxy(V2i v) { return (V4i) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4i v2i_yyxy(V2i v) { return (V4i) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4i v2i_xxyy(V2i v) { return (V4i) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4i v2i_yxyy(V2i v) { return (V4i) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4i v2i_xyyy(V2i v) { return (V4i) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4i v2i_yyyy(V2i v) { return (V4i) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4i v3i_xxxx(V3i v) { return (V4i) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4i v3i_yxxx(V3i v) { return (V4i) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4i v3i_zxxx(V3i v) { return (V4i) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4i v3i_xyxx(V3i v) { return (V4i) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4i v3i_yyxx(V3i v) { return (V4i) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4i v3i_zyxx(V3i v) { return (V4i) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4i v3i_xzxx(V3i v) { return (V4i) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4i v3i_yzxx(V3i v) { return (V4i) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4i v3i_zzxx(V3i v) { return (V4i) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4i v3i_xxyx(V3i v) { return (V4i) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4i v3i_yxyx(V3i v) { return (V4i) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4i v3i_zxyx(V3i v) { return (V4i) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4i v3i_xyyx(V3i v) { return (V4i) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4i v3i_yyyx(V3i v) { return (V4i) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4i v3i_zyyx(V3i v) { return (V4i) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4i v3i_xzyx(V3i v) { return (V4i) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4i v3i_yzyx(V3i v) { return (V4i) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4i v3i_zzyx(V3i v) { return (V4i) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4i v3i_xxzx(V3i v) { return (V4i) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4i v3i_yxzx(V3i v) { return (V4i) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4i v3i_zxzx(V3i v) { return (V4i) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4i v3i_xyzx(V3i v) { return (V4i) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4i v3i_yyzx(V3i v) { return (V4i) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4i v3i_zyzx(V3i v) { return (V4i) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4i v3i_xzzx(V3i v) { return (V4i) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4i v3i_yzzx(V3i v) { return (V4i) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4i v3i_zzzx(V3i v) { return (V4i) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4i v3i_xxxy(V3i v) { return (V4i) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4i v3i_yxxy(V3i v) { return (V4i) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4i v3i_zxxy(V3i v) { return (V4i) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4i v3i_xyxy(V3i v) { return (V4i) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4i v3i_yyxy(V3i v) { return (V4i) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4i v3i_zyxy(V3i v) { return (V4i) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4i v3i_xzxy(V3i v) { return (V4i) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4i v3i_yzxy(V3i v) { return (V4i) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4i v3i_zzxy(V3i v) { return (V4i) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4i v3i_xxyy(V3i v) { return (V4i) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4i v3i_yxyy(V3i v) { return (V4i) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4i v3i_zxyy(V3i v) { return (V4i) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4i v3i_xyyy(V3i v) { return (V4i) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4i v3i_yyyy(V3i v) { return (V4i) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4i v3i_zyyy(V3i v) { return (V4i) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4i v3i_xzyy(V3i v) { return (V4i) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4i v3i_yzyy(V3i v) { return (V4i) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4i v3i_zzyy(V3i v) { return (V4i) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4i v3i_xxzy(V3i v) { return (V4i) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4i v3i_yxzy(V3i v) { return (V4i) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4i v3i_zxzy(V3i v) { return (V4i) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4i v3i_xyzy(V3i v) { return (V4i) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4i v3i_yyzy(V3i v) { return (V4i) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4i v3i_zyzy(V3i v) { return (V4i) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4i v3i_xzzy(V3i v) { return (V4i) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4i v3i_yzzy(V3i v) { return (V4i) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4i v3i_zzzy(V3i v) { return (V4i) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4i v3i_xxxz(V3i v) { return (V4i) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4i v3i_yxxz(V3i v) { return (V4i) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4i v3i_zxxz(V3i v) { return (V4i) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4i v3i_xyxz(V3i v) { return (V4i) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4i v3i_yyxz(V3i v) { return (V4i) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4i v3i_zyxz(V3i v) { return (V4i) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4i v3i_xzxz(V3i v) { return (V4i) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4i v3i_yzxz(V3i v) { return (V4i) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4i v3i_zzxz(V3i v) { return (V4i) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4i v3i_xxyz(V3i v) { return (V4i) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4i v3i_yxyz(V3i v) { return (V4i) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4i v3i_zxyz(V3i v) { return (V4i) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4i v3i_xyyz(V3i v) { return (V4i) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4i v3i_yyyz(V3i v) { return (V4i) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4i v3i_zyyz(V3i v) { return (V4i) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4i v3i_xzyz(V3i v) { return (V4i) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4i v3i_yzyz(V3i v) { return (V4i) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4i v3i_zzyz(V3i v) { return (V4i) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4i v3i_xxzz(V3i v) { return (V4i) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4i v3i_yxzz(V3i v) { return (V4i) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4i v3i_zxzz(V3i v) { return (V4i) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4i v3i_xyzz(V3i v) { return (V4i) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4i v3i_yyzz(V3i v) { return (V4i) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4i v3i_zyzz(V3i v) { return (V4i) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4i v3i_xzzz(V3i v) { return (V4i) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4i v3i_yzzz(V3i v) { return (V4i) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4i v3i_zzzz(V3i v) { return (V4i) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4i v4i_xxxx(V4i v) { return (V4i) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4i v4i_yxxx(V4i v) { return (V4i) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4i v4i_zxxx(V4i v) { return (V4i) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4i v4i_wxxx(V4i v) { return (V4i) {.c={v.w,v.x,v.x,v.x}}; }
LADEF V4i v4i_xyxx(V4i v) { return (V4i) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4i v4i_yyxx(V4i v) { return (V4i) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4i v4i_zyxx(V4i v) { return (V4i) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4i v4i_wyxx(V4i v) { return (V4i) {.c={v.w,v.y,v.x,v.x}}; }
LADEF V4i v4i_xzxx(V4i v) { return (V4i) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4i v4i_yzxx(V4i v) { return (V4i) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4i v4i_zzxx(V4i v) { return (V4i) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4i v4i_wzxx(V4i v) { return (V4i) {.c={v.w,v.z,v.x,v.x}}; }
LADEF V4i v4i_xwxx(V4i v) { return (V4i) {.c={v.x,v.w,v.x,v.x}}; }
LADEF V4i v4i_ywxx(V4i v) { return (V4i) {.c={v.y,v.w,v.x,v.x}}; }
LADEF V4i v4i_zwxx(V4i v) { return (V4i) {.c={v.z,v.w,v.x,v.x}}; }
LADEF V4i v4i_wwxx(V4i v) { return (V4i) {.c={v.w,v.w,v.x,v.x}}; }
LADEF V4i v4i_xxyx(V4i v) { return (V4i) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4i v4i_yxyx(V4i v) { return (V4i) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4i v4i_zxyx(V4i v) { return (V4i) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4i v4i_wxyx(V4i v) { return (V4i) {.c={v.w,v.x,v.y,v.x}}; }
LADEF V4i v4i_xyyx(V4i v) { return (V4i) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4i v4i_yyyx(V4i v) { return (V4i) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4i v4i_zyyx(V4i v) { return (V4i) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4i v4i_wyyx(V4i v) { return (V4i) {.c={v.w,v.y,v.y,v.x}}; }
LADEF V4i v4i_xzyx(V4i v) { return (V4i) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4i v4i_yzyx(V4i v) { return (V4i) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4i v4i_zzyx(V4i v) { return (V4i) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4i v4i_wzyx(V4i v) { return (V4i) {.c={v.w,v.z,v.y,v.x}}; }
LADEF V4i v4i_xwyx(V4i v) { return (V4i) {.c={v.x,v.w,v.y,v.x}}; }
LADEF V4i v4i_ywyx(V4i v) { return (V4i) {.c={v.y,v.w,v.y,v.x}}; }
LADEF V4i v4i_zwyx(V4i v) { return (V4i) {.c={v.z,v.w,v.y,v.x}}; }
LADEF V4i v4i_wwyx(V4i v) { return (V4i) {.c={v.w,v.w,v.y,v.x}}; }
LADEF V4i v4i_xxzx(V4i v) { return (V4i) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4i v4i_yxzx(V4i v) { return (V4i) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4i v4i_zxzx(V4i v) { return (V4i) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4i v4i_wxzx(V4i v) { return (V4i) {.c={v.w,v.x,v.z,v.x}}; }
LADEF V4i v4i_xyzx(V4i v) { return (V4i) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4i v4i_yyzx(V4i v) { return (V4i) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4i v4i_zyzx(V4i v) { return (V4i) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4i v4i_wyzx(V4i v) { return (V4i) {.c={v.w,v.y,v.z,v.x}}; }
LADEF V4i v4i_xzzx(V4i v) { return (V4i) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4i v4i_yzzx(V4i v) { return (V4i) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4i v4i_zzzx(V4i v) { return (V4i) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4i v4i_wzzx(V4i v) { return (V4i) {.c={v.w,v.z,v.z,v.x}}; }
LADEF V4i v4i_xwzx(V4i v) { return (V4i) {.c={v.x,v.w,v.z,v.x}}; }
LADEF V4i v4i_ywzx(V4i v) { return (V4i) {.c={v.y,v.w,v.z,v.x}}; }
LADEF V4i v4i_zwzx(V4i v) { return (V4i) {.c={v.z,v.w,v.z,v.x}}; }
LADEF V4i v4i_wwzx(V4i v) { return (V4i) {.c={v.w,v.w,v.z,v.x}}; }
LADEF V4i v4i_xxwx(V4i v) { return (V4i) {.c={v.x,v.x,v.w,v.x}}; }
LADEF V4i v4i_yxwx(V4i v) { return (V4i) {.c={v.y,v.x,v.w,v.x}}; }
LADEF V4i v4i_zxwx(V4i v) { return (V4i) {.c={v.z,v.x,v.w,v.x}}; }
LADEF V4i v4i_wxwx(V4i v) { return (V4i) {.c={v.w,v.x,v.w,v.x}}; }
LADEF V4i v4i_xywx(V4i v) { return (V4i) {.c={v.x,v.y,v.w,v.x}}; }
LADEF V4i v4i_yywx(V4i v) { return (V4i) {.c={v.y,v.y,v.w,v.x}}; }
LADEF V4i v4i_zywx(V4i v) { return (V4i) {.c={v.z,v.y,v.w,v.x}}; }
LADEF V4i v4i_wywx(V4i v) { return (V4i) {.c={v.w,v.y,v.w,v.x}}; }
LADEF V4i v4i_xzwx(V4i v) { return (V4i) {.c={v.x,v.z,v.w,v.x}}; }
LADEF V4i v4i_yzwx(V4i v) { return (V4i) {.c={v.y,v.z,v.w,v.x}}; }
LADEF V4i v4i_zzwx(V4i v) { return (V4i) {.c={v.z,v.z,v.w,v.x}}; }
LADEF V4i v4i_wzwx(V4i v) { return (V4i) {.c={v.w,v.z,v.w,v.x}}; }
LADEF V4i v4i_xwwx(V4i v) { return (V4i) {.c={v.x,v.w,v.w,v.x}}; }
LADEF V4i v4i_ywwx(V4i v) { return (V4i) {.c={v.y,v.w,v.w,v.x}}; }
LADEF V4i v4i_zwwx(V4i v) { return (V4i) {.c={v.z,v.w,v.w,v.x}}; }
LADEF V4i v4i_wwwx(V4i v) { return (V4i) {.c={v.w,v.w,v.w,v.x}}; }
LADEF V4i v4i_xxxy(V4i v) { return (V4i) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4i v4i_yxxy(V4i v) { return (V4i) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4i v4i_zxxy(V4i v) { return (V4i) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4i v4i_wxxy(V4i v) { return (V4i) {.c={v.w,v.x,v.x,v.y}}; }
LADEF V4i v4i_xyxy(V4i v) { return (V4i) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4i v4i_yyxy(V4i v) { return (V4i) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4i v4i_zyxy(V4i v) { return (V4i) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4i v4i_wyxy(V4i v) { return (V4i) {.c={v.w,v.y,v.x,v.y}}; }
LADEF V4i v4i_xzxy(V4i v) { return (V4i) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4i v4i_yzxy(V4i v) { return (V4i) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4i v4i_zzxy(V4i v) { return (V4i) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4i v4i_wzxy(V4i v) { return (V4i) {.c={v.w,v.z,v.x,v.y}}; }
LADEF V4i v4i_xwxy(V4i v) { return (V4i) {.c={v.x,v.w,v.x,v.y}}; }
LADEF V4i v4i_ywxy(V4i v) { return (V4i) {.c={v.y,v.w,v.x,v.y}}; }
LADEF V4i v4i_zwxy(V4i v) { return (V4i) {.c={v.z,v.w,v.x,v.y}}; }
LADEF V4i v4i_wwxy(V4i v) { return (V4i) {.c={v.w,v.w,v.x,v.y}}; }
LADEF V4i v4i_xxyy(V4i v) { return (V4i) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4i v4i_yxyy(V4i v) { return (V4i) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4i v4i_zxyy(V4i v) { return (V4i) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4i v4i_wxyy(V4i v) { return (V4i) {.c={v.w,v.x,v.y,v.y}}; }
LADEF V4i v4i_xyyy(V4i v) { return (V4i) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4i v4i_yyyy(V4i v) { return (V4i) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4i v4i_zyyy(V4i v) { return (V4i) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4i v4i_wyyy(V4i v) { return (V4i) {.c={v.w,v.y,v.y,v.y}}; }
LADEF V4i v4i_xzyy(V4i v) { return (V4i) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4i v4i_yzyy(V4i v) { return (V4i) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4i v4i_zzyy(V4i v) { return (V4i) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4i v4i_wzyy(V4i v) { return (V4i) {.c={v.w,v.z,v.y,v.y}}; }
LADEF V4i v4i_xwyy(V4i v) { return (V4i) {.c={v.x,v.w,v.y,v.y}}; }
LADEF V4i v4i_ywyy(V4i v) { return (V4i) {.c={v.y,v.w,v.y,v.y}}; }
LADEF V4i v4i_zwyy(V4i v) { return (V4i) {.c={v.z,v.w,v.y,v.y}}; }
LADEF V4i v4i_wwyy(V4i v) { return (V4i) {.c={v.w,v.w,v.y,v.y}}; }
LADEF V4i v4i_xxzy(V4i v) { return (V4i) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4i v4i_yxzy(V4i v) { return (V4i) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4i v4i_zxzy(V4i v) { return (V4i) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4i v4i_wxzy(V4i v) { return (V4i) {.c={v.w,v.x,v.z,v.y}}; }
LADEF V4i v4i_xyzy(V4i v) { return (V4i) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4i v4i_yyzy(V4i v) { return (V4i) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4i v4i_zyzy(V4i v) { return (V4i) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4i v4i_wyzy(V4i v) { return (V4i) {.c={v.w,v.y,v.z,v.y}}; }
LADEF V4i v4i_xzzy(V4i v) { return (V4i) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4i v4i_yzzy(V4i v) { return (V4i) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4i v4i_zzzy(V4i v) { return (V4i) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4i v4i_wzzy(V4i v) { return (V4i) {.c={v.w,v.z,v.z,v.y}}; }
LADEF V4i v4i_xwzy(V4i v) { return (V4i) {.c={v.x,v.w,v.z,v.y}}; }
LADEF V4i v4i_ywzy(V4i v) { return (V4i) {.c={v.y,v.w,v.z,v.y}}; }
LADEF V4i v4i_zwzy(V4i v) { return (V4i) {.c={v.z,v.w,v.z,v.y}}; }
LADEF V4i v4i_wwzy(V4i v) { return (V4i) {.c={v.w,v.w,v.z,v.y}}; }
LADEF V4i v4i_xxwy(V4i v) { return (V4i) {.c={v.x,v.x,v.w,v.y}}; }
LADEF V4i v4i_yxwy(V4i v) { return (V4i) {.c={v.y,v.x,v.w,v.y}}; }
LADEF V4i v4i_zxwy(V4i v) { return (V4i) {.c={v.z,v.x,v.w,v.y}}; }
LADEF V4i v4i_wxwy(V4i v) { return (V4i) {.c={v.w,v.x,v.w,v.y}}; }
LADEF V4i v4i_xywy(V4i v) { return (V4i) {.c={v.x,v.y,v.w,v.y}}; }
LADEF V4i v4i_yywy(V4i v) { return (V4i) {.c={v.y,v.y,v.w,v.y}}; }
LADEF V4i v4i_zywy(V4i v) { return (V4i) {.c={v.z,v.y,v.w,v.y}}; }
LADEF V4i v4i_wywy(V4i v) { return (V4i) {.c={v.w,v.y,v.w,v.y}}; }
LADEF V4i v4i_xzwy(V4i v) { return (V4i) {.c={v.x,v.z,v.w,v.y}}; }
LADEF V4i v4i_yzwy(V4i v) { return (V4i) {.c={v.y,v.z,v.w,v.y}}; }
LADEF V4i v4i_zzwy(V4i v) { return (V4i) {.c={v.z,v.z,v.w,v.y}}; }
LADEF V4i v4i_wzwy(V4i v) { return (V4i) {.c={v.w,v.z,v.w,v.y}}; }
LADEF V4i v4i_xwwy(V4i v) { return (V4i) {.c={v.x,v.w,v.w,v.y}}; }
LADEF V4i v4i_ywwy(V4i v) { return (V4i) {.c={v.y,v.w,v.w,v.y}}; }
LADEF V4i v4i_zwwy(V4i v) { return (V4i) {.c={v.z,v.w,v.w,v.y}}; }
LADEF V4i v4i_wwwy(V4i v) { return (V4i) {.c={v.w,v.w,v.w,v.y}}; }
LADEF V4i v4i_xxxz(V4i v) { return (V4i) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4i v4i_yxxz(V4i v) { return (V4i) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4i v4i_zxxz(V4i v) { return (V4i) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4i v4i_wxxz(V4i v) { return (V4i) {.c={v.w,v.x,v.x,v.z}}; }
LADEF V4i v4i_xyxz(V4i v) { return (V4i) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4i v4i_yyxz(V4i v) { return (V4i) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4i v4i_zyxz(V4i v) { return (V4i) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4i v4i_wyxz(V4i v) { return (V4i) {.c={v.w,v.y,v.x,v.z}}; }
LADEF V4i v4i_xzxz(V4i v) { return (V4i) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4i v4i_yzxz(V4i v) { return (V4i) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4i v4i_zzxz(V4i v) { return (V4i) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4i v4i_wzxz(V4i v) { return (V4i) {.c={v.w,v.z,v.x,v.z}}; }
LADEF V4i v4i_xwxz(V4i v) { return (V4i) {.c={v.x,v.w,v.x,v.z}}; }
LADEF V4i v4i_ywxz(V4i v) { return (V4i) {.c={v.y,v.w,v.x,v.z}}; }
LADEF V4i v4i_zwxz(V4i v) { return (V4i) {.c={v.z,v.w,v.x,v.z}}; }
LADEF V4i v4i_wwxz(V4i v) { return (V4i) {.c={v.w,v.w,v.x,v.z}}; }
LADEF V4i v4i_xxyz(V4i v) { return (V4i) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4i v4i_yxyz(V4i v) { return (V4i) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4i v4i_zxyz(V4i v) { return (V4i) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4i v4i_wxyz(V4i v) { return (V4i) {.c={v.w,v.x,v.y,v.z}}; }
LADEF V4i v4i_xyyz(V4i v) { return (V4i) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4i v4i_yyyz(V4i v) { return (V4i) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4i v4i_zyyz(V4i v) { return (V4i) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4i v4i_wyyz(V4i v) { return (V4i) {.c={v.w,v.y,v.y,v.z}}; }
LADEF V4i v4i_xzyz(V4i v) { return (V4i) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4i v4i_yzyz(V4i v) { return (V4i) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4i v4i_zzyz(V4i v) { return (V4i) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4i v4i_wzyz(V4i v) { return (V4i) {.c={v.w,v.z,v.y,v.z}}; }
LADEF V4i v4i_xwyz(V4i v) { return (V4i) {.c={v.x,v.w,v.y,v.z}}; }
LADEF V4i v4i_ywyz(V4i v) { return (V4i) {.c={v.y,v.w,v.y,v.z}}; }
LADEF V4i v4i_zwyz(V4i v) { return (V4i) {.c={v.z,v.w,v.y,v.z}}; }
LADEF V4i v4i_wwyz(V4i v) { return (V4i) {.c={v.w,v.w,v.y,v.z}}; }
LADEF V4i v4i_xxzz(V4i v) { return (V4i) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4i v4i_yxzz(V4i v) { return (V4i) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4i v4i_zxzz(V4i v) { return (V4i) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4i v4i_wxzz(V4i v) { return (V4i) {.c={v.w,v.x,v.z,v.z}}; }
LADEF V4i v4i_xyzz(V4i v) { return (V4i) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4i v4i_yyzz(V4i v) { return (V4i) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4i v4i_zyzz(V4i v) { return (V4i) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4i v4i_wyzz(V4i v) { return (V4i) {.c={v.w,v.y,v.z,v.z}}; }
LADEF V4i v4i_xzzz(V4i v) { return (V4i) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4i v4i_yzzz(V4i v) { return (V4i) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4i v4i_zzzz(V4i v) { return (V4i) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4i v4i_wzzz(V4i v) { return (V4i) {.c={v.w,v.z,v.z,v.z}}; }
LADEF V4i v4i_xwzz(V4i v) { return (V4i) {.c={v.x,v.w,v.z,v.z}}; }
LADEF V4i v4i_ywzz(V4i v) { return (V4i) {.c={v.y,v.w,v.z,v.z}}; }
LADEF V4i v4i_zwzz(V4i v) { return (V4i) {.c={v.z,v.w,v.z,v.z}}; }
LADEF V4i v4i_wwzz(V4i v) { return (V4i) {.c={v.w,v.w,v.z,v.z}}; }
LADEF V4i v4i_xxwz(V4i v) { return (V4i) {.c={v.x,v.x,v.w,v.z}}; }
LADEF V4i v4i_yxwz(V4i v) { return (V4i) {.c={v.y,v.x,v.w,v.z}}; }
LADEF V4i v4i_zxwz(V4i v) { return (V4i) {.c={v.z,v.x,v.w,v.z}}; }
LADEF V4i v4i_wxwz(V4i v) { return (V4i) {.c={v.w,v.x,v.w,v.z}}; }
LADEF V4i v4i_xywz(V4i v) { return (V4i) {.c={v.x,v.y,v.w,v.z}}; }
LADEF V4i v4i_yywz(V4i v) { return (V4i) {.c={v.y,v.y,v.w,v.z}}; }
LADEF V4i v4i_zywz(V4i v) { return (V4i) {.c={v.z,v.y,v.w,v.z}}; }
LADEF V4i v4i_wywz(V4i v) { return (V4i) {.c={v.w,v.y,v.w,v.z}}; }
LADEF V4i v4i_xzwz(V4i v) { return (V4i) {.c={v.x,v.z,v.w,v.z}}; }
LADEF V4i v4i_yzwz(V4i v) { return (V4i) {.c={v.y,v.z,v.w,v.z}}; }
LADEF V4i v4i_zzwz(V4i v) { return (V4i) {.c={v.z,v.z,v.w,v.z}}; }
LADEF V4i v4i_wzwz(V4i v) { return (V4i) {.c={v.w,v.z,v.w,v.z}}; }
LADEF V4i v4i_xwwz(V4i v) { return (V4i) {.c={v.x,v.w,v.w,v.z}}; }
LADEF V4i v4i_ywwz(V4i v) { return (V4i) {.c={v.y,v.w,v.w,v.z}}; }
LADEF V4i v4i_zwwz(V4i v) { return (V4i) {.c={v.z,v.w,v.w,v.z}}; }
LADEF V4i v4i_wwwz(V4i v) { return (V4i) {.c={v.w,v.w,v.w,v.z}}; }
LADEF V4i v4i_xxxw(V4i v) { return (V4i) {.c={v.x,v.x,v.x,v.w}}; }
LADEF V4i v4i_yxxw(V4i v) { return (V4i) {.c={v.y,v.x,v.x,v.w}}; }
LADEF V4i v4i_zxxw(V4i v) { return (V4i) {.c={v.z,v.x,v.x,v.w}}; }
LADEF V4i v4i_wxxw(V4i v) { return (V4i) {.c={v.w,v.x,v.x,v.w}}; }
LADEF V4i v4i_xyxw(V4i v) { return (V4i) {.c={v.x,v.y,v.x,v.w}}; }
LADEF V4i v4i_yyxw(V4i v) { return (V4i) {.c={v.y,v.y,v.x,v.w}}; }
LADEF V4i v4i_zyxw(V4i v) { return (V4i) {.c={v.z,v.y,v.x,v.w}}; }
LADEF V4i v4i_wyxw(V4i v) { return (V4i) {.c={v.w,v.y,v.x,v.w}}; }
LADEF V4i v4i_xzxw(V4i v) { return (V4i) {.c={v.x,v.z,v.x,v.w}}; }
LADEF V4i v4i_yzxw(V4i v) { return (V4i) {.c={v.y,v.z,v.x,v.w}}; }
LADEF V4i v4i_zzxw(V4i v) { return (V4i) {.c={v.z,v.z,v.x,v.w}}; }
LADEF V4i v4i_wzxw(V4i v) { return (V4i) {.c={v.w,v.z,v.x,v.w}}; }
LADEF V4i v4i_xwxw(V4i v) { return (V4i) {.c={v.x,v.w,v.x,v.w}}; }
LADEF V4i v4i_ywxw(V4i v) { return (V4i) {.c={v.y,v.w,v.x,v.w}}; }
LADEF V4i v4i_zwxw(V4i v) { return (V4i) {.c={v.z,v.w,v.x,v.w}}; }
LADEF V4i v4i_wwxw(V4i v) { return (V4i) {.c={v.w,v.w,v.x,v.w}}; }
LADEF V4i v4i_xxyw(V4i v) { return (V4i) {.c={v.x,v.x,v.y,v.w}}; }
LADEF V4i v4i_yxyw(V4i v) { return (V4i) {.c={v.y,v.x,v.y,v.w}}; }
LADEF V4i v4i_zxyw(V4i v) { return (V4i) {.c={v.z,v.x,v.y,v.w}}; }
LADEF V4i v4i_wxyw(V4i v) { return (V4i) {.c={v.w,v.x,v.y,v.w}}; }
LADEF V4i v4i_xyyw(V4i v) { return (V4i) {.c={v.x,v.y,v.y,v.w}}; }
LADEF V4i v4i_yyyw(V4i v) { return (V4i) {.c={v.y,v.y,v.y,v.w}}; }
LADEF V4i v4i_zyyw(V4i v) { return (V4i) {.c={v.z,v.y,v.y,v.w}}; }
LADEF V4i v4i_wyyw(V4i v) { return (V4i) {.c={v.w,v.y,v.y,v.w}}; }
LADEF V4i v4i_xzyw(V4i v) { return (V4i) {.c={v.x,v.z,v.y,v.w}}; }
LADEF V4i v4i_yzyw(V4i v) { return (V4i) {.c={v.y,v.z,v.y,v.w}}; }
LADEF V4i v4i_zzyw(V4i v) { return (V4i) {.c={v.z,v.z,v.y,v.w}}; }
LADEF V4i v4i_wzyw(V4i v) { return (V4i) {.c={v.w,v.z,v.y,v.w}}; }
LADEF V4i v4i_xwyw(V4i v) { return (V4i) {.c={v.x,v.w,v.y,v.w}}; }
LADEF V4i v4i_ywyw(V4i v) { return (V4i) {.c={v.y,v.w,v.y,v.w}}; }
LADEF V4i v4i_zwyw(V4i v) { return (V4i) {.c={v.z,v.w,v.y,v.w}}; }
LADEF V4i v4i_wwyw(V4i v) { return (V4i) {.c={v.w,v.w,v.y,v.w}}; }
LADEF V4i v4i_xxzw(V4i v) { return (V4i) {.c={v.x,v.x,v.z,v.w}}; }
LADEF V4i v4i_yxzw(V4i v) { return (V4i) {.c={v.y,v.x,v.z,v.w}}; }
LADEF V4i v4i_zxzw(V4i v) { return (V4i) {.c={v.z,v.x,v.z,v.w}}; }
LADEF V4i v4i_wxzw(V4i v) { return (V4i) {.c={v.w,v.x,v.z,v.w}}; }
LADEF V4i v4i_xyzw(V4i v) { return v; }
LADEF V4i v4i_yyzw(V4i v) { return (V4i) {.c={v.y,v.y,v.z,v.w}}; }
LADEF V4i v4i_zyzw(V4i v) { return (V4i) {.c={v.z,v.y,v.z,v.w}}; }
LADEF V4i v4i_wyzw(V4i v) { return (V4i) {.c={v.w,v.y,v.z,v.w}}; }
LADEF V4i v4i_xzzw(V4i v) { return (V4i) {.c={v.x,v.z,v.z,v.w}}; }
LADEF V4i v4i_yzzw(V4i v) { return (V4i) {.c={v.y,v.z,v.z,v.w}}; }
LADEF V4i v4i_zzzw(V4i v) { return (V4i) {.c={v.z,v.z,v.z,v.w}}; }
LADEF V4i v4i_wzzw(V4i v) { return (V4i) {.c={v.w,v.z,v.z,v.w}}; }
LADEF V4i v4i_xwzw(V4i v) { return (V4i) {.c={v.x,v.w,v.z,v.w}}; }
LADEF V4i v4i_ywzw(V4i v) { return (V4i) {.c={v.y,v.w,v.z,v.w}}; }
LADEF V4i v4i_zwzw(V4i v) { return (V4i) {.c={v.z,v.w,v.z,v.w}}; }
LADEF V4i v4i_wwzw(V4i v) { return (V4i) {.c={v.w,v.w,v.z,v.w}}; }
LADEF V4i v4i_xxww(V4i v) { return (V4i) {.c={v.x,v.x,v.w,v.w}}; }
LADEF V4i v4i_yxww(V4i v) { return (V4i) {.c={v.y,v.x,v.w,v.w}}; }
LADEF V4i v4i_zxww(V4i v) { return (V4i) {.c={v.z,v.x,v.w,v.w}}; }
LADEF V4i v4i_wxww(V4i v) { return (V4i) {.c={v.w,v.x,v.w,v.w}}; }
LADEF V4i v4i_xyww(V4i v) { return (V4i) {.c={v.x,v.y,v.w,v.w}}; }
LADEF V4i v4i_yyww(V4i v) { return (V4i) {.c={v.y,v.y,v.w,v.w}}; }
LADEF V4i v4i_zyww(V4i v) { return (V4i) {.c={v.z,v.y,v.w,v.w}}; }
LADEF V4i v4i_wyww(V4i v) { return (V4i) {.c={v.w,v.y,v.w,v.w}}; }
LADEF V4i v4i_xzww(V4i v) { return (V4i) {.c={v.x,v.z,v.w,v.w}}; }
LADEF V4i v4i_yzww(V4i v) { return (V4i) {.c={v.y,v.z,v.w,v.w}}; }
LADEF V4i v4i_zzww(V4i v) { return (V4i) {.c={v.z,v.z,v.w,v.w}}; }
LADEF V4i v4i_wzww(V4i v) { return (V4i) {.c={v.w,v.z,v.w,v.w}}; }
LADEF V4i v4i_xwww(V4i v) { return (V4i) {.c={v.x,v.w,v.w,v.w}}; }
LADEF V4i v4i_ywww(V4i v) { return (V4i) {.c={v.y,v.w,v.w,v.w}}; }
LADEF V4i v4i_zwww(V4i v) { return (V4i) {.c={v.z,v.w,v.w,v.w}}; }
LADEF V4i v4i_wwww(V4i v) { return (V4i) {.c={v.w,v.w,v.w,v.w}}; }

LADEF V2u v2u_xx(V2u v) { return (V2u) {.c={v.x,v.x}}; }
LADEF V2u v2u_yx(V2u v) { return (V2u) {.c={v.y,v.x}}; }
LADEF V2u v2u_xy(V2u v) { return v; }
LADEF V2u v2u_yy(V2u v) { return (V2u) {.c={v.y,v.y}}; }
LADEF V2u v3u_xx(V3u v) { return (V2u) {.c={v.x,v.x}}; }
LADEF V2u v3u_yx(V3u v) { return (V2u) {.c={v.y,v.x}}; }
LADEF V2u v3u_zx(V3u v) { return (V2u) {.c={v.z,v.x}}; }
LADEF V2u v3u_xy(V3u v) { return (V2u) {.c={v.x,v.y}}; }
LADEF V2u v3u_yy(V3u v) { return (V2u) {.c={v.y,v.y}}; }
LADEF V2u v3u_zy(V3u v) { return (V2u) {.c={v.z,v.y}}; }
LADEF V2u v3u_xz(V3u v) { return (V2u) {.c={v.x,v.z}}; }
LADEF V2u v3u_yz(V3u v) { return (V2u) {.c={v.y,v.z}}; }
LADEF V2u v3u_zz(V3u v) { return (V2u) {.c={v.z,v.z}}; }
LADEF V2u v4u_xx(V4u v) { return (V2u) {.c={v.x,v.x}}; }
LADEF V2u v4u_yx(V4u v) { return (V2u) {.c={v.y,v.x}}; }
LADEF V2u v4u_zx(V4u v) { return (V2u) {.c={v.z,v.x}}; }
LADEF V2u v4u_wx(V4u v) { return (V2u) {.c={v.w,v.x}}; }
LADEF V2u v4u_xy(V4u v) { return (V2u) {.c={v.x,v.y}}; }
LADEF V2u v4u_yy(V4u v) { return (V2u) {.c={v.y,v.y}}; }
LADEF V2u v4u_zy(V4u v) { return (V2u) {.c={v.z,v.y}}; }
LADEF V2u v4u_wy(V4u v) { return (V2u) {.c={v.w,v.y}}; }
LADEF V2u v4u_xz(V4u v) { return (V2u) {.c={v.x,v.z}}; }
LADEF V2u v4u_yz(V4u v) { return (V2u) {.c={v.y,v.z}}; }
LADEF V2u v4u_zz(V4u v) { return (V2u) {.c={v.z,v.z}}; }
LADEF V2u v4u_wz(V4u v) { return (V2u) {.c={v.w,v.z}}; }
LADEF V2u v4u_xw(V4u v) { return (V2u) {.c={v.x,v.w}}; }
LADEF V2u v4u_yw(V4u v) { return (V2u) {.c={v.y,v.w}}; }
LADEF V2u v4u_zw(V4u v) { return (V2u) {.c={v.z,v.w}}; }
LADEF V2u v4u_ww(V4u v) { return (V2u) {.c={v.w,v.w}}; }

LADEF V3u v2u_xxx(V2u v) { return (V3u) {.c={v.x,v.x,v.x}}; }
LADEF V3u v2u_yxx(V2u v) { return (V3u) {.c={v.y,v.x,v.x}}; }
LADEF V3u v2u_xyx(V2u v) { return (V3u) {.c={v.x,v.y,v.x}}; }
LADEF V3u v2u_yyx(V2u v) { return (V3u) {.c={v.y,v.y,v.x}}; }
LADEF V3u v2u_xxy(V2u v) { return (V3u) {.c={v.x,v.x,v.y}}; }
LADEF V3u v2u_yxy(V2u v) { return (V3u) {.c={v.y,v.x,v.y}}; }
LADEF V3u v2u_xyy(V2u v) { return (V3u) {.c={v.x,v.y,v.y}}; }
LADEF V3u v2u_yyy(V2u v) { return (V3u) {.c={v.y,v.y,v.y}}; }
LADEF V3u v3u_xxx(V3u v) { return (V3u) {.c={v.x,v.x,v.x}}; }
LADEF V3u v3u_yxx(V3u v) { return (V3u) {.c={v.y,v.x,v.x}}; }
LADEF V3u v3u_zxx(V3u v) { return (V3u) {.c={v.z,v.x,v.x}}; }
LADEF V3u v3u_xyx(V3u v) { return (V3u) {.c={v.x,v.y,v.x}}; }
LADEF V3u v3u_yyx(V3u v) { return (V3u) {.c={v.y,v.y,v.x}}; }
LADEF V3u v3u_zyx(V3u v) { return (V3u) {.c={v.z,v.y,v.x}}; }
LADEF V3u v3u_xzx(V3u v) { return (V3u) {.c={v.x,v.z,v.x}}; }
LADEF V3u v3u_yzx(V3u v) { return (V3u) {.c={v.y,v.z,v.x}}; }
LADEF V3u v3u_zzx(V3u v) { return (V3u) {.c={v.z,v.z,v.x}}; }
LADEF V3u v3u_xxy(V3u v) { return (V3u) {.c={v.x,v.x,v.y}}; }
LADEF V3u v3u_yxy(V3u v) { return (V3u) {.c={v.y,v.x,v.y}}; }
LADEF V3u v3u_zxy(V3u v) { return (V3u) {.c={v.z,v.x,v.y}}; }
LADEF V3u v3u_xyy(V3u v) { return (V3u) {.c={v.x,v.y,v.y}}; }
LADEF V3u v3u_yyy(V3u v) { return (V3u) {.c={v.y,v.y,v.y}}; }
LADEF V3u v3u_zyy(V3u v) { return (V3u) {.c={v.z,v.y,v.y}}; }
LADEF V3u v3u_xzy(V3u v) { return (V3u) {.c={v.x,v.z,v.y}}; }
LADEF V3u v3u_yzy(V3u v) { return (V3u) {.c={v.y,v.z,v.y}}; }
LADEF V3u v3u_zzy(V3u v) { return (V3u) {.c={v.z,v.z,v.y}}; }
LADEF V3u v3u_xxz(V3u v) { return (V3u) {.c={v.x,v.x,v.z}}; }
LADEF V3u v3u_yxz(V3u v) { return (V3u) {.c={v.y,v.x,v.z}}; }
LADEF V3u v3u_zxz(V3u v) { return (V3u) {.c={v.z,v.x,v.z}}; }
LADEF V3u v3u_xyz(V3u v) { return v; }
LADEF V3u v3u_yyz(V3u v) { return (V3u) {.c={v.y,v.y,v.z}}; }
LADEF V3u v3u_zyz(V3u v) { return (V3u) {.c={v.z,v.y,v.z}}; }
LADEF V3u v3u_xzz(V3u v) { return (V3u) {.c={v.x,v.z,v.z}}; }
LADEF V3u v3u_yzz(V3u v) { return (V3u) {.c={v.y,v.z,v.z}}; }
LADEF V3u v3u_zzz(V3u v) { return (V3u) {.c={v.z,v.z,v.z}}; }
LADEF V3u v4u_xxx(V4u v) { return (V3u) {.c={v.x,v.x,v.x}}; }
LADEF V3u v4u_yxx(V4u v) { return (V3u) {.c={v.y,v.x,v.x}}; }
LADEF V3u v4u_zxx(V4u v) { return (V3u) {.c={v.z,v.x,v.x}}; }
LADEF V3u v4u_wxx(V4u v) { return (V3u) {.c={v.w,v.x,v.x}}; }
LADEF V3u v4u_xyx(V4u v) { return (V3u) {.c={v.x,v.y,v.x}}; }
LADEF V3u v4u_yyx(V4u v) { return (V3u) {.c={v.y,v.y,v.x}}; }
LADEF V3u v4u_zyx(V4u v) { return (V3u) {.c={v.z,v.y,v.x}}; }
LADEF V3u v4u_wyx(V4u v) { return (V3u) {.c={v.w,v.y,v.x}}; }
LADEF V3u v4u_xzx(V4u v) { return (V3u) {.c={v.x,v.z,v.x}}; }
LADEF V3u v4u_yzx(V4u v) { return (V3u) {.c={v.y,v.z,v.x}}; }
LADEF V3u v4u_zzx(V4u v) { return (V3u) {.c={v.z,v.z,v.x}}; }
LADEF V3u v4u_wzx(V4u v) { return (V3u) {.c={v.w,v.z,v.x}}; }
LADEF V3u v4u_xwx(V4u v) { return (V3u) {.c={v.x,v.w,v.x}}; }
LADEF V3u v4u_ywx(V4u v) { return (V3u) {.c={v.y,v.w,v.x}}; }
LADEF V3u v4u_zwx(V4u v) { return (V3u) {.c={v.z,v.w,v.x}}; }
LADEF V3u v4u_wwx(V4u v) { return (V3u) {.c={v.w,v.w,v.x}}; }
LADEF V3u v4u_xxy(V4u v) { return (V3u) {.c={v.x,v.x,v.y}}; }
LADEF V3u v4u_yxy(V4u v) { return (V3u) {.c={v.y,v.x,v.y}}; }
LADEF V3u v4u_zxy(V4u v) { return (V3u) {.c={v.z,v.x,v.y}}; }
LADEF V3u v4u_wxy(V4u v) { return (V3u) {.c={v.w,v.x,v.y}}; }
LADEF V3u v4u_xyy(V4u v) { return (V3u) {.c={v.x,v.y,v.y}}; }
LADEF V3u v4u_yyy(V4u v) { return (V3u) {.c={v.y,v.y,v.y}}; }
LADEF V3u v4u_zyy(V4u v) { return (V3u) {.c={v.z,v.y,v.y}}; }
LADEF V3u v4u_wyy(V4u v) { return (V3u) {.c={v.w,v.y,v.y}}; }
LADEF V3u v4u_xzy(V4u v) { return (V3u) {.c={v.x,v.z,v.y}}; }
LADEF V3u v4u_yzy(V4u v) { return (V3u) {.c={v.y,v.z,v.y}}; }
LADEF V3u v4u_zzy(V4u v) { return (V3u) {.c={v.z,v.z,v.y}}; }
LADEF V3u v4u_wzy(V4u v) { return (V3u) {.c={v.w,v.z,v.y}}; }
LADEF V3u v4u_xwy(V4u v) { return (V3u) {.c={v.x,v.w,v.y}}; }
LADEF V3u v4u_ywy(V4u v) { return (V3u) {.c={v.y,v.w,v.y}}; }
LADEF V3u v4u_zwy(V4u v) { return (V3u) {.c={v.z,v.w,v.y}}; }
LADEF V3u v4u_wwy(V4u v) { return (V3u) {.c={v.w,v.w,v.y}}; }
LADEF V3u v4u_xxz(V4u v) { return (V3u) {.c={v.x,v.x,v.z}}; }
LADEF V3u v4u_yxz(V4u v) { return (V3u) {.c={v.y,v.x,v.z}}; }
LADEF V3u v4u_zxz(V4u v) { return (V3u) {.c={v.z,v.x,v.z}}; }
LADEF V3u v4u_wxz(V4u v) { return (V3u) {.c={v.w,v.x,v.z}}; }
LADEF V3u v4u_xyz(V4u v) { return (V3u) {.c={v.x,v.y,v.z}}; }
LADEF V3u v4u_yyz(V4u v) { return (V3u) {.c={v.y,v.y,v.z}}; }
LADEF V3u v4u_zyz(V4u v) { return (V3u) {.c={v.z,v.y,v.z}}; }
LADEF V3u v4u_wyz(V4u v) { return (V3u) {.c={v.w,v.y,v.z}}; }
LADEF V3u v4u_xzz(V4u v) { return (V3u) {.c={v.x,v.z,v.z}}; }
LADEF V3u v4u_yzz(V4u v) { return (V3u) {.c={v.y,v.z,v.z}}; }
LADEF V3u v4u_zzz(V4u v) { return (V3u) {.c={v.z,v.z,v.z}}; }
LADEF V3u v4u_wzz(V4u v) { return (V3u) {.c={v.w,v.z,v.z}}; }
LADEF V3u v4u_xwz(V4u v) { return (V3u) {.c={v.x,v.w,v.z}}; }
LADEF V3u v4u_ywz(V4u v) { return (V3u) {.c={v.y,v.w,v.z}}; }
LADEF V3u v4u_zwz(V4u v) { return (V3u) {.c={v.z,v.w,v.z}}; }
LADEF V3u v4u_wwz(V4u v) { return (V3u) {.c={v.w,v.w,v.z}}; }
LADEF V3u v4u_xxw(V4u v) { return (V3u) {.c={v.x,v.x,v.w}}; }
LADEF V3u v4u_yxw(V4u v) { return (V3u) {.c={v.y,v.x,v.w}}; }
LADEF V3u v4u_zxw(V4u v) { return (V3u) {.c={v.z,v.x,v.w}}; }
LADEF V3u v4u_wxw(V4u v) { return (V3u) {.c={v.w,v.x,v.w}}; }
LADEF V3u v4u_xyw(V4u v) { return (V3u) {.c={v.x,v.y,v.w}}; }
LADEF V3u v4u_yyw(V4u v) { return (V3u) {.c={v.y,v.y,v.w}}; }
LADEF V3u v4u_zyw(V4u v) { return (V3u) {.c={v.z,v.y,v.w}}; }
LADEF V3u v4u_wyw(V4u v) { return (V3u) {.c={v.w,v.y,v.w}}; }
LADEF V3u v4u_xzw(V4u v) { return (V3u) {.c={v.x,v.z,v.w}}; }
LADEF V3u v4u_yzw(V4u v) { return (V3u) {.c={v.y,v.z,v.w}}; }
LADEF V3u v4u_zzw(V4u v) { return (V3u) {.c={v.z,v.z,v.w}}; }
LADEF V3u v4u_wzw(V4u v) { return (V3u) {.c={v.w,v.z,v.w}}; }
LADEF V3u v4u_xww(V4u v) { return (V3u) {.c={v.x,v.w,v.w}}; }
LADEF V3u v4u_yww(V4u v) { return (V3u) {.c={v.y,v.w,v.w}}; }
LADEF V3u v4u_zww(V4u v) { return (V3u) {.c={v.z,v.w,v.w}}; }
LADEF V3u v4u_www(V4u v) { return (V3u) {.c={v.w,v.w,v.w}}; }

LADEF V4u v2u_xxxx(V2u v) { return (V4u) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4u v2u_yxxx(V2u v) { return (V4u) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4u v2u_xyxx(V2u v) { return (V4u) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4u v2u_yyxx(V2u v) { return (V4u) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4u v2u_xxyx(V2u v) { return (V4u) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4u v2u_yxyx(V2u v) { return (V4u) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4u v2u_xyyx(V2u v) { return (V4u) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4u v2u_yyyx(V2u v) { return (V4u) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4u v2u_xxxy(V2u v) { return (V4u) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4u v2u_yxxy(V2u v) { return (V4u) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4u v2u_xyxy(V2u v) { return (V4u) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4u v2u_yyxy(V2u v) { return (V4u) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4u v2u_xxyy(V2u v) { return (V4u) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4u v2u_yxyy(V2u v) { return (V4u) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4u v2u_xyyy(V2u v) { return (V4u) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4u v2u_yyyy(V2u v) { return (V4u) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4u v3u_xxxx(V3u v) { return (V4u) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4u v3u_yxxx(V3u v) { return (V4u) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4u v3u_zxxx(V3u v) { return (V4u) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4u v3u_xyxx(V3u v) { return (V4u) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4u v3u_yyxx(V3u v) { return (V4u) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4u v3u_zyxx(V3u v) { return (V4u) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4u v3u_xzxx(V3u v) { return (V4u) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4u v3u_yzxx(V3u v) { return (V4u) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4u v3u_zzxx(V3u v) { return (V4u) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4u v3u_xxyx(V3u v) { return (V4u) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4u v3u_yxyx(V3u v) { return (V4u) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4u v3u_zxyx(V3u v) { return (V4u) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4u v3u_xyyx(V3u v) { return (V4u) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4u v3u_yyyx(V3u v) { return (V4u) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4u v3u_zyyx(V3u v) { return (V4u) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4u v3u_xzyx(V3u v) { return (V4u) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4u v3u_yzyx(V3u v) { return (V4u) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4u v3u_zzyx(V3u v) { return (V4u) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4u v3u_xxzx(V3u v) { return (V4u) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4u v3u_yxzx(V3u v) { return (V4u) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4u v3u_zxzx(V3u v) { return (V4u) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4u v3u_xyzx(V3u v) { return (V4u) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4u v3u_yyzx(V3u v) { return (V4u) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4u v3u_zyzx(V3u v) { return (V4u) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4u v3u_xzzx(V3u v) { return (V4u) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4u v3u_yzzx(V3u v) { return (V4u) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4u v3u_zzzx(V3u v) { return (V4u) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4u v3u_xxxy(V3u v) { return (V4u) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4u v3u_yxxy(V3u v) { return (V4u) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4u v3u_zxxy(V3u v) { return (V4u) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4u v3u_xyxy(V3u v) { return (V4u) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4u v3u_yyxy(V3u v) { return (V4u) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4u v3u_zyxy(V3u v) { return (V4u) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4u v3u_xzxy(V3u v) { return (V4u) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4u v3u_yzxy(V3u v) { return (V4u) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4u v3u_zzxy(V3u v) { return (V4u) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4u v3u_xxyy(V3u v) { return (V4u) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4u v3u_yxyy(V3u v) { return (V4u) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4u v3u_zxyy(V3u v) { return (V4u) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4u v3u_xyyy(V3u v) { return (V4u) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4u v3u_yyyy(V3u v) { return (V4u) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4u v3u_zyyy(V3u v) { return (V4u) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4u v3u_xzyy(V3u v) { return (V4u) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4u v3u_yzyy(V3u v) { return (V4u) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4u v3u_zzyy(V3u v) { return (V4u) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4u v3u_xxzy(V3u v) { return (V4u) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4u v3u_yxzy(V3u v) { return (V4u) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4u v3u_zxzy(V3u v) { return (V4u) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4u v3u_xyzy(V3u v) { return (V4u) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4u v3u_yyzy(V3u v) { return (V4u) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4u v3u_zyzy(V3u v) { return (V4u) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4u v3u_xzzy(V3u v) { return (V4u) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4u v3u_yzzy(V3u v) { return (V4u) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4u v3u_zzzy(V3u v) { return (V4u) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4u v3u_xxxz(V3u v) { return (V4u) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4u v3u_yxxz(V3u v) { return (V4u) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4u v3u_zxxz(V3u v) { return (V4u) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4u v3u_xyxz(V3u v) { return (V4u) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4u v3u_yyxz(V3u v) { return (V4u) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4u v3u_zyxz(V3u v) { return (V4u) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4u v3u_xzxz(V3u v) { return (V4u) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4u v3u_yzxz(V3u v) { return (V4u) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4u v3u_zzxz(V3u v) { return (V4u) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4u v3u_xxyz(V3u v) { return (V4u) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4u v3u_yxyz(V3u v) { return (V4u) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4u v3u_zxyz(V3u v) { return (V4u) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4u v3u_xyyz(V3u v) { return (V4u) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4u v3u_yyyz(V3u v) { return (V4u) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4u v3u_zyyz(V3u v) { return (V4u) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4u v3u_xzyz(V3u v) { return (V4u) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4u v3u_yzyz(V3u v) { return (V4u) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4u v3u_zzyz(V3u v) { return (V4u) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4u v3u_xxzz(V3u v) { return (V4u) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4u v3u_yxzz(V3u v) { return (V4u) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4u v3u_zxzz(V3u v) { return (V4u) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4u v3u_xyzz(V3u v) { return (V4u) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4u v3u_yyzz(V3u v) { return (V4u) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4u v3u_zyzz(V3u v) { return (V4u) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4u v3u_xzzz(V3u v) { return (V4u) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4u v3u_yzzz(V3u v) { return (V4u) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4u v3u_zzzz(V3u v) { return (V4u) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4u v4u_xxxx(V4u v) { return (V4u) {.c={v.x,v.x,v.x,v.x}}; }
LADEF V4u v4u_yxxx(V4u v) { return (V4u) {.c={v.y,v.x,v.x,v.x}}; }
LADEF V4u v4u_zxxx(V4u v) { return (V4u) {.c={v.z,v.x,v.x,v.x}}; }
LADEF V4u v4u_wxxx(V4u v) { return (V4u) {.c={v.w,v.x,v.x,v.x}}; }
LADEF V4u v4u_xyxx(V4u v) { return (V4u) {.c={v.x,v.y,v.x,v.x}}; }
LADEF V4u v4u_yyxx(V4u v) { return (V4u) {.c={v.y,v.y,v.x,v.x}}; }
LADEF V4u v4u_zyxx(V4u v) { return (V4u) {.c={v.z,v.y,v.x,v.x}}; }
LADEF V4u v4u_wyxx(V4u v) { return (V4u) {.c={v.w,v.y,v.x,v.x}}; }
LADEF V4u v4u_xzxx(V4u v) { return (V4u) {.c={v.x,v.z,v.x,v.x}}; }
LADEF V4u v4u_yzxx(V4u v) { return (V4u) {.c={v.y,v.z,v.x,v.x}}; }
LADEF V4u v4u_zzxx(V4u v) { return (V4u) {.c={v.z,v.z,v.x,v.x}}; }
LADEF V4u v4u_wzxx(V4u v) { return (V4u) {.c={v.w,v.z,v.x,v.x}}; }
LADEF V4u v4u_xwxx(V4u v) { return (V4u) {.c={v.x,v.w,v.x,v.x}}; }
LADEF V4u v4u_ywxx(V4u v) { return (V4u) {.c={v.y,v.w,v.x,v.x}}; }
LADEF V4u v4u_zwxx(V4u v) { return (V4u) {.c={v.z,v.w,v.x,v.x}}; }
LADEF V4u v4u_wwxx(V4u v) { return (V4u) {.c={v.w,v.w,v.x,v.x}}; }
LADEF V4u v4u_xxyx(V4u v) { return (V4u) {.c={v.x,v.x,v.y,v.x}}; }
LADEF V4u v4u_yxyx(V4u v) { return (V4u) {.c={v.y,v.x,v.y,v.x}}; }
LADEF V4u v4u_zxyx(V4u v) { return (V4u) {.c={v.z,v.x,v.y,v.x}}; }
LADEF V4u v4u_wxyx(V4u v) { return (V4u) {.c={v.w,v.x,v.y,v.x}}; }
LADEF V4u v4u_xyyx(V4u v) { return (V4u) {.c={v.x,v.y,v.y,v.x}}; }
LADEF V4u v4u_yyyx(V4u v) { return (V4u) {.c={v.y,v.y,v.y,v.x}}; }
LADEF V4u v4u_zyyx(V4u v) { return (V4u) {.c={v.z,v.y,v.y,v.x}}; }
LADEF V4u v4u_wyyx(V4u v) { return (V4u) {.c={v.w,v.y,v.y,v.x}}; }
LADEF V4u v4u_xzyx(V4u v) { return (V4u) {.c={v.x,v.z,v.y,v.x}}; }
LADEF V4u v4u_yzyx(V4u v) { return (V4u) {.c={v.y,v.z,v.y,v.x}}; }
LADEF V4u v4u_zzyx(V4u v) { return (V4u) {.c={v.z,v.z,v.y,v.x}}; }
LADEF V4u v4u_wzyx(V4u v) { return (V4u) {.c={v.w,v.z,v.y,v.x}}; }
LADEF V4u v4u_xwyx(V4u v) { return (V4u) {.c={v.x,v.w,v.y,v.x}}; }
LADEF V4u v4u_ywyx(V4u v) { return (V4u) {.c={v.y,v.w,v.y,v.x}}; }
LADEF V4u v4u_zwyx(V4u v) { return (V4u) {.c={v.z,v.w,v.y,v.x}}; }
LADEF V4u v4u_wwyx(V4u v) { return (V4u) {.c={v.w,v.w,v.y,v.x}}; }
LADEF V4u v4u_xxzx(V4u v) { return (V4u) {.c={v.x,v.x,v.z,v.x}}; }
LADEF V4u v4u_yxzx(V4u v) { return (V4u) {.c={v.y,v.x,v.z,v.x}}; }
LADEF V4u v4u_zxzx(V4u v) { return (V4u) {.c={v.z,v.x,v.z,v.x}}; }
LADEF V4u v4u_wxzx(V4u v) { return (V4u) {.c={v.w,v.x,v.z,v.x}}; }
LADEF V4u v4u_xyzx(V4u v) { return (V4u) {.c={v.x,v.y,v.z,v.x}}; }
LADEF V4u v4u_yyzx(V4u v) { return (V4u) {.c={v.y,v.y,v.z,v.x}}; }
LADEF V4u v4u_zyzx(V4u v) { return (V4u) {.c={v.z,v.y,v.z,v.x}}; }
LADEF V4u v4u_wyzx(V4u v) { return (V4u) {.c={v.w,v.y,v.z,v.x}}; }
LADEF V4u v4u_xzzx(V4u v) { return (V4u) {.c={v.x,v.z,v.z,v.x}}; }
LADEF V4u v4u_yzzx(V4u v) { return (V4u) {.c={v.y,v.z,v.z,v.x}}; }
LADEF V4u v4u_zzzx(V4u v) { return (V4u) {.c={v.z,v.z,v.z,v.x}}; }
LADEF V4u v4u_wzzx(V4u v) { return (V4u) {.c={v.w,v.z,v.z,v.x}}; }
LADEF V4u v4u_xwzx(V4u v) { return (V4u) {.c={v.x,v.w,v.z,v.x}}; }
LADEF V4u v4u_ywzx(V4u v) { return (V4u) {.c={v.y,v.w,v.z,v.x}}; }
LADEF V4u v4u_zwzx(V4u v) { return (V4u) {.c={v.z,v.w,v.z,v.x}}; }
LADEF V4u v4u_wwzx(V4u v) { return (V4u) {.c={v.w,v.w,v.z,v.x}}; }
LADEF V4u v4u_xxwx(V4u v) { return (V4u) {.c={v.x,v.x,v.w,v.x}}; }
LADEF V4u v4u_yxwx(V4u v) { return (V4u) {.c={v.y,v.x,v.w,v.x}}; }
LADEF V4u v4u_zxwx(V4u v) { return (V4u) {.c={v.z,v.x,v.w,v.x}}; }
LADEF V4u v4u_wxwx(V4u v) { return (V4u) {.c={v.w,v.x,v.w,v.x}}; }
LADEF V4u v4u_xywx(V4u v) { return (V4u) {.c={v.x,v.y,v.w,v.x}}; }
LADEF V4u v4u_yywx(V4u v) { return (V4u) {.c={v.y,v.y,v.w,v.x}}; }
LADEF V4u v4u_zywx(V4u v) { return (V4u) {.c={v.z,v.y,v.w,v.x}}; }
LADEF V4u v4u_wywx(V4u v) { return (V4u) {.c={v.w,v.y,v.w,v.x}}; }
LADEF V4u v4u_xzwx(V4u v) { return (V4u) {.c={v.x,v.z,v.w,v.x}}; }
LADEF V4u v4u_yzwx(V4u v) { return (V4u) {.c={v.y,v.z,v.w,v.x}}; }
LADEF V4u v4u_zzwx(V4u v) { return (V4u) {.c={v.z,v.z,v.w,v.x}}; }
LADEF V4u v4u_wzwx(V4u v) { return (V4u) {.c={v.w,v.z,v.w,v.x}}; }
LADEF V4u v4u_xwwx(V4u v) { return (V4u) {.c={v.x,v.w,v.w,v.x}}; }
LADEF V4u v4u_ywwx(V4u v) { return (V4u) {.c={v.y,v.w,v.w,v.x}}; }
LADEF V4u v4u_zwwx(V4u v) { return (V4u) {.c={v.z,v.w,v.w,v.x}}; }
LADEF V4u v4u_wwwx(V4u v) { return (V4u) {.c={v.w,v.w,v.w,v.x}}; }
LADEF V4u v4u_xxxy(V4u v) { return (V4u) {.c={v.x,v.x,v.x,v.y}}; }
LADEF V4u v4u_yxxy(V4u v) { return (V4u) {.c={v.y,v.x,v.x,v.y}}; }
LADEF V4u v4u_zxxy(V4u v) { return (V4u) {.c={v.z,v.x,v.x,v.y}}; }
LADEF V4u v4u_wxxy(V4u v) { return (V4u) {.c={v.w,v.x,v.x,v.y}}; }
LADEF V4u v4u_xyxy(V4u v) { return (V4u) {.c={v.x,v.y,v.x,v.y}}; }
LADEF V4u v4u_yyxy(V4u v) { return (V4u) {.c={v.y,v.y,v.x,v.y}}; }
LADEF V4u v4u_zyxy(V4u v) { return (V4u) {.c={v.z,v.y,v.x,v.y}}; }
LADEF V4u v4u_wyxy(V4u v) { return (V4u) {.c={v.w,v.y,v.x,v.y}}; }
LADEF V4u v4u_xzxy(V4u v) { return (V4u) {.c={v.x,v.z,v.x,v.y}}; }
LADEF V4u v4u_yzxy(V4u v) { return (V4u) {.c={v.y,v.z,v.x,v.y}}; }
LADEF V4u v4u_zzxy(V4u v) { return (V4u) {.c={v.z,v.z,v.x,v.y}}; }
LADEF V4u v4u_wzxy(V4u v) { return (V4u) {.c={v.w,v.z,v.x,v.y}}; }
LADEF V4u v4u_xwxy(V4u v) { return (V4u) {.c={v.x,v.w,v.x,v.y}}; }
LADEF V4u v4u_ywxy(V4u v) { return (V4u) {.c={v.y,v.w,v.x,v.y}}; }
LADEF V4u v4u_zwxy(V4u v) { return (V4u) {.c={v.z,v.w,v.x,v.y}}; }
LADEF V4u v4u_wwxy(V4u v) { return (V4u) {.c={v.w,v.w,v.x,v.y}}; }
LADEF V4u v4u_xxyy(V4u v) { return (V4u) {.c={v.x,v.x,v.y,v.y}}; }
LADEF V4u v4u_yxyy(V4u v) { return (V4u) {.c={v.y,v.x,v.y,v.y}}; }
LADEF V4u v4u_zxyy(V4u v) { return (V4u) {.c={v.z,v.x,v.y,v.y}}; }
LADEF V4u v4u_wxyy(V4u v) { return (V4u) {.c={v.w,v.x,v.y,v.y}}; }
LADEF V4u v4u_xyyy(V4u v) { return (V4u) {.c={v.x,v.y,v.y,v.y}}; }
LADEF V4u v4u_yyyy(V4u v) { return (V4u) {.c={v.y,v.y,v.y,v.y}}; }
LADEF V4u v4u_zyyy(V4u v) { return (V4u) {.c={v.z,v.y,v.y,v.y}}; }
LADEF V4u v4u_wyyy(V4u v) { return (V4u) {.c={v.w,v.y,v.y,v.y}}; }
LADEF V4u v4u_xzyy(V4u v) { return (V4u) {.c={v.x,v.z,v.y,v.y}}; }
LADEF V4u v4u_yzyy(V4u v) { return (V4u) {.c={v.y,v.z,v.y,v.y}}; }
LADEF V4u v4u_zzyy(V4u v) { return (V4u) {.c={v.z,v.z,v.y,v.y}}; }
LADEF V4u v4u_wzyy(V4u v) { return (V4u) {.c={v.w,v.z,v.y,v.y}}; }
LADEF V4u v4u_xwyy(V4u v) { return (V4u) {.c={v.x,v.w,v.y,v.y}}; }
LADEF V4u v4u_ywyy(V4u v) { return (V4u) {.c={v.y,v.w,v.y,v.y}}; }
LADEF V4u v4u_zwyy(V4u v) { return (V4u) {.c={v.z,v.w,v.y,v.y}}; }
LADEF V4u v4u_wwyy(V4u v) { return (V4u) {.c={v.w,v.w,v.y,v.y}}; }
LADEF V4u v4u_xxzy(V4u v) { return (V4u) {.c={v.x,v.x,v.z,v.y}}; }
LADEF V4u v4u_yxzy(V4u v) { return (V4u) {.c={v.y,v.x,v.z,v.y}}; }
LADEF V4u v4u_zxzy(V4u v) { return (V4u) {.c={v.z,v.x,v.z,v.y}}; }
LADEF V4u v4u_wxzy(V4u v) { return (V4u) {.c={v.w,v.x,v.z,v.y}}; }
LADEF V4u v4u_xyzy(V4u v) { return (V4u) {.c={v.x,v.y,v.z,v.y}}; }
LADEF V4u v4u_yyzy(V4u v) { return (V4u) {.c={v.y,v.y,v.z,v.y}}; }
LADEF V4u v4u_zyzy(V4u v) { return (V4u) {.c={v.z,v.y,v.z,v.y}}; }
LADEF V4u v4u_wyzy(V4u v) { return (V4u) {.c={v.w,v.y,v.z,v.y}}; }
LADEF V4u v4u_xzzy(V4u v) { return (V4u) {.c={v.x,v.z,v.z,v.y}}; }
LADEF V4u v4u_yzzy(V4u v) { return (V4u) {.c={v.y,v.z,v.z,v.y}}; }
LADEF V4u v4u_zzzy(V4u v) { return (V4u) {.c={v.z,v.z,v.z,v.y}}; }
LADEF V4u v4u_wzzy(V4u v) { return (V4u) {.c={v.w,v.z,v.z,v.y}}; }
LADEF V4u v4u_xwzy(V4u v) { return (V4u) {.c={v.x,v.w,v.z,v.y}}; }
LADEF V4u v4u_ywzy(V4u v) { return (V4u) {.c={v.y,v.w,v.z,v.y}}; }
LADEF V4u v4u_zwzy(V4u v) { return (V4u) {.c={v.z,v.w,v.z,v.y}}; }
LADEF V4u v4u_wwzy(V4u v) { return (V4u) {.c={v.w,v.w,v.z,v.y}}; }
LADEF V4u v4u_xxwy(V4u v) { return (V4u) {.c={v.x,v.x,v.w,v.y}}; }
LADEF V4u v4u_yxwy(V4u v) { return (V4u) {.c={v.y,v.x,v.w,v.y}}; }
LADEF V4u v4u_zxwy(V4u v) { return (V4u) {.c={v.z,v.x,v.w,v.y}}; }
LADEF V4u v4u_wxwy(V4u v) { return (V4u) {.c={v.w,v.x,v.w,v.y}}; }
LADEF V4u v4u_xywy(V4u v) { return (V4u) {.c={v.x,v.y,v.w,v.y}}; }
LADEF V4u v4u_yywy(V4u v) { return (V4u) {.c={v.y,v.y,v.w,v.y}}; }
LADEF V4u v4u_zywy(V4u v) { return (V4u) {.c={v.z,v.y,v.w,v.y}}; }
LADEF V4u v4u_wywy(V4u v) { return (V4u) {.c={v.w,v.y,v.w,v.y}}; }
LADEF V4u v4u_xzwy(V4u v) { return (V4u) {.c={v.x,v.z,v.w,v.y}}; }
LADEF V4u v4u_yzwy(V4u v) { return (V4u) {.c={v.y,v.z,v.w,v.y}}; }
LADEF V4u v4u_zzwy(V4u v) { return (V4u) {.c={v.z,v.z,v.w,v.y}}; }
LADEF V4u v4u_wzwy(V4u v) { return (V4u) {.c={v.w,v.z,v.w,v.y}}; }
LADEF V4u v4u_xwwy(V4u v) { return (V4u) {.c={v.x,v.w,v.w,v.y}}; }
LADEF V4u v4u_ywwy(V4u v) { return (V4u) {.c={v.y,v.w,v.w,v.y}}; }
LADEF V4u v4u_zwwy(V4u v) { return (V4u) {.c={v.z,v.w,v.w,v.y}}; }
LADEF V4u v4u_wwwy(V4u v) { return (V4u) {.c={v.w,v.w,v.w,v.y}}; }
LADEF V4u v4u_xxxz(V4u v) { return (V4u) {.c={v.x,v.x,v.x,v.z}}; }
LADEF V4u v4u_yxxz(V4u v) { return (V4u) {.c={v.y,v.x,v.x,v.z}}; }
LADEF V4u v4u_zxxz(V4u v) { return (V4u) {.c={v.z,v.x,v.x,v.z}}; }
LADEF V4u v4u_wxxz(V4u v) { return (V4u) {.c={v.w,v.x,v.x,v.z}}; }
LADEF V4u v4u_xyxz(V4u v) { return (V4u) {.c={v.x,v.y,v.x,v.z}}; }
LADEF V4u v4u_yyxz(V4u v) { return (V4u) {.c={v.y,v.y,v.x,v.z}}; }
LADEF V4u v4u_zyxz(V4u v) { return (V4u) {.c={v.z,v.y,v.x,v.z}}; }
LADEF V4u v4u_wyxz(V4u v) { return (V4u) {.c={v.w,v.y,v.x,v.z}}; }
LADEF V4u v4u_xzxz(V4u v) { return (V4u) {.c={v.x,v.z,v.x,v.z}}; }
LADEF V4u v4u_yzxz(V4u v) { return (V4u) {.c={v.y,v.z,v.x,v.z}}; }
LADEF V4u v4u_zzxz(V4u v) { return (V4u) {.c={v.z,v.z,v.x,v.z}}; }
LADEF V4u v4u_wzxz(V4u v) { return (V4u) {.c={v.w,v.z,v.x,v.z}}; }
LADEF V4u v4u_xwxz(V4u v) { return (V4u) {.c={v.x,v.w,v.x,v.z}}; }
LADEF V4u v4u_ywxz(V4u v) { return (V4u) {.c={v.y,v.w,v.x,v.z}}; }
LADEF V4u v4u_zwxz(V4u v) { return (V4u) {.c={v.z,v.w,v.x,v.z}}; }
LADEF V4u v4u_wwxz(V4u v) { return (V4u) {.c={v.w,v.w,v.x,v.z}}; }
LADEF V4u v4u_xxyz(V4u v) { return (V4u) {.c={v.x,v.x,v.y,v.z}}; }
LADEF V4u v4u_yxyz(V4u v) { return (V4u) {.c={v.y,v.x,v.y,v.z}}; }
LADEF V4u v4u_zxyz(V4u v) { return (V4u) {.c={v.z,v.x,v.y,v.z}}; }
LADEF V4u v4u_wxyz(V4u v) { return (V4u) {.c={v.w,v.x,v.y,v.z}}; }
LADEF V4u v4u_xyyz(V4u v) { return (V4u) {.c={v.x,v.y,v.y,v.z}}; }
LADEF V4u v4u_yyyz(V4u v) { return (V4u) {.c={v.y,v.y,v.y,v.z}}; }
LADEF V4u v4u_zyyz(V4u v) { return (V4u) {.c={v.z,v.y,v.y,v.z}}; }
LADEF V4u v4u_wyyz(V4u v) { return (V4u) {.c={v.w,v.y,v.y,v.z}}; }
LADEF V4u v4u_xzyz(V4u v) { return (V4u) {.c={v.x,v.z,v.y,v.z}}; }
LADEF V4u v4u_yzyz(V4u v) { return (V4u) {.c={v.y,v.z,v.y,v.z}}; }
LADEF V4u v4u_zzyz(V4u v) { return (V4u) {.c={v.z,v.z,v.y,v.z}}; }
LADEF V4u v4u_wzyz(V4u v) { return (V4u) {.c={v.w,v.z,v.y,v.z}}; }
LADEF V4u v4u_xwyz(V4u v) { return (V4u) {.c={v.x,v.w,v.y,v.z}}; }
LADEF V4u v4u_ywyz(V4u v) { return (V4u) {.c={v.y,v.w,v.y,v.z}}; }
LADEF V4u v4u_zwyz(V4u v) { return (V4u) {.c={v.z,v.w,v.y,v.z}}; }
LADEF V4u v4u_wwyz(V4u v) { return (V4u) {.c={v.w,v.w,v.y,v.z}}; }
LADEF V4u v4u_xxzz(V4u v) { return (V4u) {.c={v.x,v.x,v.z,v.z}}; }
LADEF V4u v4u_yxzz(V4u v) { return (V4u) {.c={v.y,v.x,v.z,v.z}}; }
LADEF V4u v4u_zxzz(V4u v) { return (V4u) {.c={v.z,v.x,v.z,v.z}}; }
LADEF V4u v4u_wxzz(V4u v) { return (V4u) {.c={v.w,v.x,v.z,v.z}}; }
LADEF V4u v4u_xyzz(V4u v) { return (V4u) {.c={v.x,v.y,v.z,v.z}}; }
LADEF V4u v4u_yyzz(V4u v) { return (V4u) {.c={v.y,v.y,v.z,v.z}}; }
LADEF V4u v4u_zyzz(V4u v) { return (V4u) {.c={v.z,v.y,v.z,v.z}}; }
LADEF V4u v4u_wyzz(V4u v) { return (V4u) {.c={v.w,v.y,v.z,v.z}}; }
LADEF V4u v4u_xzzz(V4u v) { return (V4u) {.c={v.x,v.z,v.z,v.z}}; }
LADEF V4u v4u_yzzz(V4u v) { return (V4u) {.c={v.y,v.z,v.z,v.z}}; }
LADEF V4u v4u_zzzz(V4u v) { return (V4u) {.c={v.z,v.z,v.z,v.z}}; }
LADEF V4u v4u_wzzz(V4u v) { return (V4u) {.c={v.w,v.z,v.z,v.z}}; }
LADEF V4u v4u_xwzz(V4u v) { return (V4u) {.c={v.x,v.w,v.z,v.z}}; }
LADEF V4u v4u_ywzz(V4u v) { return (V4u) {.c={v.y,v.w,v.z,v.z}}; }
LADEF V4u v4u_zwzz(V4u v) { return (V4u) {.c={v.z,v.w,v.z,v.z}}; }
LADEF V4u v4u_wwzz(V4u v) { return (V4u) {.c={v.w,v.w,v.z,v.z}}; }
LADEF V4u v4u_xxwz(V4u v) { return (V4u) {.c={v.x,v.x,v.w,v.z}}; }
LADEF V4u v4u_yxwz(V4u v) { return (V4u) {.c={v.y,v.x,v.w,v.z}}; }
LADEF V4u v4u_zxwz(V4u v) { return (V4u) {.c={v.z,v.x,v.w,v.z}}; }
LADEF V4u v4u_wxwz(V4u v) { return (V4u) {.c={v.w,v.x,v.w,v.z}}; }
LADEF V4u v4u_xywz(V4u v) { return (V4u) {.c={v.x,v.y,v.w,v.z}}; }
LADEF V4u v4u_yywz(V4u v) { return (V4u) {.c={v.y,v.y,v.w,v.z}}; }
LADEF V4u v4u_zywz(V4u v) { return (V4u) {.c={v.z,v.y,v.w,v.z}}; }
LADEF V4u v4u_wywz(V4u v) { return (V4u) {.c={v.w,v.y,v.w,v.z}}; }
LADEF V4u v4u_xzwz(V4u v) { return (V4u) {.c={v.x,v.z,v.w,v.z}}; }
LADEF V4u v4u_yzwz(V4u v) { return (V4u) {.c={v.y,v.z,v.w,v.z}}; }
LADEF V4u v4u_zzwz(V4u v) { return (V4u) {.c={v.z,v.z,v.w,v.z}}; }
LADEF V4u v4u_wzwz(V4u v) { return (V4u) {.c={v.w,v.z,v.w,v.z}}; }
LADEF V4u v4u_xwwz(V4u v) { return (V4u) {.c={v.x,v.w,v.w,v.z}}; }
LADEF V4u v4u_ywwz(V4u v) { return (V4u) {.c={v.y,v.w,v.w,v.z}}; }
LADEF V4u v4u_zwwz(V4u v) { return (V4u) {.c={v.z,v.w,v.w,v.z}}; }
LADEF V4u v4u_wwwz(V4u v) { return (V4u) {.c={v.w,v.w,v.w,v.z}}; }
LADEF V4u v4u_xxxw(V4u v) { return (V4u) {.c={v.x,v.x,v.x,v.w}}; }
LADEF V4u v4u_yxxw(V4u v) { return (V4u) {.c={v.y,v.x,v.x,v.w}}; }
LADEF V4u v4u_zxxw(V4u v) { return (V4u) {.c={v.z,v.x,v.x,v.w}}; }
LADEF V4u v4u_wxxw(V4u v) { return (V4u) {.c={v.w,v.x,v.x,v.w}}; }
LADEF V4u v4u_xyxw(V4u v) { return (V4u) {.c={v.x,v.y,v.x,v.w}}; }
LADEF V4u v4u_yyxw(V4u v) { return (V4u) {.c={v.y,v.y,v.x,v.w}}; }
LADEF V4u v4u_zyxw(V4u v) { return (V4u) {.c={v.z,v.y,v.x,v.w}}; }
LADEF V4u v4u_wyxw(V4u v) { return (V4u) {.c={v.w,v.y,v.x,v.w}}; }
LADEF V4u v4u_xzxw(V4u v) { return (V4u) {.c={v.x,v.z,v.x,v.w}}; }
LADEF V4u v4u_yzxw(V4u v) { return (V4u) {.c={v.y,v.z,v.x,v.w}}; }
LADEF V4u v4u_zzxw(V4u v) { return (V4u) {.c={v.z,v.z,v.x,v.w}}; }
LADEF V4u v4u_wzxw(V4u v) { return (V4u) {.c={v.w,v.z,v.x,v.w}}; }
LADEF V4u v4u_xwxw(V4u v) { return (V4u) {.c={v.x,v.w,v.x,v.w}}; }
LADEF V4u v4u_ywxw(V4u v) { return (V4u) {.c={v.y,v.w,v.x,v.w}}; }
LADEF V4u v4u_zwxw(V4u v) { return (V4u) {.c={v.z,v.w,v.x,v.w}}; }
LADEF V4u v4u_wwxw(V4u v) { return (V4u) {.c={v.w,v.w,v.x,v.w}}; }
LADEF V4u v4u_xxyw(V4u v) { return (V4u) {.c={v.x,v.x,v.y,v.w}}; }
LADEF V4u v4u_yxyw(V4u v) { return (V4u) {.c={v.y,v.x,v.y,v.w}}; }
LADEF V4u v4u_zxyw(V4u v) { return (V4u) {.c={v.z,v.x,v.y,v.w}}; }
LADEF V4u v4u_wxyw(V4u v) { return (V4u) {.c={v.w,v.x,v.y,v.w}}; }
LADEF V4u v4u_xyyw(V4u v) { return (V4u) {.c={v.x,v.y,v.y,v.w}}; }
LADEF V4u v4u_yyyw(V4u v) { return (V4u) {.c={v.y,v.y,v.y,v.w}}; }
LADEF V4u v4u_zyyw(V4u v) { return (V4u) {.c={v.z,v.y,v.y,v.w}}; }
LADEF V4u v4u_wyyw(V4u v) { return (V4u) {.c={v.w,v.y,v.y,v.w}}; }
LADEF V4u v4u_xzyw(V4u v) { return (V4u) {.c={v.x,v.z,v.y,v.w}}; }
LADEF V4u v4u_yzyw(V4u v) { return (V4u) {.c={v.y,v.z,v.y,v.w}}; }
LADEF V4u v4u_zzyw(V4u v) { return (V4u) {.c={v.z,v.z,v.y,v.w}}; }
LADEF V4u v4u_wzyw(V4u v) { return (V4u) {.c={v.w,v.z,v.y,v.w}}; }
LADEF V4u v4u_xwyw(V4u v) { return (V4u) {.c={v.x,v.w,v.y,v.w}}; }
LADEF V4u v4u_ywyw(V4u v) { return (V4u) {.c={v.y,v.w,v.y,v.w}}; }
LADEF V4u v4u_zwyw(V4u v) { return (V4u) {.c={v.z,v.w,v.y,v.w}}; }
LADEF V4u v4u_wwyw(V4u v) { return (V4u) {.c={v.w,v.w,v.y,v.w}}; }
LADEF V4u v4u_xxzw(V4u v) { return (V4u) {.c={v.x,v.x,v.z,v.w}}; }
LADEF V4u v4u_yxzw(V4u v) { return (V4u) {.c={v.y,v.x,v.z,v.w}}; }
LADEF V4u v4u_zxzw(V4u v) { return (V4u) {.c={v.z,v.x,v.z,v.w}}; }
LADEF V4u v4u_wxzw(V4u v) { return (V4u) {.c={v.w,v.x,v.z,v.w}}; }
LADEF V4u v4u_xyzw(V4u v) { return v; }
LADEF V4u v4u_yyzw(V4u v) { return (V4u) {.c={v.y,v.y,v.z,v.w}}; }
LADEF V4u v4u_zyzw(V4u v) { return (V4u) {.c={v.z,v.y,v.z,v.w}}; }
LADEF V4u v4u_wyzw(V4u v) { return (V4u) {.c={v.w,v.y,v.z,v.w}}; }
LADEF V4u v4u_xzzw(V4u v) { return (V4u) {.c={v.x,v.z,v.z,v.w}}; }
LADEF V4u v4u_yzzw(V4u v) { return (V4u) {.c={v.y,v.z,v.z,v.w}}; }
LADEF V4u v4u_zzzw(V4u v) { return (V4u) {.c={v.z,v.z,v.z,v.w}}; }
LADEF V4u v4u_wzzw(V4u v) { return (V4u) {.c={v.w,v.z,v.z,v.w}}; }
LADEF V4u v4u_xwzw(V4u v) { return (V4u) {.c={v.x,v.w,v.z,v.w}}; }
LADEF V4u v4u_ywzw(V4u v) { return (V4u) {.c={v.y,v.w,v.z,v.w}}; }
LADEF V4u v4u_zwzw(V4u v) { return (V4u) {.c={v.z,v.w,v.z,v.w}}; }
LADEF V4u v4u_wwzw(V4u v) { return (V4u) {.c={v.w,v.w,v.z,v.w}}; }
LADEF V4u v4u_xxww(V4u v) { return (V4u) {.c={v.x,v.x,v.w,v.w}}; }
LADEF V4u v4u_yxww(V4u v) { return (V4u) {.c={v.y,v.x,v.w,v.w}}; }
LADEF V4u v4u_zxww(V4u v) { return (V4u) {.c={v.z,v.x,v.w,v.w}}; }
LADEF V4u v4u_wxww(V4u v) { return (V4u) {.c={v.w,v.x,v.w,v.w}}; }
LADEF V4u v4u_xyww(V4u v) { return (V4u) {.c={v.x,v.y,v.w,v.w}}; }
LADEF V4u v4u_yyww(V4u v) { return (V4u) {.c={v.y,v.y,v.w,v.w}}; }
LADEF V4u v4u_zyww(V4u v) { return (V4u) {.c={v.z,v.y,v.w,v.w}}; }
LADEF V4u v4u_wyww(V4u v) { return (V4u) {.c={v.w,v.y,v.w,v.w}}; }
LADEF V4u v4u_xzww(V4u v) { return (V4u) {.c={v.x,v.z,v.w,v.w}}; }
LADEF V4u v4u_yzww(V4u v) { return (V4u) {.c={v.y,v.z,v.w,v.w}}; }
LADEF V4u v4u_zzww(V4u v) { return (V4u) {.c={v.z,v.z,v.w,v.w}}; }
LADEF V4u v4u_wzww(V4u v) { return (V4u) {.c={v.w,v.z,v.w,v.w}}; }
LADEF V4u v4u_xwww(V4u v) { return (V4u) {.c={v.x,v.w,v.w,v.w}}; }
LADEF V4u v4u_ywww(V4u v) { return (V4u) {.c={v.y,v.w,v.w,v.w}}; }
LADEF V4u v4u_zwww(V4u v) { return (V4u) {.c={v.z,v.w,v.w,v.w}}; }
LADEF V4u v4u_wwww(V4u v) { return (V4u) {.c={v.w,v.w,v.w,v.w}}; }

#endif // LA_IMPLEMENTATION
