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
        plane(vec3 &p, vec3 &n, Material &material);

        vec3* intersection(ray &ray) override;
        vec3 getNormal(vec3 point) override;
    };
}

#endif // PLANE_H
