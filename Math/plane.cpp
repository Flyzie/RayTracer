//
// Created by Kubus on 25.03.2025.
//

#include "plane.h"
#include <cmath>

namespace math {

    plane::plane() : point(), normal() {}

    plane::plane(vec3 &p, vec3 &n) {
        point = p;
        normal = n.normalize();
    }

    bool plane::intersection(ray &r, float t_min, float t_max, float &t) {
        float denom = normal.dotProduct(r.direction);
        if (fabs(denom) < 1e-6) {
            return false;
        }
        vec3 diff = point.subtract(r.origin);
        float num = normal.dotProduct(diff);
        t = num / denom;
        if (t < t_min || t > t_max) {
            return false;
        }
        return true;
    }

}