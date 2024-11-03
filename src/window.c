#include "window.h"
#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Window *current_focused_window;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

Window *create_window(size_t w, size_t h, char *name) {
  Window *self = (Window *)malloc(sizeof(Window));
  memset(self, 0, sizeof(Window));
  if (!glfwInit()) {
    fprintf(stderr, "Failed to Init Window");
    exit(EXIT_FAILURE);
  }


  glfwWindowHint(GLFW_REFRESH_RATE, 60);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  self->window_ptr = glfwCreateWindow((int)w, (int)h, name, NULL, NULL);

  // OpenGL features
  glfwMakeContextCurrent(self->window_ptr); // neccesary to use below functions
  gladLoadGL(glfwGetProcAddress);
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  self->width = w;
  self->height = h;

  glfwSetFramebufferSizeCallback(self->window_ptr, framebuffer_size_callback);
  return self;
}

void init_window(int w, int h, char *name, Window* win) {
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

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  printf("Window Framebuffer Size Callback:\t%p\n", (void *)window);
  current_focused_window->width = width;
  current_focused_window->height = height;
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
