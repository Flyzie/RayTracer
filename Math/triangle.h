//
// Created by Kubus on 25.03.2025.
//
/*
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
        triangle(vec3 &a, vec3 &b, vec3 &c);

        bool intersection(ray &ray) override;
        bool intersectsLine(vec3 &P1, vec3 &P2, vec3 &intersectionPoint);
    };
}

#endif // TRIANGLE_H
*/