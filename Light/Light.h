//
// Created by barti on 07.04.2025.
//
#pragma once
#include "lightIntensity.h"
#include "PerspectiveCam.h"
#include "primitive.h"
#ifndef LIGHT_H
#define LIGHT_H
using namespace display;

namespace lighting {
    class Light {
    public:
        lightIntensity intensity;

        Light(lightIntensity intensity);
        Light();
        virtual ~Light() = default;

        virtual lightIntensity getAmbient(math::primitive* object) = 0;
        virtual lightIntensity getDiffuse(math::primitive* object, math::vec3 point) = 0;
        virtual lightIntensity getSpecular(math::primitive* object, math::vec3 point, Camera* camera) = 0;

    };
}


#endif //LIGHT_H
