#include "tuple3.h"

namespace softedge {

Tuple3::Tuple3() :
        x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Tuple3::Tuple3(const Tuple3& tuple) :
        x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    *this = tuple;
}

Tuple3::Tuple3(const real array[3]) :
        x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    tuple[0] = array[0];
    tuple[1] = array[1];
    tuple[2] = array[2];
}

Tuple3::Tuple3(real x, real y, real z) :
        x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    tuple[0] = x;
    tuple[1] = y;
    tuple[2] = z;
}

Tuple3& Tuple3::operator =(const Tuple3& tuple) {
    if (&tuple != this) {
        this->tuple[0] = tuple.tuple[0];
        this->tuple[1] = tuple.tuple[1];
        this->tuple[2] = tuple.tuple[2];
    }
    return *this;
}

Tuple3 Tuple3::operator -(const Tuple3& t) const {
    return Tuple3(tuple[0] - t.tuple[0], tuple[1] - t.tuple[1],
                  tuple[2] - t.tuple[2]);
}

Tuple3 Tuple3::operator +(const Tuple3& t) const {
    return Tuple3(tuple[0] + t.tuple[0], tuple[1] + t.tuple[1],
                  tuple[2] + t.tuple[2]);
}

Tuple3 Tuple3::operator *(const Tuple3& t) const {
    return Tuple3(tuple[0] * t.tuple[0], tuple[1] * t.tuple[1],
                  tuple[2] * t.tuple[2]);
}

Tuple3 Tuple3::operator /(const Tuple3& t) const {
    return Tuple3(tuple[0] / t.tuple[0], tuple[1] / t.tuple[1],
                  tuple[2] / t.tuple[2]);
}

Tuple3& Tuple3::operator -=(const Tuple3& t) {
    tuple[0] -= t.tuple[0];
    tuple[1] -= t.tuple[1];
    tuple[2] -= t.tuple[2];
    return *this;
}

Tuple3& Tuple3::operator +=(const Tuple3& t) {
    tuple[0] += t.tuple[0];
    tuple[1] += t.tuple[1];
    tuple[2] += t.tuple[2];
    return *this;
}

Tuple3& Tuple3::operator *=(const Tuple3& t) {
    tuple[0] *= t.tuple[0];
    tuple[1] *= t.tuple[1];
    tuple[2] *= t.tuple[2];
    return *this;
}

Tuple3& Tuple3::operator /=(const Tuple3& t) {
    tuple[0] /= t.tuple[0];
    tuple[1] /= t.tuple[1];
    tuple[2] /= t.tuple[2];
    return *this;
}

Tuple3 Tuple3::operator *(real s) const {
    return Tuple3(tuple[0] * s, tuple[1] * s, tuple[2] * s);
}

Tuple3 Tuple3::operator /(real s) const {
    return Tuple3(tuple[0] / s, tuple[1] / s, tuple[2] / s);
}

Tuple3& Tuple3::operator *=(real s) {
    tuple[0] *= s;
    tuple[1] *= s;
    tuple[2] *= s;
    return *this;
}

Tuple3& Tuple3::operator /=(real s) {
    tuple[0] /= s;
    tuple[1] /= s;
    tuple[2] /= s;
    return *this;
}

} /* namespace softedge */
