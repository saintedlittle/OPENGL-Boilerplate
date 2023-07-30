//
// Created by saintedlittle on 29.07.2023.
//

#pragma once

#ifndef EDUCATION_OPENGL_DRAW_MANAGER_H
#define EDUCATION_OPENGL_DRAW_MANAGER_H

#include "../shaders/shader_manager.h"

#include "../objects/triangle/triangle.h"
#include "../objects/point/point.h"
#include "../objects/line/line.h"
#include "../objects/circle/circle.h"

void initialize_shaders();

void draw_point(struct point my_point);

void draw_line(struct line myLine);

void draw_triangle(struct triangle my_triangle);

void draw_circle(struct circle my_circle);

void drawFilledSun(struct circle my_circle, int color[3]);

#endif //EDUCATION_OPENGL_DRAW_MANAGER_H
