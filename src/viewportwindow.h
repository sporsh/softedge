#ifndef VIEWPORTWINDOW_H_
#define VIEWPORTWINDOW_H_

#include "viewport.h"

namespace softedge {

class ViewportWindow: public Viewport {
public:
    ViewportWindow(const unsigned int width, const unsigned int height,
                   const char* title, const int left, const int top) :
            Viewport(width, height), title(title), left(left), top(top) {
    }

    virtual ~ViewportWindow() {
    }

protected:
    const char* title;
    int left;
    int top;
};

} /* namespace softedge */
#endif /* VIEWPORTWINDOW_H_ */
