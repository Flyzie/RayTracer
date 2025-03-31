//
// Created by barti on 29.03.2025.
//

#include "lightIntensity.h"

using namespace display;
using namespace std;
#include <algorithm>




lightIntensity::lightIntensity() {
    this -> r = 0.0f;
    this -> g = 0.0f;
    this -> b = 0.0f;
}

lightIntensity::~lightIntensity(){}

lightIntensity::lightIntensity(double r, double g, double b) {
    this -> r = r;
    this -> g = g;
    this -> b = b;
}

lightIntensity::lightIntensity(double r, double g) {
    this -> r = r;
    this -> g = g;
    this -> b = 0.0f;
}

lightIntensity::lightIntensity(double r) {
    this -> r = r;
    this -> g = 0.0f;
    this -> b = 0.0f;
}

int lightIntensity::red() const {
    return std::clamp(static_cast<int>(this->r * 255), 0, 255);
}

int lightIntensity::green() const {
    return std::clamp(static_cast<int>(this->g * 255), 0, 255);
}

int lightIntensity::blue() const {
    return std::clamp(static_cast<int>(this->b * 255), 0, 255);
}

lightIntensity lightIntensity::operator+(const lightIntensity& other) const {
    return {this->r + other.r, this->g + other.g, this->b + other.b};
}

lightIntensity lightIntensity::operator-(const lightIntensity& other) const {
    return {this->r - other.r, this->g - other.g, this->b - other.b};
}

lightIntensity lightIntensity::operator*(const lightIntensity& other) const {
    return {this->r * other.r, this->g * other.g, this->b * other.b};
}

lightIntensity lightIntensity::operator/(const lightIntensity& other) const {
    return {this->r / other.r, this->g / other.g, this->b / other.b};
}

lightIntensity lightIntensity::operator/(const float &num) const {
    return {this->r / num, this->g / num, this->b / num};
}



