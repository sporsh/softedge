#include "point3.h"

namespace softedge {

Point3::Point3() :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Point3::Point3(const Tuple<3, real>& tuple) :
        Tuple(tuple), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
}

Point3::Point3(const Point3& vector) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    *this = vector;
}

Point3::Point3(real x, real y, real z) :
        Tuple(), x(this->tuple[0]), y(this->tuple[1]), z(this->tuple[2]) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point3& Point3::operator =(const Point3& v) {
    if (&v != this) {
        x = v.x;
        y = v.y;
        z = v.z;
    }
    return *this;
}

}  // namespace softedge
