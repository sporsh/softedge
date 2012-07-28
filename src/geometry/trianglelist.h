#ifndef TRIANGLELIST_H_
#define TRIANGLELIST_H_

#include "geometric.h"
#include "point3.h"

#include <vector>

namespace softedge {

class Visitor;

typedef std::vector<Point3> VertexArray;

class TriangleList: public Geometric {
public:
    TriangleList(const VertexArray& vertex_array);
    virtual ~TriangleList();

    virtual void accept(Visitor& visitor);

//private:
    const VertexArray& vertex_array;
};

} /* namespace softedge */
#endif /* TRIANGLELIST_H_ */
