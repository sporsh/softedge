/*
 * vector
 *
 *  Created on: May 1, 2012
 *      Author: geir
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include "real.h"

class Vector {
public:
    Vector(real x, real y, real z);

    Vector& operator =(const Vector&);

    static real dot(const Vector& A, const Vector& B) const;
    static real length(const Vector& v) const;
    static Vector normalize(const Vector& v) const;
    static Vector resize(const Vector& v, const real length) const;

    friend Vector operator +(const Vector&, const Vector&);
    friend Vector operator -(const Vector&, const Vector&);
    friend Vector operator *(const Vector&, const real);

private:
    real x, y, z;
};

Vector::Vector(real x, real y, real z) :
        x(x), y(y), z(z) {
}

Vector& Vector::operator =(const Vector& v) {
    if (&v != this) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

real Vector::dot(const Vector& A, const Vector& B) const {
    return Vector((A.x * B.x) + (A.y * B.y) + (A.z * B.z));
}

real Vector::length() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

Vector Vector::normalize() const {
    return resize(1);
}

Vector Vector::resize(const real length) const {
    return *this * (length / length());
}

Vector operator +(const Vector& lhs, const Vector& rhs) {
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

Vector operator -(const Vector& lhs, const Vector& rhs) {
    return Vector(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
}

Vector operator *(const Vector& v, const real s) const {
    return Vector(v.x * s, v.y * s, v.z * s);
}

Vector operator /(const Vector& v, const real s) const {
    real _s = 1 / s;
    return v * _s;
}

#endif /* VECTOR_H_ */
