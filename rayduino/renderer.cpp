#include "renderer.h"

Renderer::Renderer() {
    projectionPlane = Vector3(96, 64, depth); 
}

Renderer::Renderer(int length, int width) {
    projectionPlane = Vector3((float) length / 2, (float) width / 2, depth);
};
