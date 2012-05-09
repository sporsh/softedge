#include "viewport.h"
#include "color.h"
#include "renderer.h"

namespace softedge {

Renderer::Renderer() {
}

void Renderer::render(Viewport& viewport) const {
    unsigned int width = viewport.get_width();
    unsigned int height = viewport.get_height();
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            Color color(1.0 * x / width, 1.0 * y / height,
                        1.0 - 1.0 * x / width);
            viewport.set_pixel(x, y, color);
        }
    }
}

}  // namespace softedge
