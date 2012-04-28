#ifndef X11VIEWPORTWINDOW_H_
#define X11VIEWPORTWINDOW_H_

#include "viewportwindow.h"
#include <X11/Xlib.h>

namespace softedge {

class X11ViewportWindow: public ViewportWindow {
public:
    X11ViewportWindow(const unsigned int width, const unsigned int height,
                      const char* title, Display* display, const int left,
                      const int top) :
            ViewportWindow(width, height, title, left, top), display(display) {
    }

    virtual ~X11ViewportWindow() {
    }

    void create() {
        int x11_screen = DefaultScreen(display);
        Window parent = DefaultRootWindow(display);
        unsigned int border_width = 0;
        unsigned long border = BlackPixel(display, x11_screen);
        unsigned long background = WhitePixel(display, x11_screen);

        window = XCreateSimpleWindow(display, parent, left, top, width, height,
                                     border_width, border, background);
    }

    void destroy() {
        XDestroyWindow(display, window);
    }

    void show() {
        XMapWindow(display, window);

        XSelectInput(display, window, StructureNotifyMask);
        XEvent event;
        do {
            XNextEvent(display, &event);
        } while (MapNotify != event.type);

    }

    void update() {
    }

    Window get_handle() const {
        return window;
    }

private:
    Window window;
    Display* display;
//    XImage* x11_image;
};

}  // namespace softedge
#endif /* X11VIEWPORTWINDOW_H_ */
