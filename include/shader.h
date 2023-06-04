#ifndef SHADER_H
#define SHADER_H

#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <cglm/types.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Shader_ {
  GLuint ID;
} Shader;

// will consume the cstrings and free them
Shader *Shader_new(char *vertex_source, char *frag_source);

int Shader_destroy(Shader *self);

void Shader_use(Shader *self);

void Shader_setBool(Shader *self, const char *name, bool value);
void Shader_setFloat(Shader *self, const char *name, GLfloat value);
void Shader_setInt(Shader *self, const char *name, GLint value);

void Shader_setMat4f(Shader *self, const char *name, mat4 mat);

// stolen from:
// https://stackoverflow.com/questions/2029103/correct-way-to-read-a-text-file-into-a-buffer-in-c
char *load_file_from_path(const char *path);
GLuint GLShaderProgram_fromChar(const char *vertexShader,
                                const char *fragmentShader);

#endif
