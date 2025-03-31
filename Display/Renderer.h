//
// Created by barti on 30.03.2025.
//

#ifndef RENDERER_H
#define RENDERER_H
#include "Camera.h"
#include "Image.h"
#include "lightIntensity.h"
#include "primitive.h"

using namespace std;

namespace display {
    class Renderer {
    private:
        Camera* camera;
        vector<math::primitive*> primitives;
        lightIntensity* background;
    public:
        Renderer();
        ~Renderer() = default;
        Renderer(Camera* camera, vector<math::primitive>, lightIntensity* background);
        Image render(int width, int height);
    };
}


#endif //RENDERER_H
