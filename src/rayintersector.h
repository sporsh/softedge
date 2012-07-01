#ifndef RAYINTERSECTOR_H_
#define RAYINTERSECTOR_H_

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

    bool intersect(Plane3& plane, RayIntersection* intersection_result = 0);
    bool intersect(Triangle3& triangle, RayIntersection* intersection_result = 0);
    bool intersect(Sphere& sphere, RayIntersection* intersection_result = 0);

private:
    const Ray3& ray;
    bool backface;
};

} /* namespace softedge */
#endif /* RAYINTERSECTOR_H_ */
