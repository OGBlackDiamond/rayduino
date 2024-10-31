#include "renderer.h"

Renderer::Renderer() {
    projectionPlane = Vector3(96, 64, depth); 
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;
}

Renderer::Renderer(int length, int width) {
    // initializes the projection plane to be in the center of the width and height
    projectionPlane = Vector3(length / 2.0, width / 2.0, depth);
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;
};

Renderer::~Renderer() {
    delete[] shapes;
}

void Renderer::addShape(Shape& shape) {
    if (numShapes == maxShapes) {
        maxShapes *= 2;
        Shape* tmp = new Shape[maxShapes];
        for (int i = 0; i < numShapes; i++) {
            tmp[i] = shapes[i];
        }
        shapes = tmp;
        delete[] tmp;
    }
    shapes[numShapes] = shape;
    numShapes++;
}


