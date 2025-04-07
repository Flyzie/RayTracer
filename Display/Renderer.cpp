//
// Created by barti on 30.03.2025.
//

#include "Renderer.h"

#include <iostream>
#include <ostream>
#include <random>
#include "PerspectiveCam.h"
#include "OrthographicCam.h"
using namespace std;

using namespace display;

Renderer::Renderer() {
    this->camera = new OrthographicCam();
    this->primitives = vector<math::primitive*>();
    this->background = new lightIntensity(1,0,0);
    this->lights = std::vector<lighting::Light *>();
    this->aliasingSamples = 5;
}

Renderer::Renderer(Camera *camera,vector<lighting::Light*> lights, vector<math::primitive*> primitives, lightIntensity *background, int aliasingSamples) {
    this->camera = camera;
    this->primitives = primitives;
    this->background = background;
    this->aliasingSamples = aliasingSamples;
    this->lights = lights;
}

Image Renderer::render(int width, int height) {
    Image image(width, height);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-0.15f, 0.15f);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            lightIntensity finalColor;
            for (int s = 0; s < this->aliasingSamples; s++) {
                float jitterX = dist(gen);
                float jitterY = dist(gen);
                bool hit = false;
                math::ray ray = camera->fireRay(x + jitterX, y + jitterY, width, height);
                for (int i = 0; i < this->primitives.size(); i++) {

                    math::vec3 *intersection = this->primitives[i]->intersection(ray);
                    if (intersection != nullptr) {
                        for (int z = 0; z < this->lights.size(); z++) {
                            math::ray shadowRay = lights[z]->genShadowRay(*intersection);
                            math::vec3 *shadowHit = nullptr;

                            for (int p = 0; p < this->primitives.size(); p++) {
                                if (p == i) {
                                    continue;
                                }
                                shadowHit = this->primitives[p]->intersection(shadowRay);
                                if (shadowHit != nullptr) {
                                    break;
                                }
                            }
                            if (shadowHit != nullptr) {
                                finalColor = this->lights[z]->getAmbient(this->primitives[i]);
                            }else {
                                lightIntensity ambientCol = this->lights[z]->getAmbient(this->primitives[i]);
                                lightIntensity diffuseCol = this->lights[z]->getDiffuse(this->primitives[i], *intersection);
                                lightIntensity specularCol = this->lights[z]->getSpecular(this->primitives[i], *intersection, this->camera);

                                finalColor = finalColor + ambientCol + diffuseCol + specularCol;
                                //image.setPixel(x, y, this->primitives[i]->color);
                                hit = true;
                                //break;
                            }
                        }
                    }
                }
                if (!hit) {
                    finalColor = finalColor + *this->background;
                   // image.setPixel(x, y, *this->background);
                }
            }
            finalColor = finalColor / this->aliasingSamples;
            image.setPixel(x, y, finalColor);
        }
    }
    Camera *cam = this->camera;
    if (dynamic_cast<OrthographicCam*>(cam)) {
        image.save("orthographic.ppm");
        cout << "Image saved as orthographic.ppm" << endl;
    } else if (dynamic_cast<PerspectiveCam*>(cam)) {
        image.save("perspective.ppm");
        cout << "Image saved as perspective.ppm" << endl;
    } else {
        cout << "Problem with the camera" << endl;
    }
    return image;
}