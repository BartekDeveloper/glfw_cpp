#pragma once

#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <vector>

#include "classes/game.cpp"
#include "classes/render.cpp"

void Loop(Render render, double delta, double fps) {
    glClearColor(
        1,
        1,
        1,
        1
    );
    printf("*** DELTA: %.1f  |  FPS: %.f ***\n", delta * 1000, fps);

    render.Draw();
}

int main() {

    if( !glfwInit() ) {
        std::cout << "Failed to initialize GLFW\n\n\n";
        return -1;
    }

    Game game( 720, 240, "Hello World!");

    if( !game.CreateWindow() ) {
        glfwTerminate();
        return -3;
    }

    GLenum err = glewInit();
    if( err != GLEW_OK ) {
        std::cout << "Failed to initialize GLEW: " << glewGetErrorString( err ) << "\n\n\n";
        glfwTerminate();
        return -2;
    }

    std::vector<float> verticies = {
        1, .5, 1,
        0, 0, 1,
        0, 1, 1
    };

    Render render;
    render.InitBuffers( verticies );

    game.GameLoop( Loop );
    
    glfwTerminate();
    return 0;
}