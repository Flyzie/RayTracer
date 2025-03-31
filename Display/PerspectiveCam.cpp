//
// Created by Kubus on 31.03.2025.
//

#include "PerspectiveCam.h"
#include <cmath>

using namespace display;
using namespace math;

PerspectiveCam::PerspectiveCam() : Camera(), fov(90.0f) {}

PerspectiveCam::PerspectiveCam(const math::vec3 &position, const math::vec3 &target, const math::vec3 &up,
                               float nearPlane, float farPlane, float fov)
    : Camera(position, target, up, nearPlane, farPlane), fov(fov) {}

math::ray PerspectiveCam::fireRay(int pixelX, int pixelY, int imageWidth, int imageHeight) {
    float aspect = static_cast<float>(imageWidth) / static_cast<float>(imageHeight);
    float fovRad = fov * static_cast<float>(M_PI) / 180.0f;

    float imagePlaneWidth = 2.0f * nearPlane * tan(fovRad * 0.5f);
    float imagePlaneHeight = imagePlaneWidth / aspect;

    float x = -imagePlaneWidth / 2.0f + (pixelX + 0.5f) * (imagePlaneWidth / imageWidth);
    float y = imagePlaneHeight / 2.0f - (pixelY + 0.5f) * (imagePlaneHeight / imageHeight);

    math::vec3 pos = position;
    math::vec3 tgt = target;
    math::vec3 upVec = up;

    math::vec3 w = tgt.subtract(pos).normalize();
    math::vec3 u_vec = upVec.crossProduct(w).normalize();
    math::vec3 v_vec = w.crossProduct(u_vec);

    math::vec3 temp1 = w.multiply(nearPlane);
    math::vec3 imageOrigin = pos.add(temp1);
    math::vec3 temp2 = u_vec.multiply(x);
    imageOrigin = imageOrigin.add(temp2);
    math::vec3 temp3 = v_vec.multiply(y);
    math::vec3 imagePoint = imageOrigin.add(temp3);

    math::vec3 rayDir = imagePoint.subtract(pos).normalize();

    return math::ray(pos, rayDir);
}