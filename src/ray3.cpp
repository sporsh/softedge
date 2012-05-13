#include "point3.h"
#include "vector3.h"
#include "ray3.h"

namespace softedge {

Ray3::Ray3(Point3 point, Vector3 direction) :
        point(point), direction(direction) {
}

Ray3::operator Point3() {
    return point;
}

Ray3::operator Vector3() {
    return direction;
}

}  // namespace softedge
