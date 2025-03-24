//
// Created by barti on 24.03.2025.
//
#pragma once
#include "vec3.h"
#ifndef RAY_H
#define RAY_H


namespace math {
    class ray {
    public:
        vec3 origin;
        vec3 direction;
        ray();
        ~ray();
        ray(vec3 &origin, vec3 &direction);
        vec3 pointAtParameter(float t);
    };
}



#endif //RAY_H
