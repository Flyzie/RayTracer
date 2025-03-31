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
}

sphere::~sphere() {}

sphere::sphere(vec3 &center, float radius) {
    this->center = center;

    if (radius < 0) {
        throw invalid_argument("radius cant be negative");
    }

    this->radius = radius;
}

sphere::sphere(const sphere &sphere) {
    this->center = sphere.center;
    this->radius = sphere.radius;
}

float root(float b, float discriminant, float a) {
    if (discriminant > 0) {
        return (-b + sqrt(discriminant)) / a;
    }else {
        return (-b - sqrt(-discriminant)) / a;
    }
}

bool sphere::intersection(ray &ray) {
    return this->intersection(ray, numeric_limits<float>::min(), numeric_limits<float>::max());
}


bool sphere::intersection(ray &ray, float t_min, float t_max) {
   vec3 oc = ray.origin.subtract(this->center);

    float a = ray.direction.dotProduct(ray.direction);
    float b = oc.dotProduct(ray.direction);
    float c = oc.dotProduct(oc) - this->radius * this->radius;

    float discriminant = b * b - a * c;

    if (discriminant < 0) {
        return false;
    }

    // Calculate the two points of intersection
    float t1 = root(b, -discriminant, a);
    float t2 = root(b, discriminant, a);
/*
    if (discriminant < 0) {
       cout << "no intersection" << endl;
    }else if (discriminant > 0) {
        vec3 hitPoint1 = ray.pointAtParameter(t1);
        vec3 hitPoint2 = ray.pointAtParameter(t2);
        cout << "Parameter T: " << t1 << " and " << t2 <<endl;
        cout << "Intersection point 1: " << hitPoint1.x << " " << hitPoint1.y << " " << hitPoint1.z << endl;
        cout << "Intersection point 2: " << hitPoint2.x << " " << hitPoint2.y << " " << hitPoint2.z << endl;
    }else {
        vec3 hitPoint1 = ray.pointAtParameter(t1);
        cout << "Parameter T: " << t1 << endl;
        cout << "Intersection point: " << hitPoint1.x << " " << hitPoint1.y << " " << hitPoint1.z << endl;
    }
    */
    return (t1 > t_min && t2 < t_max) || (t2 > t_min && t2 < t_max);
}

