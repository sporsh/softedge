#ifndef VIEWPORT_H_
#define VIEWPORT_H_

namespace softedge {

class Viewport {
public:
    Viewport(const unsigned int width, const unsigned int height) :
            width(width), height(height) {
    }
    virtual ~Viewport() {
    }

    virtual bool on_key_down(unsigned char key) {
        return true;
    }

protected:
    unsigned int width;
    unsigned int height;
};


} /* namespace softedge */
#endif /* VIEWPORT_H_ */
