
#include "vec3.h"
#include <cmath>
#include <stdexcept>

using namespace math;
using namespace std;

vec3::vec3() {
    this -> x = 0.0f;
    this -> y = 0.0f;
    this -> z = 0.0f;
}

vec3::~vec3() {}

vec3::vec3(float x, float y, float z) {
    this -> x = x;
    this -> y = y;
    this -> z = z;
}

vec3::vec3(const vec3 &other) {
    this -> x = other.x;
    this -> y = other.y;
    this -> z = other.z;
}

vec3 vec3::add(vec3 &other) const{
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}

vec3 vec3::subtract(vec3 &other) {
    return {this->x - other.x, this->y - other.y, this->z - other.z};
}

vec3 vec3::multiply(float multiplier) const {
    return vec3(this->x * multiplier, this->y * multiplier, this->z * multiplier);
}

vec3 vec3::divide(float divider) {
    if (divider == 0.0f) {
        throw std::invalid_argument("dont divide by 0!");
    }
    return {this->x / divider, this->y / divider, this->z / divider};
}

float vec3::length() const{
    return (float)sqrt(pow(this->x, 2) + pow(this->y, 2) +
                         pow(this->z, 2));
}

float vec3::lengthSquared() const {
    return x * x + y * y + z * z;
}

vec3 vec3::normalize() const{
    vec3 n = *this;
    float length = n.length();

    if (length == 0.0f) {
        throw invalid_argument("cant divide by 0");
    }
    vec3 finalVec = n.divide(length);

    return finalVec;
}

float vec3::dotProduct(const vec3 &other) const{
    return this->x * other.x + this->y * other.y + this->z * other.z;
}

vec3 vec3::crossProduct(vec3 &other) const{
    return vec3(this->y * other.z - this->z * other.y,
                this->z * other.x - this->x * other.z,
                this->x * other.y - this->y * other.x);
}

vec3 vec3::operator-(const vec3 &v) const{
    return {this->x - v.x, this->y - v.y, this->z - v.z};
}

vec3 vec3::operator*(float scalar) const{
    return {this->x * scalar, this->y * scalar, this->z * scalar};
}

vec3 vec3::operator-() {
    return vec3{
    -this->x,
    -this->y,
    -this->z,
        };
}

vec3 vec3::operator+(const vec3 &v) const{
    return {this->x + v.x, this->y + v.y, this->z + v.z};
}

bool vec3::operator!=(const vec3 &other) const {
    return this->x != other.x || this->y != other.y || this->z != other.z;
}


