#include "vector.h"
#include "ray.h"


namespace softedge {

Ray::Ray(Vector origin, Vector direction) :
        origin(origin), direction(direction) {
}

}  // namespace softedge
