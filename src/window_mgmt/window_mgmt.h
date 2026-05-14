#include "logger/logger.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    GLFWwindow* window;
    int width;
    int height;
} WMGMTwindow;

void         framebufferSizeCallback( GLFWwindow* window, int width, int height);

WMGMTwindow* wmgmtInitWindow(         const char* title, int width, int height);

bool         wmgmtWindowOpen(         WMGMTwindow* window);

void         wmgmtSwapBuffers(        WMGMTwindow* window);

void         wmgmtTerminate(          WMGMTwindow* window);
