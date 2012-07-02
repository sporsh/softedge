#ifndef GLUTRENDERER_H_
#define GLUTRENDERER_H_

#include "renderer.h"
#include "geometry/geometric.h"
#include "vector3.h"

namespace softedge {

class Plane3;
class Triangle3;
class Sphere;

class Scene;

class GLXViewportWindow;

class GLUTRasterizer: public Visitor {
public:
    GLUTRasterizer();
    virtual ~GLUTRasterizer();

    virtual void visit(Plane3& plane);
    virtual void visit(Triangle3& triangle);
    virtual void visit(Sphere& sphere);

    void set_color(Color& color);

    GLXViewportWindow* viewport;
};


class GLUTRenderer: public Renderer {
public:
    GLUTRenderer();
    virtual ~GLUTRenderer();

    void render(GLXViewportWindow& viewport, const Camera& camera,
                        const Scene& scene);

private:
    Vector3 light;
    GLUTRasterizer rasterizer;
};

} /* namespace softedge */
#endif /* GLUTRENDERER_H_ */
