#include "shader.h"
#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <assert.h>
#include <cglm/mat4.h>
#include <stdio.h>

Shader *Shader_new(char *vertex_source, char *frag_source) {
  Shader *self = (Shader *)malloc(sizeof(Shader));

  GLuint shader_program =
      shader_program_from_chararray(vertex_source, frag_source);
  self->ID = shader_program;
  return self;
}
int Shader_destroy(Shader *self) {
  glDeleteProgram(self->ID);
  free(self);
  return EXIT_SUCCESS;
}

void Shader_use(Shader *self) { glUseProgram(self->ID); }

void Shader_setFloat(Shader *self, const char *name, GLfloat value) {
  glUniform1f(glGetUniformLocation(self->ID, name), value);
}
void Shader_setInt(Shader *self, const char *name, GLint value) {
  glUniform1i(glGetUniformLocation(self->ID, name), value);
}

void Shader_setMat4f(Shader *self, const char *name, mat4 mat) {
  glUniformMatrix4fv(glGetUniformLocation(self->ID, name), 1, GL_FALSE,
                     (float *)mat);
}

char *load_file_from_path(const char *path) {
  char *source = NULL;
  FILE *fp = fopen(path, "r");
  if (fp != NULL) {
    /* Go to the end of the file. */
    if (fseek(fp, 0L, SEEK_END) == 0) {
      /* Get the size of the file. */
      long bufsize = ftell(fp);
      if (bufsize == -1) { /* Error */
      }
      /* Allocate our buffer to that size. */
      source = malloc(sizeof(char) * (bufsize + 1));
      /* Go back to the start of the file. */
      if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */
      }

      /* Read the entire file into memory. */
      size_t newLen = fread(source, sizeof(char), bufsize, fp);
      if (ferror(fp) != 0) {
        fputs("Error reading file", stderr);
      } else {
        source[newLen++] = '\0'; /* Just to be safe. */
      }
    }
    fclose(fp);
  }

  return source;
}

GLuint shader_program_from_chararray(const char *vertex_source,
                                     const char *frag_source) {

  GLuint vertex_shader_object =
      compile_shader_object(vertex_source, GL_VERTEX_SHADER);
  GLuint frag_shader_object =
      compile_shader_object(frag_source, GL_FRAGMENT_SHADER);

  // link shaders
  GLuint objects[] = {vertex_shader_object, frag_shader_object};
  GLuint shader_program = link_shader_program(objects, 2);

  glDeleteShader(vertex_shader_object);
  glDeleteShader(frag_shader_object);
  return shader_program;
}

GLuint compile_shader_object(const char *source, GLenum shader_type) {
  GLuint result_shader = glCreateShader(shader_type);
  glShaderSource(result_shader, 1, &source, NULL);
  glCompileShader(result_shader);

  int success;
  char info_log[512];

  glGetShaderiv(result_shader, GL_COMPILE_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(result_shader, 512, NULL, info_log);
    fprintf(stderr, "Error failed to compile shader with source: \n%s\n",
            source);
  }

  return result_shader;
}

GLuint link_shader_program(GLuint *objects, GLuint count) {
  GLuint shader_program = glCreateProgram();
  for (GLuint i = 0; i < count; i++) {
    GLuint shader_object = objects[i];
    glAttachShader(shader_program, shader_object);
  }

  glLinkProgram(shader_program);

  int success;
  char info_log[512];

  glGetProgramiv(shader_program, GL_LINK_STATUS, &success);

  if (!success) {
    glGetShaderInfoLog(shader_program, 512, NULL, info_log);
    fprintf(stderr, "Error failed to link shader\n");
  }
  return shader_program;
}
