#include "shader_mgmt.h"

unsigned int smgmtCreateProgram(const char* vertexSource, const char* fragmentSource) {
    unsigned int shaderProgram = glCreateProgram();
    unsigned int vertexShader = smgmtCreateVertexShader(vertexSource);
    unsigned int fragmentShader = smgmtCreateFragmentShader(fragmentSource);

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    int success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        consoleError(SHADER_MGMT_H, (const char*)infoLog);
        shaderProgram = 0;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

unsigned int smgmtCreateVertexShader(   const char* source) {
    return smgmtCreateShader(source, GL_VERTEX_SHADER);
}

unsigned int smgmtCreateFragmentShader( const char* source) {
    return smgmtCreateShader(source, GL_FRAGMENT_SHADER);
}

unsigned int smgmtCreateShader(         const char* source, GLenum type) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        consoleError(SHADER_MGMT_H, (const char*)infoLog);
        return -1;
    }
    return shader;
}
