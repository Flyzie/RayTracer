#include <iostream>
#include "vec3.h"
#include "mat3x3.h"
using namespace std;
using namespace math;

void printMatrix(mat3x3& m);

int main() {
    cout << "Hello, World!" << std::endl;

    mat3x3 m1(1,2,3,4,5,6,7,8,9);
    mat3x3 m2(9, 8, 7, 6, 5, 4, 3, 2, 1);

     mat3x3 m3 = m1.multiply(m2);

    printMatrix(m3);


    return 0;
}

void printMatrix(mat3x3& m) {
  for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
          cout << m.m[i * 3 + j] << " ";
      }
      cout << endl;
  }
}