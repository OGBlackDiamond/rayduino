#include "renderer.h"

Renderer::Renderer(int length, int width) {
    // initializes the projection plane to be in the center of the width and height
    projectionPlane = Vector3(length, width, depth);
    cameraCenter = Vector3(0, 0, 0);
    numShapes = 0;
    maxShapes = 1;
    spheres = new Sphere[maxShapes];

    viewPortWidth = viewPortHeight  * (float(width) / length);
    viewPortU = Vector3(viewPortWidth, 0, 0);
    viewPortV = Vector3(0, -viewPortHeight, 0);

    pixelDeltaU = viewPortU / double(width);
    pixelDeltaV = viewPortV / double(length);

    viewPortUpperLeft = cameraCenter - Vector3(0, 0, depth) - viewPortU/2 - viewPortV/2;

    pixel00Loc = viewPortUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

    display = new Display(length, width);
};

Renderer::~Renderer() {
    delete[] spheres;
    delete display;
}

void Renderer::addSphere(Sphere shape) {
    if (numShapes == maxShapes) {
        maxShapes *= 2;
        Sphere* tmp = new Sphere[maxShapes];
        for (int i = 0; i < numShapes; i++) {
            tmp[i] = spheres[i];
        }
        delete[] spheres;
        spheres = tmp;
    }
    spheres[numShapes] = Sphere(shape);
    numShapes++;
}

void Renderer::castRays() {
    for (int i = 0; i < projectionPlane.y(); i++) {
        for (int j = 0; j < projectionPlane.x(); j++) {

            Vector3 pixelCenter = pixel00Loc + (j * pixelDeltaU) + (i * pixelDeltaV);
            Vector3 rayDirection = pixelCenter - cameraCenter;

            // initializes a new ray
            Ray ray(
                cameraCenter,
                rayDirection
            );

            for (int k = 0; k < numShapes; k++) {
                HitInfo hit = spheres[k].checkCollision(ray);

                if (hit.didHit) {
                    Vector3 n(ray.at(hit.distance) - Vector3(0, 0, -1)); n.normalize();
                    display->sendColor(Color(n.x() + 1, n.y() + 1, n.z() + 1));
                } else{
                    display->sendColor(Color(0, 0, 0));
                }
            }
        }
    }
}
