//
// Created by Kubus on 25.03.2025.
//

#include "plane.h"
#include <cmath>
#include <limits>

namespace math {

    plane::plane() : point(), normal() {}

    plane::plane(vec3 &p, vec3 &n, Material &mat) {
        point = p;
        normal = n.normalize();
        material = mat;
    }

    vec3* plane::intersection(ray &ray) {
        float denom = normal.dotProduct(ray.direction);
        if (fabs(denom) < 1e-6) return nullptr;

        vec3 diff = point.subtract(ray.origin);
        float t = diff.dotProduct(normal) / denom;

        if (t >= std::numeric_limits<float>::epsilon()) {
            vec3 hitPoint = ray.pointAtParameter(t);
            return new vec3(hitPoint);
        }

        return nullptr;
    }

    vec3 plane::getNormal(vec3 point) {
        return normal;
    }

}
