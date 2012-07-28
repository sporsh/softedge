#ifndef RAYINTERSECTOR_H_
#define RAYINTERSECTOR_H_

#include "vector3.h"
#include "real.h"

namespace softedge {

class Ray3;
class Plane3;
class Triangle3;
class Sphere;

class RayIntersection {
public:
    real t;
};

class RayIntersector {
public:
    RayIntersector(const Ray3& ray, bool backface = false);
    virtual ~RayIntersector();

    bool intersect(const Plane3& plane, RayIntersection* result = 0);
    bool intersect(const Triangle3& triangle, RayIntersection* result = 0);
    bool intersect(const Sphere& sphere, RayIntersection* result = 0);

private:
    const Ray3& ray;
    const Vector3 qp;
    bool backface;
};

} /* namespace softedge */
#endif /* RAYINTERSECTOR_H_ */
