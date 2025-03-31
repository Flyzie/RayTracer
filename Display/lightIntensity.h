//
// Created by barti on 29.03.2025.
//
#pragma once
#ifndef LIGHTINTENSITY_H
#define LIGHTINTENSITY_H


namespace display {
    class lightIntensity {
    public:
        double r, g, b;

        lightIntensity();
        lightIntensity(double r, double g, double b);
        lightIntensity(double r, double g);
        lightIntensity(double r);
        ~lightIntensity();

        int red() const;
        int green() const;
        int blue() const;


        lightIntensity operator+(const lightIntensity& other) const;
        lightIntensity operator-(const lightIntensity& other) const;
        lightIntensity operator*(const lightIntensity& other) const;
        lightIntensity operator/(const lightIntensity& other) const;
        lightIntensity operator/(const float& num) const;

    };
}


#endif //LIGHTINTENSITY_H
