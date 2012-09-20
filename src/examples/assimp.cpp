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

#include <assimp/assimp.h>
#include <assimp/aiScene.h>

#include <assert.h>
#include <stdio.h>
#include <vector>
#include <algorithm>

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

        Vector3 light = Vector3(320, 120, 0);
        scene.lights.push_back(&light);

        Sphere sphere = Sphere(Point3(50, 50, 50), 20);
        sphere.color = Color(1.0, 0.2, 0.2);
        scene.renderables.push_back(&sphere);

        VertexArray vertex_array;
        const struct aiScene* ai_scene = NULL;
        const char* filename = "src/examples/models/spider.obj";
        ai_scene = aiImportFile(filename, 0);
        if (!ai_scene) {
            printf("FAILED TO OPEN %s\n", filename);
            return 1;
        }
//        const struct aiNode* ai_node = ai_scene->mRootNode;
        for (int n = 0; n < ai_scene->mNumMeshes; n++){
            const struct aiMesh* ai_mesh = ai_scene->mMeshes[n];
            printf("NUM FACES: %i", ai_mesh->mNumFaces);
            for (unsigned int t = 0; t < ai_mesh->mNumFaces; ++t) {
                const struct aiFace* ai_face = &ai_mesh->mFaces[t];
                for (unsigned int i = 0; i < ai_face->mNumIndices; ++i) {
                    int index = ai_face->mIndices[i];
    //                vertex_array.push_back(Point3(index*10, index*10, index*10));
                    vertex_array.push_back((Point3(
                            ai_mesh->mVertices[index].x+150,
                            ai_mesh->mVertices[index].z+150,
                            ai_mesh->mVertices[index].y+100
                            ))*2);
                }
            }
        }
        TriangleList tri_list(vertex_array);
        scene.renderables.push_back(&tri_list);

        VertexArray vertex_array2;
        vertex_array2.push_back(Point3(400, 100, 100));
        vertex_array2.push_back(Point3(100, 400, 400));
        vertex_array2.push_back(Point3(100, 100, 400));

        vertex_array2.push_back(Point3(400, 100, 100));
        vertex_array2.push_back(Point3(200, 550, 800));
        vertex_array2.push_back(Point3(100, 400, 400));
        TriangleList tri_soup(vertex_array2);
//        scene.renderables.push_back(&tri_soup);

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
                break;
            case ButtonPress:
                switch (event.xbutton.button) {
                case 1:
                    x = &light.x;
                    y = &light.y;
                    break;
                case 3:
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
                case XK_1:
                    glut_renderer.render(glx_viewport, camera, scene);
                    glx_viewport.update();
                    break;
                case XK_2:
                    x11_viewport.update();
                    x11_renderer.render(x11_viewport, camera, scene);
                    break;
                case XK_3:
                    rt_renderer.render(rt_viewport, camera, scene);
                    rt_viewport.update();
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

