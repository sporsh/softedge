#include "color.h"
#include "viewport.h"

namespace softedge {

Viewport::Viewport(const unsigned int width, const unsigned int height) :
        width(width), height(height) {
    data = new unsigned int[width * height];
}

Viewport::~Viewport() {
    delete[] data;
}

unsigned int Viewport::get_width() const {
    return width;
}

unsigned int Viewport::get_height() const {
    return height;
}

void Viewport::set_pixel(unsigned int x, unsigned int y,
                         const Color& color) const {
    unsigned int i = (y * width + x);
    data[i] = color;
}

} /* namespace softedge */
