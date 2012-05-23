#include "raytracerenderer.h"
#include "viewport.h"
#include "color.h"
#include "vector3.h"
#include "geometry/ray3.h"
#include "camera.h"
#include "geometry/geometric3.h"

namespace softedge {

static Color normal_shade(const Vector3& normal, const Vector3&) {
    return Color(normalize(Vector3(1, 1, 1) - normal));
}

static Color lambert_shade(const Vector3& normal, const Vector3& in) {
    static Color ambient(.1, .1, .15);
    real i = dot(in, normal);
    if (i < 0) {
        return ambient;
    } else {
        return ambient + Color(.7, .7, .99) * i;
    }
}

static Color (*shade)(const Vector3&, const Vector3&) = &lambert_shade;

RaytraceRenderer::RaytraceRenderer() {
    // TODO Auto-generated constructor stub

}

RaytraceRenderer::~RaytraceRenderer() {
    // TODO Auto-generated destructor stub
}

void RaytraceRenderer::render(Viewport& viewport, const Camera& camera,
                      const Geometric3* geometry, const Vector3* light) const {
    unsigned int width, height;
    viewport.get_metrics(width, height);
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            Ray3 ray(Point3(x, y, -1000), camera.direction);
            real t;
            Vector3 n;
            if (geometry->intersect(ray, &t, &n)) {
                Point3 p = ray.point + (ray.direction * t);
                viewport.set_pixel(x, y, shade(n, normalize(*light - p)));
            }
        }
    }
}

} /* namespace softedge */
