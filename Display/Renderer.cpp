//
// Created by barti on 30.03.2025.
//

#include "Renderer.h"

#include <iostream>
#include <ostream>
#include <random>
#include <cmath>
#include "PerspectiveCam.h"
#include "OrthographicCam.h"
#include "../Light/PointLight.h"
#include "../Light/DirectionalLight.h"
using namespace std;
using namespace lighting;
using namespace display;

/*Renderer::Renderer() {
    this->camera = new OrthographicCam();
    this->primitives = vector<math::primitive*>();
    this->background = new lightIntensity(1,0,0);
    this->lights = std::vector<lighting::Light *>();
    this->aliasingSamples = 5;
}

Renderer::Renderer(Camera *camera, vector<lighting::Light*> lights, vector<math::primitive*> primitives, lightIntensity *background, int aliasingSamples) {
    this->camera = camera;
    this->primitives = primitives;
    this->background = background;
    this->aliasingSamples = aliasingSamples;
    this->lights = lights;
}

math::ray Renderer::refractRay(const math::ray &incident, const math::vec3 &normal, float n1, float n2) {
    float cosI = -normal.dotProduct(incident.direction);
    float eta = n1 / n2;
    float k = 1 - eta * eta * (1 - cosI * cosI);

    math::vec3 refractedDir;
    if (k < 0) {
        refractedDir = math::vec3(0, 0, 0); // total internal reflection
    } else {
        math::vec3 temp1 = incident.direction.multiply(eta);
        math::vec3 temp2 = normal.multiply(eta * cosI - sqrtf(k));
        refractedDir = temp1.add(temp2);
    }

    math::ray refractedRay;
    math::vec3 temp3 = incident.direction.multiply(0.001f);
    refractedRay.origin = incident.origin.add(temp3);
    refractedRay.direction = refractedDir.normalize();
    return refractedRay;
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
                        math::primitive* object = this->primitives[i];
                        math::vec3 normal = object->getNormal(*intersection);

                        for (int z = 0; z < this->lights.size(); z++) {

                            math::vec3 bias = normal * 0.001f;
                            math::ray shadowRay = lights[z]->genShadowRay(*intersection);
                            math::vec3 *shadowHit = nullptr;

                            bool isShadow = false;

                            for (int p = 0; p < this->primitives.size(); p++) {
                                if (p == i) {
                                    continue;
                                }
                                shadowHit = this->primitives[p]->intersection(shadowRay);
                                if (shadowHit != nullptr) {
                                    delete shadowHit;
                                    isShadow = true;
                                    break;
                                }
                                delete shadowHit;
                            }

                            finalColor = finalColor + this->lights[z]->getAmbient(object);

                            lightIntensity diffuseCol = this->lights[z]->getDiffuse(object, *intersection);
                            lightIntensity specularCol = this->lights[z]->getSpecular(object, *intersection, this->camera);

                            if (!isShadow) {
                                finalColor = finalColor + diffuseCol + specularCol;
                            }
                        }

                        if (object->material.isTransparent) {
                            float n1 = 1.0f;
                            float n2 = object->material.refractiveIndex;
                            math::ray refracted = refractRay(ray, normal, n1, n2);

                            for (int j = 0; j < this->primitives.size(); j++) {
                                math::vec3 *refractHit = this->primitives[j]->intersection(refracted);
                                if (refractHit != nullptr) {
                                    math::primitive* refractObj = this->primitives[j];
                                    lightIntensity refractedCol;

                                    for (int l = 0; l < this->lights.size(); l++) {
                                        refractedCol = refractedCol + this->lights[l]->getAmbient(refractObj);

                                        if (refractObj != object) {
                                            lightIntensity diff = this->lights[l]->getDiffuse(refractObj, *refractHit);
                                            lightIntensity spec = this->lights[l]->getSpecular(refractObj, *refractHit, this->camera);
                                            refractedCol = refractedCol + diff + spec;
                                        }
                                    }
                                    finalColor = finalColor + refractedCol;
                                    delete refractHit;
                                    break;
                                }
                                delete refractHit;
                            }
                        }

                        hit = true;
                        delete intersection;
                        break;
                    }
                    delete intersection;
                }

                if (!hit) {
                    finalColor = finalColor + *this->background;
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
}*/
Renderer::~Renderer() {
    delete camera;
    delete background;
}

Renderer::Renderer() {
    this->camera = new OrthographicCam();
    this->primitives = vector<math::primitive*>();
    this->background = new lightIntensity(1,0,0);
    this->lights = std::vector<lighting::Light *>();
    this->aliasingSamples = 5;
}

Renderer::Renderer(Camera *camera, vector<lighting::Light*> lights, vector<math::primitive*> primitives, lightIntensity *background, int aliasingSamples) {
    this->camera = camera;
    this->primitives = primitives;
    this->background = background;
    this->aliasingSamples = aliasingSamples;
    this->lights = lights;
}
math::ray Renderer::reflectRay(const math::ray& incident, const math::vec3& normal, const math::vec3& hitPoint) const {
    float cos_theta = normal.dotProduct(incident.direction);
    math::vec3 reflected = incident.direction - normal * (2 * cos_theta);
    return math::ray(hitPoint + reflected.normalize() * 0.01f, reflected.normalize());
}

