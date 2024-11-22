#pragma once
#include "GL/glew.h"
#include <GL/GL.h>

#include "GLFW/glfw3.h"
#include <vector>

class Render {
    private:
        GLuint VAO;
        GLuint VBO;
        GLuint EBO;

    public:
    Render(): VAO( 0 ), VBO( 0 ), EBO( 0 ) {
        glGenVertexArrays( 1, &this->VAO );
        glGenBuffers( 1, &this->VBO );
    }

    ~Render() {
        glDeleteVertexArrays( 1, &this->VAO );
        glDeleteBuffers( 1, &this->VBO );
    }

    void InitBuffers( const std::vector<float> &vertices ) {
        glBindVertexArray( this->VAO );
        glBindBuffer( GL_ARRAY_BUFFER, this->VBO );
        glBufferData( GL_ARRAY_BUFFER, vertices.size() * sizeof( float ), vertices.data(), GL_STATIC_DRAW );
        glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( float ), (void *)0 );
        glEnableVertexAttribArray( 0 );
        glBindBuffer( GL_ARRAY_BUFFER, 0 );  // Unbind VBO
        glBindVertexArray( 0 );  // Unbind VAO
    }

    void Draw() {
        glBindVertexArray( this->VAO );
        glDrawArrays( GL_TRIANGLES, 0, 3 );
        glBindVertexArray( 0 );
    }
};