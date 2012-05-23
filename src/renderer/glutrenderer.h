#ifndef GLUTRENDERER_H_
#define GLUTRENDERER_H_

#include "renderer.h"

namespace softedge {

class Sphere;

class GLUTRenderer: public Renderer {
public:
    GLUTRenderer();
    virtual ~GLUTRenderer();

//    virtual void render(const Geometric* geometry) const;
    void draw(Sphere& sphere);
};

} /* namespace softedge */
#endif /* GLUTRENDERER_H_ */
