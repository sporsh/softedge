#ifndef SCENE_H_
#define SCENE_H_

#include "geometry/geometric.h"
#include "vector3.h"
#include "color.h"

#include <vector>

namespace softedge {


class Renderable {
public:
    Renderable();
    virtual ~Renderable();

    Geometric& geometry;
    Color color;
};


class Scene {
public:
    Scene() {

    }

    std::vector<Geometric*> renderables;
    std::vector<Vector3*> lights;
};

}  // namespace softedge
#endif /* SCENE_H_ */
