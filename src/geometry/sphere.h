#ifndef SPHERE_H_
#define SPHERE_H_

#include "geometric.h"
#include "point3.h"
#include "real.h"

namespace softedge {

class Vector3;
class Ray3;

class Sphere: public Geometric {
public:
    Sphere(Point3 origin, real radius);

    bool intersect(const Ray3& ray, real* t, Vector3* normal) const;
    virtual void accept(Visitor& visitor);

    Point3 origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
