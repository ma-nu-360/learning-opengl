cmake_minimum_required(VERSION 3.10)

project(MyOpenGLApp C)

file(GLOB MyCSources  src/*/*.c)

add_executable(MyOpenGLApp
    ${MyCSources}
    src/glad.c
    src/main.c
)

target_include_directories(MyOpenGLApp PRIVATE
    include
    src
)

target_link_directories(MyOpenGLApp PRIVATE
    lib
)

find_package(glfw3 REQUIRED)


target_link_libraries(MyOpenGLApp
    glfw
    GL
    m
)