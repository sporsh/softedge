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

bool Triangle3::intersect(const Ray3& ray, real* t, Vector3* normal) const {
    Vector3 ab = b - a;
    Vector3 ac = c - a;
    Vector3 qp = normalize(ray.direction * -1);

    Vector3 n = plane.normal;

    real d = dot(qp, n);
    if (d <= 0) {
        //Plane and ray is parallel or points away.
//        return false;
    }

    Vector3 ap = ray.point - a;
    *t = dot(ap, n);
    if (*t < .0) {
        return false;
    }

    Vector3 e = cross(qp, ap);
    real v = dot(ac, e);
    if (v < .0 || v > d) {
        return false;
    }
    real w = -dot(ab, e);
    if (w < .0 || v + w > d) {
        return false;
    }

    real ood = 1.0 / d;
    *t *= ood;
//    *normal = plane.normal;
    *normal = normalize(n);
    return true;

//// Distance from ray origin to plane.
//    real distp = dot(plane.normal, ray.point) - plane.d;
//    if (distp < .0) {
//        // Ray starts behind plane.
////        return false;
//    }
//    real distq = dot(plane.normal, ray.point + ray.direction * 100) - plane.d;
//    real denom = distp - distq;
//    if (t) {
//        *t = distp / denom;
//        Point3 s(ray.point + (ray.direction * *t));
//        real u = dot(s, edge_plane_bc.normal) - edge_plane_bc.d;
//        if (u < .0 || u > 1.0) {
//            return false;
//        }
//        real v = dot(s, edge_plane_ca.normal) - edge_plane_ca.d;
//        if (v < .0) {
//            return false;
//        }
//        real w = 1.0 - u - v;
//        if (w < .0) {
//            return false;
//        }
//    }
//    *normal = plane.normal;
//    return true;
}

} /* namespace softedge */
