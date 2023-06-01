#ifndef GRAPHICS_VERTEX_H
#define GRAPHICS_VERTEX_H
#include "glad/gl.h"
#include <GLFW/glfw3.h>

// Describes How Data is Organized in Array Sent to Graphics Card
// Assumes Vertex, Color and Texture Coords
typedef struct VertexDesc_ {
  GLuint type;  
  GLint vertexes;
  GLint colors;
} VertexDesc;

#endif
