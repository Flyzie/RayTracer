//
// Created by barti on 24.03.2025.
//

#ifndef VEC3_H
#define VEC3_H
namespace math {
    class vec3 {
    public:
        float x, y, z;

        vec3();
        ~vec3();
        vec3(float x, float y, float z);
        vec3(const vec3 &other);
        vec3& add(vec3 &other);
        vec3& subtract(vec3 &other);
        vec3& multiply(float multiplier);
        vec3& divide(float divider);
        float length();
        vec3 normalize();
        float dotProduct(vec3 &other);
        vec3 crossProduct(vec3 &other);
    };
}



#endif //VEC3_H
