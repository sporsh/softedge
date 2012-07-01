#ifndef RAY3_H_
#define RAY3_H_

#include "point3.h"
#include "vector3.h"

namespace softedge {

class Point3;
class Vector3;

class Ray3 {
public:
    Ray3();
    Ray3(Point3 point, Vector3 direction);
    Ray3(Point3 p1, Point3 p2);

    operator Point3();
    operator Vector3();

//private:
    Point3 point;
    Vector3 direction;
};

}  // namespace softedge
#endif /* RAY3_H_ */
