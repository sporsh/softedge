#include "x11viewportwindow.h"
//#include <boost/thread.hpp>

namespace softedge {

enum State {
    APP_STATE_STOPPED = 10,
    APP_STATE_UNINITIALIZED,
    APP_STATE_RUNNING
};

class X11WindowApplication {
public:
    X11WindowApplication() {
        state = APP_STATE_UNINITIALIZED;
    }

    virtual ~X11WindowApplication() {
        state = APP_STATE_STOPPED;
    }

    virtual int run(int argc, char** argv) {
        state = APP_STATE_RUNNING;
        return main(argc, argv);
    }

    virtual int main(int argc, char** argv) {
        Display* display = XOpenDisplay(NULL);
        if (!display) {
            return 1;
        }
        X11ViewportWindow viewport_window(640, 480, "Test Application",
                                          display, 0, 0);
        viewport_window.create();
        viewport_window.show();

        XSelectInput(display, viewport_window.get_handle(),
                     ButtonPressMask | ButtonReleaseMask);

        XEvent event;
        while (APP_STATE_RUNNING == state) {
            XNextEvent(display, &event);
            switch (event.type) {
            case ButtonRelease:
            case KeyPress:
                state = APP_STATE_STOPPED;
                break;
            default:
                break;
            }
        };

        XCloseDisplay(display);
        viewport_window.destroy();

        return state;
    }
private:
    State state;
};

int X11WindowEventHandler(Window window, XEvent event) {
    return 0;
}

}  // namespace softedge

using namespace softedge;

int main(int argc, char** argv) {
    X11WindowApplication application;
    int exit_status = application.run(argc, argv);
    return exit_status;
}

