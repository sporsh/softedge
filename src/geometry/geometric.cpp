#include "geometric.h"

namespace softedge {

Visitor::~Visitor() {

}

Geometric::Geometric() :
        color(Color(.5, .5, .5)) {
}

Geometric::~Geometric() {
}

}  // namespace softedge
