#include "scene.h"
#include "raytracerenderer.h"
#include "viewport.h"
#include "color.h"
#include "vector3.h"
#include "geometry/ray3.h"
#include "camera.h"
#include "geometry/geometric.h"
#include "geometry/sphere.h"
#include "geometry/triangle3.h"
#include "geometry/trianglelist.h"

#include <math.h>

namespace softedge {

//static Color normal_shade(const Vector3& normal, const Color&,
//                          const Vector3&) {
//    return Color(normalize(Vector3(1, 1, 1) - normal));
//}

static Color lambert_shade(const Vector3& normal, const Color& color,
                           const Vector3& in) {
//    Color ambient(.1, .1, .2);
    Color ambient(.1, .1, .1);
    real i = dot(in, normal);
    if (i < .0) {
        return ambient;
    }
    return ambient + color * i;
}

static Color (*shade)(const Vector3&, const Color& color,
                      const Vector3&) = &lambert_shade;

RayCaster::RayCaster(const Ray3& ray) :
        ray(ray), intersector(RayIntersector(ray, true)), color(0) {
}

void RayCaster::visit(Plane3& plane) {
    if (intersector.intersect(plane, &i)) {
        if (!color || i.t < t) {
            t = i.t;
            point = ray.point + (ray.direction * t);
            normal = plane.normal;
            color = &plane.color;
        }
    }
}

void RayCaster::visit(Triangle3& triangle) {
    if (intersector.intersect(triangle, &i)) {
        if (!color || i.t < t) {
            t = i.t;
            point = ray.point + (ray.direction * t);
            normal = normalize(triangle.plane.normal);
            color = &triangle.color;
        }
    }
}

void RayCaster::visit(TriangleList& ts) {
    for (unsigned int n = 0; n < ts.vertex_array.size(); ++n) {
        Triangle3 triangle(ts.vertex_array[n],
                           ts.vertex_array[n++],
                           ts.vertex_array[n++]);
        if (intersector.intersect(triangle, &i)) {
            if (!color || i.t < t) {
                t = i.t;
                point = ray.point + (ray.direction * t);
                normal = normalize(triangle.plane.normal);
                color = &ts.color;
            }
        }
    }
}

void RayCaster::visit(Sphere& sphere) {
    if (intersector.intersect(sphere, &i)) {
        if (!color || i.t < t) {
            t = i.t;
            point = ray.point + (ray.direction * t);
            normal = normalize(point - sphere.origin);
            color = &sphere.color;
        }
    }
}

RaytraceRenderer::RaytraceRenderer() {
}

RaytraceRenderer::~RaytraceRenderer() {
}

void RaytraceRenderer::render(Viewport& viewport, const Camera& camera,
                              const Scene& scene) {
    unsigned int width, height;
    viewport.get_metrics(width, height);
    Vector3& light = *(scene.lights[0]);
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            Ray3 ray(Point3(x, y, 0), camera.direction);
            RayCaster caster(ray);
            for (unsigned int i = 0; i < scene.renderables.size(); ++i) {
                Geometric& renderable = *scene.renderables[i];
                renderable.accept(caster);
            }
            if (caster.color) {
                viewport.set_pixel(
                        x,
                        y,
                        shade(caster.normal, *caster.color,
                              normalize(light - caster.point)));
            }
        }
    }
}

} /* namespace softedge */
