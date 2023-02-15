#include "mesh.h"
#include "shader.h"
#include "window.h"
#include <BMP/bmp.h>
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
  // Load Image Data using my Library
  BMP *img00 = NULL;
  BMP_init(&img00);
  int bmp_status = BMP_load_from_path(&img00, "images/minecraft_dirt.bmp");
  BMP_fexplain_err(stderr, bmp_status);

  // Upload to OpenGL
  GLuint texture00;
  /// Generate number of textures and pass array of IDs
  glGenTextures(1, &texture00);
  // texture units are defined from 0 to 15
  glActiveTexture(GL_TEXTURE0);
  glBindTexture(GL_TEXTURE_2D, texture00);

  /// Texture Options
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  if (bmp_status == BMP_SUCCESS) {

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img00->width, img00->height, 0,
                 GL_BGRA, GL_UNSIGNED_BYTE, img00->data);
    glGenerateMipmap(GL_TEXTURE_2D);
    BMP_destroy(img00);
  } else {
    fprintf(stderr, "Failed to load texture!\n");
    BMP_destroy(img00);
    return EXIT_FAILURE;
  }

  // Second texture
  BMP *img01 = NULL;
  BMP_init(&img01);
  int bmp01_status = BMP_load_from_path(&img01, "images/alterjoan.bmp");
  BMP_fexplain_err(stderr, bmp01_status);

  GLuint texture01;
  glGenTextures(1, &texture01);
  glActiveTexture(GL_TEXTURE2);
  glBindTexture(GL_TEXTURE_2D, texture01);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  if (bmp01_status == BMP_SUCCESS) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, img01->width, img01->height, 0,
                 GL_BGRA, GL_UNSIGNED_BYTE, img01->data);
    glGenerateMipmap(GL_TEXTURE_2D);
    BMP_destroy(img01);
  } else {
    fprintf(stderr, "Failed to Load Texture!\n");
    BMP_destroy(img01);
    return EXIT_FAILURE;
  }

  // Destroy data from image

  Shader *shader = Shader_new("shaders/vertex.glsl", "shaders/frag.glsl");

  // set up vertex data (and buffer(s)) and configure vertex attributes
  GLfloat vertices[] = {
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
  while (!Window_shouldClose(window)) {
    Window_handleEvents(window);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Textures to Use

    Shader_use(shader);
    Shader_setInt(shader, "ourTexture00", 0);
    Shader_setInt(shader, "ourTexture01", 1);

    glBindTexture(GL_TEXTURE_2D, texture00);
    glBindTexture(GL_TEXTURE_2D, texture01);
    Mesh_draw(mesh, 0);
  }

  return EXIT_SUCCESS;
}
