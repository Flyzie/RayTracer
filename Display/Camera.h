//
// Created by barti on 30.03.2025.
//

#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"

namespace display{
    class Camera {
        public:
        math::vec3 position;
        math::vec3 target;
        math::vec3 up;

        float nearPlane;
        float farPlane;

        Camera();
        ~Camera();
        Camera(math::vec3 &position, math::vec3 &target, math::vec3 &up, float nearPlane, float farPlane);

    };
}


#endif //CAMERA_H
