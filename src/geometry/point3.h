#ifndef POINT3_H_
#define POINT3_H_

#include "tuple.h"
#include "real.h"

namespace softedge {

class Point3: public Tuple<3, real> {
public:
    real& x;
    real& y;
    real& z;

    Point3();
    Point3(const Tuple<3, real>& tuple);
    Point3(const Point3& point);
    Point3(real x, real y, real z);

    Point3& operator =(const Point3&);
};

}  // namespace softedge
#endif /* POINT3_H_ */
