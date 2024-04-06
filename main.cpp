#include "src/header/LUtil.h"
#include <GL/freeglut_std.h>

void runMainLoop(int val) {

  // Frame Logic
  update();
  render();

  // Run frame one more time
  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, val);
}

int main(int argc, char *argv[]) {
  glutInit(&argc, argv);

  glutInitContextVersion(2, 1);

  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
  glutCreateWindow("Hello OpenGL!");

  if (!initGL()) {
    printf("Unable to initialize graphics library\n");
    return 1;
  }

  glutDisplayFunc(render);

  glutTimerFunc(1000 / SCREEN_FPS, runMainLoop, 0);

  glutMainLoop();

  return 0;
}
