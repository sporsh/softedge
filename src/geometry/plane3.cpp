#include "plane3.h"
#include "ray3.h"
#include "point3.h"
#include "vector3.h"

namespace softedge {

Plane3::Plane3() {
}

Plane3::Plane3(Vector3 normal, real d) :
        normal(normal), d(d) {
}
Plane3::Plane3(Vector3 normal, Point3 p) :
        normal(normal), d(length(p)) {
}

Plane3::Plane3(Point3 a, Point3 b, Point3 c) :
        normal(cross(b - a, c - a)), d(dot(normal, a)) {

}

bool Plane3::intersect(const Ray3& ray, real* t, Vector3* normal) const {
    real NdD = dot(this->normal, ray.direction);
    if (NdD == 0) {
        // Plane and ray is parallel.
        return false;
    }

    // Distance from ray origin to plane.
    real distp = dot(this->normal, ray.point) - d;
    if (distp < .0) {
        // Ray starts behind plane.
        return false;
    }

    *t = (d - dot(this->normal, ray.point)) / NdD;
    *normal = this->normal;

//    if (d > 0) {
//        // Plane is pointing away from ray.
//        return false;
//    }

    return true;
}

}  // namespace softedge
