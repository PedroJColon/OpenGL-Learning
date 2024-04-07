#include "header/LUtil.h"
#include <GL/gl.h>

// current color rendering mode
int gColorMode = COLOR_MODE_CYAN;

// projection scale
GLfloat gProjectionScale = 1.0f;

// Viewport
int gViewportMode = VIEWPORT_MODE_HALF_CENTER;

bool initGL() {
  // Set viewport
  glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

  // Init Projection Matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0);

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
  // Clear color buffer
  glClear(GL_COLOR_BUFFER_BIT);

  // Reset modelview matrix
  glLoadIdentity();

  // Move to center to screen
  glTranslatef(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f, 0.0f);

  // Full View
  if (gViewportMode == VIEWPORT_MODE_FULL) {
    // Fill the screen
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);

    // Red quad
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
    glVertex2f(SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
    glVertex2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
    glVertex2f(-SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
    glEnd();
  } else if (gViewportMode == VIEWPORT_MODE_HALF_CENTER) {
    // Center viewport
    glViewport(SCREEN_WIDTH / 4.0f, SCREEN_HEIGHT / 4.0f, SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);

    // Green Quad
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
    glVertex2f(SCREEN_WIDTH / 2.0f, -SCREEN_HEIGHT / 2.0f);
    glVertex2f(SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
    glVertex2f(-SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f);
    glEnd();
  } else if (gViewportMode == VIEWPORT_MODE_HALF_TOP) {
    // Viewtop at top
    
  
  }

  // Render quad
  // if (gColorMode == COLOR_MODE_CYAN) {
    // // solid cyan
    // glBegin(GL_QUADS);
    // glColor3f(0.0f, 1.0f, 1.0f);
    // glVertex2f(-50.0f, -50.0f);
    // glVertex2f(50.0f, -50.0f);
    // glVertex2f(50.0f, 50.0f);
    // glVertex2f(-50.0f, 50.0f);
    // glEnd();
  // } else {
    // // rygb mix
    // glBegin(GL_QUADS);
    // glColor3f(1.0f, 0.0f, 0.0f);
    // glVertex2f(-50.0f, -50.0f);
    // glColor3f(1.0f, 1.0f, 0.0f);
    // glVertex2f(50.0f, -50.0f);
    // glColor3f(0.0f, 1.0f, 0.0f);
    // glVertex2f(50.0f, 50.0f);
    // glColor3f(1.0f, 0.0f, 1.0f);
    // glVertex2f(-50.0f, 50.0f);
    // glEnd();
  // }

  // update screen
  glutSwapBuffers();
}

void handleKeys(unsigned char key, int x, int y) {
  if (key == 'q') {
    // toggle color modes
    if (gColorMode == COLOR_MODE_CYAN) {
      gColorMode = COLOR_MODE_MULTI;
    } else {
      gColorMode = COLOR_MODE_CYAN;
    }
  } else if (key == 'e') {
    // cycle through projection scales
    if (gProjectionScale == 1.0f) {
      // Zoom out
      gProjectionScale = 2.0f;
    } else if (gProjectionScale == 2.0f) {
      // Zoom in
      gProjectionScale = 0.5f;
    } else if (gProjectionScale == 0.5f) {
      // Default zoom
      gProjectionScale = 1.0f;
    }
  }

  // update projection matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, SCREEN_WIDTH * gProjectionScale,
          SCREEN_HEIGHT * gProjectionScale, 0.0, 1.0, -1.0);
}
