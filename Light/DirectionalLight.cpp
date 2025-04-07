//
// Created by barti on 07.04.2025.
//

#include "DirectionalLight.h"
#include "ray.h"

#include <algorithm>
#include <cmath>
using namespace lighting;
using namespace math;
using namespace std;

DirectionalLight::DirectionalLight()
:Light(lightIntensity()), direction(vec3(0, -1, -1)) {}

DirectionalLight::DirectionalLight(lightIntensity intensity, vec3 direction) : Light(intensity), direction(direction) {}

lightIntensity DirectionalLight::getAmbient(primitive *object) {
    return this->intensity * object->material.ambient;
}

lightIntensity DirectionalLight::getDiffuse(primitive *object, vec3 point) {
    vec3 normal = object->getNormal(point);
    vec3 lightDir = this->direction.normalize();

    float diffuseFactor = max(0.0f, normal.dotProduct(lightDir));

    return this->intensity * object->material.diffuse * diffuseFactor;
}

lightIntensity DirectionalLight::getSpecular(primitive *object, vec3 point, Camera *camera) {
    vec3 normal = object->getNormal(point);
    vec3 lightDir = this->direction.normalize();
    vec3 viewDir = (camera->position - point).normalize();

    vec3 R = (normal * (2.0f * normal.dotProduct(lightDir)) - lightDir).normalize();
    float dotProduct = std::max(0.0f, R.dotProduct(viewDir));
    float specularFactor = pow(dotProduct, object->material.shininess);

    return this->intensity * object->material.specular * specularFactor;
}

ray DirectionalLight::genShadowRay(vec3 origin) {
    ray sray;
    sray.origin = origin;
    sray.direction = this->direction;
    return sray;
}


