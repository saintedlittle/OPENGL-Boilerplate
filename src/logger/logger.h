//
// Created by saintedlittle on 29.07.2023.
//

#ifndef EDUCATION_OPENGL_LOGGER_H
#define EDUCATION_OPENGL_LOGGER_H

#define GL_LOG_FILE "gl.log"

bool restart_gl_log();

bool gl_log(const char* message, ...);

bool gl_log_err(const char* message, ...);

#endif //EDUCATION_OPENGL_LOGGER_H
