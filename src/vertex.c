#include "glad/gl.h"
#include "graphics/vertex.h"
#include "graphics/vertex_desc.h"
#include "graphics/geometry.h"
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

GLuint *gen_indices_from_vertex_count(GLuint vertex_count) {
  GLuint *result = calloc(vertex_count, sizeof(GLuint));
  for (GLuint i = 0; i < vertex_count; i++) {
    result[i] = i;
  }
  return result;
}
