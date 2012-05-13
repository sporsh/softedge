#include "renderer.h"

#include "viewport.h"
#include "color.h"
#include "vector3.h"
#include "ray3.h"
#include "geometric3.h"

namespace softedge {

Color normal_shade(const Vector3& normal, const Vector3&) {
    return Color(normalize(Vector3(1, 1, 1) - normal));
}

Color lambert_shade(const Vector3& normal, const Vector3& in) {
    static Color ambient(.1, .1, .15);
    real i = dot(in, normal);
    if (i < 0) {
        return ambient;
    } else {
        return ambient + Color(.7, .7, .99) * i;
    }
}

Color (*shade)(const Vector3&, const Vector3&) = &lambert_shade;

Renderer::Renderer() {
}

void Renderer::render(Viewport& viewport, const Geometric3* geometry,
                      const Vector3* light) const {
    unsigned int width = viewport.get_width();
    unsigned int height = viewport.get_height();
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            Ray3 ray(Point3(x, y, 0), Vector3(0, 0, 1));
            real t;
            Vector3 n;
            if (geometry->intersect(ray, &t, &n)) {
                viewport.set_pixel(
                        x, y, shade(n, normalize(Vector3(x, y, t) - *light)));
            }
        }
    }
}

}  // namespace softedge
