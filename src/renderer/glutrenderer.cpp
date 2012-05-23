#include "glutrenderer.h"
#include "geometry/sphere.h"

#include <GL/glx.h>
#include <GL/glu.h>

namespace softedge {

GLUTRenderer::GLUTRenderer() {
}

GLUTRenderer::~GLUTRenderer() {
}

void GLUTRenderer::draw(Sphere& sphere) {
//    unsigned int width, height;
//    viewport.get_metrics(width, height);
//    glViewport(0, 0, width, height);

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0., 640., -420., 0., 1., 1000.);
//    glOrtho(-1., 1., -1., 1., 1., 20.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0., 0., 10., 0., 0., 0., 0., 1., 0.);
//
//    glBegin(GL_QUADS);
//    glColor3f(1., 0., 0.);
//    glVertex3f(-.75, -.75, 0.);
//    glColor3f(0., 1., 0.);
//    glVertex3f(.75, -.75, 0.);
//    glColor3f(0., 0., 1.);
//    glVertex3f(.75, .75, 0.);
//    glColor3f(1., 1., 0.);
//    glVertex3f(-.75, .75, 0.);
//    glEnd();

    GLfloat mat_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat model_ambient[] = { 0.5, 0.5, 0.5, 1.0 };
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);


    GLUquadricObj *quadric = gluNewQuadric();
    gluQuadricDrawStyle(quadric, GLU_FILL);
    gluQuadricNormals(quadric, GLU_SMOOTH);
    glColor3f(1.0, .0, 0.0);
//    glTranslatef(100, 1, 1);
    glPushMatrix();
    gluSphere(quadric, 50, 12, 12);
    glPopMatrix();
    gluDeleteQuadric(quadric);
}


} /* namespace softedge */
