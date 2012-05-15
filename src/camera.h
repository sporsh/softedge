#ifndef CAMERA_H_
#define CAMERA_H_

#include "vector3.h"
#include "point3.h"

namespace softedge {

class Camera {
public:
    Camera() {
    }
    Camera(const Point3& origin, const Vector3& direction) :
            origin(origin), direction(direction) {
    }

    Point3 origin;
    Vector3 direction;
private:

};

}  // namespace softedge
#endif /* CAMERA_H_ */
