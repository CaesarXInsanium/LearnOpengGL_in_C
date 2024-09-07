#ifndef MESH_H
#define MESH_H
#include "glad/gl.h"
#include "graphics/geometry.h"
#include "graphics/vertex.h"
#include <GLFW/glfw3.h>

// This struct represents an individual thing that can be draw by my engine. A
// model or a scene or a skybox or something. All the data has already been
// uploaded to GPU
// attribution between index sets and meshes must be done seperatly
typedef struct {
  GLuint vao;

  // IDs are stored in a heap allocated buffer
  size_t vertex_count;
  GLuint vbo;

  GLuint ebo;
  GLuint index_count;

  GLuint instance_count;
} Mesh;

Mesh *mesh_from_geometry(Geometry *geo);

// simple call to glDrawArrays
int mesh_render(Mesh *mesh);

// uses a specified set of indices. simply, the entire buffer contains all the frame
// of an animation. a set of indices would select from buffer the select vertices
// for a select animation.
int mesh_render_with_indices(Mesh *mesh, GLuint ebo);

// basically we must already have plans for the number of instances from within
// the shader. a array must already be predetermined
// this function will use glDrawElementsInstanced internally
int mesh_render_instances(Mesh *mesh, int instance_count);
int mesh_destroy(Mesh *mesh);

#endif
