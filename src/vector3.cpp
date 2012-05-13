#include "vector3.h"
#include <math.h>

namespace softedge {

Vector3::Vector3() :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Vector3::Vector3(const Tuple<3, real>& tuple) :
        Tuple(tuple), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Vector3::Vector3(const Vector3& vector) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    *this = vector;
}

Vector3::Vector3(real x, real y, real z) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Vector3& Vector3::operator =(const Vector3& v) {
    if (&v != this) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

real dot(const Vector3& A, const Vector3& B) {
    return (A.x * B.x) + (A.y * B.y) + (A.z * B.z);
}

Vector3 cross(const Vector3& A, const Vector3& B) {
    return Vector3(A.y * B.z - A.z * B.y,
                   A.z * B.x - A.x * B.z,
                   A.x * B.y - A.y * B.x);
}

real length(const Vector3& v) {
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

Vector3 normalize(const Vector3& v) {
    return resize(v, 1);
}

Vector3 resize(const Vector3& v, const real s) {
    return v * (s / length(v));
}

}  // namespace softedge
