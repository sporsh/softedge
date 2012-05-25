#ifndef SCENE_H_
#define SCENE_H_

#include "vector3.h"
#include "geometric3.h"


namespace softedge {

class Node;
class Renderable;
class Intersectable;

class Scene {
public:
    Scene(Vector3 light, Geometric3 geometry) :
            light(light), geometry(geometry) {
    }

    Vector3 light;
    Geometric3 geometry;
};

}  // namespace softedge
#endif /* SCENE_H_ */
