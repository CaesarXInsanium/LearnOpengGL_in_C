#pragma once
#include <GL/glew.h>

typedef struct {
  GLuint id;
  GLuint index;
} Texture;

Texture newTexture(const char*filepath, GLuint index);

void useTexture(Texture tex);
