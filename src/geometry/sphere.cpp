#include "sphere.h"
#include "geometric.h"
#include "point3.h"
#include "vector3.h"
#include "ray3.h"

#include <math.h>

namespace softedge {

Sphere::Sphere(Point3 origin, real radius) :
        Geometric(), origin(origin), radius(radius) {
}

void Sphere::accept(Visitor& visitor) {
    visitor.visit(*this);
}

} // namespace softedge
