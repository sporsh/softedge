#include "glutrenderer.h"
#include "glxviewportwindow.h"
#include "geometry/sphere.h"
#include "geometry/triangle3.h"
#include "geometry/trianglelist.h"
#include "scene.h"
#include "camera.h"

#include <GL/glx.h>
#include <GL/glu.h>

namespace softedge {

GLUTRasterizer::GLUTRasterizer() {
}

GLUTRasterizer::~GLUTRasterizer() {
}

void GLUTRasterizer::visit(Plane3& plane) {
}

void GLUTRasterizer::visit(Sphere& sphere) {
    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    GLfloat color[] = { (GLfloat) sphere.color.r, (GLfloat) sphere.color.g,
                        (GLfloat) sphere.color.b };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);
    glLoadIdentity();
    glTranslatef(sphere.origin.x, sphere.origin.y, sphere.origin.z);
    glPushMatrix();
    gluSphere(quadric, sphere.radius, 30, 30);
    glPopMatrix();
    gluDeleteQuadric(quadric);
}

void GLUTRasterizer::visit(Triangle3& triangle) {
    GLfloat color[] = { (GLfloat) triangle.color.r, (GLfloat) triangle.color.g,
                        (GLfloat) triangle.color.b };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

    glLoadIdentity();
    glBegin(GL_TRIANGLES); //tells OpenGL that we're going to start drawing triangles
    glVertex3f(triangle.a.x, triangle.a.y, triangle.a.z); //specifies the first vertex of our triangle
    glVertex3f(triangle.b.x, triangle.b.y, triangle.b.z); //specifies the second vertex of our triangle
    glVertex3f(triangle.c.x, triangle.c.y, triangle.c.z); //specifies the third vertex of our triangle
    glEnd();                //tells OpenGL that we've finished drawing
}

void GLUTRasterizer::visit(TriangleList& ts) {
    const GLfloat color[] = { (GLfloat) ts.color.r, (GLfloat) ts.color.g,
                              (GLfloat) ts.color.b };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

    glLoadIdentity();
    glBegin(GL_TRIANGLES);
    for (unsigned int i = 0; i < ts.vertex_array.size(); ++i) {
        const Point3& p = ts.vertex_array[i];
        glVertex3f(p.x, p.y, p.z);
    }
    glEnd();
}

GLUTRenderer::GLUTRenderer() :
        rasterizer(GLUTRasterizer()) {
}

GLUTRenderer::~GLUTRenderer() {
}

void GLUTRenderer::render(GLXViewportWindow& viewport, const Camera& camera,
                          const Scene& scene) {
    rasterizer.viewport = &viewport;
    light = *scene.lights[0];

    unsigned int w, h;
    int l, t;
    viewport.get_metrics(w, h, l, t);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    GLbitfield mask = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT;
//    GLbitfield mask = GL_DEPTH_BUFFER_BIT;
    glClear(mask);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, 0.0, -1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);
//    gluLookAt(camera.origin.x, camera.origin.y, camera.origin.z,
//              camera.origin.x, camera.origin.y, camera.origin.z+camera.direction.z,
//              0., 1., 0.);

    glEnable(GL_LIGHTING);
    GLfloat light_position[] = { (GLfloat) light.x, (GLfloat) light.y,
                                 (GLfloat) light.z, 1 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    for (unsigned int i = 0; i < scene.renderables.size(); ++i) {
        Geometric& renderable = *scene.renderables[i];
        renderable.accept(rasterizer);
    }
}

} /* namespace softedge */
