#ifndef TRIANGLE3_H_
#define TRIANGLE3_H_

#include "geometric.h"
#include "plane3.h"
#include "point3.h"

namespace softedge {


class Triangle3: public Geometric {
public:
    const Point3& a;
    const Point3& b;
    const Point3& c;

    Triangle3(const Point3& p1, const Point3& p2, const Point3& p3);
    virtual ~Triangle3();

    virtual void accept(Visitor& visitor);

//private:
    Triangle3();
    Plane3 plane;
};

} /* namespace softedge */
#endif /* TRIANGLE3_H_ */
