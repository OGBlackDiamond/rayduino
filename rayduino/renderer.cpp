#include "renderer.h"
#include "hitInfo.h"

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

            uint32_t randomSeed = j * projectionPlane.x() + i;

            // initializes a new ray
            Ray ray(
                cameraCenter,
                rayDirection
            );

            Color totalColor;

            for (int k = 0; k < raysPerPixel; k++) {
                totalColor += traceRay(ray, randomSeed);
            }

            totalColor /= raysPerPixel;

            display->sendColor(totalColor);
        }
    }
}

Color Renderer::traceRay(Ray& ray, uint32_t& randomSeed) {
    Color light = Color(0, 0, 0);
    Color color = Color(1, 1, 1);

    const Color emittedLight = Color(1, 1, 1);
    
    for (int i = 0; i <= maxBounceCount; i++) {

        HitInfo hit = calcRayCollision(ray);
        if (hit.didHit) {
            
            Vector3 randDir = Util::randomDirection(
                hit.normal,
                randomSeed 
            );


            ray.setPosition(hit.hitPoint);
            ray.setDirection(randDir);

            ray.color = hit.shapeColor;

            light += color * ray.color.light;
            color *= ray.color;

            if (ray.color.light != 0) break;

        } else break;
    }
    return light;   
}

HitInfo Renderer::calcRayCollision(Ray ray) {
    HitInfo info;

    // max float value
    float closestToRay = 340282346638528859811704183484516925440.0000000000000000;

    for (int i = 0; i < numShapes; i++) {
        HitInfo hit = spheres[i].checkCollision(ray);
        if (hit.didHit) {
            if (hit.distance < closestToRay) {
                info.didHit = hit.didHit;
                info.distance = hit.distance;
                info.hitPoint = hit.hitPoint;
                info.normal = hit.normal;
                info.shapeColor = spheres[i].getColor();
            }
        }

    }

    return info;
}
