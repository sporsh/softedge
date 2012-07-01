#ifndef RENDERER_H_
#define RENDERER_H_

#include "real.h"

namespace softedge {

class Viewport;
class Camera;
class Scene;

}  // namespace softedge

namespace softedge {

class Renderer {
public:
    Renderer();
    virtual ~Renderer();

//    virtual void render(Viewport& viewport, const Camera& camera, const Scene& scene) = 0;
};

}  // namespace softedge

#endif /* RENDERER_H_ */
