//
// Created by Kubus on 25.03.2025.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "vec3.h"
#include "ray.h"
#include "primitive.h"

namespace math {
    class triangle : public primitive {
    public:
        vec3 A, B, C;

        triangle();
        triangle(vec3 &a, vec3 &b, vec3 &c, Material &material);

        vec3* intersection(ray &ray) override;
        vec3 getNormal(vec3 point) override;
    };
}

#endif // TRIANGLE_H