// #define STB_IMAGE_IMPLEMENTATION
// #include "window_mgmt/window_mgmt.h"
// #include "shader_mgmt/shader_mgmt.h"
// #include <cglm/cglm.h>
// #include "shaders/fragment.glsl.h"
// #include "shaders/vertex.glsl.h"
// #include "stb_image.h"
// #include "vertex_mgmt/vertex_mgmt.h"
// #include "utils/utils.h"
// #include "shapes/shapes.h"
// typedef struct {
//     vec3 position;
//     vec3 color;
// } Vertex;

// int main() {
//     vec3 darker;
//     mutilsHexToRGB(darker, "#5A492A");
//     vec3 lighter;
//     mutilsHexToRGB(lighter, "#CCA65F");
    

//     WMGMTwindow* window = wmgmtInitWindow("Title", 800, 600);
//     float vertices[] = {
//          0.0f,  0.5f,  0.0f, darker[0], darker[1], darker[2],
//          0.5f, -0.5f,  0.5f, lighter[0], lighter[1], lighter[2],
//          0.5f, -0.5f, -0.5f, lighter[0], lighter[1], lighter[2],
//         -0.5f, -0.5f, -0.5f, lighter[0], lighter[1], lighter[2],
//         -0.5f, -0.5f,  0.5f, lighter[0], lighter[1], lighter[2]
//     };
//     unsigned int indices[] = {  // note that we start from 0!
//         0, 1, 2,
//         0, 2, 3,
//         0, 3, 4,
//         0, 4, 1,
//         1, 2, 3,
//         1, 3, 4
//     };
//     unsigned int shaderProgram = smgmtCreateProgram((const char*)src_shaders_vertex_glsl, (const char*)src_shaders_fragment_glsl);
//     glUseProgram(shaderProgram);
//     // unsigned int vao = vmgmtCreateVertexArrayObject();
//     // unsigned int vbo = vmgmtCreateBufferObject();
//     // unsigned int ebo = vmgmtCreateBufferObject();
//     // vmgmtFillElementBufferObject(
//     //     vao,
//     //     ebo,
//     //     vbo,
//     //     vertices,
//     //     indices,
//     //     sizeof(vertices),
//     //     sizeof(indices)
//     // );
//     // vmgmtCreateVertexAttribPointer(0, 3, 6, 0);
//     // vmgmtCreateVertexAttribPointer(1, 2, 6, 3);
//     Shape shape;
//     shCreateShape(&shape, vertices, indices, (vec3){0.0f, 0.0f, 0.0f}, sizeof(vertices), sizeof(indices), 0, shaderProgram);

    
//     // unsigned int texture;
//     // glGenTextures(1, &texture);
//     // glBindTexture(GL_TEXTURE_2D, texture);

//     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//     // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

//     // int width, height, nrChannels;
//     // unsigned char* data = stbi_load("assets/red_brick_diff_4k.jpg", &width, &height, &nrChannels, 0);

//     // if (data) {
//     //     glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
//     //     glGenerateMipmap(GL_TEXTURE_2D);
//     // } else {
//     //     consoleError("MAIN_C", "Failed to load texture");
//     // }
//     // glUseProgram(shaderProgram);
//     // unsigned int vao = vmgmtCreateVertexArrayObject();
//     // unsigned int vbo = vmgmtCreateBufferObject();
//     // unsigned int ebo = vmgmtCreateBufferObject();
//     // vmgmtFillElementBufferObject(vao, ebo, vbo, vertices, indices, sizeof(vertices), sizeof(indices));
//     // vmgmtCreateVertexAttribPointer(0, 3, 8, 0);
//     // vmgmtCreateVertexAttribPointer(1, 3, 8, 3);
//     // vmgmtCreateVertexAttribPointer(2, 2, 8, 6);

//     mat4 model;
//     glm_mat4_identity(model);

//     mat4 view;
//     glm_mat4_identity(view);
//     glm_translate(view, (vec3){0.0f, 0.0f, -3.0f});

//     mat4 projection;
//     glm_mat4_zero(projection);
//     glm_perspective(glm_rad(45.0f), (float)window->width / (float)window->height, 0.1f, 100.0f, projection);

//     // unsigned int modelLoc      = glGetUniformLocation(shaderProgram, "model");
//     unsigned int viewLoc      = glGetUniformLocation(shaderProgram, "view");
//     unsigned int projectionLoc      = glGetUniformLocation(shaderProgram, "projection");
//     glUniformMatrix4fv(viewLoc, 1, GL_FALSE, (float*)view);
//     glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, (float*)projection);


//     float rotation = 0.5f;

//     glEnable(GL_DEPTH_TEST);

//     while (wmgmtWindowOpen(window)) {
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//         glfwPollEvents();

//         // glm_rotate(model, glm_rad(rotation), (vec3){0.0f, 1.0f, 0.0f});
//         // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, (float*)model);

//         // glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
//         shDrawShape(&shape);
//         wmgmtSwapBuffers(window);
//     }
//     wmgmtTerminate(window);
//     // stbi_image_free(data);
//     // glDeleteBuffers(1, &vbo);
//     // glDeleteVertexArrays(1, &vao);
//     shFreeShape(&shape);
//     glDeleteProgram(shaderProgram);
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main() {
    float pi = 1.0f;
    float div = 3.0f;
    int iterations = 10000000;
    for (int i = 0; i < iterations; i++) {
        pi -= 1.0f / div;
        div += 2.0f;
        pi += 1.0f / div;
        div += 2.0f;
    }
    pi *= 4;
    printf("%f", pi);
}

