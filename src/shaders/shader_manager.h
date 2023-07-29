//
// Created by saintedlittle on 28.07.2023.
//

#pragma once

#ifndef EDUCATION_OPENGL_SHADER_MANAGER_H
#define EDUCATION_OPENGL_SHADER_MANAGER_H

#define MAX_SHADER_SZ 100000

#include "GL/glew.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

GLuint load_shader(char* shader_name);

void delete_shader(GLuint shader_programme);

void print_programme_info_log(GLuint programme);

GLuint create_shader_program_from_strings(const char* vertex_shader_str, const char* fragment_shader_str);

#endif //EDUCATION_OPENGL_SHADER_MANAGER_H
