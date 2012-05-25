#ifndef SPHERE_H_
#define SPHERE_H_

#include "geometric3.h"
#include "point3.h"
#include "real.h"

namespace softedge {

class Vector3;
class Ray3;

class Sphere: public Geometric3 {
public:
    Sphere(Point3 origin, real radius);

    bool intersect(const Ray3& ray, real* t, Vector3* normal) const;

    Point3 origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
