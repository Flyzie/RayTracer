#include "triangle.h"
#include <cmath>
#include <limits>

static void barycentric(math::vec3 &A, math::vec3 &B, math::vec3 &C, math::vec3 &P,
                        float &u, float &v, float &w) {
    math::vec3 v0 = B.subtract(A);
    math::vec3 v1 = C.subtract(A);
    math::vec3 v2 = P.subtract(A);

    float d00 = v0.dotProduct(v0);
    float d01 = v0.dotProduct(v1);
    float d11 = v1.dotProduct(v1);
    float d20 = v2.dotProduct(v0);
    float d21 = v2.dotProduct(v1);

    float denom = d00 * d11 - d01 * d01;
    if (fabs(denom) < 1e-6f) {
        u = v = w = -1.0f;
        return;
    }
    v = (d11 * d20 - d01 * d21) / denom;
    w = (d00 * d21 - d01 * d20) / denom;
    u = 1.0f - v - w;
}

namespace math {

    triangle::triangle() : A(), B(), C() {}

    triangle::triangle(vec3 &a, vec3 &b, vec3 &c) {
        A = a;
        B = b;
        C = c;
    }

    bool triangle::intersection(ray &ray) {
        vec3 edge1 = B.subtract(A);
        vec3 edge2 = C.subtract(A);
        vec3 h = ray.direction.crossProduct(edge2);
        float a = edge1.dotProduct(h);

        if (fabs(a) < 1e-6f) return false;

        float f = 1.0f / a;
        vec3 s = ray.origin.subtract(A);
        float u = f * s.dotProduct(h);
        if (u < 0.0f || u > 1.0f) return false;

        vec3 q = s.crossProduct(edge1);
        float v = f * ray.direction.dotProduct(q);
        if (v < 0.0f || u + v > 1.0f) return false;

        float t = f * edge2.dotProduct(q);
        return (t > std::numeric_limits<float>::min());
    }

}