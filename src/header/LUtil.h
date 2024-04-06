#ifndef LUTIL_H_
#define LUTIL_H_

#include "LOpenGL.h"

// Screen constants

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_FPS = 60;

// Functions
bool initGL();
// Pre
// Create a valid OpenGL Context
// Post
// Init matrices and clear color
// Reports console if there was error
// Returns false if there is error in init
// Side
// Projection matrix is set to identity
// Modeview matrix is set to identity
// Matrix mode is set to modelview
// Clear color is set to black

void update(); // Handle per frame logic

void render();
// Pre
// Have valid OpenGL Context
// Have an active modelview matrix
// Post
// Renders/Draws scene
// Side
// Clear the color buffer
// swap front and back buffer

#endif // LUTIL_H_
