//
// Created by barti on 24.03.2025.
//

#include "sphere.h"
#include "ray.h"
#include "vec3.h"
#include <cmath>
using namespace math;
using namespace std;

#include <stdexcept>
#include <iostream>

sphere::sphere() {
    this->center = vec3();
    this->radius = 0;
    this->material = Material();
}

sphere::~sphere() {}

sphere::sphere(vec3 &center, float radius, Material &material) {
    this->center = center;

    if (radius < 0) {
        throw invalid_argument("radius cant be negative");
    }

    this->radius = radius;
    this->material = material;
}

sphere::sphere(const sphere &sphere) {
    this->center = sphere.center;
    this->radius = sphere.radius;
    this->material = sphere.material;
}

float root(float b, float discriminant, float a) {
    if (discriminant > 0) {
        return (-b + sqrt(discriminant)) / a;
    }else {
        return (-b - sqrt(-discriminant)) / a;
    }
}


vec3 sphere::getNormal(vec3 point) {
    vec3 normal = point.subtract(this->center);
    normal.normalize();
    return normal;
}


vec3* sphere::intersection(ray &ray) {
   vec3 oc = ray.origin.subtract(this->center);

    float a = ray.direction.dotProduct(ray.direction);
    float b = 2 * oc.dotProduct(ray.direction);
    float c = oc.dotProduct(oc) - this->radius * this->radius;

    float discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0) {
        return nullptr;
    }

    // Calculate the two points of intersection
    float x1 = (-b - std::sqrt(discriminant)) / (2 * a);
    float x2 = (-b + std::sqrt(discriminant)) / (2 * a);
    float x;

    if (x1 > 0) {
        x = x1;
    } else if (x2 > 0) {
        x = x2;
    } else {
        return nullptr;
    }

    vec3 result = ray.pointAtParameter(x);
    vec3* resultPtr = new vec3(result);
    return resultPtr;
}

