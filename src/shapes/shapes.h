#ifndef SHAPES_H
#define SHAPES_H "SHAPES_H"

#include <cglm/cglm.h>
#include "vertex_mgmt/vertex_mgmt.h"
#include <stdlib.h>

typedef struct {
    unsigned int vao;
    vec3 position;
    unsigned int triangle_count;
    unsigned int shader;
} Shape;

void shCreateShape(
    Shape* shape,
    float* vertices,
    int* indices,
    vec3 position,
    unsigned int vSize,
    unsigned int iSize,
    const char* texture,
    unsigned int shader
);
void shDrawShape(Shape* shape);

void shFreeShape(Shape* shape);

#endif