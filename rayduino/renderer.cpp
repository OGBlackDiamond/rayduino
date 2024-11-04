#include "renderer.h"

Renderer::Renderer() {
    projectionPlane = Vector3(96, 64, depth); 
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;

    display = new Display();
}

Renderer::Renderer(int length, int width) {
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

void Renderer::addShape(Sphere& shape) {
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
    for (int i = 0; i < projectionPlane.y * 2; i++) {
        for (int j = 0; j < projectionPlane.x * 2; j++) {
            // initializes a new ray
            Ray* ray = new Ray(
                0, 0, -100, 
                j - projectionPlane.x, 
                i - projectionPlane.y,
                projectionPlane.z
            );

            Sphere* sphere = new Sphere(
                0, 0, 0, 20, 20 ,20, 0.9 
            );


            //for (int k = 0; k < numShapes; k++) {
                if (sphere->checkCollision(*ray)) {
                    //Serial.println("HIT!");
                    display->sendColor(Color(20, 20, 20));
                }
            //}
                else{display->sendColor(Color(0, 0, 0));}
            delete sphere;
            delete ray;
        }
    }
}
