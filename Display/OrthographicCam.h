//
// Created by barti on 31.03.2025.
//

#ifndef ORTHOGRAPHICCAM_H
#define ORTHOGRAPHICCAM_H
#include "Camera.h"


namespace display {
    class OrthographicCam : public Camera {
    public:
        OrthographicCam(const math::vec3 &position,const math::vec3 &target,const math::vec3 &up, float nearPlane, float farPlane);
        OrthographicCam();
        math::ray fireRay(int pixelX, int pixelY, int imageWidth, int imageHeight);
    };
}


#endif //ORTHOGRAPHICCAM_H
