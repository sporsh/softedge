#ifndef GEOMETRIC_H_
#define GEOMETRIC_H_

#include "color.h"
#include "real.h"

namespace softedge {

class Renderer;
class Ray3;
class Vector3;

class Geometric;
class Plane3;
class Triangle3;
class Sphere;

class Visitor {
public:
//    virtual void visit(Geometric& geometry) = 0;
    virtual void visit(Plane3& plane) = 0;
    virtual void visit(Triangle3& triangle) = 0;
    virtual void visit(Sphere& sphere) = 0;
};

class Geometric {
public:
    Geometric();
    virtual ~Geometric();

    virtual bool intersect(const Ray3& ray, real* t,
                           Vector3* normal) const = 0;

    virtual void accept(Visitor& visitor) = 0;

    Color color;
};

}  // namespace softedge
#endif /* GEOMETRIC_H_ */
