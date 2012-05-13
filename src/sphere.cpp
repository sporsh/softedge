#include "point3.h"
#include "vector3.h"
#include "ray3.h"
#include "sphere.h"

#include <math.h>

namespace softedge {

Sphere::Sphere(Point3 origin, real radius) :
        origin(origin), radius(radius) {
}

bool Sphere::intersect(const Ray3& ray, real* t, Vector3* normal) const {
    Vector3 diff(origin - ray.point);
    real d = dot(ray.direction, diff);
    real incidence = d * d - dot(diff, diff) + radius * radius;
    if (incidence > .0) {
        real s = sqrt(incidence);
        if (s < 0) {
            d += s;
        } else {
            d -= s;
        }
        if (d < 0) {
            return false;
        }
        if (t) {
            *t = d;
        }
        if (normal) {
            *normal = normalize(origin - (ray.point + (ray.direction * d)));
        }
        return true;
    } else {
        return false;
    }
}

} // namespace softedge
