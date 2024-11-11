
#ifndef VERTEX_H
#define VERTEX_H

#include "glad/gl.h"
#include <stdbool.h>

typedef struct {
  GLfloat x;
  GLfloat y;
} GLVec2;

typedef struct {
  GLfloat x;
  GLfloat y;
  GLfloat z;
} GLVec3;

typedef struct {
  GLVec3 pos;
  GLVec3 color;
  GLVec2 tex;
} Vertex;

static const GLuint FLOATS_IN_VERTEX = 8;

void Vertex_describe(GLuint vao, GLuint vbo);

GLuint *gen_indices_from_vertex_count(GLuint vertex_count);

static const GLfloat CUBE_VERTICES[] = {
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.5f,  -0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  -0.5f, 0.0f,
    0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,
    1.0f,  1.0f,  -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  0.0f,

    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,  0.5f,  -0.5f,
    0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  1.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,

    -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  -0.5f, 0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,
    0.0f,  0.0f,  0.0f,  1.0f,  -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
    0.0f,  1.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,
    0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,
    0.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  1.0f,  0.0f,

    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  -0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  -0.5f, 0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  -0.5f, -0.5f, 0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, -0.5f, -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,

    -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f,  0.5f,  0.5f,
    -0.5f, 0.0f,  0.0f,  0.0f,  1.0f,  1.0f,  0.5f,  0.5f,  0.5f,  0.0f,
    0.0f,  0.0f,  1.0f,  0.0f,  0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  0.0f,
    1.0f,  0.0f,  -0.5f, 0.5f,  0.5f,  0.0f,  0.0f,  0.0f,  0.0f,  0.0f,
    -0.5f, 0.5f,  -0.5f, 0.0f,  0.0f,  0.0f,  0.0f,  1.0f};

#endif
