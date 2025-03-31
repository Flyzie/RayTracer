//
// Created by Kubus on 31.03.2025.
//

#ifndef PERSPECTIVE_CAM_H
#define PERSPECTIVE_CAM_H

#include "Camera.h"

namespace display {

    class PerspectiveCam : public Camera {
    public:
        float fov;

        PerspectiveCam();
        PerspectiveCam(const math::vec3 &position, const math::vec3 &target, const math::vec3 &up,
                       float nearPlane, float farPlane, float fov);

        virtual math::ray fireRay(int pixelX, int pixelY, int imageWidth, int imageHeight) override;
    };

}

#endif // PERSPECTIVE_CAM_H