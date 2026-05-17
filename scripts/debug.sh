#!/bin/sh
for file in src/shaders/*.glsl; do
    xxd -i "$file" > "$file.h"
done
cmake -B build
cmake --build build
build/MyOpenGLApp