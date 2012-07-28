#ifndef RAY3_H_
#define RAY3_H_

#include "point3.h"
#include "vector3.h"

namespace softedge {


class Ray3 {
public:
    Ray3();
    Ray3(Point3 point, Vector3 direction);


//private:
    Point3 point;
    Vector3 direction;
};

}  // namespace softedge
#endif /* RAY3_H_ */
