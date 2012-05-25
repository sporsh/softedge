#ifndef GEOMETRIC3_H_
#define GEOMETRIC3_H_

#include "real.h"

namespace softedge {

class Renderer;
class Ray3;
class Vector3;

enum GeometricType {
    NONE, PLANE, TRIANGLE, SPHERE
};

class Geometric3 {
public:
    const GeometricType type;
    Geometric3(GeometricType type);
    virtual ~Geometric3();

    virtual bool intersect(const Ray3& ray, real* t,
                           Vector3* normal) const = 0;
};

}  // namespace softedge
#endif /* GEOMETRIC3_H_ */
