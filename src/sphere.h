/*
 * sphere.h
 *
 *  Created on: May 1, 2012
 *      Author: geir
 */

#ifndef SPHERE_H_
#define SPHERE_H_

#include "real.h"
#include "vector.h"
#include "ray.h"

class Sphere {
public:
    Sphere(Vector origin, real radius);

private:
    Vector origin;
    real radius;
};

Sphere::Sphere(Vector origin, real radius) :
        origin(origin), radius(radius) {

}

int intersect(Ray& ray, Sphere& sphere) {
    real m = ray.origin - origin;
    real b = m.dot(ray.direction);

}

#endif /* SPHERE_H_ */
