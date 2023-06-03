#include "glad/gl.h"
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
  Window *window = newWindow(800, 800, "GLAD!");
  focusWindow(window);
  gladLoadGL(glfwGetProcAddress);

  glEnable(GL_BLEND);
  glEnable(GL_DEPTH_TEST);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Texture texture_01 = newTexture("images/alterjoan.png", 1);

  Texture texture_02 = newTexture("images/rem.png", 0);
  // Destroy data from image

  Shader *shader = Shader_new("shaders/vertex.glsl", "shaders/frag.glsl");

  // set up vertex data (and buffer(s)) and configure vertex attributes
  Geometry *cube_geometry =
      Geometry_fromGLfloatArray(36, CUBE_VERTICES, 0, NULL);
  Mesh *mesh = Mesh_fromGeometry(cube_geometry);

  // begin declaring uniforms
  Shader_use(shader); // but first declare that are using this shader

  Shader_setInt(shader, "ourTexture00", 0);
  Shader_setInt(shader, "ourTexture01", 1);

  while (!Window_shouldClose(window)) {
    Window_handleEvents(window);
    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glActiveTexture(GL_TEXTURE0);
    useTexture(texture_01);

    glActiveTexture(GL_TEXTURE1);
    useTexture(texture_02);

    // model
    mat4 model;
    glm_mat4_identity(model);
    vec3 model_axis = {0.5, 1.0, 0.0};
    double time = glfwGetTime();
    float time_float = glm_radians((float)time);
    glm_rotate(model, time_float, model_axis);

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

    Shader_use(shader);
    Shader_setMat4f(shader, "model", model);
    Shader_setMat4f(shader, "view", view);
    Shader_setMat4f(shader, "projection", projection);

    Mesh_draw(mesh);
  }

  return EXIT_SUCCESS;
}
