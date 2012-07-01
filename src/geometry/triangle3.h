#ifndef TRIANGLE3_H_
#define TRIANGLE3_H_

#include "geometric.h"
#include "plane3.h"
#include "point3.h"

namespace softedge {

class Vector3;

class Triangle3: public Geometric {
public:
    Point3 a;
    Point3 b;
    Point3 c;

    Triangle3(const Point3& p1, const Point3& p2, const Point3& p3);
    virtual ~Triangle3();

    virtual bool intersect(const Ray3& ray, real* t, Vector3* normal) const;

    virtual void accept(Visitor& visitor);

//private:
    Triangle3();
    Plane3 plane;
};

} /* namespace softedge */
#endif /* TRIANGLE3_H_ */
