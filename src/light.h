#ifndef LIGHT_H_
#define LIGHT_H_

namespace softedge {

class Color;

class Light {
    real intensity;
    real wave_length;

    real red_intensity;
    real green_intensity;
    real blue_intensity;

    Color color();
};

class RGBColor;
class CMYKColor;
class HSVColor;
class HSLColor;

}  // namespace softedge
#endif /* LIGHT_H_ */
