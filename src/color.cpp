#include "real.h"
#include "color.h"

namespace softedge {

Color::Color(real red, real green, real blue) :
        red(red), green(green), blue(blue) {
}

Color::operator unsigned int() const {
    union {
        struct {
            unsigned char b;
            unsigned char g;
            unsigned char r;
            unsigned char a;
        } comp;
        unsigned int color;
    };
    comp.a = 0xff;
    comp.r = 0xff * red;
    comp.g = 0xff * green;
    comp.b = 0xff * blue;
    return color;
}

}  // namespace softedge
