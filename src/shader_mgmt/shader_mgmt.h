#ifndef SHADER_MGMT_H
#define SHADER_MGMT_H "SHADER_MGMT_H"

#include "utils/utils.h"
#include <glad/glad.h>

unsigned int smgmtCreateProgram(            const char* vertexSource, const char* fragmentSource);
unsigned int smgmtCreateVertexShader(       const char* source);
unsigned int smgmtCreateFragmentShader(     const char* source);
unsigned int smgmtCreateShader(             const char* source, GLenum type);
unsigned int smgmtCreateVertexBufferObject( float* data, unsigned int vertexCount, unsigned int offset, unsigned int stride);
unsigned int smgmtCreateVertexArrayObject();
void         smgmtDeleteVertexArrayObject(  unsigned int* vao);
#endif