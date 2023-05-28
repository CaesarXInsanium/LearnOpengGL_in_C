#include "mesh.h"
#include "shader.h"
#include "texture.h"
#include "window.h"
#include <GL/gl.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  Window *window = newWindow(900, 700, "GLEW!");
  focusWindow(window);
  if (glewInit() != GLEW_OK) {
    puts("Failed to Load OpenGL Context");
    return EXIT_FAILURE;
  }

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Texture texture_01 = newTexture("images/alterjoan.png", 1);

  Texture texture_02 = newTexture("images/rem.png", 0);
  // Destroy data from image

  Shader *shader = Shader_new("shaders/vertex.glsl", "shaders/frag.glsl");

  // set up vertex data (and buffer(s)) and configure vertex attributes
  float vertices[] = {
      // positions          // colors           // texture coords
      0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
      0.5f,  -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
      -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
      -0.5f, 0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f  // top left
  };

  GLuint indices[] = {0, 1, 3, 1, 2, 3};
  GLuint indexCount = 6;
  GLuint vertexCount = 4;
  GLuint perVertexValueCount = 8;

  Mesh *mesh =
      Mesh_new(vertices, indices, vertexCount, indexCount, perVertexValueCount);

  Shader_use(shader);
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
    // glBindTextureUnit(0, texture_02.id);
    // glBindTextureUnit(1, texture_01.id);

    Shader_use(shader);

    Mesh_draw(mesh, 0);
  }

  return EXIT_SUCCESS;
}
