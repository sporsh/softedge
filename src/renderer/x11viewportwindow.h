#ifndef X11VIEWPORTWINDOW_H_
#define X11VIEWPORTWINDOW_H_

#include "viewportwindow.h"

#include <X11/Xlib.h>
#include <stdlib.h>

namespace softedge {

class X11ViewportWindow: public ViewportWindow {
public:
    X11ViewportWindow(X11ViewportWindow& viewport) :
            ViewportWindow(viewport) {
    }

    X11ViewportWindow(const unsigned int width, const unsigned int height,
                      const char* title, Display* display, const int left,
                      const int top);

    virtual ~X11ViewportWindow();

    virtual void show();
    virtual void update();

    virtual void set_pixel(const unsigned int x, const unsigned int y,
                           const Color& color) const;

public:
//private:
    unsigned int* data;
    Display* display;
    Window window;
    GC gc;
    XImage* image;
};

}  // namespace softedge
#endif /* X11VIEWPORTWINDOW_H_ */
