#ifndef VIEWPORT_H_
#define VIEWPORT_H_

namespace softedge {

class Color;

class Viewport {
public:
    Viewport(Viewport& viewport);
    Viewport(const unsigned int width, const unsigned int height);
    virtual ~Viewport();

    unsigned int get_width() const;
    unsigned int get_height() const;
    virtual void set_pixel(const unsigned int x, const unsigned int y,
                           const Color& color) const = 0;

protected:
    unsigned int width;
    unsigned int height;
};

} /* namespace softedge */
#endif /* VIEWPORT_H_ */
