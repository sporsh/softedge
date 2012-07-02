#include "rayintersector.h"

#include "geometry/ray3.h"
#include "geometry/plane3.h"
#include "geometry/triangle3.h"
#include "geometry/sphere.h"

#include <math.h>

namespace softedge {

RayIntersector::RayIntersector(const Ray3& ray, bool backface) :
        ray(ray), backface(backface) {
}

RayIntersector::~RayIntersector() {
}

bool RayIntersector::intersect(const Plane3& plane, RayIntersection* result) {
    real NdD = dot(plane.normal, ray.direction);
    if (NdD == 0) {
        // Plane and ray is parallel.
        return false;
    }

    // Distance from ray origin to plane.
    real distp = dot(plane.normal, ray.point) - plane.d;
    if (distp < 0.0) {
        // Ray starts behind plane.
        return false;
    }

    real t = (plane.d - dot(plane.normal, ray.point)) / NdD;

    if (plane.d > 0 && !backface) {
        // Plane is pointing away from ray.
        return false;
    }

    if (result) {
        result->t = t;
    }
    return true;
}

bool RayIntersector::intersect(const Triangle3& triangle, RayIntersection* result) {
    real t;
    Vector3 ab = triangle.b - triangle.a;
    Vector3 ac = triangle.c - triangle.a;
    Vector3 qp = ray.direction * -1;

    Vector3 n = triangle.plane.normal;

    real d = dot(qp, n);
    if (d <= 0.0 && !backface) {
        //Plane and ray is parallel or points away.
        return false;
    }

    Vector3 ap = ray.point - triangle.a;
    t = dot(ap, n);
    if (t < 0.0) {
        return false;
    }

    Vector3 e = cross(qp, ap);
    real v = dot(ac, e);
    if (v < 0.0 || v > d) {
        return false;
    }
    real w = -dot(ab, e);
    if (w < 0.0 || v + w > d) {
        return false;
    }

    if (result) {
        real ood = 1.0 / d;
        t *= ood;
        result->t = t;
    }
    return true;
}

bool RayIntersector::intersect(const Sphere& sphere, RayIntersection* result) {
    Vector3 m = ray.point - sphere.origin;
    real c = dot(m, m) - sphere.radius * sphere.radius;

    // Defently a hit, but we don't care about where
    if (!result && c <= 0.0)
        return true;

    real b = dot(m, ray.direction);
    // Ray origin outside sphere, and pointing away
    if (b > 0.0)
        return false;

    real discr = b * b - c;
    // Ray missing sphere
    if (discr < 0.0)
        return false;

    if (result) {
        real t = -b - sqrt(discr);
        // Ray started inside sphere
        if (t < 0.0) {
            t = -b + sqrt(discr);
        }
        result->t = t;
    }
    return true;
}

} /* namespace softedge */
