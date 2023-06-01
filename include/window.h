#ifndef WINDOW_H
#define WINDOW_H
#include "glad/gl.h"
#include <GLFW/glfw3.h>

typedef struct Window_ {
  GLFWwindow *window_ptr;
  size_t width;
  size_t height;
} Window;

// Init Window
Window *newWindow(size_t w, size_t h, char *name);
// Deallocates interresources before deallocate self
int destroyWindow(Window *self);

int focusWindow(Window *self);

int Window_handleEvents(Window *self);

int Window_shouldClose(Window *self);

#endif
