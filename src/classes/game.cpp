#pragma once
#include <GL/glew.h>
#include <GL/GL.h>
#include <GLFW/glfw3.h>
#include <ctime>
#include <iostream>
#include <string>
#include "render.cpp"

class Game {
 

 private:
  GLFWwindow *window;
  int width, height;
  std::string title;
  bool vsync, hiDpi;
  GLFWmonitor *monitor;
  GLFWwindow *share;

    public:
    Game( int width, int height, const std::string &title, bool vsync = true,
         bool hiDpi = false, GLFWmonitor *monitor = nullptr,
         GLFWwindow *share = nullptr )
        : width( width ),
        height( height ),
        title( title ),
        vsync( vsync ),
        hiDpi( hiDpi ),
        monitor( monitor ),
        share( share ) {}
    ~Game() {
        this->DestroyWindow();
    }

    bool CreateWindow() {
        glfwWindowHint( GLFW_VERSION_MAJOR, 4 );
        glfwWindowHint( GLFW_VERSION_MINOR, 3 );
        glfwWindowHint( GLFW_OPENGL_ANY_PROFILE, GLFW_OPENGL_CORE_PROFILE );

        window = glfwCreateWindow( width, height, title.c_str(), monitor, share );
        if( !window ) {
            std::cerr << "Failed to create GLFW window\n";
            return false;
        }
        glfwMakeContextCurrent( window );

        return true;
    }

    void ChangeVsync() {
        this->vsync = !this->vsync;
        glfwSwapInterval( ( vsync ) ? 1 : 0 );
    }

    bool GetVsync() {
        return this->vsync;
    }

    void GameLoop( void ( *Loop )(Render render, double delta, double fps) ) {
       
        double deltaTime = 0;
        double lastTime = glfwGetTime();
        float fps = 0, lastFps = 0;

        while( !glfwWindowShouldClose( window ) ) {
            double currTime = glfwGetTime();
            deltaTime = currTime - lastTime;
            lastTime = currTime;
            if (deltaTime != 0) fps = (1.0f / (float)deltaTime);
            glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

            Loop( render, deltaTime, fps);

            glfwSwapBuffers( window );
            glfwPollEvents();
        }
    }

    void DestroyWindow() { glfwDestroyWindow( window ); }
};