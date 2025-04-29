//
// Created by Kubus on 25.03.2025.
//

#include "plane.h"
#include <cmath>
#include <limits>

namespace math {

    plane::plane()
        : point(), normal(), halfWidth(0), halfHeight(0)
    {
        material = Material();
    }

    plane::plane(const vec3 &p,
                 const vec3 &n,
                 float hw,
                 float hh,
                 const Material &mat)
        : point(p),
          normal(n.normalize()),
          halfWidth(hw),
          halfHeight(hh)
    {
        material = mat;
    }

    plane::plane(const plane &other)
        : point(other.point),
          normal(other.normal),
          halfWidth(other.halfWidth),
          halfHeight(other.halfHeight)
    {
        material = other.material;
    }

    vec3* plane::intersection(ray &ray) {
        // 1) Back-face cull
        float denom = normal.dotProduct(ray.direction);
        if (denom >= std::numeric_limits<float>::epsilon())
            return nullptr;

        // 2) Solve for t
        vec3 diff = point.subtract(ray.origin);
        float t = diff.dotProduct(normal) / denom;
        if (t < std::numeric_limits<float>::epsilon())
            return nullptr;

        // 3) Hit point
        vec3 hitP = ray.pointAtParameter(t);

        // 4) Build in-plane axes (must use lvalues for crossProduct)
        vec3 up(0.0f, 1.0f, 0.0f);
        vec3 right(1.0f, 0.0f, 0.0f);

        vec3 tangent = normal.crossProduct(up);
        if (tangent.lengthSquared() < 1e-6f) {
            tangent = normal.crossProduct(right);
        }
        tangent = tangent.normalize();

        vec3 bitan = normal.crossProduct(tangent).normalize();

        // 5) Project offset
        vec3 d = hitP.subtract(point);
        float x = d.dotProduct(tangent);
        float y = d.dotProduct(bitan);

        // 6) Clamp to rectangular bounds
        if (fabs(x) > halfWidth || fabs(y) > halfHeight)
            return nullptr;

        // 7) Return hit
        return new vec3(hitP);
    }

    vec3 plane::getNormal(vec3 /*unused*/) {
        return normal;
    }

}