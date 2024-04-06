#include "header/LUtil.h"
#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cstdio>

bool initGL() {
  // Init Projection Matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Init Modelview Matrix
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Init Clear Color
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Check for any errors
  GLenum error = glGetError();
  if (error != GL_NO_ERROR) {
    printf("Error Initalizing OpenGL! %s\n", gluErrorString(error));
    return false;
  }

  return true;
}

void update() {}

void render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_QUADS);
  glVertex2f(-0.5f, -0.5f);
  glVertex2f(0.5f, -0.5f);
  glVertex2f(0.5f, 0.5f);
  glVertex2f(-0.5f, 0.5f);
  glEnd();

  glutSwapBuffers();
}