math::ray Renderer::refractRay(const math::ray &incident, math::vec3 normal, float n1, float n2, const math::vec3 &hitPoint) const {
    float cos_i = -normal.dotProduct(incident.direction.normalize());
    float eta = n1 / n2;
    math::vec3 n = normal;

    if (cos_i < 0) {
        cos_i = -cos_i;
        n = -normal;
        eta = n2 / n1;
    }

    float k = 1 - eta * eta * (1 - cos_i * cos_i);
    if (k < 0) return math::ray(hitPoint, math::vec3(0,0,0)); // Całkowite odbicie

    math::vec3 refracted_dir = (incident.direction.normalize() * eta) + (n * (eta * cos_i - sqrtf(k)));
    refracted_dir = refracted_dir.normalize();

    // Bias w kierunku przeciwnym do normalnej
    return math::ray(hitPoint - n * 0.001f, refracted_dir);
}

lightIntensity Renderer::trace(math::ray &ray, int depth) const {
    if (depth <= 0) return *background;

    math::primitive* closest = nullptr;
    math::vec3 hit_point;
    float min_dist = INFINITY;

    for (auto obj : primitives) {
        math::vec3* hit = obj->intersection(ray);
        if (hit) {
            float dist = (ray.origin - *hit).lengthSquared();
            if (dist < min_dist) {
                min_dist = dist;
                hit_point = *hit;
                closest = obj;
            }
            delete hit;
        }
    }

    if (!closest) return *background;

    const Material& mat = closest->material;
    math::vec3 normal = closest->getNormal(hit_point).normalize();
    lightIntensity local = calculateLocalIllumination(closest, hit_point);
    lightIntensity reflected(0, 0, 0);
    lightIntensity refracted(0, 0, 0);

    if (mat.reflectiveness > 0.0f) {
        math::ray reflected_ray = reflectRay(ray, normal, hit_point);
        reflected = trace(reflected_ray, depth - 1) * mat.reflectiveness;
    }

    if (mat.isTransparent) {
        math::ray refracted_ray = refractRay(ray, normal, 1.0f, mat.refractiveIndex, hit_point);
        if (refracted_ray.direction != math::vec3(0,0,0)) {
            refracted = trace(refracted_ray, depth - 1) * (1.0f - mat.reflectiveness);
        }
    }

    return local + reflected + refracted;
}

lightIntensity Renderer::calculateLocalIllumination(
    math::primitive* currentObj,
    const math::vec3& hitPoint
) const {
    lightIntensity result;

    // Surface normal at hit
    math::vec3 N = currentObj->getNormal(hitPoint).normalize();
    const float bias = 1e-4f;  // to avoid self-shadowing

    for (auto light : lights) {
        // 1) Ambient always applies
        result = result + light->getAmbient(currentObj);

        // 2) Build shadow-ray & compute maxDist
        math::ray shadowRay;
        float maxDist = std::numeric_limits<float>::infinity();

        if (auto* pl = dynamic_cast<PointLight*>(light)) {
            // For point lights, only occluders _closer_ than the light block
            math::vec3 L = pl->position - hitPoint;
            maxDist = L.length();
            // genShadowRay already returns ray.origin = hitPoint + bias*N
            // and ray.direction = normalized(L)
            shadowRay = pl->genShadowRay(hitPoint + N * bias);
        }
        else if (auto* dl = dynamic_cast<DirectionalLight*>(light)) {
            // For directional lights, treat as infinite
            shadowRay = dl->genShadowRay(hitPoint + N * bias);
        }
        else {
            // Fallback: assume infinite
            shadowRay = light->genShadowRay(hitPoint + N * bias);
        }

        // 3) Trace occluders
        bool inShadow = false;
        for (auto* obj : primitives) {
            if (obj == currentObj) continue;
            math::vec3* ih = obj->intersection(shadowRay);
            if (!ih) continue;

            // compute distance along shadowRay to ih
            float dist = (*ih - shadowRay.origin).length();
            delete ih;

            if (dist < maxDist) {
                inShadow = true;
                break;
            }
        }

        // 4) If not in shadow, add diffuse & specular
        if (!inShadow) {
            result = result
                   + light->getDiffuse(currentObj, hitPoint)
                   + light->getSpecular(currentObj, hitPoint, camera);
        }
    }

    return result;
}

Image Renderer::render(int width, int height) {
    Image image(width, height);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-0.01f, 0.01f);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            lightIntensity color;

            for (int s = 0; s < aliasingSamples; ++s) {
                float jitterX = dist(gen);
                float jitterY = dist(gen);

                math::ray ray = camera->fireRay(
                    x + jitterX,
                    y + jitterY,
                    width,
                    height
                );

                color = color + trace(ray, 5);
            }

            color = color / aliasingSamples;
            image.setPixel(x, y, color);
        }
    }

    if (dynamic_cast<OrthographicCam*>(camera)) {
        image.save("orthographic.ppm");
        cout << "Image saved as orthographic.ppm" << endl;
    } else if (dynamic_cast<PerspectiveCam*>(camera)) {
        image.save("perspective.ppm");
        cout << "Image saved as perspective.ppm" << endl;
    } else {
        cout << "Problem with the camera" << endl;
    }

    return image;
}