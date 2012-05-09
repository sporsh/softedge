#ifndef COLOR_H_
#define COLOR_H_

#include "real.h"
#include "tuple.h"

namespace softedge {

class Color: public Tuple<3, real> {
public:
    real& r;
    real& g;
    real& b;

    Color();
    Color(const Tuple<3, real>& tuple);
    Color(const Color& color);
    Color(const real red, const real green, const real blue);

    Color& operator =(const Color&);

    operator unsigned int() const;
};

}  // namespace softedge
#endif /* COLOR_H_ */
