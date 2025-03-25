//
// Created by barti on 24.03.2025.
//

#include "ray.h"
using namespace math;
using namespace std;

ray::ray() {
    this->origin = vec3();
    this->direction = vec3();
}


ray::ray(vec3 &origin, vec3 &direction) {
    this->origin = origin;
    this->direction = direction;
}

vec3 ray::pointAtParameter(float t) {
    vec3 var1 = vec3(this->origin);
    vec3 var2 = vec3(this->direction);

    vec3 var3 = var2.multiply(t);

    return var1.add(var3);
}

ray::~ray() {}
