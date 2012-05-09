#ifndef VIEWPORT_H_
#define VIEWPORT_H_

namespace softedge {

class Color;

class Viewport {
public:
    Viewport(const unsigned int width, const unsigned int height);
    virtual ~Viewport();

    unsigned int get_width() const;
    unsigned int get_height() const;
    virtual void set_pixel(unsigned int x, unsigned int y, Color& color) const;

protected:
    unsigned int width;
    unsigned int height;
    unsigned int* data;
};

} /* namespace softedge */
#endif /* VIEWPORT_H_ */
