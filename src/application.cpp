#include "x11viewportwindow.h"
#include "renderer.h"
#include "scene.h"
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

        Scene scene(Vector(0, 0, 0), Sphere(Vector(200, 150, 100), 50));

        Renderer renderer;
        X11ViewportWindow viewport(640, 480, "Test Application", display, 0,
                                   0);
        viewport.create();
        viewport.show();
        viewport.update();

        XEvent event;
        while (APP_STATE_RUNNING == state) {
            XNextEvent(display, &event);
            switch (event.type) {
            case ButtonRelease:
                switch (event.xbutton.button) {
                case 1:
                    scene.light.x = event.xbutton.x;
                    scene.light.y = event.xbutton.y;
                    break;
                case 3:
                    scene.sphere.origin.x = event.xbutton.x;
                    scene.sphere.origin.y = event.xbutton.y;
                    break;
                }
                renderer.render(viewport, scene);
                viewport.update();
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

        viewport.destroy();
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

