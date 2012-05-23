#include "viewport.h"

namespace softedge {

Viewport::Viewport(Viewport& viewport) {
}

Viewport::Viewport(const unsigned int width, const unsigned int height) :
        width(width), height(height) {
}

Viewport::~Viewport() {
}

void Viewport::get_metrics(unsigned int& width, unsigned int& height) const {
    width = this->width;
    height = this->height;
}

} /* namespace softedge */
