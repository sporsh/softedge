#include "x11renderer.h"
#include "x11viewportwindow.h"

#include "camera.h"
#include "geometry/geometric3.h"
#include "geometry/triangle3.h"
#include "geometry/sphere.h"
#include "vector3.h"
#include "color.h"

namespace softedge {

static unsigned long int lambert_shade(const Vector3& normal,
                                       const Vector3& in) {
    union {
        unsigned long int color;
        struct {
            unsigned char a, r, g, b;
//            unsigned char r, g, b, a;
        } comp;
    };

    float ambient = .1;
    real i = dot(in, normal);
    if (i < .0) {
        comp.r = comp.g = comp.b = 0xff * ambient;
    } else {
        comp.r = comp.g = comp.b = 0xff * i;
    }
    return color;
}

X11Renderer::X11Renderer() {
}

X11Renderer::~X11Renderer() {
}

void X11Renderer::render(X11ViewportWindow& viewport, const Camera& camera,
                         const Geometric3* geometry, const Vector3& light) {
    this->viewport = &viewport;
}

void X11Renderer::render(const Geometric3& renderable, const Vector3& light) {
    switch (renderable.type) {
    case TRIANGLE:
        draw(static_cast<const Triangle3&>(renderable), light);
        break;
    case SPHERE:
        draw(static_cast<const Sphere&>(renderable));
        break;
    default:
        break;
    }
}

void X11Renderer::draw(const Triangle3& triangle, const Vector3& light) {
    XPoint points[] = { { triangle.a.x, triangle.a.y }, { triangle.b.x,
            triangle.b.y }, { triangle.c.x, triangle.c.y } };

    unsigned long c = lambert_shade(triangle.plane.normal, light - triangle.a);

    XSetForeground(viewport->display, viewport->gc, c);
    XFillPolygon(viewport->display, viewport->window, viewport->gc, points, 3,
                 Convex, CoordModeOrigin);
}

void X11Renderer::draw(const Sphere& sphere) {
    XSetForeground(viewport->display, viewport->gc, 0xff0000ff);
    XFillArc(viewport->display, viewport->window, viewport->gc,
             sphere.origin.x - sphere.radius, sphere.origin.y - sphere.radius,
             sphere.radius * 2, sphere.radius * 2, 0, 360 * 64);
}

}  // namespace softedge
