#include "glad/gl.h"
#include "graphics/vertex_desc.h"
#include "graphics/vertex.h"
#include <stdlib.h>

size_t gl_type_size(GLenum type){
  switch (type){
    case GL_FLOAT:
      return sizeof(GLfloat);
      break;
    case GL_UNSIGNED_INT:
      return sizeof(GLuint);
    default:
      return 0;
  }
}

VertexDescEntry vertex_entry(GLuint vbo, GLuint value_count,
                                      GLenum type) {
  VertexDescEntry result;
  result.type = type;
  result.vbo = vbo;
  result.value_count = value_count;
  return result;
}

void vertex_describe_gl(GLuint vao, VertexDescEntry entries[], size_t count){
  glBindVertexArray(vao);
  size_t vertex_stride = sizeof(Vertex);
  size_t offset = 0;
  for(size_t i = 0; i < count; i++){
    VertexDescEntry entry = entries[i];
    glVertexAttribPointer(i, entry.value_count, entry.type, GL_FALSE, vertex_stride, ADDR(offset)); 
    glEnableVertexAttribArray(i);
    offset = offset + (entry.value_count * gl_type_size(entry.type));
  }
}

