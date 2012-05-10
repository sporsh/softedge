#include "viewport.h"
#include "color.h"
#include "vector3.h"
#include "sphere.h"
#include "ray.h"
#include "scene.h"
#include "renderer.h"

#include <math.h>

namespace softedge {

struct Camera {
    Vector3 origin;
    Vector3 direction;
};
Camera camera = { Vector3(0, 0, 0), Vector3(0, 0, 1) };

real intersect(Ray ray, Sphere sphere) {
    Vector3 c(sphere.origin - ray.origin);
    real d = dot(ray.direction, c);
    real incidence = d * d - dot(c, c) + sphere.radius * sphere.radius;
    if (incidence > .0) {
        real s = sqrt(incidence);
        if (s < 0) {
            return d + s;
        } else {
            return d - s;
        }
    } else {
        return -1;
    }
}

Color lambert_brdf(Vector3 in, Vector3 n) {
    real i = dot(in, n);
    Color color(.7, .7, .99);
    if (i < 0) {
        return Color(0, 0, 0);
    } else {
        return color * i;
    }
}

Renderer::Renderer() {
}

Color ambient(.1, .1, .1);

void Renderer::render(Viewport& viewport, const Scene& scene) const {
    unsigned int width = viewport.get_width();
    unsigned int height = viewport.get_height();
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {

            Ray ray(Vector3(x, y, 0), camera.direction);
            real t = intersect(ray, scene.sphere);

            if (t > 0) {
                Vector3 point_on_sphere = Vector3(x, y, t);
                Vector3 in(point_on_sphere - scene.light);
                Vector3 n(point_on_sphere - scene.sphere.origin);
                Color lambert(lambert_brdf(normalize(in), normalize(n)));
                Color color(lambert + ambient);
                viewport.set_pixel(x, y, color);
            } else {
                viewport.set_pixel(x, y, ambient / 2.0);
            }
        }
    }
}

}  // namespace softedge
