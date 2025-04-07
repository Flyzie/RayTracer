//
// Created by barti on 07.04.2025.
//

#include "Light.h"
using namespace lighting;

Light::Light(display::lightIntensity intensity) {
    this->intensity = intensity;
}

Light::Light() {
    this->intensity = display::lightIntensity(0,0,0);
}

