#ifndef VECTOR_H
#define VECTOR_H

#include "Arduino.h"

struct Vector3{
public:
    double e[3];

    Vector3();
    Vector3(double e0, double e1, double e2);

    double x() const;
    double y() const;
    double z() const;

    Vector3 operator-() const;
    double operator[](int) const;
    double& operator[](int);

    Vector3& operator+=(const Vector3&);

    Vector3& operator*=(double);

    Vector3& operator/=(double);

    double length() const;

    double length_squared() const;

    void normalize();
};

inline Vector3 operator+(const Vector3& u, const Vector3& v) {
    return Vector3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline Vector3 operator-(const Vector3& u, const Vector3& v) {
    return Vector3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline Vector3 operator*(const Vector3& u, const Vector3& v) {
    return Vector3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline Vector3 operator*(double t, const Vector3& v) {
    return Vector3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline Vector3 operator*(const Vector3& v, double t) {
    return t * v;
}

inline Vector3 operator/(const Vector3& v, double t) {
    return (1/t) * v;
}

inline double dot(const Vector3& u, const Vector3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline Vector3 cross(const Vector3& u, const Vector3& v) {
    return Vector3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline Vector3 unit_vector(const Vector3& v) {
    return v / v.length();
}

#endif
