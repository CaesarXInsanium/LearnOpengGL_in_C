#ifndef MESH_H
#define MESH_H
#include "glad/gl.h"
#include "graphics/geometry.h"
#include "graphics/vertex.h"
#include <GLFW/glfw3.h>

// This struct represents an individual thing that can be draw by my engine. A
// model or a scene or a skybox or something. All the data has already been
// uploaded to GPU
typedef struct {
  GLuint vao;

  // IDs are stored in a heap allocated buffer
  size_t vertex_count;
  GLuint vbo;

  GLuint ebo;
  GLuint index_count;
} Mesh;

Mesh *Mesh_fromGeometry(Geometry *geo);

int Mesh_draw(Mesh *mesh);
int Mesh_destroy(Mesh *mesh);

#endif
