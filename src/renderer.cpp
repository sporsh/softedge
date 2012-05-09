#include "viewport.h"
#include "color.h"
#include "vector.h"
#include "sphere.h"
#include "ray.h"
#include "scene.h"
#include "renderer.h"

#include <math.h>

namespace softedge {

struct Camera {
    Vector origin;
    Vector direction;
};
Camera camera = { Vector(0, 0, 0), Vector(0, 0, 1) };

real intersect(Ray ray, Sphere sphere) {
    Vector c(sphere.origin - ray.origin);
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

Color brdf(Vector in, Vector n) {
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

void Renderer::render(Viewport& viewport, const Scene& scene) const {
    unsigned int width = viewport.get_width();
    unsigned int height = viewport.get_height();
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {

            Ray ray(Vector(x, y, 0), camera.direction);
            real t = intersect(ray, scene.sphere);

            if (t > 0) {
                Vector point_on_sphere = Vector(x, y, t);
                Vector in(point_on_sphere - scene.light);
                Vector n(scene.sphere.origin - point_on_sphere);
                Color color(brdf(normalize(in), normalize(n)));
                viewport.set_pixel(x, y, color);
            } else {
                Color color(0, 0, 0);
                viewport.set_pixel(x, y, color);
            }
        }
    }
}

}  // namespace softedge
