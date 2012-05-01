/*
 * ray.h
 *
 *  Created on: May 1, 2012
 *      Author: geir
 */

#ifndef RAY_H_
#define RAY_H_

#include "vector.h"

class Ray {
public:
    Ray(Vector origin, Vector direction);

private:
    Vector origin;
    Vector direction;
};

Ray::Ray(Vector origin, Vector direction) :
        origin(origin), direction(direction) {
}

#endif /* RAY_H_ */
