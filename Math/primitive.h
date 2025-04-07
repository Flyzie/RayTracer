//
// Created by barti on 31.03.2025.
//
#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "LightIntensity.h"
#include "ray.h"
#include "../Light/Material.h"

namespace math {
    class primitive {
        public:
        Material material;
        virtual vec3* intersection(ray &ray) = 0;
        virtual vec3 getNormal(vec3 point) = 0;
    };
}

#endif //PRIMITIVE_H
