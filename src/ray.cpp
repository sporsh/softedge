#include "vector3.h"
#include "ray.h"


namespace softedge {

Ray::Ray(Vector3 origin, Vector3 direction) :
        origin(origin), direction(direction) {
}

}  // namespace softedge
