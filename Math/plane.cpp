//
// Created by Kubus on 25.03.2025.
//

#include "plane.h"
#include <cmath>
#include <limits>

namespace math {

    plane::plane() : point(), normal() {}

    plane::plane(vec3 &p, vec3 &n, display::lightIntensity &color) {
        point = p;
        normal = n.normalize();
        this->color = color;
    }

    bool plane::intersection(ray &ray) {
        float t;
        return intersection(ray, std::numeric_limits<float>::min(), std::numeric_limits<float>::max(), t);
    }

    bool plane::intersection(ray &r, float t_min, float t_max, float &t) {
        float denom = normal.dotProduct(r.direction);
        if (fabs(denom) < 1e-6) return false;

        vec3 diff = point.subtract(r.origin);
        float num = normal.dotProduct(diff);
        t = num / denom;

        return (t >= t_min && t <= t_max);
    }
}