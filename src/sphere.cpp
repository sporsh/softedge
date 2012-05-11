#include "point3.h"
#include "vector3.h"
#include "sphere.h"

#include <math.h>

namespace softedge {

Sphere::Sphere(Point3 origin, real radius) :
        origin(origin), radius(radius) {
}

void Sphere::move(Point3 point) {
    origin = point;
}


bool Sphere::intersect(const Point3 point, const Vector3 direction, real* t,
                       Vector3* normal) const {
    Vector3 c(origin - point);
    real d = dot(direction, c);
    real incidence = d * d - dot(c, c) + radius * radius;
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
            *normal = normalize(origin - (point + (direction * d)));
        }
        return true;
    } else {
        return false;
    }
}

}// namespace softedge
