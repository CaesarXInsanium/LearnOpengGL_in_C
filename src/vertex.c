#include "vertex.h"
#include "glad/gl.h"
#include "graphics/vertex_desc.h"
#include <stdlib.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void Vertex_describe(GLuint vao, GLuint vbo){
  VertexDescEntry entries[3];
  entries[0] = (VertexDescEntry){
    .vbo = vbo,
    .value_count = 3,
    .type = GL_FLOAT
  };

  entries[1] = (VertexDescEntry){
    .vbo = vbo,
    .value_count = 3,
    .type = GL_FLOAT
  };

  entries[2] = (VertexDescEntry){
    .vbo = vbo,
    .value_count = 2,
    .type = GL_FLOAT
  };
  vertex_describe_gl(vao, entries, 3);  
}

void Vertex_describeVerticesSingleBuffer(GLuint vao) {
  size_t vertex_stride = sizeof(Vertex);
  printf("Size of Vertex: %lu\n", vertex_stride);
  glBindVertexArray(vao);

  // vertex data
  size_t vertex_offset = 0 * sizeof(GLfloat);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertex_stride,
                        (void *)vertex_offset);
  glEnableVertexAttribArray(0);

  // Color Data
  size_t color_offset = 3 * sizeof(GLfloat);
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertex_stride,
                        (void *)color_offset);
  glEnableVertexAttribArray(1);

  // Texture Data
  size_t texture_offset = 6 * sizeof(GLfloat);
  glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertex_stride,
                        (void *)texture_offset);
  glEnableVertexAttribArray(2);
}

GLuint *gen_indices_from_vertex_count(GLuint vertex_count) {
  GLuint *result = calloc(vertex_count, sizeof(GLuint));
  for (GLuint i = 0; i < vertex_count; i++) {
    result[i] = i;
  }
  return result;
}
// must pass an array of GLfloats that are declare on the stack
Geometry *Geometry_fromGLfloatArray(GLuint vertex_count,
                                    const GLfloat vertices[],
                                    GLuint index_count,
                                    const GLuint indices[]) {
  Geometry *result = calloc(1, sizeof(Geometry));
  assert((vertex_count * sizeof(GLfloat) * FLOATS_IN_VERTEX) == sizeof(Vertex) * vertex_count);

  result->vertex_count = vertex_count;
  result->vertices = (Vertex *)vertices;
  if (index_count == 0) {
    result->index_count = vertex_count;
    result->indices = gen_indices_from_vertex_count(vertex_count);
  } else {
    result->index_count = index_count;
    result->indices = (GLuint *)indices;
  }
  result->heap_allocated = false;
  return result;
}

void Geometry_destroy(Geometry *self) {
  if (self->heap_allocated) {
    free(self->indices);
    free(self->vertices);
  }
  free(self);
}
