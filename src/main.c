#include "window_mgmt/window_mgmt.h"
#include "utils/utils.h"
#include "shader_mgmt/shader_mgmt.h"
#include <cglm/cglm.h>
#include "shaders/fragment.glsl.h"
#include "shaders/vertex.glsl.h"

int main() {
    WMGMTwindow* window = wmgmtInitWindow("Title", 800, 600);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
         0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
    };

    unsigned int shaderProgram = smgmtCreateProgram((const char*)src_shaders_vertex_glsl, (const char*)src_shaders_fragment_glsl);
    if (!shaderProgram) return 1;
    unsigned int vao = smgmtCreateVertexArrayObject();
    if (!vao) return 1;
    glUseProgram(shaderProgram);
    glBindVertexArray(vao);
    unsigned int vbo = smgmtCreateVertexBufferObject(vertices, 3, 3, 6);

    mat4 model;
    glm_mat4_identity(model);

    mat4 view;
    glm_mat4_identity(view);
    glm_translate(view, (vec3){0.0f, 0.0f, -3.0f});

    mat4 projection;
    glm_mat4_zero(projection);
    glm_perspective(glm_rad(45.0f), (float)window->width / (float)window->height, 0.1f, 100.0f, projection);

    unsigned int modelLoc      = glGetUniformLocation(shaderProgram, "model");
    unsigned int viewLoc       = glGetUniformLocation(shaderProgram, "view");
    unsigned int projectionLoc = glGetUniformLocation(shaderProgram, "projection");

    glUniformMatrix4fv(modelLoc,      1, GL_FALSE, (float*)model);
    glUniformMatrix4fv(viewLoc,       1, GL_FALSE, (float*)view);
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, (float*)projection);

    float rotation = 0.5f;

    while (wmgmtWindowOpen(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();

        glm_rotate(model, glm_rad(rotation += 0.001f), (vec3){0.0f, 1.0f, 0.0f});
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (float*)model);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        wmgmtSwapBuffers(window);
    }
    wmgmtTerminate(window);
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
    glDeleteProgram(shaderProgram);
    return 0;
}