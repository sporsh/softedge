#ifndef GEOMETRIC3_H_
#define GEOMETRIC3_H_

#include "real.h"

namespace softedge {

class Ray3;
class Vector3;

class Geometric3 {
public:
    virtual ~Geometric3();

    virtual bool intersect(const Ray3& ray, real* t, Vector3* normal) const = 0;
protected:
    Geometric3();
};

}  // namespace softedge
#endif /* GEOMETRIC3_H_ */
