#include "trianglelist.h"

namespace softedge {

TriangleList::TriangleList(const VertexArray& vertex_array) :
        Geometric(), vertex_array(vertex_array) {
}

TriangleList::~TriangleList() {
}

void TriangleList::accept(Visitor& visitor) {
    visitor.visit(*this);
}

} /* namespace softedge */
