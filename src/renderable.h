#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include "vector3.h"
#include "real.h"

namespace softedge {

class Geometry {
};

class Space: public Geometry {
    class VectorN;
    static VectorN X, Y, Z, W;
};

class Plane: public Geometry {
public:
    Plane(Vector3 normal, real d);
private:
    Vector3 normal;
    real d;
};

class Line: public Geometry {
public:
    static const Line XY, XZ, YZ;
private:
    Plane plane1, plane2;
};

class Point: public Geometry {
    Point(Vector3& vector) :
            plane1(Vector3::X, vector.x), plane2(Vector3::Y, vector.y),
            plane3(Vector3::Z, vector.z) {
    }
    Point(Plane plane1, Plane plane2, Plane plane3);
    Point(Line line, Plane plane);
private:
    Plane plane1, plane2, plane3;
};

class Triangle: public Geometry {
private:
    Plane plane, planea, planeb, planec;
};

enum RenderableType {
    TRIANGLE_LIST, TRIANGLE_STRIP, TRIANGLE_FAN, QUADRIC
};

class Renderable {
public:
    Renderable();
    virtual ~Renderable();

private:
    Geometry* geometry;
};

} /* namespace softedge */
#endif /* RENDERABLE_H_ */
