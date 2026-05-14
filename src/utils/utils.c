#include "utils/utils.h"

char* mutilsReadFile(const char* location) {
    FILE* fptr = fopen(location, "r");
    if (!fptr) {
        consoleError(M_UTILS_H, "Failed to open file!");
        return NULL;
    }
    size_t capacity = 1024;
    size_t length = 0;
    char* content = malloc(capacity);
    int c;
    while ((c = fgetc(fptr)) != EOF) {
        if (length > capacity) {
            capacity *= 2;
            char* resize = realloc(content, capacity);
            if (!resize) {
                consoleError(M_UTILS_H, "Failed to allocate resize content!");
                free(content);
                return NULL;
            }
            content = resize;
        }
        content[length++] = (char)c;
    }
    char* resize = realloc(content, sizeof(char) * length);
    if (!resize) {
        consoleError(M_UTILS_H, "Failed to allocate resize content!");
        free(content);
        return NULL;
    }
    content = resize;
    return content;
}