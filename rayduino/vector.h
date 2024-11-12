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

    inline friend Vector3 operator+(const Vector3&, const Vector3&);
    inline friend Vector3 operator-(const Vector3&, const Vector3&);
    inline friend Vector3 operator*(const Vector3&, const Vector3&);
    inline friend Vector3 operator*(const Vector3&, double);
    inline friend Vector3 operator*(double, const Vector3&);
    inline friend Vector3 operator/(const Vector3&, double);

    inline friend double dot(const Vector3&, const Vector3&);
    inline friend Vector3 cross(const Vector3&, const Vector3&);

    Vector3& operator+=(const Vector3&);

    Vector3& operator*=(double);

    Vector3& operator/=(double);

    double length() const;

    double length_squared() const;

    void normalize();
};

#endif
