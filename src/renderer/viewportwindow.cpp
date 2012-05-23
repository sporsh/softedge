#include "viewportwindow.h"

namespace softedge {

ViewportWindow::ViewportWindow(const unsigned int width,
                               const unsigned int height, const char* title,
                               const int left, const int top) :
        Viewport(width, height), title(title), left(left), top(top) {
}

ViewportWindow::~ViewportWindow() {
}

void ViewportWindow::get_metrics(unsigned int& width, unsigned int& height,
                         int& left, int& top) const {
    Viewport::get_metrics(width, height);
    left = this->left;
    top = this->top;
}

} /* namespace softedge */
