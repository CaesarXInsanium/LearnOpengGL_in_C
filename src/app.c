#include "glad/gl.h"
#include "app.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cglm/cam.h>
#include <cglm/cglm.h>
#include <cglm/mat4.h>
#include <cglm/types.h>

static AppState *current_app;

int app_create(AppState *app, struct ApplicationSettings settings){
  if (!glfwInit()) {
    fprintf(stderr, "Failed to Init Window");
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_REFRESH_RATE, 60);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

  GLFWwindow* window = glfwCreateWindow(settings.width, settings.height, settings.name, NULL, NULL);

  // OpenGL features
  glfwMakeContextCurrent(window); // neccesary to use below functions
  gladLoadGL(glfwGetProcAddress);
  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  app->window_width = settings.width;
  app->window_height = settings.height;
  app->window = window;

  glfwSetFramebufferSizeCallback(app->window, framebuffer_size_callback);
  return EXIT_SUCCESS;
}

int app_show_frame(AppState *app){
  glfwFocusWindow(app->window);
  return EXIT_SUCCESS;
}

int app_handle_events(AppState *app){
  processInput(app->window);
  glfwSwapBuffers(app->window);
  glfwPollEvents();
  return EXIT_SUCCESS;
}

int app_should_close(AppState *app){
  return glfwWindowShouldClose(app->window);
}

int app_destroy(AppState *app){
  glfwDestroyWindow(app->window);
  // texture_delete(app->active_textures, app->active_texture_count);
  glfwTerminate();
  return EXIT_SUCCESS;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  printf("Window Framebuffer Size Callback:\t%p\n", (void *)window);
  current_app->window_width = width;
  current_app->window_height = height;
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}
