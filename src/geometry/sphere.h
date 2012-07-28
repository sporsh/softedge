#ifndef SPHERE_H_
#define SPHERE_H_

#include "geometric.h"
#include "point3.h"
#include "real.h"

namespace softedge {

class Ray3;

class Sphere: public Geometric {
public:
    Sphere(Point3 origin, real radius);

    virtual void accept(Visitor& visitor);

    Point3 origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
