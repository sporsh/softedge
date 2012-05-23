/*
 * raytracerenderer.h
 *
 *  Created on: May 18, 2012
 *      Author: geir
 */

#ifndef RAYTRACERENDERER_H_
#define RAYTRACERENDERER_H_

#include "renderer.h"

namespace softedge {

class Viewport;
class Camera;
class Geometric3;
class Vector3;

class RaytraceRenderer: public Renderer {
public:
    RaytraceRenderer();
    virtual ~RaytraceRenderer();

    void render(Viewport& viewport, const Camera& camera,
                const Geometric3* geometry, const Vector3* light) const;
};

} /* namespace softedge */
#endif /* RAYTRACERENDERER_H_ */
