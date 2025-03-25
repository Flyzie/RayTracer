//
// Created by Kubus on 25.03.2025.
//

#include "triangle.h"
#include <cmath>

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

    float denominator = d00 * d11 - d01 * d01;
    if (fabs(denominator) < 1e-6) {
        u = v = w = -1.0f;
        return;
    }
    v = (d11 * d20 - d01 * d21) / denominator;
    w = (d00 * d21 - d01 * d20) / denominator;
    u = 1.0f - v - w;
}

static bool pointInTriangle2D(const math::vec3 &P, const math::vec3 &A,
                              const math::vec3 &B, const math::vec3 &C) {
    auto sign = [](const math::vec3 &p1, const math::vec3 &p2, const math::vec3 &p3) -> float {
        return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
    };
    float d1 = sign(P, A, B);
    float d2 = sign(P, B, C);
    float d3 = sign(P, C, A);

    bool isNegative = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool isPositive = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(isNegative && isPositive);
}

static bool segmentsIntersect2D(const math::vec3 &A, const math::vec3 &B,
                                const math::vec3 &C, const math::vec3 &D) {
    auto orientation = [](const math::vec3 &p, const math::vec3 &q, const math::vec3 &r) -> float {
        return (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    };

    float o1 = orientation(A, B, C);
    float o2 = orientation(A, B, D);
    float o3 = orientation(C, D, A);
    float o4 = orientation(C, D, B);

    if (o1 * o2 < 0 && o3 * o4 < 0)
        return true;
    return false;
}

namespace math {

triangle::triangle() : A(), B(), C() {}

triangle::triangle(vec3 &a, vec3 &b, vec3 &c) {
    A = a;
    B = b;
    C = c;
}

bool triangle::intersectsLine(vec3 &P1, vec3 &P2, vec3 &intersectionPoint) {
    vec3 edge1 = B.subtract(A);
    vec3 edge2 = C.subtract(A);
    vec3 planeNormal = edge1.crossProduct(edge2).normalize();

    vec3 lineDir = P2.subtract(P1);
    float denominator = planeNormal.dotProduct(lineDir);

    if (fabs(denominator) < 1e-6) {
        vec3 diff = P1.subtract(A);
        if (fabs(planeNormal.dotProduct(diff)) > 1e-6) {
            return false;
        }
        if (pointInTriangle2D(P1, A, B, C) || pointInTriangle2D(P2, A, B, C))
            return true;
        if (segmentsIntersect2D(P1, P2, A, B) ||
            segmentsIntersect2D(P1, P2, B, C) ||
            segmentsIntersect2D(P1, P2, C, A))
            return true;
        return false;
    } else {
        vec3 diff = A.subtract(P1);
        float t = planeNormal.dotProduct(diff) / denominator;
        vec3 tmp = lineDir.multiply(t);
        vec3 interPoint = P1.add(tmp);

        float u, v, w;
        barycentric(A, B, C, interPoint, u, v, w);

        if (u >= 0 && v >= 0 && w >= 0 && u <= 1 && v <= 1 && w <= 1) {
            int zeroCount = 0;
            if (fabs(u) < 1e-6) zeroCount++;
            if (fabs(v) < 1e-6) zeroCount++;
            if (fabs(w) < 1e-6) zeroCount++;
            if (zeroCount >= 2)
                return false;
            intersectionPoint = interPoint;
            return true;
        }
        return false;
    }
}

}