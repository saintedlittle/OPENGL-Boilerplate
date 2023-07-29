//
// Created by saintedlittle on 28.07.2023.
//

#ifndef EDUCATION_OPENGL_TRIANGLE_H
#define EDUCATION_OPENGL_TRIANGLE_H

#include "GL/glew.h"

struct triangle {
    GLuint vbo;
    GLuint vao;

    float points[9];

};

struct triangle create_triangle(const float points[9]);

#endif //EDUCATION_OPENGL_TRIANGLE_H
