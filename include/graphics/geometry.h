#ifndef GEOMETRY_H
#define GEOMETRY_H
#include <stdbool.h>
#include "glad/gl.h"
#include "graphics/vertex.h"

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
#endif
