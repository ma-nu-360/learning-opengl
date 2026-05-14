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

unsigned int smgmtCreateVertexBufferObject(float* data, unsigned int vertexCount, unsigned int offset, unsigned int stride) {
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * stride * vertexCount, data, GL_STATIC_DRAW);

    glVertexAttribPointer(0, vertexCount, GL_FLOAT, GL_FALSE, stride * sizeof(float), NULL);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, vertexCount, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(1);
    return vbo;
}

unsigned int smgmtCreateVertexArrayObject() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    return vao;
}
