//
// Created by barti on 07.04.2025.
//
#pragma once
#include "lightIntensity.h"
#include "PerspectiveCam.h"
#include "primitive.h"
#ifndef LIGHT_H
#define LIGHT_H

namespace lighting {
    class Light {
    public:
        display::lightIntensity intensity;

        Light(display::lightIntensity intensity);
        Light();
        virtual ~Light() = default;

        virtual display::lightIntensity getAmbient(math::primitive* object) = 0;
        virtual display::lightIntensity getDiffuse(math::primitive* object, math::vec3 point) = 0;
        virtual display::lightIntensity getSpecular(math::primitive* object, math::vec3 point, display::Camera* camera) = 0;

    };
}


#endif //LIGHT_H
