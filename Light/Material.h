//
// Created by barti on 05.04.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once

#include "lightIntensity.h"
#include "vec3.h"


class Material {
    public:
    display::lightIntensity diffuse;
    display::lightIntensity specular;
    display::lightIntensity ambient;

    float shininess;
    float reflectiveness;
    float refractiveIndex;
    bool isTransparent;

    Material();
    ~Material() = default;
    Material(const Material& other);

    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular, float shininess, float reflectiveness, float refractiveIndex, bool isTransparent);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular, float shininess, float refractiveIndex);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular);
    Material(const display::lightIntensity &ambient, const display::lightIntensity &diffuse, const display::lightIntensity &specular, float shininess);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse);
    Material(const display::lightIntensity& ambient);

};



#endif //MATERIAL_H
