//
// Created by barti on 30.03.2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "Camera.h"
#include "Image.h"
#include "lightIntensity.h"
#include "primitive.h"
#include "../Light/Light.h"

using namespace std;

namespace display {
    class Renderer {
    private:
        Camera* camera;
        vector<math::primitive*> primitives;
        vector<lighting::Light*> lights;
        lightIntensity* background;
        int aliasingSamples;
    public:
        Renderer();
        ~Renderer() = default;
        Renderer(Camera* camera,vector<lighting::Light*> lights, vector<math::primitive*> primitives, lightIntensity* background, int aliasingSamples);
        Image render(int width, int height);
    };
}


#endif //RENDERER_H
