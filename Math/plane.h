//
// Created by Kubus on 25.03.2025.
//

#ifndef PLANE_H
#define PLANE_H

#include "vec3.h"
#include "ray.h"
#include "primitive.h"

namespace math {
    class plane : public primitive {
    public:
        vec3 point;
        vec3 normal;

        plane();
        plane(vec3 &p, vec3 &n, display::lightIntensity &color);

        bool intersection(ray &ray) override;
        bool intersection(ray &r, float t_min, float t_max, float &t);
    };
}

#endif // PLANE_H
