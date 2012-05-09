#include "vector.h"
#include "ray.h"
#include "sphere.h"

namespace softedge {

Sphere::Sphere(Vector origin, real radius) :
        origin(origin), radius(radius) {

}

//int intersect(Ray& ray, Sphere& sphere) {
//    Vector m = ray.origin - sphere.origin;
//    real b = m.dot(ray.direction);
//}

}  // namespace softedge
