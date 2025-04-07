//
// Created by Kubus on 07.04.2025.
//

#include "PointLight.h"
#include <cmath>
#include <algorithm>
using namespace lighting;
using namespace math;
using namespace std;

PointLight::PointLight()
    : Light(lightIntensity()), position(vec3(0, 0, 0)),
      constantAttenuation(1.0f), linearAttenuation(0.09f), quadraticAttenuation(0.032f) {}

PointLight::PointLight(lightIntensity intensity, vec3 pos,
                       float constant, float linear, float quadratic)
    : Light(intensity), position(pos),
      constantAttenuation(constant), linearAttenuation(linear), quadraticAttenuation(quadratic) {}

lightIntensity PointLight::getAmbient(primitive* object) {
    return this->intensity * object->material.ambient;
}

lightIntensity PointLight::getDiffuse(primitive* object, vec3 point) {
    vec3 normal = object->getNormal(point);
    vec3 lightDir = (this->position.subtract(point)).normalize();
    float diffuseFactor = max(0.0f, normal.dotProduct(lightDir));

    float distance = (this->position.subtract(point)).length();
    float attenuation = 1.0f / (constantAttenuation + linearAttenuation * distance + quadraticAttenuation * distance * distance);

    return this->intensity * object->material.diffuse * diffuseFactor * attenuation;
}

lightIntensity PointLight::getSpecular(primitive* object, vec3 point, Camera* camera) {
    vec3 normal = object->getNormal(point);
    vec3 lightDir = (this->position.subtract(point)).normalize();
    vec3 viewDir = (camera->position.subtract(point)).normalize();
    vec3 R = (normal * (2.0f * normal.dotProduct(lightDir)) - lightDir).normalize();
    float dotProduct = max(0.0f, R.dotProduct(viewDir));
    float specularFactor = pow(dotProduct, object->material.shininess);

    float distance = (this->position.subtract(point)).length();
    float attenuation = 1.0f / (constantAttenuation + linearAttenuation * distance + quadraticAttenuation * distance * distance);

    return this->intensity * object->material.specular * specularFactor * attenuation;
}

ray PointLight::genShadowRay(vec3 origin) {
    ray sray;
    sray.origin = origin;
    sray.direction = (this->position.subtract(origin)).normalize();
    return sray;
}