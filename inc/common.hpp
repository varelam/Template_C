#ifndef __FOO__
#define __FOO__

#include <float.h>
#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

typedef  int8_t  s8;
typedef  int8_t s08;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef  uint8_t  u8;
typedef  uint8_t u08;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef s08   b8;
typedef s08  b08;
typedef s32  b32;

typedef int_fast8_t   s8x;
typedef int_fast8_t  s08x;
typedef int_fast16_t s16x;
typedef int_fast32_t s32x;
typedef int_fast64_t s64x;

typedef uint_fast8_t   u8x;
typedef uint_fast8_t  u08x;
typedef uint_fast16_t u16x;
typedef uint_fast32_t u32x;
typedef uint_fast64_t u64x;

typedef  intptr_t smm;
typedef uintptr_t umm;

typedef s08   b8;
typedef s08  b08;
typedef s32  b32;

typedef s08x  b8x;
typedef s08x b08x;
typedef s32x b32x;

typedef float  f32;
typedef double f64;

#define  U8Min ( (u8) 0)
#define U16Min ((u16) 0)
#define U32Min ((u32) 0)
#define U64Min ((u64) 0)
#define  U8Max ( (u8)-1)
#define U16Max ((u16)-1)
#define U32Max ((u32)-1)
#define U64Max ((u64)-1)

#define  S8Min ( (s8)( U8Max & ~( U8Max >> 1)))
#define S16Min ((s16)(U16Max & ~(U16Max >> 1)))
#define S32Min ((s32)(U32Max & ~(U32Max >> 1)))
#define S64Min ((s64)(U64Max & ~(U64Max >> 1)))
#define  S8Max ( (s8)( U8Max >> 1))
#define S16Max ((s16)(U16Max >> 1))
#define S32Max ((s32)(U32Max >> 1))
#define S64Max ((s64)(U64Max >> 1))

#define F32Inf ((f32)INFINITY)
#define F64Inf ((f64)INFINITY)
#define F32Min ((f32)-FLT_MAX)
#define F64Min ((f64)-DBL_MAX)
#define F32Max ((f32) FLT_MAX)
#define F64Max ((f64) DBL_MAX)

#define internal static
#define gvarbl   static
#define gconst   static const
#define gcexpr   static constexpr

#define arrayCount(Array) (sizeof(Array) / sizeof(*(Array)))
#define bitWidthOf(A) (8*sizeof(A))
#define isPow2(Value) (((Value) & ((Value)-1)) == 0)
#define isEven(Value) (((Value) & 1) == 0)
#define isOdd( Value) (((Value) & 1) == 1)
#define dividesEvenly(Num, Den) (((Num) % (Den)) == 0)
#define ceilDivide(Num, Den) (((Num) + ((Den)-1))/(Den))
#define floorDiv(Num,Den) (((Num) - ((((Num)<0)^((Den)<0)) ? ((Den)-1) : 0)) / (Den))
#define floorMod(Num,Den) (((Num) % (Den)) + ((((Num)<0)^((Den)<0)) ? (Den) : 0))


#define PASTE_(X, Y) X ## Y
#define PASTE(X, Y) PASTE_(X, Y)

#define DEFINE_V2(type)                         \
    union v2##type                              \
    {                                           \
        type E[2];                              \
        struct { type X, Y; };                  \
        struct { type Width, Height; };         \
        struct { type W, H; };                  \
        struct { type Real, Imag; };            \
        struct { type R, I; };                  \
        struct { type U, V; };                  \
        struct { type Lat, Lon; };              \
        struct { type Min, Max; };              \
        struct { type Int, Frac; };             \
        struct { type Mono, Alpha; };           \
    };

#define DEFINE_V3(type)                         \
    union v3##type                              \
    {                                           \
        type E[3];                              \
        struct { type X, Y, Z; };               \
        struct { type Width, Height, Depth; };  \
        struct { type W, H, D; };               \
        struct { type Red, Green, Blue; };      \
        struct { type R, G, B; };               \
        struct { type Lat, Lon, Alt; };         \
    };


    #define SQUARE(A) ((A)*(A))
    #define CUBE(  A) ((A)*(A)*(A))

    gcexpr f32 Pi32  = 3.14159265359f;
    gcexpr f64 Pi64  = 3.14159265358979323;

    gcexpr f32 RadPerDeg32 = Pi32/180.f;
    gcexpr f64 RadPerDeg64 = Pi64/180.0;
    gcexpr f32 DegPerRad32 = 180.f/Pi32;
    gcexpr f64 DegPerRad64 = 180.0/Pi64;

    gcexpr f32 SpeedOfLight32 = 299792458.f;
    gcexpr f64 SpeedOfLight64 = 299792458.0;

    internal inline f32
    sign(f32 X)
    {
        f32 Sign = ((X >= 0.f) ? 1.f : -1.f);
        return Sign;
    }

    internal inline f64
    sign(f64 X)
    {
        f32 Sign = ((X >= 0.0) ? 1.0 : -1.0);
        return Sign;
    }
#endif
