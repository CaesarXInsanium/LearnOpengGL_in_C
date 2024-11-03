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
Window *create_window(size_t w, size_t h, char *name);

// assumes that memory is allocated for the memory object.
void init_window(int w, int h, char* window_name, Window *win);
// Deallocates interresources before deallocate self
int window_destroy(Window *self);

int focus_window(Window *self);

int window_handle_events(Window *self);

int window_should_close(Window *self);

#endif
