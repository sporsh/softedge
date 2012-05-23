#ifndef VIEWPORTWINDOW_H_
#define VIEWPORTWINDOW_H_

#include "viewport.h"

namespace softedge {

class ViewportWindow: public Viewport {
public:
    ViewportWindow(const unsigned int width, const unsigned int height,
                   const char* title, const int left, const int top);

    virtual ~ViewportWindow();

    void get_metrics(unsigned int& width, unsigned int& height,
                             int& left, int& top) const;

    virtual void show() = 0;
    virtual void update() = 0;

protected:
    const char* title;
    int left;
    int top;
};

} /* namespace softedge */
#endif /* VIEWPORTWINDOW_H_ */
