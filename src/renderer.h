#ifndef RENDERER_H_
#define RENDERER_H_

namespace softedge {

class Buffer {
public:

private:
};

class Camera {

};

class Scene {
public:

private:
};

class Renderer {
public:
    Renderer() {
    }

    void render() {
        render_region();
    }

private:
    void render_region() {
        for (int y = 0; y < viewport->getHeight(); ++y) {
            for (int x = 0; x < viewport->getHeight(); ++x) {

            }
        }
    }
};

}  // namespace softedge

#endif /* RENDERER_H_ */
