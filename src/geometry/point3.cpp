#include "point3.h"

namespace softedge {

Point3::Point3() :
        Tuple(), x(tuple[0]), y(tuple[1]), z(tuple[2]) {
}

Point3::Point3(const Tuple<3, real>& t) :
        Tuple(t), x(tuple[0]), y(tuple[1]), z(tuple[2]) {
}

Point3::Point3(const Point3& point) :
        Tuple(), x(tuple[0]), y(tuple[1]), z(tuple[2]) {
    *this = point;
}

Point3::Point3(real x, real y, real z) :
        Tuple(), x(tuple[0]), y(tuple[1]), z(tuple[2]) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point3& Point3::operator =(const Point3& point) {
    if (&point != this) {
        x = point.x;
        y = point.y;
        z = point.z;
    }
    return *this;
}

}  // namespace softedge
