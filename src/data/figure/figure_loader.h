//
// Created by lkapi on 2/15/2024.
//

#ifndef EDUCATION_OPENGL_FIGURE_LOADER_H
#define EDUCATION_OPENGL_FIGURE_LOADER_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/string_utils.h"

#define MAX_PATH_LENGTH 4096

struct ini_content {
    char shader_path[MAX_PATH_LENGTH];
};

struct precircle {
    struct ini_content content;
    float center_x;
    float center_y;
    float radius;
    int num_segments;
};

struct preline {
    struct ini_content content;
    float point1_x;
    float point1_y;
    float point2_x;
    float point2_y;
};

struct prepoint {
    struct ini_content content;
    float x;
    float y;
};

struct pretriangle {
    struct ini_content content;
    float point1_x;
    float point1_y;
    float point2_x;
    float point2_y;
    float point3_x;
    float point3_y;
};

struct Shader {
    char vertex_shader[MAX_PATH_LENGTH];
    char fragment_shader[MAX_PATH_LENGTH];
};

struct precircle read_circle_ini(const char *filename);
struct preline read_line_ini(const char *filename);
struct prepoint read_point_ini(const char *filename);
struct pretriangle read_triangle_ini(const char *filename);

struct Shader read_shader_paths(const char *filename);

#endif //EDUCATION_OPENGL_FIGURE_LOADER_H
