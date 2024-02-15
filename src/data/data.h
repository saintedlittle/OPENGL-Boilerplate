
#ifndef EDUCATION_OPENGL_DATA_H
#define EDUCATION_OPENGL_DATA_H

#include <stdbool.h>

struct AppConfig {
    int width;
    int height;
    char* title;
};

bool load_configuration(const char* filename, struct AppConfig* config);


#endif //EDUCATION_OPENGL_DATA_H
