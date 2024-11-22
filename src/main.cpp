#include <iostream>
#include <GLFW/glfw3.h>

int main() {
  
    GLFWwindow *window = glfwCreateWindow( 480, 280, "Siemka", NULL, NULL );

    while (glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}