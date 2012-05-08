#include "x11viewportwindow.h"
#include <stdio.h>
//#include <boost/thread.hpp>

namespace softedge {

enum State {
    APP_STATE_STOPPED,
    APP_STATE_STOPPING,
    APP_STATE_STARTING,
    APP_STATE_RUNNING
};

class X11WindowApplication {
public:
    X11WindowApplication() {
        state = APP_STATE_STARTING;
    }

    virtual ~X11WindowApplication() {
        state = APP_STATE_STOPPED;
    }

    virtual int run(int argc, char** argv) {
        state = APP_STATE_RUNNING;
        return main(argc, argv);
    }

private:
    virtual int main(int argc, char** argv) {
        Display* display = XOpenDisplay(NULL);
        if (NULL == display) {
            return 1;
        }

        X11ViewportWindow viewport_window(640, 480, "Test Application",
                                          display, 0, 0);
        viewport_window.create();
        viewport_window.show();
        viewport_window.update();

        XEvent event;
        while (APP_STATE_RUNNING == state) {
            XNextEvent(display, &event);
            switch (event.type) {
            case ButtonRelease:
                viewport_window.update();
                break;
            case KeyRelease:
                state = APP_STATE_STOPPING;
                break;
            case ClientMessage:
                printf("Unhandeled event: %s\n",
                       XGetAtomName(display, event.xclient.message_type));
                break;
            default:
                printf("Unhandeled event: %d\n", event.type);
                break;
            }
        };

        viewport_window.destroy();
        XCloseDisplay(display);

        return state;
    }

    State state;
}
;

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

