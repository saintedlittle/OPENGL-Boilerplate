//
// Created by saintedlittle on 28.07.2023.
//

#include <assert.h>
#include "shader_manager.h"
#include "../utils/string_utils.h"

GLuint create_shader_program_from_files(const char* vertex_shader_filename, const char* fragment_shader_filename);

GLuint load_shader(char* shader_name) {
    const char* fragment_filename = sum_string(shader_name, "_fragment.glsl");
    const char* vertex_filename = sum_string(shader_name, "_vertex.glsl");

    return create_shader_program_from_files(vertex_filename, fragment_filename);;
}

void print_programme_info_log(GLuint programme) {
    int max_length = 2048;
    int actual_length = 0;
    char program_log[2048];
    glGetProgramInfoLog(programme, max_length, &actual_length, program_log);

    gl_log("program info log for GL index %u:\n%s", programme, program_log);

}

GLuint create_shader_program_from_files(const char* vertex_shader_filename, const char* fragment_shader_filename) {

    assert( vertex_shader_filename && fragment_shader_filename );

    gl_log("\nloading shader from files `%s` and `%s`\n", vertex_shader_filename, fragment_shader_filename);

    char vs_shader_str[MAX_SHADER_SZ];
    char fs_shader_str[MAX_SHADER_SZ];
    vs_shader_str[0] = fs_shader_str[0] = '\0';

    { // read vertex shader file into a buffer
        FILE* fp = fopen( vertex_shader_filename, "r" );
        if ( !fp ) {

            gl_log_err("ERROR: could not open vertex shader file `%s`\n", vertex_shader_filename);

            return 0;
        }
        size_t count = fread( vs_shader_str, 1, MAX_SHADER_SZ - 1, fp );
        assert( count < MAX_SHADER_SZ - 1 ); // file was too long
        vs_shader_str[count] = '\0';
        fclose( fp );
    }

    { // read fragment shader file into a buffer
        FILE* fp = fopen( fragment_shader_filename, "r" );
        if ( !fp ) {
            gl_log_err("shader info log for GL index %u:\n%s\n", "ERROR: could not open fragment shader file `%s`\n", fragment_shader_filename);

            return 0;
        }
        size_t count = fread( fs_shader_str, 1, MAX_SHADER_SZ - 1, fp );
        assert( count < MAX_SHADER_SZ - 1 ); // file was too long
        fs_shader_str[count] = '\0';
        fclose( fp );
    }

    return create_shader_program_from_strings( vs_shader_str, fs_shader_str );
}

GLuint create_shader_program_from_strings(const char* vertex_shader_str, const char* fragment_shader_str) {

    assert( vertex_shader_str && fragment_shader_str );

    GLuint shader_program         = glCreateProgram();
    GLuint vertex_shader_handle   = glCreateShader( GL_VERTEX_SHADER );
    GLuint fragment_shader_handle = glCreateShader( GL_FRAGMENT_SHADER );

    int lparams = -1;
    const int max_length = 2048;
    int actual_length    = 0;

    { // compile shader and check for errors
        glShaderSource( vertex_shader_handle, 1, &vertex_shader_str, NULL );
        glCompileShader( vertex_shader_handle );
        glGetShaderiv( vertex_shader_handle, GL_COMPILE_STATUS, &lparams );

        if ( GL_TRUE != lparams ) {

            gl_log_err("ERROR: vertex shader index %u did not compile\n", vertex_shader_handle);

            char slog[2048];
            glGetShaderInfoLog( vertex_shader_handle, max_length, &actual_length, slog );

            gl_log_err("shader info log for GL index %u:\n%s\n", vertex_shader_handle, slog);

            glDeleteShader( vertex_shader_handle );
            glDeleteShader( fragment_shader_handle );
            glDeleteProgram( shader_program );
            return 0;
        }

    }

    { // compile shader and check for errors
        glShaderSource( fragment_shader_handle, 1, &fragment_shader_str, NULL );
        glCompileShader( fragment_shader_handle );
        lparams = -1;
        glGetShaderiv( fragment_shader_handle, GL_COMPILE_STATUS, &lparams );

        if ( GL_TRUE != lparams ) {

            gl_log_err("ERROR: fragment shader index %u did not compile\n",
                       fragment_shader_handle);

            char slog[2048];
            glGetShaderInfoLog( fragment_shader_handle, max_length, &actual_length, slog );

            gl_log_err("shader info log for GL index %u:\n%s\n", fragment_shader_handle, slog);

            glDeleteShader( vertex_shader_handle );
            glDeleteShader( fragment_shader_handle );
            glDeleteProgram( shader_program );
            return 0;
        }

    }

    glAttachShader( shader_program, fragment_shader_handle );
    glAttachShader( shader_program, vertex_shader_handle );

    { // link program and check for errors
        glLinkProgram( shader_program );
        glDeleteShader( vertex_shader_handle );
        glDeleteShader( fragment_shader_handle );

        lparams = -1;
        glGetProgramiv( shader_program, GL_LINK_STATUS, &lparams );

        if ( GL_TRUE != lparams ) {

            gl_log_err("ERROR: could not link shader program GL index %u\n", shader_program);

            char plog[2048];
            glGetProgramInfoLog( shader_program, max_length, &actual_length, plog );

            gl_log_err("program info log for GL index %u:\n%s", shader_program, plog );

            glDeleteProgram( shader_program );
            return 0;
        }

    }

    return shader_program;
}

void delete_shader(GLuint shader_programme) {
    glDeleteProgram(shader_programme);
}