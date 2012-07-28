#include "geometric.h"
#include "plane3.h"
#include "ray3.h"
#include "point3.h"
#include "vector3.h"

namespace softedge {

Plane3::Plane3() :
        Geometric() {
}

Plane3::Plane3(const Vector3& normal, real d) :
        Geometric(), normal(normal), d(d) {
}
Plane3::Plane3(const Vector3& normal, const Point3& p) :
        Geometric(), normal(normal), d(length(p)) {
}

Plane3::Plane3(const Point3& a, const Point3& b, const Point3& c) :
        Geometric(), normal((cross(b - a, c - a))), d(dot(normal, a)) {

}

void Plane3::accept(Visitor& visitor) {
    visitor.visit(*this);
}

}  // namespace softedge
