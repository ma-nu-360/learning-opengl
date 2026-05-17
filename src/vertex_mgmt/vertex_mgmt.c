#include "vertex_mgmt/vertex_mgmt.h"

unsigned int vmgmtFillVertexArrayObject(unsigned int vao, unsigned int vbo, float* data, unsigned int size) {
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

unsigned int vmgmtCreateVertexArrayObject() {
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    return vao;
}

void vmgmtFillElementBufferObject(
    unsigned int vao,
    unsigned int ebo,
    unsigned int vbo,
    float*       vertices,
    int*         indices,
    unsigned int vSize,
    unsigned int iSize
) {
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vSize, vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, iSize, indices, GL_STATIC_DRAW);
}

unsigned int vmgmtCreateBufferObject() {
    unsigned int bufferObject;
    glGenBuffers(1, &bufferObject);
    return bufferObject;
}

void vmgmtCreateVertexAttribPointer(
    unsigned int index,
    unsigned int count,
    unsigned int stride,
    unsigned int offset
) {
    glVertexAttribPointer(index, count, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
    glEnableVertexAttribArray(index);
}