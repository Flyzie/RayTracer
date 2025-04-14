#include <cmath>
#include <iostream>
#include <math.h>

#include "Camera.h"
#include "vec3.h"
#include "OrthographicCam.h"
#include "LightIntensity.h"
#include "Renderer.h"
#include "ray.h"
#include "sphere.h"
#include "mat3x3.h"
#include "triangle.h"
#include "plane.h"
#include "objectParser.h"
#include "PerspectiveCam.h"
#include "Light/Light.h"
#include "Light/DirectionalLight.h"
#include "Light/PointLight.h"
using namespace std;
using namespace math;
using namespace display;
using namespace lighting;

int main() {
    /*
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
    cout << endl;
    cout << "--------------------------------" << endl;

    //Zadanie 12 i 13: Płaszczyzna P i przecięcie z promieniem R2
    vec3 pPoint(0, 0, 0);
    vec3 pNormal(0, 1, 1);
    plane P(pPoint, pNormal);

    vec3 r2Origin(0, 0, -20);
    vec3 r2Direction(0, 1, 0);
    ray R2(r2Origin, r2Direction);

    float t_plane;
    bool planeHit = P.intersection(R2, 0.0f, 1000.0f, t_plane);
    if (planeHit) {
        vec3 interPoint = R2.pointAtParameter(t_plane);
        cout << "Punkt przeciecia plaszczyzny P z promieniem R2: "
             << interPoint.x << ", " << interPoint.y << ", " << interPoint.z << endl;
    } else {
        cout << "Brak przeciecia plaszczyzny P z promieniem R2" << endl;
    }

    cout << "--------------------------------" << endl;

    //Zadanie 15: Sprawdzenie przecięcia linii z trójkątem
    vec3 A(0, 0, 0);
    vec3 B(1, 0, 0);
    vec3 C(0, 1, 0);
    triangle tri(A, B, C);

    vec3 interSectionPt;

    // Przypadek 1: Linia przechodząca przez trójkąt.
    // P1: (-1, 0.5, 0), P2: (1, 0.5, 0) ->  true
    vec3 P1_case1(-1, 0.5, 0);
    vec3 P2_case1(1, 0.5, 0);
    bool case1 = tri.intersectsLine(P1_case1, P2_case1, interSectionPt);
    cout << "Przypadek 1 (linia przechodzaca przez trojkat): "
         << (case1 ? "true" : "false") << endl;

    // Przypadek 2: Linia leżąca na plaszczyźnie trójkąta, ale poza nim.
    // P1: (2, -1, 0), P2: (2, 2, 0) -> false
    vec3 P1_case2(2, -1, 0);
    vec3 P2_case2(2, 2, 0);
    bool case2 = tri.intersectsLine(P1_case2, P2_case2, interSectionPt);
    cout << "Przypadek 2 (linia na plaszczyznie, ale poza trojkatem): "
         << (case2 ? "true" : "false") << endl;

    // Przypadek 3: Linia nieprzecinajaca trójkąta.
    // P1: (0, 0, -1), P2: (0, 0, 1) -> false
    vec3 P1_case3(0, 0, -1);
    vec3 P2_case3(0, 0, 1);
    bool case3 = tri.intersectsLine(P1_case3, P2_case3, interSectionPt);
    cout << "Przypadek 3 (linia przecinajaca plaszczyzne poza trojkatem): "
         << (case3 ? "true" : "false") << endl;

    //.obj parser
    objectParser parser;
    parser.loadObj("G:\\RayTracer\\cube.obj");
*/
    //ortagonalna
    OrthographicCam OrthoCam(
        vec3(0, 0, 0),
        vec3(0, 0, -1),
        vec3(0, 1, 0),
        0.1f,
        1000.0f);

    Material sphere1Mat (lightIntensity(0.01, 0, 0),
        lightIntensity(1.0, 0.0, 0.0),
        lightIntensity(0.7, 0.7, 0.7),
        50,
        0.0);

    Material sphere2Mat (lightIntensity(0, 0, 0.01),
        lightIntensity(0.0, 0.0, 1.0),
        lightIntensity(1.0, 1.0, 1.0),
        80,
        0.0);

    Material planeMat (lightIntensity(0, 0.01, 0),
        lightIntensity(0.0, 1.0, 0.0),
        lightIntensity(0.7, 0.7, 0.7),
        50,
        0.0);

    Material rightWall (lightIntensity(0, 0.01, 0.01),
        lightIntensity(0.0, 0.3, 0.3),
        lightIntensity(0.7, 0.7, 0.7),
        50,
        0.0);

    Material backWall (lightIntensity(0.01, 0.01, 0),
        lightIntensity(0.3, 0.5, 0.7),
        lightIntensity(0.7, 0.7, 0.7),
        50,
        0.0);

    vec3 sphere1Center = vec3(0, 0, -30);
    lightIntensity sphere1Col(0, 0, 1);
    sphere s1(sphere1Center, 0.5f, sphere1Mat);
    lightIntensity bgColor(0.1,0.1,0.1);

    DirectionalLight light1(lightIntensity(0.7,0.7,0.7), vec3(-0.2,-0.5,-0.5));
    PointLight pointLight(lightIntensity(1.7, 3, 1.4), vec3(6, 3, -4));



    vector<primitive*> primitives;
    vector<Light*> lights;
    primitives.push_back(&s1);
    lights.push_back(&light1);
    //lights.push_back(&pointLight);
    Renderer renderer(&OrthoCam,lights, primitives, &bgColor, 20);

    renderer.render(300, 300);

    //perspektywiczna
    PerspectiveCam PerspCam(
        vec3(0, 0, 0),
        vec3(0, 0, -0.5),
        vec3(0, 1, 0),
        0.1f,
        1000.0f,
        90.0f);

    vec3 sphere2Center = vec3(-2, 0, -10);
    sphere s2(sphere2Center, 2.0f, sphere1Mat);
    vec3 sphere3Center = vec3(0, 3, -8);
    sphere s3(sphere3Center, 1.5f, sphere2Mat);

    //floor
    vec3 p1Normal(0, 1, 0); // Normal pointing up
    vec3 p1Center(0, -4.5, 0);
    plane P(p1Center, p1Normal, planeMat);

    //right wall
    vec3 p2Normal(1,0,0);
    vec3 p2Center(-10.5, 0, 0);
    plane P2(p2Center, p2Normal, rightWall);

    //backwall
    vec3 p3Normal(0,0,1);
    vec3 p3Center(0, 0, -28);
    plane P3(p3Center, p3Normal, backWall);


    vector<primitive*> primitivesPerspective;
    primitivesPerspective.push_back(&s2);
    primitivesPerspective.push_back(&s3);
    primitivesPerspective.push_back(&P);
   // primitivesPerspective.push_back(&P2);
  //  primitivesPerspective.push_back(&P3);

    Renderer perspRenderer(&PerspCam,lights, primitivesPerspective, &bgColor, 10);
    perspRenderer.render(500, 500);
    return 0;
}




