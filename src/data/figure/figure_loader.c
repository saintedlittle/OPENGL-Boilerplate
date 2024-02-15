#include "figure_loader.h"

struct precircle read_circle_ini(const char *filename) {
    struct precircle circle;
    OPEN_FILE_AND_CHECK(filename)

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "center_x") != NULL)
            sscanf(line, "center_x = %f", &circle.center_x);
        else if (strstr(line, "center_y") != NULL)
            sscanf(line, "center_y = %f", &circle.center_y);
        else if (strstr(line, "radius") != NULL)
            sscanf(line, "radius = %f", &circle.radius);
        else if (strstr(line, "num_segments") != NULL)
            sscanf(line, "num_segments = %d", &circle.num_segments);
        else if (strstr(line, "shader_path") != NULL)
            sscanf(line, "shader_path = %s", circle.content.shader_path);
    }
    fclose(file);
    return circle;
}

struct preline read_line_ini(const char *filename) {
    struct preline line;
    OPEN_FILE_AND_CHECK(filename)

    char line_str[MAX_PATH_LENGTH];
    while (fgets(line_str, sizeof(line_str), file)) {
        if (strstr(line_str, "point1_x") != NULL)
            sscanf(line_str, "point1_x = %f", &line.point1_x);
        else if (strstr(line_str, "point1_y") != NULL)
            sscanf(line_str, "point1_y = %f", &line.point1_y);
        else if (strstr(line_str, "point2_x") != NULL)
            sscanf(line_str, "point2_x = %f", &line.point2_x);
        else if (strstr(line_str, "point2_y") != NULL)
            sscanf(line_str, "point2_y = %f", &line.point2_y);
        else if (strstr(line_str, "shader_path") != NULL)
            sscanf(line_str, "shader_path = %s", line.content.shader_path);
    }
    fclose(file);
    return line;
}

struct prepoint read_point_ini(const char *filename) {
    struct prepoint point;
    OPEN_FILE_AND_CHECK(filename)

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "x") != NULL)
            sscanf(line, "x = %f", &point.x);
        else if (strstr(line, "y") != NULL)
            sscanf(line, "y = %f", &point.y);
        else if (strstr(line, "shader_path") != NULL)
            sscanf(line, "shader_path = %s", point.content.shader_path);
    }
    fclose(file);
    return point;
}

struct pretriangle read_triangle_ini(const char *filename) {
    struct pretriangle triangle;
    OPEN_FILE_AND_CHECK(filename)

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "point1_x") != NULL)
            sscanf(line, "point1_x = %f", &triangle.point1_x);
        else if (strstr(line, "point1_y") != NULL)
            sscanf(line, "point1_y = %f", &triangle.point1_y);
        else if (strstr(line, "point2_x") != NULL)
            sscanf(line, "point2_x = %f", &triangle.point2_x);
        else if (strstr(line, "point2_y") != NULL)
            sscanf(line, "point2_y = %f", &triangle.point2_y);
        else if (strstr(line, "point3_x") != NULL)
            sscanf(line, "point3_x = %f", &triangle.point3_x);
        else if (strstr(line, "point3_y") != NULL)
            sscanf(line, "point3_y = %f", &triangle.point3_y);
        else if (strstr(line, "shader_path") != NULL)
            sscanf(line, "shader_path = %s", triangle.content.shader_path);
    }
    fclose(file);
    return triangle;
}

struct Shader read_shader_paths(const char *filename) {
    struct Shader shader;
    OPEN_FILE_AND_CHECK(filename)

    char line[MAX_PATH_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "vertex_shader_path") != NULL)
            sscanf(line, "vertex_shader_path = %s", shader.vertex_shader);
        else if (strstr(line, "fragment_shader_path") != NULL)
            sscanf(line, "fragment_shader_path = %s", shader.fragment_shader);
    }
    fclose(file);
    return shader;
}
