#include "Camera.h"
//
// Created by barti on 31.03.2025.
//
using namespace display;
#include "OrthographicCam.h"

OrthographicCam::OrthographicCam(math::vec3 &position, math::vec3 &target, math::vec3 &up, float nearPlane, float farPlane)
: Camera(position, target, up, nearPlane, farPlane) {
}

OrthographicCam::OrthographicCam() : Camera() {

}


math::ray OrthographicCam::fireRay(int pixelX, int pixelY, int imageWidth, int imageHeight) {
    float pixelWidth = 2.0f / imageHeight;
    float pixelHeight = 2.0f / imageWidth;

    float x = -1.0f + (pixelX + 0.5f) * pixelWidth;
    float y = 1.0f - (pixelY + 0.5f) * pixelHeight;

    math::vec3 origin = math::vec3(x, y, 0.0f);
    math::vec3 direction = target.normalize();

    math::ray ray(origin, direction);

    return ray;
}
