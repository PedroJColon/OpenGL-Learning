#include "src/header/LUtil.h"
#include <GL/freeglut_std.h>

void runMainLoop(int val) {
  // Pre
  // Init freeGLUT
  // Post
  // Calls main loop function and sets itself to be called in 1000 / SCREEN_FPS
  // mills Side effects Set the glutTimer Func
  // Frame Logic
  update();
  render();

  // Run frame one more time
  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}

int main(int argc, char *argv[]) {
  // Init FreeGlut
  glutInit(&argc, argv);

  // Create OpenGL 2.1 context
  // Since we are using 2.1 we will be using the fixed function pipeline
  // Rather than a programmable pipeline
  glutInitContextVersion(2, 1);

  // Create double buffered window
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutCreateWindow("Hello OpenGL!");

  // Do post window/context creation init
  if (!initGL()) {
    printf("Unable to initialize graphics library\n");
    return 1;
  }

  // Sets rendering function
  glutDisplayFunc(render);

  // Set main loop
  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, 0);

  // Start GLUT Main loop
  glutMainLoop();

  return 0;
}
