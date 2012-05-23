#include "point2.h"

namespace softedge {

Point2::Point2() :
        Tuple(), x(tuple[0]), y(tuple[1]) {
}

Point2::Point2(const Tuple<2, real>& t) :
        Tuple(t), x(tuple[0]), y(tuple[1]) {
}

Point2::Point2(const Point2& point) :
        Tuple(), x(tuple[0]), y(tuple[1]) {
    *this = point;
}

Point2::Point2(real x, real y) :
        Tuple(), x(tuple[0]), y(tuple[1]) {
    this->x = x;
    this->y = y;
}

Point2& Point2::operator =(const Point2& point) {
    if (&point != this) {
        x = point.x;
        y = point.y;
    }
    return *this;
}

}  // namespace softedge
