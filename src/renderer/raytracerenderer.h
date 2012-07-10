/*
 * raytracerenderer.h
 *
 *  Created on: May 18, 2012
 *      Author: geir
 */

#ifndef RAYTRACERENDERER_H_
#define RAYTRACERENDERER_H_

#include "renderer.h"

#include "rayintersector.h"

#include "geometry/point3.h"
#include "vector3.h"
#include "geometry/ray3.h"
#include "geometry/geometric.h"

#include <vector>

namespace softedge {

class Viewport;
class Camera;

class Sphere;
class Triangle3;
class Plane3;

class RayCaster: public Visitor {
public:
    RayCaster(const Ray3& ray);

    virtual void visit(Plane3& plane);
    virtual void visit(Sphere& sphere);
    virtual void visit(Triangle3& triangle);
    virtual void visit(TriangleList& ts);

    real t;
    Point3 point;
    Vector3 normal;
    Color* color;
private:
    const Ray3& ray;
    RayIntersector intersector;
    RayIntersection i;
};

class RaytraceRenderer: public Renderer {
public:
    RaytraceRenderer();
    virtual ~RaytraceRenderer();

    void render(Viewport& viewport, const Camera& camera, const Scene& scene);
    void trace(Ray3& ray, const Scene& scene);
};

} /* namespace softedge */
#endif /* RAYTRACERENDERER_H_ */
