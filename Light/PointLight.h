//
// Created by Kubus on 07.04.2025.
//

#ifndef POINTLIGHT_H
#define POINTLIGHT_H

#include "Light.h"

namespace lighting {
    class PointLight : public Light {
    public:
        math::vec3 position;
        float constantAttenuation;
        float linearAttenuation;
        float quadraticAttenuation;

        PointLight();
        PointLight(lightIntensity intensity, math::vec3 pos,
                   float constant = 1.0f, float linear = 0.09f, float quadratic = 0.032f);

        virtual lightIntensity getAmbient(math::primitive* object) override;
        virtual lightIntensity getDiffuse(math::primitive* object, math::vec3 point) override;
        virtual lightIntensity getSpecular(math::primitive* object, math::vec3 point, Camera* camera) override;
        virtual math::ray genShadowRay(math::vec3 origin) override;
    };
}

#endif
