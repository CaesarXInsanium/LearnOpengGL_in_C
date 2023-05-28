#include <cglm/types.h>
#ifndef VERTEX_H
#include <GL/glew.h>
#include <cglm/vec3.h>
#include <cglm/vec2.h>
#define VERTEX_H

typedef struct {
  vec3 pos;
  vec3 color;
  vec2 text_coord;
} Vertex;

#endif
