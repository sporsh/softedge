#ifndef SCENE_H_
#define SCENE_H_

#include "vector.h"
#include "sphere.h"

namespace softedge {

class Scene {
public:
    Scene(Vector light, Sphere sphere) :
            light(light), sphere(sphere) {
    }

    Vector light;
    Sphere sphere;
};

}  // namespace softedge
#endif /* SCENE_H_ */
