//
// Created by barti on 30.03.2025.
//

#include "Renderer.h"

#include <iostream>
#include <ostream>
#include "PerspectiveCam.h"
#include "OrthographicCam.h"
using namespace std;

using namespace display;

Renderer::Renderer() {
    this->camera = new OrthographicCam();
    this->primitives = vector<math::primitive*>();
    this->background = new lightIntensity(1,0,0);
}

Renderer::Renderer(Camera *camera, vector<math::primitive*> primitives, lightIntensity *background) {
    this->camera = camera;
    this->primitives = primitives;
    this->background = background;
}

Image Renderer::render(int width, int height) {
    Image image(width, height);
    lightIntensity hitColor (50, 100, 255);
    lightIntensity bgColor (255, 0, 0);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bool hit = false;
            math::ray ray = camera->fireRay(x, y, width, height);
            for (int i = 0; i < this->primitives.size(); i++) {
                if (this->primitives[i]->intersection(ray)) {
                    hit = true;
                    image.setPixel(x, y, hitColor);
                    break;
                }
            }
            if (!hit) {
                image.setPixel(x, y, bgColor);
            }
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