//
// Created by barti on 30.03.2025.
//

#include "Renderer.h"

#include "OrthographicCam.h"

using namespace display;

Renderer::Renderer() {
    this->camera = new OrthographicCam();
}
