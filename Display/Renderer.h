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

/*namespace display {
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
        lightIntensity traceRay(const math::ray &ray, int depth);
        math::ray refractRay(const math::ray &incident, const math::vec3 &normal, float n1, float n2);
        Image render(int width, int height);
    };
}*/
namespace display {
    class Renderer {
    private:
        Camera* camera;
        vector<math::primitive*> primitives;
        vector<lighting::Light*> lights;
        lightIntensity* background;
        int aliasingSamples;

        lightIntensity trace(math::ray &ray, int depth) const;
        lightIntensity calculateLocalIllumination(math::primitive* obj, const math::vec3& hitPoint) const;
        math::ray reflectRay(const math::ray& incident, const math::vec3& normal, const math::vec3& hitPoint) const;
        math::ray refractRay(const math::ray &incident, math::vec3 normal, float n1, float n2, const math::vec3 &hitPoint) const;

    public:
        Renderer();
        ~Renderer();
        Renderer(Camera* camera, vector<lighting::Light*> lights, vector<math::primitive*> primitives, lightIntensity* background, int aliasingSamples);
        Image render(int width, int height);
    };
}


#endif //RENDERER_H
