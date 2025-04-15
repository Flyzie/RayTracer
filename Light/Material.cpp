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
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material(const lightIntensity &ambient, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = lightIntensity(0, 0, 0);
    this->specular = lightIntensity(0, 0, 0);
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material(const lightIntensity &ambient, const lightIntensity &diffuse, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = lightIntensity(0, 0, 0);
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material(const lightIntensity &ambient, const lightIntensity &diffuse, const lightIntensity &specular, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = 0.0f;
    this->reflectiveness = 0.0f;
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material(const lightIntensity &ambient, const lightIntensity &diffuse, const lightIntensity &specular, float shininess, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->reflectiveness = 0.0f;
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material(const lightIntensity &ambient, const lightIntensity &diffuse, const lightIntensity &specular, float shininess, float reflectiveness, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->reflectiveness = reflectiveness;
    this->refractiveIndex = 1.0f;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}

Material::Material (const lightIntensity &ambient, const lightIntensity &diffuse, const lightIntensity &specular, float shininess, float reflectiveness, float refractiveIndex, bool isTransparent, const MaterialType type) {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->shininess = shininess;
    this->reflectiveness = reflectiveness;
    this->refractiveIndex = refractiveIndex;
    this->isTransparent = isTransparent;

    if (isTransparent) {
        this->type = REFRACTIVE;
    } else if (reflectiveness > 0.8f) {
        this->type = REFLECTIVE;
    } else {
        this->type = DIFFUSE;
    }
}







