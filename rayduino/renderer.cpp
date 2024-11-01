#include "renderer.h"

Renderer::Renderer() {
    projectionPlane = Vector3(96, 64, depth); 
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;

    display = new Display();
}

Renderer::Renderer(int length, int width) {
  Serial.println("constructing deez");
    // initializes the projection plane to be in the center of the width and height
    projectionPlane = Vector3(length / 2.0, width / 2.0, depth);
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;

    display = new Display(length, width);
};

Renderer::~Renderer() {
    delete[] shapes;
    delete display;
}

void Renderer::addShape(Sphere shape) {
    if (numShapes == maxShapes) {
        maxShapes *= 2;
        Sphere* tmp = new Sphere[maxShapes];
        for (int i = 0; i < numShapes; i++) {
            tmp[i] = shapes[i];
        }
        shapes = tmp;
        delete[] tmp;
    }
    shapes[numShapes] = shape;
    numShapes++;
}

void Renderer::castRays() {
    for (int i = 0; i < projectionPlane.x * 2; i++) {
        for (int j = 0; j < projectionPlane.y * 2; j++) {
            // initializes a new ray
            Ray ray = Ray(
                0, 0, 0, 
                i - projectionPlane.x, 
                j - projectionPlane.y,
                projectionPlane.z
            );
            Serial.print("Casting Ray: ");
            Serial.print(i);
            Serial.print(", ");
            Serial.println(j);

            for (int k = 0; k < numShapes; k++) {
                if (shapes[k].checkCollision(ray)) {
                    display->setPixel(i, j, shapes[k].getColor());
                    break;
                }
            }
        }
    }
}
