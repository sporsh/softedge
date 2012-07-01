#ifndef PLANE3_H_
#define PLANE3_H_

#include "geometric.h"
#include "vector3.h"
#include "real.h"

namespace softedge {

class Point3;
class Ray3;

class Plane3: public Geometric {
public:
    Plane3();
//    Plane3(Plane3& plane);
    Plane3(Vector3 normal, real d);
    Plane3(Vector3 normal, Point3 p);
    Plane3(Point3 p1, Point3 p2, Point3 p3);

    bool intersect(const Ray3& ray, real* t, Vector3* normal) const;

    Vector3 normal;
    real d;
};

}  // namespace softedge
#endif /* PLANE3_H_ */
