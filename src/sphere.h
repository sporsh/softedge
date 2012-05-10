#ifndef SPHERE_H_
#define SPHERE_H_

#include "real.h"

namespace softedge {

class Vector3;

class Sphere {
public:
    Sphere(Vector3 origin, real radius);

//    friend int intersect(Ray& ray, Sphere& sphere);

public:
    Vector3 origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
