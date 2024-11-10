// bullshit code the CXI writes
#include "app.h"
#include "graphics/geometry.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "uniform.h"
#include "app.h"

// external libraries
#include <GLFW/glfw3.h>
#include <cglm/cam.h>
#include <cglm/cglm.h>
#include <cglm/mat4.h>
#include <cglm/types.h>

// standard library
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  struct ApplicationSettings settings = {
    .width = 800,
    .height = 600,
    .name = "GLAD!"
  };

  AppState app;
  app_create(&app, settings);
  // basically calls the glfwFocusWindow
  app_show_frame(&app);

  Texture texture_01 = texture_create("images/alterjoan.png", 1);
  Texture texture_02 = texture_create("images/rem.png", 0);

  char *vertex_source = load_file_from_path("shaders/vertex.glsl");
  char *frag_source = load_file_from_path("shaders/frag.glsl");

  ShaderProgram *shader = shader_program_new(vertex_source, frag_source);

  free(vertex_source);
  free(frag_source);

  // set up vertex data (and buffer(s)) and configure vertex attributes
  Geometry *cube_geometry =
      geometry_from_array(36, CUBE_VERTICES, 0, NULL);
  Mesh *cube_mesh= mesh_from_geometry(cube_geometry);
  geometry_destroy(cube_geometry);

  // begin declaring uniforms
  shader_enable(shader); // but first declare that are using this shader

  shader_set_int(shader, "ourTexture00", 0);
  shader_set_int(shader, "ourTexture01", 1);

  while (!app_should_close(&app)) {
    app_handle_events(&app);
    // TODO: move this to app_draw_frame
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    activate_texture(texture_01);

    glActiveTexture(GL_TEXTURE1);
    activate_texture(texture_02);

    // model
    mat4 model;
    glm_mat4_identity(model);
    vec3 model_axis = {0.5, 1.0, 0.0};
    double time = glfwGetTime();
    float delta = glm_radians((float)time * 50.0);
    glm_rotate(model, delta, model_axis);

    // view
    mat4 view;
    glm_mat4_identity(view);
    vec3 direction = {0.0, 0.0, -3.0};
    glm_translate(view, direction);

    // projection
    mat4 projection;
    glm_mat4_identity(projection);
    GLfloat aspect_ratio = ((GLfloat)app.window_width / (GLfloat)app.window_height);
    glm_perspective(glm_radians(45.0), aspect_ratio, 0.1, 100.0, projection);

    // move to apply_uniform_data
    shader_enable(shader);
    shader_set_mat4f(shader, "model", model);
    shader_set_mat4f(shader, "view", view);
    shader_set_mat4f(shader, "projection", projection);

    mesh_render(cube_mesh);
  }

  mesh_destroy(cube_mesh);
  shader_destroy(shader);
  app_destroy(&app);

  return EXIT_SUCCESS;
}
