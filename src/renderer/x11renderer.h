#ifndef X11RENDERER_H_
#define X11RENDERER_H_

#include "renderer.h"

#include <X11/Xlib.h>

namespace softedge {

class X11ViewportWindow;
class Camera;
class Geometric3;
class Vector3;
class Triangle3;
class Sphere;

class X11Renderer: public Renderer {
public:
    X11Renderer();
    virtual ~X11Renderer();

    void render(X11ViewportWindow& viewport, const Camera& camera,
                const Geometric3* geometry, const Vector3& light);

    void render(const Geometric3& renderable, const Vector3& light);
    void draw(const Triangle3& triangle, const Vector3& light);
    void draw(const Sphere& sphere);
private:
    X11ViewportWindow* viewport;
};

}  // namespace softedge
#endif /* X11RENDERER_H_ */
