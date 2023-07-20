#include "mesh.h"
#include "glad/gl.h"
#include "graphics/geometry.h"
#include "graphics/vertex.h"

#include <GLFW/glfw3.h>
#include <stdio.h>
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

  result->vao = vao;
  // this function assumes a single geometry
  result->vertex_count = geo->vertex_count;
  result->vbo = vbo;

  result->ebo = ebo;
  result->index_count = geo->index_count;

  return result;
}

int Mesh_draw(Mesh *mesh) {

  glBindVertexArray(mesh->vao); // seeing as we only have a single VAO there's
                                // no need to bind it every time, but we'll do
                                // so to keep things a bit more organized
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
  glDrawElements(GL_TRIANGLES, mesh->index_count, GL_UNSIGNED_INT, 0);
  // glDrawArrays(GL_TRIANGLES, 0, 36);
  return 0;
}
int Mesh_destroy(Mesh *mesh) {
  glDeleteBuffers(1, &mesh->vbo);
  glDeleteBuffers(1, &mesh->ebo);
  glDeleteVertexArrays(1, &mesh->vao);

  free(mesh);
  return 0;
}
