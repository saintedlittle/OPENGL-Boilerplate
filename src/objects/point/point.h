//
// Created by saintedlittle on 29.07.2023.
//

#ifndef EDUCATION_OPENGL_POINT_H
#define EDUCATION_OPENGL_POINT_H

#include "GL/glew.h"

struct point {
    GLuint vbo;
    GLuint vao;

    float coord[3];
};

struct point create_point(float x, float y);

#endif //EDUCATION_OPENGL_POINT_H
