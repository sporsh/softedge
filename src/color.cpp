#include "real.h"
#include "tuple.h"
#include "color.h"

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
    comp.r = 0xff * r;
    comp.g = 0xff * g;
    comp.b = 0xff * b;
    return color;
}

}  // namespace softedge
