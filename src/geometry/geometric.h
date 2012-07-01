#ifndef GEOMETRIC_H_
#define GEOMETRIC_H_

#include "color.h"
#include "real.h"

namespace softedge {

class Renderer;
class Ray3;
class Vector3;

};

class Geometric {
public:
    Geometric();
    virtual ~Geometric();

    virtual bool intersect(const Ray3& ray, real* t,
                           Vector3* normal) const = 0;
    Color color;
};

}  // namespace softedge
#endif /* GEOMETRIC_H_ */
