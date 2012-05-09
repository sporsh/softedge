#ifndef RENDERER_H_
#define RENDERER_H_

#include "real.h"

namespace softedge {

class Viewport;

class Renderer {
public:
    Renderer();
    void render(Viewport& viewport) const;
};

}  // namespace softedge

#endif /* RENDERER_H_ */
