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

