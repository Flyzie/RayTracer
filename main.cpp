#include <cmath>
#include <iostream>
#include <math.h>

#include "vec3.h"
#include "ray.h"
#include "sphere.h"
#include "mat3x3.h"
using namespace std;
using namespace math;

void printMatrix(mat3x3& m);

int main() {
    //Zadanie 1 i 2
    vec3 v1(0, 2, 3);
    vec3 v2(4, 5, 6);
    vec3 v3 = v1.add(v2);
    vec3 v4 = v2.add(v1);

    cout <<"naprzemienność wektorow:" << endl;
    cout<< "dodawanie v1 + v2: " << v3.x << " " << v3.y << " " << v3.z << endl;
    cout<< "dodawanie v2 + v1: " << v4.x << " " << v4.y << " " << v4.z << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
    //Zadanie 3 - kąt między wektorami

    vec3 v5(0, 3, 0);
    vec3 v6(5, 5, 0);

    float dotv5v6 = v5.dotProduct(v6);
    dotv5v6 = dotv5v6 / (v5.length() * v6.length());
    float angle = acos(dotv5v6) * 180 / M_PI;

    cout << "Kat miedzy wektorami: " << angle << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
    //Zadanie 4 - Wektor prostopadły
    vec3 v7(4, 5, 1);
    vec3 v8(4, 1, 3);

    vec3 crossv7v8 = v7.crossProduct(v8);
    cout << "Wektor prostopadly do podanych wektorow: " << crossv7v8.x << " " << crossv7v8.y << " " << crossv7v8.z << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
    //Zadanie 5 - Normalizacja wektora
    vec3 normalized = crossv7v8.normalize();
    cout << "Normalizacja wektora: " << normalized.x << " " << normalized.y << " " << normalized.z << endl;
    cout << endl;
    cout << "--------------------------------" << endl;
    //Zadanie 6 i 7 - Sfera
    vec3 center(0, 0, 0);
    sphere s(center, 10);

    //Zadanie 8 - Promien r1
    vec3 r1o(0,0,-20);
    vec3 dirr1 = center.subtract(r1o).normalize();
    ray r1(r1o, dirr1);

    math::vec3 ress = r1o.crossProduct(dirr1);

    //Zadanie 9 - Promien r2 rownolegle do osi y
    vec3 dirr2(0,1,0);
    ray r2(r1o, dirr2);

    //Zadanie 10 i 11 - Przeciecie sfery z promieniami r1 i r2
    cout << "r1: " << endl;
    bool intersection = s.intersection(r1, 0, 10);
    cout << "r2: " << endl;
    bool intersection2 = s.intersection(r2, 0, 1000);
    cout << endl;
    cout << "--------------------------------" << endl;

    //Zadanie 12 - Promien R3 przecinajacy w jednym punkcie
    vec3 dirr3(0,0,1);
    vec3 r3o (0,10,-20);
    ray r3(r3o, dirr3);
    cout << "r3 przeciecie: " << endl;
    bool intersection3 = s.intersection(r3, 0, 1000);






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