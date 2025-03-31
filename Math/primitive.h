//
// Created by barti on 31.03.2025.
//

#ifndef PRIMITIVE_H
#define PRIMITIVE_H
#include "LightIntensity.h"
#include "ray.h"

namespace math {
    class primitive {
        public:
        virtual bool intersection(ray &ray) = 0;
    };
}

#endif //PRIMITIVE_H
