#include "window.h"
#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void init_window(int w, int h, char *name, Window** window_ptr) {
  Window *win = *window_ptr;
  if (!glfwInit()) {
    fprintf(stderr, "Failed to Init Window");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_REFRESH_RATE, 60);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  win->window_ptr = glfwCreateWindow(w, h, name, NULL, NULL);

  // OpenGL features
  glfwMakeContextCurrent(win->window_ptr); // neccesary to use below functions
  gladLoadGL(glfwGetProcAddress);
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  win->width = w;
  win->height = h;

  glfwSetFramebufferSizeCallback(win->window_ptr, framebuffer_size_callback);
}

int window_destroy(Window *self) {
  glfwDestroyWindow(self->window_ptr);
  glfwTerminate();
  free(self);
  return EXIT_SUCCESS;
}

int focus_window(Window *self) {
  current_focused_window = self;
  glfwMakeContextCurrent(self->window_ptr);
  return EXIT_SUCCESS;
}
int window_handle_events(Window *self) {
  processInput(self->window_ptr);
  glfwSwapBuffers(self->window_ptr);
  glfwPollEvents();
  return EXIT_SUCCESS;
}
int window_should_close(Window *self) {
  return glfwWindowShouldClose(self->window_ptr);
}

