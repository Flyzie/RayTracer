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
using namespace std;

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

math::vec3 Renderer::randomDirectionOnHemisphere(const math::vec3 &normal) const {
    // Random numbers
    float r1 = static_cast<float>(rand()) / RAND_MAX;
    float r2 = static_cast<float>(rand()) / RAND_MAX;

    float r = sqrtf(r1);
    float theta = 2.0f * M_PI * r2;

    float x = r * cosf(theta);
    float y = r * sinf(theta);
    float z = sqrtf(1.0f - r1);  // Notice this is cosine-weighted

    // Create an orthonormal basis (u, v, normal)
    math::vec3 u;
    if (fabs(normal.x) > fabs(normal.z))
        u = math::vec3(-normal.y, normal.x, 0.0f).normalize();
    else
        u = math::vec3(0.0f, -normal.z, normal.y).normalize();

    math::vec3 v = normal.crossProduct(u);

    // Transform to world space
    math::vec3 direction = (u * x) + (v * y) + (normal * z);
    return direction.normalize();
}

lightIntensity Renderer::pathTrace(math::ray& ray, int depth) const {
    if (depth <= 0) {
        return *background;
    }

    // Find closest intersection
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

    if (!closest) {
        return *background;
    }

    const Material& mat = closest->material;
    math::vec3 normal = closest->getNormal(hit_point).normalize();

    // Make sure normal faces the ray
    if (normal.dotProduct(ray.direction) > 0) {
        normal = -normal;
    }

    // Calculate direct lighting (explicit light sampling)
    lightIntensity directLight = calculateLocalIllumination(closest, hit_point);

    // Calculate indirect lighting with Russian Roulette
    lightIntensity indirectLight(0, 0, 0);

    // Russian Roulette probability based on material reflectance
    float maxReflectance = std::max(std::max(mat.diffuse.r, mat.diffuse.g), mat.diffuse.b);
    float survivalProbability = std::min(0.9f, std::max(0.1f, maxReflectance));



    // Decide whether to continue tracing or not
    if (static_cast<float>(rand()) / RAND_MAX < survivalProbability) {
            math::vec3 bounce_dir = randomDirectionOnHemisphere(normal);
            math::ray bounce_ray(hit_point + normal * 0.001f, bounce_dir);

            // Cosine-weighted importance sampling
            float cos_theta = std::max(0.0f, normal.dotProduct(bounce_dir));
            float PDF = cos_theta / M_PI;
        if (PDF <= 0.0001f) {
            return directLight;
        }
            indirectLight = pathTrace(bounce_ray, depth - 1) * mat.diffuse * cos_theta * (1.0f / survivalProbability * PDF);
    }

    return directLight + indirectLight;
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

lightIntensity Renderer::calculateLocalIllumination(math::primitive* currentObj, const math::vec3& hitPoint) const {
    lightIntensity result;
    math::vec3 normal = currentObj->getNormal(hitPoint);

    for (auto light : lights) {
        result = result + light->getAmbient(currentObj);

        math::vec3 bias = normal * 0.001f;
       // math::ray shadow_ray = light->genShadowRay(hitPoint + bias);

        bool in_shadow = false;

        for (auto obj : primitives) {
            if (obj == currentObj) continue;


        }

        if (!in_shadow) {
            result = result + light->getDiffuse(currentObj, hitPoint);
            result = result + light->getSpecular(currentObj, hitPoint, camera);
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

                color = color + pathTrace(ray, 16);
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
