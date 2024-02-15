
#include "data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool load_configuration(const char* filename, struct AppConfig* config) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error opening configuration file\n");
        return false;
    }

    char line[256];
    while (fgets(line, sizeof(line), file)) {
        char key[64], value[64];
        if (sscanf(line, "%63[^=]=%63s", key, value) == 2) {
            if (strcmp(key, "width") == 0) {
                config->width = atoi(value);
            } else if (strcmp(key, "height") == 0) {
                config->height = atoi(value);
            } else if (strcmp(key, "title") == 0) {
                config->title = strdup(value);
            }
        }
    }

    fclose(file);
    return true;
}
