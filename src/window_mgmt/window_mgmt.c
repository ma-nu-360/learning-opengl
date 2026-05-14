#ifndef WINDOW_MGMT_H
#define WINDOW_MGMT_H "window_mgmt.h"

#include "window_mgmt/window_mgmt.h"

void framebufferSizeCallback(GLFWwindow* glfwWindow, int width, int height) {
    WMGMTwindow* window = glfwGetWindowUserPointer(glfwWindow);
    window->width = width;
    window->height = height;
    glViewport(0, 0, width, height);
}

WMGMTwindow* wmgmtInitWindow(const char* title, int width, int height) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    WMGMTwindow* window = malloc(sizeof(WMGMTwindow));
    window->window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (window->window == NULL) {
        consoleError(WINDOW_MGMT_H, "Window creation failed!");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window->window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        consoleError(WINDOW_MGMT_H, "Initializing GLAD failed!");
        return NULL;
    }

    glViewport(0, 0, width, height);
    window->width = width;
    window->height = height;
    glfwSetWindowUserPointer(window->window, window);
    glfwSetFramebufferSizeCallback(window->window, framebufferSizeCallback);
    return window;
}

bool wmgmtWindowOpen(WMGMTwindow *window) {
    return !glfwWindowShouldClose(window->window);
}

void wmgmtSwapBuffers(WMGMTwindow* window) {
    glfwSwapBuffers(window->window);
}

void wmgmtTerminate(WMGMTwindow* window) {
    free(window);
    window = NULL;
    glfwTerminate();
}

#endif
