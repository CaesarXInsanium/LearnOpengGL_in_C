#ifndef WINDOW_H
#define WINDOW_H
#include "glad/gl.h"
#include <GLFW/glfw3.h>

typedef struct Window_ {
  GLFWwindow *window_ptr;
  int width;
  int height;
} Window;

// assumes that memory is allocated for the memory object.
void init_window(int w, int h, char* window_name, Window **win);

// Deallocates interresources before deallocate self
int window_destroy(Window *self);

int focus_window(Window *self);

int window_handle_events(Window *self);

int window_should_close(Window *self);

#endif
