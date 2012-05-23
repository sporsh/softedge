#ifndef GLXVIEWPORTWINDOW_H_
#define GLXVIEWPORTWINDOW_H_

#include "viewportwindow.h"

#include <GL/glx.h>
#include <X11/Xlib.h>

namespace softedge {
class Triangle3;
}

namespace softedge {

class GLXViewportWindow: public ViewportWindow {
public:
    GLXViewportWindow(GLXViewportWindow& viewport) :
            ViewportWindow(viewport) {
    }

    GLXViewportWindow(const unsigned int width, const unsigned int height,
                      const char* title, Display* display, const int left,
                      const int top);

    virtual ~GLXViewportWindow();

    void show();

    void update();

    inline void set_pixel(unsigned int x, unsigned int y,
                          const Color& color) const;

private:
    unsigned int* data;
    Display* display;
    Window window;
    GLXContext glc;
};

}  // namespace softedge
#endif /* GLXVIEWPORTWINDOW_H_ */
