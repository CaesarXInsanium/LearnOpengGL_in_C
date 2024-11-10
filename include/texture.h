#pragma once
#include "glad/gl.h"

typedef struct {
  GLuint id;
  GLuint index;
} Texture;

Texture texture_create(const char*filepath, GLuint index);

void activate_texture(Texture tex);
