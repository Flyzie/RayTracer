//
// Created by barti on 24.03.2025.
//
#pragma once
#include "primitive.h"
#include "ray.h"
#include "vec3.h"

#ifndef SPHERE_H
#define SPHERE_H


namespace math {
    class sphere : public primitive {
    private:
        bool intersection(ray &ray, float t_min, float t_max);
    public:
        vec3 center;
        float radius;
        sphere();
        ~sphere();
        sphere(vec3 &center, float radius, Material &material);
        sphere(const sphere &sphere);
        vec3 getNormal(vec3 point);
        vec3* intersection(ray &ray);

    };
}


#endif //SPHERE_H
