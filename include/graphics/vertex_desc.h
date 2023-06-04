#pragma once
#include "glad/gl.h"
#include "graphics/vertex.h"
#include <stddef.h>

#define ADDR(value) ((void *)value)

typedef struct {
  // associated vertex buffer object to associate with the VertexDescEntry
  GLuint vbo;
  // number of values inside the vertex entry, example 3 floats for the color
  GLuint value_count;
  // use the glad bindings to define this
  GLenum type;
} VertexDescEntry;

VertexDescEntry vertex_entry(GLuint vbo, GLuint value_count, GLenum type);
void vertex_describe_gl(GLuint vao, VertexDescEntry entries[], size_t count);
