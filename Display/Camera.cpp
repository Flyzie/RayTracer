//
// Created by barti on 30.03.2025.
//

#include "Camera.h"

using namespace std;
using namespace display;
using namespace math;

Camera::Camera() {
    this->position = vec3(0,0,0);
    this->target = vec3(0,0,-1);
    this->up = vec3(0,1,0);
    this->nearPlane = 0.1f;
    this->farPlane = 1000.0f;
}

Camera::Camera(const math::vec3 &position,const math::vec3 &target,const math::vec3 &up, float nearPlane, float farPlane) {
    this->position = position;
    this->target = target;
    this->up = up;
    this->nearPlane = nearPlane;
    this->farPlane = farPlane;
}

