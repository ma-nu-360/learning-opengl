#ifndef SHADER_MGMT_H
#define SHADER_MGMT_H "SHADER_MGMT_H"

#include "logger/logger.h"
#include <glad/glad.h>
#include <stdbool.h>
#include <stdlib.h>

unsigned int smgmtCreateProgram(            const char* vertexSource, const char* fragmentSource);
unsigned int smgmtCreateVertexShader(       const char* source);
unsigned int smgmtCreateFragmentShader(     const char* source);
unsigned int smgmtCreateShader(             const char* source, GLenum type);

#endif