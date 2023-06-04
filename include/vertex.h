#ifndef VERTEX_H
#define VERTEX_H
#include <cglm/types.h>
#include <stdbool.h>
#include "glad/gl.h"
#include <cglm/vec2.h>
#include <cglm/vec3.h>
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

// assumes that all of the data is stored inside of a VBO
// will unbind vao
void Vertex_describeVerticesSingleBuffer(GLuint vao);

void Vertex_describe(GLuint vao, GLuint vbo);

typedef struct {
  bool heap_allocated;
  GLuint vertex_count;
  Vertex *vertices;
  GLuint index_count;
  GLuint *indices;
} Geometry;

Geometry *Geometry_fromGLfloatArray(GLuint vertex_count,
                                    const GLfloat *vertices, GLuint index_count,
                                    const GLuint *indices);

void Geometry_destroy(Geometry *self);

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
