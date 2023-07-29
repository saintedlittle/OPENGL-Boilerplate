//
// Created by saintedlittle on 29.07.2023.
//

#ifndef EDUCATION_OPENGL_DRAW_MANAGER_H
#define EDUCATION_OPENGL_DRAW_MANAGER_H

#include "../shaders/shader_manager.h"

#include "../objects/triangle/triangle.h"
#include "../objects/point/point.h"
#include "../objects/line/line.h"

#define M_PI 3.14
#include "math.h"

void initialize_shaders();

void draw_point(struct point my_point);

void draw_line(struct point first, struct point second);

void draw_triangle(struct triangle my_triangle);

void draw_circle(float centerX, float centerY, float radius, int numPoints);

#endif //EDUCATION_OPENGL_DRAW_MANAGER_H
