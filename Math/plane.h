//
// Created by Kubus on 25.03.2025.
//

#ifndef PLANE_H
#define PLANE_H

#include "vec3.h"
#include "ray.h"
#include <cmath>

namespace math {

    class plane {
    public:
        vec3 point;
        vec3 normal;

        plane();
        plane(vec3 &p, vec3 &n);

        bool intersection(ray &r, float t_min, float t_max, float &t);
    };

}


#endif //PLANE_H
