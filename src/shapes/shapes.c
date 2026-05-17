#include "shapes/shapes.h"
#include "shapes.h"

void shCreateShape(
    Shape* shape,
    float* vertices,
    int* indices,
    vec3 position,
    unsigned int vSize,
    unsigned int iSize,
    const char* texture,
    unsigned int shader
) {
    unsigned int vao = vmgmtCreateVertexArrayObject();
    unsigned int vbo = vmgmtCreateBufferObject();
    unsigned int ebo = vmgmtCreateBufferObject();
    vmgmtFillElementBufferObject(
        vao,
        ebo,
        vbo,
        vertices,
        indices,
        vSize,
        iSize
    );
    int stride = 3;
    if (texture) stride += 2;
    else stride += 3;
    vmgmtCreateVertexAttribPointer(0, 3, stride, 0);
    if (texture) {
        vmgmtCreateVertexAttribPointer(1, 2, stride, 3);
    } else {
        vmgmtCreateVertexAttribPointer(1, 3, stride, 3);
    }

    shape->vao = vao;
    printf("VAO: %i", vao);
    shape->shader = shader;
    shape->triangle_count = iSize / sizeof(int);
    printf("COUNT: %i", shape->triangle_count);
    glm_vec3_copy(position, shape->position);
}

void shDrawShape(Shape* shape) {
    glUseProgram(shape->shader);
    glBindVertexArray(shape->vao);
    unsigned int modelLoc = glGetUniformLocation(shape->shader, "model");
    mat4 model;
    glm_mat4_identity(model);
    //glm_translate(model, shape->position);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (float*)model);
    glDrawElements(GL_TRIANGLES, shape->triangle_count, GL_UNSIGNED_INT, 0);
}
void shFreeShape(Shape *shape) {
    glDeleteVertexArrays(1, &shape->vao);
}