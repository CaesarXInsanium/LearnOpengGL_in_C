#include "graphics/geometry.h"
#include "glad/gl.h"
#include "assert.h"
#include "graphics/vertex.h"
#include <stdlib.h>

// must pass an array of GLfloats that are declare on the stack
Geometry *geometry_from_array(GLuint vertex_count,
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

void geometry_destroy(Geometry *self) {
  if (self->heap_allocated) {
    free(self->indices);
    free(self->vertices);
  }
  free(self);
}
