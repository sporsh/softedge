#ifndef PLANE3_H_
#define PLANE3_H_

#include "geometric3.h"
#include "vector3.h"
#include "point3.h"

namespace softedge {

class Ray3;

class Plane3: public Geometric3 {
public:
    Plane3();
//    Plane3(Plane3& plane);
    Plane3(Point3 point, Vector3 normal);
//    Plane3(Point3 p1, Point3 p2, Point3 p3);

    bool intersect(const Ray3& ray, real* t, Vector3* normal) const;

    Point3 point;
    Vector3 normal;
};

}  // namespace softedge
#endif /* PLANE3_H_ */
