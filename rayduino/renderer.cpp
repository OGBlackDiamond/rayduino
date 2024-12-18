#include "renderer.h"
#include "hitInfo.h"
#include "util.h"

Renderer::Renderer(int length, int width) {
    // initializes the projection plane to be in the center of the width and height
    projectionPlane = Vector3(length, width, depth);
    numSpheres = 0;
    numTris = 0;
    maxSpheres= 1;
    maxTris = 1;
    spheres = new Sphere[maxSpheres];
    triangles = new Triangle[maxTris];

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
    delete[] triangles;
    delete display;
}

void Renderer::addSphere(Sphere shape) {
    if (numSpheres == maxSpheres) {
        maxSpheres *= 2;
        Sphere* tmp = new Sphere[maxSpheres];
        for (int i = 0; i < numSpheres; i++) {
            tmp[i] = spheres[i];
        }
        delete[] spheres;
        spheres = tmp;
    }
    spheres[numSpheres] = Sphere(shape);
    numSpheres++;
}

void Renderer::addTriangle(Triangle tri) {
    if (numTris == maxTris) {
        maxTris *= 2;
        Triangle* tmp = new Triangle[maxTris];
        for (int i = 0; i < numTris; i++) {
            tmp[i] = triangles[i];
        }
        delete[] triangles;
        triangles = tmp;
    }
    triangles[numTris] = Triangle(tri);
    numTris++;
}

void Renderer::castRays() {
    for (int i = 0; i < projectionPlane.y(); i++) {
        for (int j = 0; j < projectionPlane.x(); j++) {

            Vector3 pixelCenter = pixel00Loc + (j * pixelDeltaU) + (i * pixelDeltaV);
            Vector3 rayDirection = pixelCenter - cameraCenter;

            uint randomSeed = (i * projectionPlane.y()) * projectionPlane.x() + (j * projectionPlane.x());

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

            display->setPixel(j, i, totalColor);
        }
    }
}

Color Renderer::traceRay(Ray ray, uint& randomSeed) {
    Color light = Color(0, 0, 0);
    Color color = Color(1, 1, 1);

    for (int i = 0; i <= maxBounceCount; i++) {

        HitInfo hit = calcRayCollision(ray);
        if (hit.didHit) {

            Vector3 randDir = unit_vector(hit.normal + Util::randomDirection(randomSeed));
            
            Vector3 specularReflection = ray.getDirection() - 2 * dot(ray.getDirection(), hit.normal) * hit.normal;

            Surface surface = hit.shapeSurface;

            Vector3 rayDir = lerp(randDir, specularReflection, surface.smoothness);


            ray.setPosition(hit.hitPoint);
            ray.setDirection(rayDir);


            light += color * (surface.emissionColor * surface.emissionStrength);
            color *= surface.surfaceColor;

        } else break;
    }
    return light;   
}

HitInfo Renderer::calcRayCollision(Ray ray) {
    HitInfo info;

    // max float value
    float closestToRay = 340282346638528859811704183484516925440.0000000000000000;

    for (int i = 0; i < numSpheres; i++) {
        HitInfo hit = spheres[i].checkCollision(ray);
        if (hit.didHit) {
            if (hit.distance < closestToRay && hit.distance > 0) {
                info.didHit = hit.didHit;
                info.distance = hit.distance;
                info.hitPoint = hit.hitPoint;
                info.normal = hit.normal;
                info.shapeSurface = spheres[i].getSurface();
                closestToRay = hit.distance;
            }
        }

    }

    for (int i = 0; i < numTris; i++) {
        HitInfo hit = triangles[i].checkCollision(ray);
        if (hit.didHit) {
            if (hit.distance < closestToRay) {
                info.didHit = hit.didHit;
                info.distance = hit.distance;
                info.hitPoint = hit.hitPoint;
                info.normal = hit.normal;
                info.shapeSurface = triangles[i].getSurface();
                closestToRay = hit.distance;
            }
        }

    }

    return info;
}
