#include "triangle3.h"
#include "vector3.h"
#include "ray3.h"
#include "plane3.h"
#include "point3.h"

#include <vector>

namespace softedge {

//Triangle3::Triangle3() :
//        p1(points[0]), p2(points[1]), p3(points[2]) {
//}

Triangle3::Triangle3(const Point3& A, const Point3& B, const Point3& C) :
        Geometric(), a(A), b(B), c(C), plane(Plane3(A, B, C)) {
}

Triangle3::~Triangle3() {
}

void Triangle3::accept(Visitor& visitor) {
    visitor.visit(*this);
}

} /* namespace softedge */
