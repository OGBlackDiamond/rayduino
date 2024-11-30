#include "vector.h"

Vector3::Vector3() : e{0,0,0} {}
Vector3::Vector3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double Vector3::x() const { return e[0]; }
double Vector3::y() const { return e[1]; }
double Vector3::z() const { return e[2]; }

Vector3 Vector3::operator-() const { return Vector3(-e[0], -e[1], -e[2]); }
double Vector3::operator[](int i) const { return e[i]; }
double& Vector3::operator[](int i) { return e[i]; }

Vector3& Vector3::operator+=(const Vector3& v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

Vector3& Vector3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

Vector3& Vector3::operator/=(double t) {
    return *this *= 1/t;
}

double Vector3::length() const {
    return sqrt(length_squared());
}

double Vector3::length_squared() const {
    return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
}

void Vector3::normalize() {
    double len = length();
    if (len == 0) return;
    e[0] /= len;
    e[1] /= len;
    e[2] /= len;
}

