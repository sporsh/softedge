#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

namespace softedge {

struct Framebuffer {
};

struct SoftwareFramebuffer: public Framebuffer {
    void* color;
    void* depth;
    void* stencil;
    void* accumulation;
};

struct X11Framebuffer: public Framebuffer {
    Pixmap pixmap;
};

struct GLFramebuffer: public Framebuffer {
    GLXContext glc;
};

} /* namespace softedge */
#endif /* FRAMEBUFFER_H_ */
