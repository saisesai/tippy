#include <GLES3/gl3.h>
#include "GLFW/glfw3.h"

#include <iostream>

GLFWwindow *window = nullptr;

int main() {
    if (glfwInit() != GLFW_TRUE) {
        std::cerr << "failed to init glfw!" << std::endl;
        exit(-1);
    }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    window = glfwCreateWindow(1280, 720, "hello", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "failed to create window!" << std::endl;
        exit(-1);
    }

    while (!glfwWindowShouldClose(window)) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}