#include "renderer/x11viewportwindow.h"
#include "renderer/raytracerenderer.h"
#include "renderer/x11renderer.h"

#include "renderer/glxviewportwindow.h"
#include "renderer/glutrenderer.h"

#include "scene.h"

#include "camera.h"
#include "geometry/ray3.h"
#include "vector3.h"
#include "geometry/point3.h"
#include "geometry/geometric.h"
#include "geometry/triangle3.h"
#include "geometry/plane3.h"
#include "geometry/sphere.h"
#include "geometry/trianglelist.h"

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

//#include <boost/thread.hpp>

namespace softedge {

//class GeometrySoup: public Geometric {
//public:
//    GeometrySoup(std::vector<Geometric*> objects) :
//            Geometric(), objects(objects) {
//    }
//
//    bool intersect(const Ray3& ray, real* final_t, Vector3* final_n) const {
//        real hit = false;
//        for (unsigned int i = 0; i < objects.size(); ++i) {
//            real t;
//            Vector3 n;
//            if (objects[i]->intersect(ray, &t, &n)) {
//                if (!hit || t < *final_t) {
//                    *final_t = t;
//                    *final_n = n;
//                }
//                hit = true;
//            }
//        }
//        return hit;
//    }
//
//private:
//    std::vector<Geometric*> objects;
//};

enum State {
    APP_STATE_STOPPED,
    APP_STATE_STOPPING,
    APP_STATE_STARTING,
    APP_STATE_RUNNING
};

class X11WindowApplication {
public:
    X11WindowApplication() {
        display = XOpenDisplay(NULL);
        assert(display != NULL);
        state = APP_STATE_STARTING;
    }

    virtual ~X11WindowApplication() {
        XCloseDisplay(display);
        state = APP_STATE_STOPPED;
    }

    virtual int run(int argc, char* argv[]) {
        state = APP_STATE_RUNNING;
        return main(argc, argv);
    }

private:
    Display* display;

    virtual int main(int argc, char* argv[]) {
        Scene scene;

        Camera camera(Point3(640 / 2, 480 / 2, 0), Vector3(0, 0, 1));

        Vector3 light = Vector3(320, 120, 50);
        scene.lights.push_back(&light);

        Sphere sphere = Sphere(Point3(640 / 2, 480 / 2, 400), 200);
        sphere.color = Color(1.0, 0.2, 0.2);
        Sphere sphere2(Point3(640, 480, 500), 250);
        sphere2.color = Color(1.0, 1.0, 0.0);
        Sphere sphere3(Point3(0, 0, 0), 200);
        sphere3.color = Color(0.0, 0.0, 1.0);

        scene.renderables.push_back(&sphere);
        scene.renderables.push_back(&sphere2);
        scene.renderables.push_back(&sphere3);

        Plane3 plane1(normalize(Vector3(5, 0, -1)), 0);
        Plane3 plane2(normalize(Vector3(-5, 0, -1)), -640);
        Plane3 plane3(normalize(Vector3(0, 0, -1)), -1000);
        scene.renderables.push_back(&plane1);
        scene.renderables.push_back(&plane2);
        scene.renderables.push_back(&plane3);

//        Triangle3 triangle1(Point3(100, 100, 400), Point3(100, 400, 400),
//                            Point3(400, 100, 100));
//        Triangle3 triangle2(Point3(100, 400, 400), Point3(200, 550, 800),
//                            Point3(400, 100, 100));
//        scene.renderables.push_back(&triangle1);
//        scene.renderables.push_back(&triangle2);

        VertexArray vertex_array;
        vertex_array.push_back(Point3(400, 100, 100));
        vertex_array.push_back(Point3(100, 400, 400));
        vertex_array.push_back(Point3(100, 100, 400));

        vertex_array.push_back(Point3(400, 100, 100));
        vertex_array.push_back(Point3(200, 550, 800));
        vertex_array.push_back(Point3(100, 400, 400));
        TriangleList tri_soup(vertex_array);
        scene.renderables.push_back(&tri_soup);

        RaytraceRenderer rt_renderer;
        X11ViewportWindow rt_viewport(640, 480, "Raytracer", display, 0, 0);
        rt_viewport.show();

        X11Renderer x11_renderer;
        X11ViewportWindow x11_viewport(640, 480, "X11 Renderer", display, 0,
                                       0);
        x11_viewport.show();

        GLUTRenderer glut_renderer;
        GLXViewportWindow glx_viewport(640, 480, "GLUT Renderer", display, 0,
                                       0);
        glx_viewport.show();

        real *x = NULL, *y = NULL;
        XEvent event;
        while (APP_STATE_RUNNING == state) {
            XNextEvent(display, &event);
            switch (event.type) {
            case ButtonRelease:
                x = y = NULL;
                rt_renderer.render(rt_viewport, camera, scene);
                rt_viewport.update();
                x11_viewport.update();
                x11_renderer.render(x11_viewport, camera, scene);
                break;
            case ButtonPress:
                switch (event.xbutton.button) {
                case 1:
                    x = &light.x;
                    y = &light.y;
                    break;
                case 3:
                    x = &sphere.origin.x;
                    y = &sphere.origin.y;
                    break;
                }
                break;
            case MotionNotify:
                if (x && y && *x != event.xmotion.x) {
                    *x = event.xmotion.x;
                    *y = event.xmotion.y;
                    glut_renderer.render(glx_viewport, camera, scene);
                    glx_viewport.update();
                }
//                printf("MotionNotify: %d\n", event.xmotion.x);
                break;
            case KeyRelease:
                switch (XLookupKeysym(&event.xkey, 0)) {
                case XK_q:
                case XK_Q:
                case XK_Escape:
                    state = APP_STATE_STOPPING;
                    break;
                default:
//                    printf("Key event: %s\n", XKeysymToString(key_sym));
                    break;
                }
                break;
            case ClientMessage:
                printf("Unhandeled event: %s\n",
                       XGetAtomName(display, event.xclient.message_type));
                break;
            default:
//                printf("Unhandeled event: %d\n", event.type);
                break;
            }
        };
        return state;
    }
    State state;
};

int X11WindowEventHandler(Window window, XEvent event) {
    return 0;
}

}  // namespace softedge

using namespace softedge;

int main(int argc, char* argv[]) {
    X11WindowApplication application;
    int exit_status = application.run(argc, argv);
    return exit_status;
}

