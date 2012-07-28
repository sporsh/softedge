#include "point3.h"
#include "vector3.h"
#include "ray3.h"

namespace softedge {

Ray3::Ray3(Point3 point, Vector3 direction) :
        point(point), direction(direction) {
}


}  // namespace softedge
