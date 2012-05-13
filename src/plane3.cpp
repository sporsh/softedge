#include "plane3.h"
#include "vector3.h"
#include "ray3.h"

namespace softedge {

Plane3::Plane3() {
}

Plane3::Plane3(Point3 point, Vector3 normal) :
        point(point), normal(normal) {
}

bool Plane3::intersect(const Ray3& ray, real* t, Vector3* normal) const {
    real d = dot(this->normal, ray.direction);
    if (d == 0) {
        // Plane and ray is parallel.
        return false;
    }

    *t = dot((point - ray.point), this->normal) / d;
    *normal = this->normal;

//    if (d > 0) {
//        // Plane is pointing away from ray.
//        return false;
//    }

    return true;
}

}  // namespace softedge
