#include "real.h"
#include "tuple.h"
#include "color.h"

#include <algorithm>

namespace softedge {

Color::Color() :
        Tuple(), r(this->tuple[0]), g(this->tuple[1]), b(this->tuple[2]) {
}

Color::Color(const Tuple<3, real>& tuple) :
        Tuple(tuple), r(this->tuple[0]), g(this->tuple[1]), b(this->tuple[2]) {
}

Color::Color(const Color& color) :
        Tuple(), r(this->tuple[0]), g(this->tuple[1]), b(this->tuple[2]) {
    *this = color;
}

Color::Color(const real red, const real green, const real blue) :
        Tuple(), r(this->tuple[0]), g(this->tuple[1]), b(this->tuple[2]) {
    r = red;
    g = green;
    b = blue;
}

Color& Color::operator =(const Color& color) {
    if (&color != this) {
        r = color.r;
        g = color.g;
        b = color.b;
    }
    return *this;
}

unsigned int Color::get_color(const ColorMode mode) const {
    unsigned char ca = 0xff;
    unsigned char cr = std::min(0xff, (int) (0xff * r));
    unsigned char cg = std::min(0xff, (int) (0xff * g));
    unsigned char cb = std::min(0xff, (int) (0xff * b));

    union {
        struct {
            unsigned char c1;
            unsigned char c2;
            unsigned char c3;
            unsigned char c4;
        } comp;
        unsigned int value;
    };

    switch(mode) {
    case ARGB:
        comp.c1 = cb;
        comp.c2 = cg;
        comp.c3 = cr;
        comp.c4 = ca;
        break;
    case RGBA:
        comp.c1 = ca;
        comp.c2 = cb;
        comp.c3 = cg;
        comp.c4 = cr;
        break;
    }

    return value;
}

}  // namespace softedge
