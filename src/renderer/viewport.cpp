#include "viewport.h"

namespace softedge {

Viewport::Viewport(Viewport& viewport) {
}

Viewport::Viewport(const unsigned int width, const unsigned int height) :
        width(width), height(height) {
}

Viewport::~Viewport() {
}

unsigned int Viewport::get_width() const {
    return width;
}

unsigned int Viewport::get_height() const {
    return height;
}

} /* namespace softedge */
