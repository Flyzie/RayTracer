//
// Created by barti on 24.03.2025.
//

#include "mat3x3.h"

using namespace math;
using namespace std;

mat3x3::mat3x3() {
    for (int i = 0; i < 9; i++) {
        m[i] = 0;
    }
}

mat3x3::~mat3x3() {};

mat3x3::mat3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
    m[0] = a;
    m[1] = b;
    m[2] = c;
    m[3] = d;
    m[4] = e;
    m[5] = f;
    m[6] = g;
    m[7] = h;
    m[8] = i;
}

mat3x3& mat3x3::operator=(const mat3x3& other) {
    for (int i = 0; i < 9; i++) {
        m[i] = other.m[i];
    }
    return *this;
}

mat3x3 mat3x3::add(const mat3x3& other) {
    mat3x3 matrix = *this;
    for (int i = 0; i < 9; i++) {
        matrix.m[i] = m[i] + other.m[i];
    }
    return matrix;
}

mat3x3 mat3x3::subtract(const mat3x3& other) {
    mat3x3 matrix = *this;
    for (int i = 0; i < 9; i++) {
        matrix.m[i] = m[i] - other.m[i];
    }
}

mat3x3 mat3x3::multiply(const mat3x3& other) {
    mat3x3 matrix = *this;

    float temp[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                temp[i][j] += matrix.m[i * 3 + k] * other.m[k * 3 + j];
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix.m[i * 3 + j] = temp[i][j];
        }
    }
    return matrix;
}

mat3x3 mat3x3::multiply(float f) {
    mat3x3 matrix = *this;
    for (int i = 0; i < 9; i++) {
        matrix.m[i] = m[i] * f;
    }
    return matrix;
}

mat3x3 mat3x3::divide(float f) {
    mat3x3 matrix = *this;
    for (int i = 0; i < 9; i++) {
        matrix.m[i] = m[i] / f;
    }
    return matrix;
}
mat3x3 mat3x3::cIdentity() {
    return mat3x3(1, 0, 0,
                  0, 1, 0,
                  0, 0, 1);
}

mat3x3 mat3x3::transpose() {
    mat3x3 matrix = *this;
    float temp[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = m[j * 3 + i];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matrix.m[i * 3 + j] = temp[i][j];
        }
    }
    return matrix;
}








