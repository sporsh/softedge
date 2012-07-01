#include "sphere.h"
#include "geometric.h"
#include "point3.h"
#include "vector3.h"
#include "ray3.h"

#include <math.h>

namespace softedge {

Sphere::Sphere(Point3 origin, real radius) :
        Geometric(), origin(origin), radius(radius) {
}

bool Sphere::intersect(const Ray3& ray, real* t, Vector3* normal) const {
    Vector3 dist = origin - ray.point;
    real B = dot(ray.direction, dist);
    real D = B * B - dot(dist, dist) + radius * radius;
    if (D < 0.0) {
        return false;
    }
    *t = B - sqrt(D);
    *normal = normalize((ray.point + (ray.direction * *t)) - origin);
    return true;
}

//bool Sphere::intersect(const Ray3& ray, real* t, Vector3* normal) const {
//    Vector3 m(ray.point - origin);
//    real b = dot(m, ray.direction);
//    real c = dot(m, m) - radius * radius;
//    if (c > .0 && b > .0) {
//        return false;
//    }
//    real discr = b * b - c;
//    if (discr < .0) {
//        return false;
//    }
//    if (t) {
//        real s = sqrt(discr);
//        *t = (s < 0) ? -b - s : -b + s;
//    }
//    if (normal) {
//        *normal = normalize((ray.point + (ray.direction * *t)) - origin);
//    }
//    return true;
//}

}// namespace softedge
