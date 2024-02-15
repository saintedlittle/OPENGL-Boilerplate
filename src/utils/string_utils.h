//
// Created by saintedlittle on 28.07.2023.
//

#ifndef EDUCATION_OPENGL_STRING_UTILS_H
#define EDUCATION_OPENGL_STRING_UTILS_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../logger/logger.h"

#define OPEN_FILE_AND_CHECK(filename) \
    FILE *file = fopen(filename, "r"); \
    if (file == NULL) { \
        perror("Error opening file"); \
        exit(EXIT_FAILURE); \
    }


char* sum_string(char* first, char* two) {
    size_t len_shader_name = strlen(first);
    size_t len_additional_line = strlen(two);

    char* modified_shader_name = (char*)malloc(len_shader_name + len_additional_line + 1);
    if (!modified_shader_name) {
        gl_log_err("Memory allocation error!\n");

        return NULL;
    }

    sprintf(modified_shader_name, "%s%s", first, two);

    return modified_shader_name;
}

#endif //EDUCATION_OPENGL_STRING_UTILS_H
