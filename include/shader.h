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
} ShaderProgram;

// will consume the cstrings and free them
ShaderProgram *shader_program_new(char *vertex_source, char *frag_source);

int shader_destroy(ShaderProgram *self);

void shader_enable(ShaderProgram *self);

void shader_set_bool(ShaderProgram *self, const char *name, bool value);
void shader_set_float(ShaderProgram *self, const char *name, GLfloat value);
void shader_set_int(ShaderProgram *self, const char *name, GLint value);

void shader_set_mat4f(ShaderProgram *self, const char *name, mat4 mat);

// stolen from:
// https://stackoverflow.com/questions/2029103/correct-way-to-read-a-text-file-into-a-buffer-in-c
char *load_file_from_path(const char *path);
GLuint shader_program_from_chararray(const char *vertexShader,
                                     const char *fragmentShader);

GLuint compile_shader_object(const char *source, GLenum shader_type);
GLuint link_shader_program(GLuint *objects, GLuint count);

#endif
