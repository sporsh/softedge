#include "glxviewportwindow.h"

#include "color.h"

//#include <X11/Xutil.h>
//#include <X11/Xatom.h>

#include <stdlib.h>
#include <stdio.h>

namespace softedge {

GLXViewportWindow::GLXViewportWindow(const unsigned int width,
                                     const unsigned int height,
                                     const char* title, Display* display,
                                     const int left, const int top) :
        ViewportWindow(width, height, title, left, top), display(display) {

    GLint gl_attributes[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER,
            None };
    XVisualInfo* vi = glXChooseVisual(display, 0, gl_attributes);
    if (vi == NULL) {
        printf("\n\tno appropriate visual found\n\n");
        exit(0);
    } else {
        printf("\n\tvisual %p selected\n", (void *) vi->visualid);
    }/* %p creates hexadecimal output like in glxinfo */

    Colormap cmap = XCreateColormap(display, DefaultRootWindow(display),
                                    vi->visual, AllocNone);

    XSetWindowAttributes swa;
    swa.colormap = cmap;
    swa.event_mask = StructureNotifyMask | ExposureMask | KeyPressMask;

    window = XCreateWindow(display, DefaultRootWindow(display), left, top,
                           width, height, 0, vi->depth, InputOutput,
                           vi->visual, CWColormap | CWEventMask, &swa);

    XStoreName(display, window, title);

    glc = glXCreateContext(display, vi, NULL, GL_TRUE);
    glXMakeCurrent(display, window, glc);

    glEnable(GL_DEPTH_TEST);
}

GLXViewportWindow::~GLXViewportWindow() {
    glXMakeCurrent(display, None, NULL);
    glXDestroyContext(display, glc);
    XDestroyWindow(display, window);
}

void GLXViewportWindow::show() {
    XMapWindow(display, window);
    XEvent event;
    do {
        XNextEvent(display, &event);
    } while (MapNotify != event.type);
}

void GLXViewportWindow::update() {
    glXSwapBuffers(display, window);
}

void GLXViewportWindow::set_pixel(unsigned int x, unsigned int y,
                                  const Color& color) const {
}

} /* namespace softedge */
