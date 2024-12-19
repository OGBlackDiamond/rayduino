#include "renderer.h"
#include "sphere.h"
#include "surface.h"

void setup() {
    Renderer renderer(96, 64);

    Sphere sphere1(
        Vector3(0.5 + 0.5, 0, -2.0),
        Surface(
            Color(1, 0.2, 0.2),
            Color(0, 0, 0),
            0, 
            0
        ),
        0.5
    );
    Sphere sphere2(
        Vector3(-0.5 + 0.5, 0, -2.0),
        Surface(
            Color(0.2, 1, 0.2),
            Color(0, 0, 0),
            0,
            0
        ),
        0.5
    );
    Sphere sphere3(
        Vector3(-1.5 + 0.5, 0.5, -1.0),
        Surface(0.2, 1, 0.2),
        1
    );
    Sphere sphere4(
        Vector3(1.5 + 0.5, 0.5, -1.0),
        Surface(
            Color(1, 1, 1),
            Color(0, 0, 0),
            0,
            0
        ),
        1
    );
    Sphere sphere5(
        Vector3(0 + 0.5, 0, -1.00),
        Surface(
            Color(1, 1, 1),
            Color(),
            0,
            1
        ),
        .25
    );
    Sphere sphere6(
        Vector3(0 + 0.5, 0, -1.50),
        Surface(
            Color(0.2, 0.8, 0.8),
            Color(),
            0,
            0
        ),
        0.125
    );
    Sphere ground(
        Vector3(0 + 0.5, -100.5, 1.0),
        Surface(1.0, 1, 1.0),
        100
    );
    Sphere sun(
        Vector3(55, 35, -45.0),
        Surface(
            Color(0, 0, 0),
            Color(1, 1, 1),
            2,
            0
        ),
        65
    );

    renderer.addSphere(sphere1);
    renderer.addSphere(sphere2);
    renderer.addSphere(sphere3);
    renderer.addSphere(sphere4);
    renderer.addSphere(sphere5);
    renderer.addSphere(sphere6);
    renderer.addSphere(ground);
    //renderer.addSphere(sun);
    Sphere tst1(
        Vector3(0.5, 0, -0.10),
        Surface(
            Color(0, 0, 0),
            Color(1, 0, 0),
            2,
            0
        ),
        .1
    );

    Sphere tst2(
        Vector3(0, 1, -0.10),
        Surface(
            Color(0, 0, 0),
            Color(0, 1, 0),
            2,
            0
        ),
        .1
    );

    Sphere tst3(
        Vector3(-0.5, 0, -0.10),
        Surface(
            Color(0, 0, 0),
            Color(0, 0, 1),
            2,
            0
        ),
        .1
    );


    Triangle tri = Triangle(
        Vector3(-0.5, 0, -0.10),
        Surface(
            Color(0, 0, 0),
            Color(1, 1, 1),
            2,
            0
        ),
        Vector3(2 + 0.5, 3, -2),
        Vector3(-2 + 0.5, 3, -0),
        Vector3(-2 + 0.5, 3, -2)
    );

    Triangle tri2 = Triangle(
        Vector3(0, 2, -1),
        Surface(
            Color(0, 0, 0),
            Color(1, 1, 1),
            2,
            0
        ),
        Vector3(2 + 0.5, 3, -2),
        Vector3(2 + 0.5, 3, 0),
        Vector3(-2 + 0.5, 3, -0)
    );

    Triangle tri3 = Triangle(
        Vector3(0, 0, 0.0),
        Surface(
            Color(0, 0, 0),
            Color(1, 1, 1),
            1,
            0
        ),
        tst1.getPosition(),
        tst2.getPosition(),
        tst3.getPosition()
    );

    renderer.addTriangle(tri);
    renderer.addTriangle(tri2);
    //renderer.addTriangle(tri3);

    //renderer.addSphere(tst1);
    //renderer.addSphere(tst2);
    //renderer.addSphere(tst3);

    renderer.castRays();
}

void loop() {}