#ifndef SPHERE_H_
#define SPHERE_H_

#include "point3.h"
#include "real.h"

namespace softedge {

class Vector3;

class Sphere {
public:
    Sphere(Point3 origin, real radius);

    void move(Point3 point);

private:
    Point3 origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
