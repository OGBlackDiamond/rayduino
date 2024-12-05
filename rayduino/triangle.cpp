#include "triangle.h"
#include "vector.h"

Triangle::Triangle() : Shape() {
    v1 = Vector3(1, 0, 0);
    v2 = Vector3(0, 1, 0);
    v3 = Vector3(0, 0, 1);
}

Triangle::Triangle(Vector3 position, Surface surface) : Shape(position, surface) {
    v1 = Vector3(1, 0, 0);
    v2 = Vector3(0, 1, 0);
    v3 = Vector3(0, 0, 1);
}

Triangle::Triangle(Vector3 position, Surface surface, Vector3 v1, Vector3 v2, Vector3 v3)
    : Shape(position, surface) {
    this->v1 = v1;
    this->v2 = v2;
    this->v3 = v3;
}

Triangle::Triangle(const Triangle& tri) : Shape(tri){
    v1 = tri.v1;
    v2 = tri.v2;
    v3 = tri.v3;
}

HitInfo Triangle::checkCollision(Ray ray) {
    Vector3 E1 = v2 - v1;
    Vector3 E2 = v3 - v1;

    Vector3 N = cross(E1, E2);

    float det = -dot(ray.getDirection(), N);

    float invdet = 1.0/det;

    Vector3 AO = ray.getPosition() - v1;
    Vector3 DAO = cross(AO, ray.getDirection());
    float u = dot(E2, DAO) * invdet;
    float v = -dot(E1, DAO) * invdet;
    float dist = dot(AO, N) * invdet;
    float w = 1 - u - v;


    HitInfo hit;

    hit.didHit = (det >= 1e-6 && dist >= 0.0 && u >= 0.0 && v >= 0.0 && (u+v) <= 1.0);

    if (hit.didHit) {
        hit.distance = dist;
        hit.hitPoint = ray.at(dist);
        hit.normal = N; hit.normal.normalize();
    }

    return hit;
}

