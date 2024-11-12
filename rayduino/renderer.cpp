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

    viewPortWidth = viewPortHeight  * (float(width) / length);

    viewPortU = Vector3(viewPortWidth, 0, 0);
    viewPortV = Vector3(0, -viewPortHeight, 0);

    pixelDeltaU = viewPortU / length;
    pixelDeltaV = viewPortV / width;

    viewPortUpperLeft = Vector3(0, 0, 0)
                        - Vector3(0, 0, depth) - viewPortU/2 - viewPortV/2;

    pixel00Loc = viewPortUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

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
    for (int i = 0; i < projectionPlane.y() * 2; i++) {
        for (int j = 0; j < projectionPlane.x() * 2; j++) {

            Vector3 cameraCenter = Vector3(0, 0, 0);
            Vector3 pixelCenter = pixel00Loc + (j * pixelDeltaU) + (i * pixelDeltaV);
            Vector3 rayDirection = pixelCenter - cameraCenter;

            // initializes a new ray
            Ray* ray = new Ray(
                cameraCenter,
                rayDirection
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
