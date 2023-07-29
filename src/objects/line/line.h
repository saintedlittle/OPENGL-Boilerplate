//
// Created by saintedlittle on 29.07.2023.
//

#ifndef EDUCATION_OPENGL_LINE_H
#define EDUCATION_OPENGL_LINE_H

#include "GL/glew.h"

#include "../point/point.h"

struct line {
    GLuint vbo;
    GLuint vao;

    GLfloat vertices[6];
};

struct line create_line(struct point first, struct point second);

#endif //EDUCATION_OPENGL_LINE_H
