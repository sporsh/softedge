#ifndef COLOR_H_
#define COLOR_H_

#include "real.h"

namespace softedge {

class Color {
public:
    Color(real red, real green, real blue);
    operator unsigned int() const;

private:
    real red, green, blue;
};

}  // namespace softedge
#endif /* COLOR_H_ */
