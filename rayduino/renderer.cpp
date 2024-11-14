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
    projectionPlane = Vector3(length, width, depth);
    cameraCenter = Vector3(0, 0, 0);
    numShapes = 0;
    maxShapes = 1;
    shapes = nullptr;

    viewPortWidth = viewPortHeight  * (float(width) / length);

    viewPortU = Vector3(viewPortWidth, 0, 0);
    viewPortV = Vector3(0, -viewPortHeight, 0);

    pixelDeltaU = viewPortU / double(width);
    pixelDeltaV = viewPortV / double(length);

    viewPortUpperLeft = cameraCenter - Vector3(0, 0, depth) - viewPortU/2 - viewPortV/2;
    Serial.println(viewPortWidth);

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
    for (int i = 0; i < projectionPlane.y(); i++) {
        for (int j = 0; j < projectionPlane.x(); j++) {

            Vector3 pixelCenter = pixel00Loc + (j * pixelDeltaU) + (i * pixelDeltaV);
            Vector3 rayDirection = pixelCenter - cameraCenter;

            // initializes a new ray
            Ray* ray = new Ray(
                cameraCenter,
                rayDirection
            );

            Sphere* sphere = new Sphere(
                1, 1, -5, 18, 60 ,18, 1
            );


            //for (int k = 0; k < numShapes; k++) {
                if (sphere->checkCollision(*ray)) {
                    //Serial.println("HIT!");
                    display->sendColor(Color(sphere->getColor()));
                }
            //}
                else{display->sendColor(Color(0, 0, 0));}
            delete sphere;
            delete ray;
        }
    }
}
