#ifndef PLANE3_H_
#define PLANE3_H_

#include "geometric.h"
#include "vector3.h"
#include "point3.h"
#include "real.h"

namespace softedge {

class Ray3;

class Plane3: public Geometric {
public:
    Plane3();
//    Plane3(Plane3& plane);
    Plane3(const Vector3& normal, real d);
    Plane3(const Vector3& normal, const Point3& p);
    Plane3(const Point3& p1, const Point3& p2, const Point3& p3);

    virtual void accept(Visitor& visitor);

    Vector3 normal;
    real d;
};

}  // namespace softedge
#endif /* PLANE3_H_ */
