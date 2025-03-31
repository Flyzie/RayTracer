//
// Created by barti on 29.03.2025.
//

#include "lightIntensity.h"

using namespace display;
using namespace std;




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



