#ifndef RENDERER_H
#define RENDERER_H

#include "hitInfo.h"
#include "triangle.h"
#include "vector.h"
#include "sphere.h"
#include "display.h"
#include "util.h"

class Renderer {
public:
    Renderer();
    Renderer(int, int);
    ~Renderer();

    Display* display;

    void addSphere(Sphere);
    void addTriangle(Triangle);

    void castRays();
private:

    Sphere* spheres;
    Triangle* triangles;

    const float depth = 2;

    const int maxBounceCount = 1;
    const int raysPerPixel = 1;
    
    Vector3 projectionPlane;

    Vector3 cameraCenter = Vector3(0, 0, 10);

    const float aspectRatio = 3.0 / 2;
    const float viewPortHeight = 2;
    float viewPortWidth;

    Vector3 viewPortU;
    Vector3 viewPortV;

    Vector3 pixelDeltaU;
    Vector3 pixelDeltaV;

    Vector3 viewPortUpperLeft;

    Vector3 pixel00Loc;

    int numSpheres;
    int maxSpheres;

    int numTris;
    int maxTris;

    Color traceRay(Ray, uint32_t&);
    
    HitInfo calcRayCollision(Ray);

};
#endif
