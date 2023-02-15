#include "window.h"
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static Window *current;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

Window *newWindow(size_t w, size_t h, char *name) {
  Window *self = (Window *)malloc(sizeof(Window));
  memset(self, 0, sizeof(Window));
  if (!glfwInit()) {
    fprintf(stderr, "Failed to Init Window");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_REFRESH_RATE, 60);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  self->window_ptr = glfwCreateWindow(w, h, name, NULL, NULL);
  self->width = w;
  self->height = h;

  glfwSetFramebufferSizeCallback(self->window_ptr, framebuffer_size_callback);
  return self;
}

int destroyWindow(Window *self) {
  glfwDestroyWindow(self->window_ptr);
  glfwTerminate();
  free(self);
  return EXIT_SUCCESS;
}

int focusWindow(Window *self) {
  current = self;
  glfwMakeContextCurrent(self->window_ptr);
  return EXIT_SUCCESS;
}
int Window_handleEvents(Window *self) {
  processInput(self->window_ptr);
  glfwSwapBuffers(self->window_ptr);
  glfwPollEvents();
  return EXIT_SUCCESS;
}
int Window_shouldClose(Window *self){
  return glfwWindowShouldClose(self->window_ptr);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  printf("Window Framebuffer Size Callback:\t%p\n", (void *)window);
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
