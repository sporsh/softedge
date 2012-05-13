#ifndef RENDERER_H_
#define RENDERER_H_

#include "real.h"

namespace softedge {

class Viewport;
class Geometric3;
class Vector3;

class Renderer {
public:
    Renderer();
    void render(Viewport& viewport, const Geometric3* geometry,
                const Vector3* light) const;
};

}  // namespace softedge

#endif /* RENDERER_H_ */
