#include "utils/utils.h"

void mutilsHexToRGB(vec3 vec, const char* hex) {
    if (hex[0] != '#') {
        return;
    }
    char* r = malloc(2 * sizeof(char));
    r[0] = hex[1];
    r[1] = hex[2];
    char* g = malloc(2 * sizeof(char));
    g[0] = hex[3];
    g[1] = hex[4];
    char* b = malloc(2 * sizeof(char));
    b[0] = hex[5];
    b[1] = hex[6];

    float rgbR = (float)strtol(r, NULL, 16);
    float rgbG = (float)strtol(g, NULL, 16);
    float rgbB = (float)strtol(b, NULL, 16);
    free(r); free(g); free(b);
    
    vec3 cp = { rgbR / 255.0f, rgbG / 255.0f, rgbB / 255.0f };
    glm_vec3_copy(cp, vec);
}