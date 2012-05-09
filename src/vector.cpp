#include "vector.h"
#include <math.h>

namespace softedge {

Vector::Vector() :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Vector::Vector(const Tuple<3, real>& tuple) :
        Tuple(tuple), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Vector::Vector(const Vector& vector) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    *this = vector;
}

Vector::Vector(real x, real y, real z) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector& Vector::operator =(const Vector& v) {
    if (&v != this) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

real dot(const Vector& A, const Vector& B) {
    return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
}

real length(const Vector& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vector normalize(const Vector& v) {
    return resize(v, 1);
}

Vector resize(const Vector& v, const real s) {
    return v * (s / length(v));
}

}  // namespace softedge
