//
// Created by barti on 07.04.2025.
//

#ifndef DIRECTIONALLIGHT_H
#define DIRECTIONALLIGHT_H
#include "Light.h"


namespace lighting {
    class DirectionalLight : public Light {

        /*
        public:
        math::vec3 direction;

        DirectionalLight(display::lightIntensity intensity, math::vec3 direction);
        DirectionalLight();

        display::lightIntensity getAmbient(math::primitive* object) = 0;
        display::lightIntensity getDiffuse(math::primitive* object, math::vec3 point) = 0;
        display::lightIntensity getSpecular(math::primitive* object, math::vec3 point, display::Camera* camera) = 0;
*/
    };
}


#endif //DIRECTIONALLIGHT_H
