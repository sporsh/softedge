#ifndef COLOR_H_
#define COLOR_H_

#include "real.h"
#include "tuple.h"

namespace softedge {

enum ColorMode {
    RGBA,
    ARGB
};

class Color: public Tuple<3, real> {
public:
    real& r;
    real& g;
    real& b;

    Color();
    Color(const Tuple<3, real>& tuple);
    Color(const Color& color);
    Color(const real red, const real green, const real blue);
    Color(const unsigned long color, const ColorMode mode);

    unsigned int get_color(const ColorMode mode) const;
    operator unsigned int() const;

    Color& operator =(const Color&);

};

}  // namespace softedge
#endif /* COLOR_H_ */
