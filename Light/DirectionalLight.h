//
// Created by barti on 07.04.2025.
//
#pragma once

#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#include "Light.h"
using namespace display;
using namespace math;


namespace lighting {
    class DirectionalLight : public Light {
        public:
        vec3 direction;

        DirectionalLight(lightIntensity intensity, vec3 direction);
        DirectionalLight();

        lightIntensity getAmbient(primitive* object) override;
        lightIntensity getDiffuse(primitive* object, vec3 point) override;
        lightIntensity getSpecular(primitive* object, vec3 point, Camera* camera) override;

    };
}


#endif //DIRECTIONALLIGHT_H
