#ifndef X11RENDERER_H_
#define X11RENDERER_H_

#include "renderer.h"
#include "geometry/geometric.h"
#include "vector3.h"

#include <X11/Xlib.h>

namespace softedge {


class X11ViewportWindow;
class Camera;

class Geometric;
class Sphere;
class Triangle3;
class Plane3;


class X11Rasterizer: public Visitor {
public:
    X11Rasterizer();
    virtual ~X11Rasterizer();

    virtual void visit(Plane3& plane);
    virtual void visit(Triangle3& triangle);
    virtual void visit(TriangleList& ts);
    virtual void visit(Sphere& sphere);

    void set_color(Color& color);

    Vector3 light;
    X11ViewportWindow* viewport;
};

class X11Renderer: public Renderer {
public:
    X11Renderer();
    virtual ~X11Renderer();

    void render(X11ViewportWindow& viewport, const Camera& camera,
                        const Scene& scene);

private:
    X11Rasterizer rasterizer;
};

}  // namespace softedge
#endif /* X11RENDERER_H_ */
