#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef struct {double x, y, z;} vec3;

static inline vec3 vec3Add(vec3 a, vec3 b) {return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};}
static inline vec3 vec3Sub(vec3 a, vec3 b) {return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};}

static inline vec3 vec3Scale(vec3 a, double b) {return (vec3){a.x * b, a.y * b, a.z * b};}
static inline vec3 vec3Div(vec3 a, double b) {return vec3Scale(a, 1.0 / b);}

static inline vec3 vec3Hadamard(vec3 a, vec3 b) {return (vec3){a.x * b.x, a.y * b.y, a.z * b.z};}

static inline double vec3Dot(vec3 a, vec3 b) {return a.x * b.x + a.y * b.y + a.z * b.z;}
static inline vec3 vec3Cross(vec3 a, vec3 b) 
{
  return (vec3){a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x};
}

static inline double vec3LengthSquared(vec3 a) {return a.x * a.x + a.y * a.y + a.z * a.z;}
static inline double vec3Length(vec3 a) {return sqrt(vec3LengthSquared(a));}

static inline vec3 vec3Normalize(vec3 a) 
{
    double len = vec3Length(a);
    return (len > 0.0) ? vec3Div(a, len) : (vec3){0, 0, 0};
}

static inline vec3 vec3Reflect(vec3 v, vec3 n) {return vec3Sub(v, vec3Scale(n, 2.0 * vec3Dot(v, n)));}

// Linear Interpolation
static inline vec3 vec3Lerp(vec3 a, vec3 b, double t) {return vec3Add(a, vec3Scale(vec3Sub(b, a), t));}


#endif
