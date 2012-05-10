#include "vector3.h"
#include "ray.h"
#include "sphere.h"

namespace softedge {

Sphere::Sphere(Vector3 origin, real radius) :
        origin(origin), radius(radius) {

}

//int intersect(Ray& ray, Sphere& sphere) {
//    Vector m = ray.origin - sphere.origin;
//    real b = m.dot(ray.direction);
//}

}  // namespace softedge
