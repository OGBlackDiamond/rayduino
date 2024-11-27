#include "renderer.h"
#include "sphere.h"

int main() {
    Renderer renderer(96, 64);
    Sphere sphere(1.0, 0, -13.0, 1, 0.2, 0.2, 5);
    Sphere ground(1, -95, -13, 0.2, 1, 0.2, 100);
    Sphere sun(
        Vector3(45, 45, 45.0),
        Color(0, 0, 0, 500),
        75 
    );
    renderer.addSphere(sphere);
    renderer.addSphere(ground);
    renderer.addSphere(sun);
    renderer.castRays();

    return 0;
}
