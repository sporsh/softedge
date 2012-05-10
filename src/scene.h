#ifndef SCENE_H_
#define SCENE_H_

#include "vector3.h"
#include "sphere.h"

namespace softedge {

class Scene {
public:
    Scene(Vector3 light, Sphere sphere) :
            light(light), sphere(sphere) {
    }

    Vector3 light;
    Sphere sphere;
};

}  // namespace softedge
#endif /* SCENE_H_ */
