//
// Created by saintedlittle on 30.07.2023.
//

#ifndef EDUCATION_OPENGL_CIRCLE_H
#define EDUCATION_OPENGL_CIRCLE_H

struct circle {
    float cx;
    float cy;
    float r;
    int num_segments;
};

struct circle create_circle(float cx, float cy, float r, int num_segments);

#endif //EDUCATION_OPENGL_CIRCLE_H
