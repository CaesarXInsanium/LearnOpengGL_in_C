#ifndef APP_H
#define APP_H

#include <stdio.h>
#include <stdlib.h>
#include <cglm/cam.h>
#include <cglm/cglm.h>
#include <cglm/mat4.h>
#include <cglm/types.h>
#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include "chunk.h"

struct UniformData{
  mat4 model;
  mat4 view;
  mat4 projection;
};

void apply_uniform_data(struct UniformData data);

struct ApplicationSettings {
  int width;
  int height;
  // is this allocated?
  char *name;
  int name_buffer_size;
};

// forward declaring to keep this private

struct AppState{
  int window_width;
  int window_height;
  GLFWwindow *window;

  GLuint voxel_mesh_vao;
  GLuint *voxel_mesh_vbos;
  int voxel_mesh_count;

  int loaded_chunk_count;
  VoxelChunkData loaded_chunks;
};

typedef struct AppState AppState;

int app_create(AppState *app, struct ApplicationSettings settings);
int app_destroy(AppState *app);

int app_draw_frame(AppState* app);
int app_show_frame(AppState *app);

int app_handle_events(AppState *app);

int app_should_close(AppState *app);

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

#endif
