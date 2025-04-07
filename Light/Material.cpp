//
// Created by barti on 05.04.2025.
//

#include "Material.h"
using namespace display;

Material::Material() {
    this->ambient = lightIntensity(0, 0, 0);
    this->diffuse = lightIntensity(0, 0, 0);
    this->specular = lightIntensity(0, 0, 0);
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
}

Material::Material(const lightIntensity &ambient) {
    this->ambient = ambient;
    this->diffuse = lightIntensity(0, 0, 0);
    this->specular = lightIntensity(0, 0, 0);
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
}
Material::Material(const lightIntensity &ambient, const lightIntensity &diffuse) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = lightIntensity(0, 0, 0);
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
}

Material::Material(const display::lightIntensity &ambient, const display::lightIntensity &diffuse, const display::lightIntensity &specular) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
}

Material::Material(const display::lightIntensity &ambient, const display::lightIntensity &diffuse, const display::lightIntensity &specular, float shininess) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->reflectiveness = 0.0f;
}

Material::Material(const display::lightIntensity &ambient, const display::lightIntensity &diffuse, const display::lightIntensity &specular, float shininess, float reflectiveness) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->reflectiveness = reflectiveness;
}







