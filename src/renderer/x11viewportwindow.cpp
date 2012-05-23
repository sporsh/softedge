#include "x11viewportwindow.h"
#include "color.h"

#include <X11/Xlib.h>
#include <X11/Xutil.h>
//#include <X11/Xatom.h>

namespace softedge {

X11ViewportWindow::X11ViewportWindow(const unsigned int width,
                                     const unsigned int height,
                                     const char* title, Display* display,
                                     const int left, const int top) :
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
                                 top, width, height, 0, border, background);
    XStoreName(display, window, title);

    gc = XCreateGC(display, window, 0, NULL);

    XSelectInput(
            display,
            window,
            StructureNotifyMask | ButtonPressMask | ButtonReleaseMask
                    | KeyReleaseMask);

    Atom wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);
}

X11ViewportWindow::~X11ViewportWindow() {
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XDestroyImage(image);
    delete[] data;
}

void X11ViewportWindow::show() {
    XMapWindow(display, window);

    XEvent event;
    do {
        XNextEvent(display, &event);
    } while (MapNotify != event.type);

}

void X11ViewportWindow::update() {
    XPutImage(display, window, gc, image, 0, 0, 0, 0, image->width,
              image->height);
    XFlushGC(display, gc);
}

void X11ViewportWindow::set_pixel(unsigned int x, unsigned int y,
                                  const Color& color) const {
    unsigned int i = (y * width + x);
    data[i] = color;
}

} /* namespace softedge */
