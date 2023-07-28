//
// Created by saintedlittle on 28.07.2023.
//

#include "shader_manager.h"
#include "../utils/string_utils.h"

char* read_shader_source(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open shader file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* source = (char*)malloc(length + 1);
    if (!source) {
        fclose(file);
        fprintf(stderr, "Memory allocation error\n");
        return NULL;
    }

    fread(source, 1, length, file);
    source[length] = '\0';
    fclose(file);
    return source;
}

static char* fragment_source;
static char* vertex_source;

GLuint load_shader(char* shader_name) {
    const char* fragment_filename = sum_string(shader_name, "_fragment.glsl");
    const char* vertex_filename = sum_string(shader_name, "_vertex.glsl");

    vertex_source = read_shader_source(vertex_filename);
    if (!vertex_source) {
        return 1;
    }

    fragment_source = read_shader_source(fragment_filename);
    if (!fragment_source) {
        return 1;
    }

    GLuint vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vs, 1, &vertex_source, NULL);
    glCompileShader(vs);

    if (check_compile_errors(vs))
        return 1;

    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fs, 1, &fragment_source, NULL);
    glCompileShader(fs);

    if (check_compile_errors(fs))
        return 1;

    GLuint shader_programme = glCreateProgram();
    glAttachShader(shader_programme, fs);
    glAttachShader(shader_programme, vs);
    glLinkProgram(shader_programme);

    if (check_link_errors(shader_programme))
        return 1;

    if (shader_programme == 0) {
        fprintf(stderr, "Failed to load shader!\n");
        // Handle the error
        return 1;
    }

    // Free the allocated memory
    free(vertex_source);
    free(fragment_source);

    return shader_programme;
}

void delete_shader(GLuint shader_programme) {
    glDeleteProgram(shader_programme);
}

bool check_compile_errors(GLuint index) {
    int params = -1;
    glGetShaderiv(index, GL_COMPILE_STATUS, &params);
    if (GL_TRUE != params) {
        fprintf(stderr, "ERROR: GL shader index %i did not compile\n", index);
        print_shader_info_log(index);
        return false; // or exit or something
    }

    return true;
}

bool check_link_errors(GLuint programme) {
    int params = -1;
    glGetProgramiv(programme, GL_LINK_STATUS, &params);
    if (GL_TRUE != params) {
        fprintf(stderr,
                "ERROR: could not link shader programme GL index %u\n",
                programme);
        print_programme_info_log(programme);
        return false;
    }

    return true;
}

void print_shader_info_log(GLuint shader_index) {
    int max_length = 2048;
    int actual_length = 0;
    char shader_log[2048];
    glGetShaderInfoLog(shader_index, max_length, &actual_length, shader_log);
    printf("shader info log for GL index %u:\n%s\n", shader_index, shader_log);
}

void print_programme_info_log(GLuint programme) {
    int max_length = 2048;
    int actual_length = 0;
    char program_log[2048];
    glGetProgramInfoLog(programme, max_length, &actual_length, program_log);
    printf("program info log for GL index %u:\n%s", programme, program_log);
}