#ifndef VERTEX_MGMT_H
#define VERTEX_MGMT_H "VERTEX_MGMT_H"

#include <glad/glad.h>
#include <stdlib.h>

unsigned int vmgmtFillVertexArrayObject(
    //////////////////
    unsigned int vao,
    unsigned int vbo,
    float*       data,
    unsigned int size
    //////////////////
);

unsigned int vmgmtCreateVertexArrayObject();

unsigned int vmgmtCreateBufferObject();

void         vmgmtFillElementBufferObject(
    //////////////////////
    unsigned int vao,
    unsigned int ebo,
    unsigned int vbo,
    float*       vertices,
    int*         indices,
    unsigned int vSize,
    unsigned int iSize
    //////////////////////
);

void         vmgmtCreateVertexAttribPointer(
    ////////////////////
    unsigned int index,
    unsigned int count,
    unsigned int stride,
    unsigned int offset
    ////////////////////
);

#endif