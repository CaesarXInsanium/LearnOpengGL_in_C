#include "glad/gl.h"
#include "graphics/geometry.h"
#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "uniform.h"
#include "window.h"
#include <GLFW/glfw3.h>
#include <cglm/cam.h>
#include <cglm/cglm.h>
#include <cglm/mat4.h>
#include <cglm/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Window *window = create_window(800, 800, "GLAD!");
  focus_window(window);

  Texture texture_01 = create_texture("images/alterjoan.png", 1);
  Texture texture_02 = create_texture("images/rem.png", 0);

  char *vertex_source = load_file_from_path("shaders/vertex.glsl");
  char *frag_source = load_file_from_path("shaders/frag.glsl");

  ShaderProgram *shader = shader_program_new(vertex_source, frag_source);

  free(vertex_source);
  free(frag_source);

  // set up vertex data (and buffer(s)) and configure vertex attributes
  Geometry *cube_geometry =
      geometry_from_array(36, CUBE_VERTICES, 0, NULL);
  Mesh *mesh = mesh_from_geometry(cube_geometry);
  geometry_destroy(cube_geometry);

  // begin declaring uniforms
  shader_enable(shader); // but first declare that are using this shader

  shader_set_int(shader, "ourTexture00", 0);
  shader_set_int(shader, "ourTexture01", 1);

  while (!window_should_close(window)) {
    window_handle_events(window);
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
    GLfloat aspect_ratio = ((GLfloat)window->width / (GLfloat)window->height);
    glm_perspective(glm_radians(45.0), aspect_ratio, 0.1, 100.0, projection);

    shader_enable(shader);
    shader_set_mat4f(shader, "model", model);
    shader_set_mat4f(shader, "view", view);
    shader_set_mat4f(shader, "projection", projection);

    mesh_render(mesh);
  }

  mesh_destroy(mesh);
  shader_destroy(shader);
  window_destroy(window);

  return EXIT_SUCCESS;
}
