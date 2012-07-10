#include "x11renderer.h"
#include "x11viewportwindow.h"

#include "scene.h"
#include "camera.h"
#include "geometry/geometric.h"
#include "geometry/triangle3.h"
#include "geometry/sphere.h"
#include "vector3.h"
#include "color.h"

namespace softedge {

X11Rasterizer::X11Rasterizer() {
}

X11Rasterizer::~X11Rasterizer() {
}

void X11Rasterizer::visit(Plane3& plane) {
}

void X11Rasterizer::visit(Sphere& sphere) {
    set_color(sphere.color);
    XFillArc(viewport->display, viewport->window, viewport->gc,
             sphere.origin.x - sphere.radius, sphere.origin.y - sphere.radius,
             sphere.radius * 2, sphere.radius * 2, 0, 360 * 64);
}

void X11Rasterizer::visit(Triangle3& triangle) {
    set_color(triangle.color);

    XPoint points[] = { { triangle.a.x, triangle.a.y }, { triangle.b.x,
            triangle.b.y }, { triangle.c.x, triangle.c.y } };
    XFillPolygon(viewport->display, viewport->window, viewport->gc, points, 3,
                 Convex, CoordModeOrigin);
}

void X11Rasterizer::visit(TriangleList& ts) {
}

void X11Rasterizer::set_color(Color& color) {
    XSetForeground(viewport->display, viewport->gc, color.get_color(ARGB));
}

X11Renderer::X11Renderer() :
        rasterizer(X11Rasterizer()) {
}

X11Renderer::~X11Renderer() {
}

void X11Renderer::render(X11ViewportWindow& viewport, const Camera& camera,
                         const Scene& scene) {
    rasterizer.viewport = &viewport;
    rasterizer.light = *scene.lights[0];
    for (unsigned int i = 0; i < scene.renderables.size(); ++i) {
        Geometric& renderable = *scene.renderables[i];
        renderable.accept(rasterizer);
    }
}

} // namespace softedge
