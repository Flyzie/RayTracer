//
// Created by Kubus on 25.03.2025.
//

#ifndef PLANE_H
#define PLANE_H

#include "vec3.h"
#include "ray.h"
#include "primitive.h"

namespace math {

    class plane : public primitive {
    public:
        vec3 point;    // center of your rectangle
        vec3 normal;   // as before
        float halfWidth, halfHeight;

        plane();
        // new ctor: give it a size
        plane(const vec3 &p, const vec3 &n,
              float hw, float hh,
              const Material &mat);

        plane(const plane &other);

        vec3* intersection(ray &ray) override;
        vec3  getNormal(vec3 point) override;
    };

}
#endif // PLANE_H
