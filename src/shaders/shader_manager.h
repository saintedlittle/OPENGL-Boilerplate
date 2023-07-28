//
// Created by saintedlittle on 28.07.2023.
//

#ifndef EDUCATION_OPENGL_SHADER_MANAGER_H
#define EDUCATION_OPENGL_SHADER_MANAGER_H

#include "GL/glew.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLuint load_shader(char* shader_name);

void delete_shader(GLuint shader_programme);

bool check_compile_errors(GLuint index);
bool check_link_errors(GLuint programme);

void print_shader_info_log(GLuint shader_index);
void print_programme_info_log(GLuint programme);

#endif //EDUCATION_OPENGL_SHADER_MANAGER_H
