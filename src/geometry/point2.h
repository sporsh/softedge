#ifndef POINT2_H_
#define POINT2_H_

#include "tuple.h"
#include "real.h"

namespace softedge {

class Point2: public Tuple<2, real> {
public:
    real& x;
    real& y;

    Point2();
    Point2(const Tuple<2, real>& tuple);
    Point2(const Point2& point);
    Point2(real x, real y);

    Point2& operator =(const Point2& point);
};

}  // namespace softedge
#endif /* POINT2_H_ */
