#include "renderer.h"

Renderer::Renderer() {
    projectionPlane = Vector3(96, 64, depth); 
}

Renderer::Renderer(int length, int width) {
    // initializes the projection plane to be in the center of the width and height
    projectionPlane = Vector3(length / 2.0, width / 2.0, depth);
};
