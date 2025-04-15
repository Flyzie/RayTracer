//
// Created by barti on 05.04.2025.
//

#ifndef MATERIAL_H
#define MATERIAL_H
#pragma once

#include "lightIntensity.h"
#include "vec3.h"

enum MaterialType {
    DIFFUSE,
    REFLECTIVE,
    REFRACTIVE
};
class Material {
    public:
    display::lightIntensity diffuse;
    display::lightIntensity specular;
    display::lightIntensity ambient;

    float shininess;
    float reflectiveness;
    float refractiveIndex;
    bool isTransparent;
    MaterialType type;

    Material();
    ~Material() = default;
    Material(const Material& other);

    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular, float shininess, float reflectiveness, float refractiveIndex, bool isTransparent, MaterialType type);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular, float shininess, float refractiveIndex, MaterialType type);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, const display::lightIntensity& specular, MaterialType type);
    Material(const display::lightIntensity &ambient, const display::lightIntensity &diffuse, const display::lightIntensity &specular, float shininess, MaterialType type);
    Material(const display::lightIntensity& ambient, const display::lightIntensity& diffuse, MaterialType type);
    Material(const display::lightIntensity& ambient, MaterialType type);

};



#endif //MATERIAL_H
