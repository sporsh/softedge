#ifndef SPHERE_H_
#define SPHERE_H_

#include "real.h"

namespace softedge {

class Vector;

class Sphere {
public:
    Sphere(Vector origin, real radius);

//    friend int intersect(Ray& ray, Sphere& sphere);

private:
    Vector origin;
    real radius;
};

}  // namespace softedge
#endif /* SPHERE_H_ */
