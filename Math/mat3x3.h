//
// Created by barti on 24.03.2025.
//

#ifndef MAT3X3_H
#define MAT3X3_H


namespace math {
    class mat3x3 {
    public:
        float m[9];

        mat3x3();
        ~mat3x3();
        mat3x3(float a, float b, float c
                ,float d ,float e,float f,
                float g,float h,float i);
        mat3x3& operator=(const mat3x3&);

        mat3x3 add(const mat3x3 &other);
        mat3x3 subtract(const mat3x3 &other);
        mat3x3 multiply(const mat3x3 &other);
        mat3x3 multiply(float f);
        mat3x3 divide(float f);

        mat3x3 cIdentity();


    };
}

#endif //MAT3X3_H
