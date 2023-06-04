#include "mesh.h"
#include "glad/gl.h"
#include "vertex.h"
#include <GLFW/glfw3.h>
#include <stdlib.h>


Mesh *Mesh_fromGeometry(Geometry *geo) {
  Mesh *result = calloc(1, sizeof(Mesh));

  GLuint vbo, ebo, vao;
  glGenVertexArrays(1, &vao);
  glGenBuffers(1, &vbo);
  glGenBuffers(1, &ebo);

  glBindVertexArray(vao);

  glBindBuffer(GL_ARRAY_BUFFER, vbo);

  glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * geo->vertex_count,
               geo->vertices, GL_STATIC_DRAW);

  // bind Element array buffer inside of VAO in order to link the two of them
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * geo->index_count,
               geo->indices, GL_STATIC_DRAW);

  // describe the vertex data
  // Vertex_describeVerticesSingleBuffer(vao);
  Vertex_describe(vao, vbo);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  result->VAO = vao;
  // this function assumes a single geometry
  result->vertex_buffer_count = 1;
  GLuint *vbos = calloc(result->vertex_buffer_count, sizeof(GLuint));
  vbos[0] = vbo;

  result->ebo = ebo;
  result->index_count = geo->index_count;

  result->instance_count = 1;
  // unused value
  result->instance_uniforms = NULL;

  return result;
}

int Mesh_draw(Mesh *mesh) {

  glBindVertexArray(mesh->VAO); // seeing as we only have a single VAO there's
                                // no need to bind it every time, but we'll do
                                // so to keep things a bit more organized
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
  glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_INT, 0);
  //glDrawArrays(GL_TRIANGLES, 0, 36);
  return 0;
}
int Mesh_destroy(Mesh *mesh) {
  for(size_t i = 0; i < mesh->vertex_buffer_count; i++){
    glDeleteBuffers(1, &mesh->vbos_array[i]);
  }
  free(mesh->vbos_array);
  glDeleteVertexArrays(1, &mesh->VAO);
  glDeleteBuffers(1, &mesh->ebo);

  free(mesh);
  return 0;
}
