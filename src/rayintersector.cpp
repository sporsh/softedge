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

bool RayIntersector::intersect(Plane3& plane,
                               RayIntersection* intersection_result) {
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

    if (intersection_result) {
        intersection_result->t = t;
    }
    return true;
}

bool RayIntersector::intersect(Triangle3& triangle,
                               RayIntersection* intersection_result) {
    real t;
    Vector3 ab = triangle.b - triangle.a;
    Vector3 ac = triangle.c - triangle.a;
    Vector3 qp = normalize(ray.direction * -1);

    Vector3 n = triangle.plane.normal;

    real d = dot(qp, n);
    if (d <= 0 && !backface) {
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

    if (intersection_result) {
        real ood = 1.0 / d;
        t *= ood;
        intersection_result->t = t;
    }
    return true;
}

bool RayIntersector::intersect(Sphere& sphere,
                               RayIntersection* intersection_result) {
    Vector3 dist = sphere.origin - ray.point;
    real B = dot(ray.direction, dist);
    real D = B * B - dot(dist, dist) + sphere.radius * sphere.radius;
    if (D < 0.0 && !backface) {
        // Inside sphere
        return false;
    }
    if (intersection_result) {
        real t = B - sqrt(D);
        intersection_result->t = t;
    }
    return true;
}

} /* namespace softedge */
