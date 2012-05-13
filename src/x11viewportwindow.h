#ifndef X11VIEWPORTWINDOW_H_
#define X11VIEWPORTWINDOW_H_

#include "viewportwindow.h"
#include "color.h"

#include <stdlib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>

namespace softedge {

class X11ViewportWindow: public ViewportWindow {
public:
    X11ViewportWindow(X11ViewportWindow& viewport) : ViewportWindow(viewport){
    }

    X11ViewportWindow(const unsigned int width, const unsigned int height,
                      const char* title, Display* display, const int left,
                      const int top) :
            ViewportWindow(width, height, title, left, top), display(display) {
        data = new unsigned int[width * height];
        int screen = DefaultScreen(display);
        int format = ZPixmap;
        int bitmap_pad = 32;
        int bytes_per_line = 0;
        image = XCreateImage(display, DefaultVisual(display, screen),
                             XDefaultDepth(display, screen), format, 0,
                             (char*) data, width, height, bitmap_pad,
                             bytes_per_line);

        unsigned long border = BlackPixel(display, screen);
        unsigned long background = WhitePixel(display, screen);
        window = XCreateSimpleWindow(display, DefaultRootWindow(display), left,
                                     top, width, height, 0, border,
                                     background);

        gc = XCreateGC(display, window, 0, NULL);

        XSelectInput(
                display,
                window,
                StructureNotifyMask | ButtonPressMask | ButtonReleaseMask
                        | KeyReleaseMask);

        Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(display, window, &wmDeleteMessage, 1);
    }

    virtual ~X11ViewportWindow() {
        XFreeGC(display, gc);
        XDestroyWindow(display, window);
        XDestroyImage(image);
        delete[] data;
    }

    void show() {
        XMapWindow(display, window);

        XEvent event;
        do {
            XNextEvent(display, &event);
        } while (MapNotify != event.type);

    }

    void update() {
        XPutImage(display, window, gc, image, 0, 0, 0, 0, image->width,
                  image->height);
        XFlushGC(display, gc);
    }

    inline void set_pixel(unsigned int x, unsigned int y, const Color& color) const {
        unsigned int i = (y * width + x);
        data[i] = color;
    }

private:
    unsigned int* data;
    Display* display;
    Window window;
    GC gc;
    XImage* image;
};

}  // namespace softedge
#endif /* X11VIEWPORTWINDOW_H_ */
