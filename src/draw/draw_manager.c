//
// Created by saintedlittle on 29.07.2023.
//

#include "draw_manager.h"

static GLuint triangle_shader;
static GLuint line_shader;
static GLuint point_shader;

void initialize_shaders() {
    point_shader = load_shader("point");
    line_shader = load_shader("line");
    triangle_shader = load_shader("triangle");
}

void draw_point(struct point my_point) {
    glUseProgram(point_shader);

    glBindVertexArray(my_point.vao);

    // draw coords 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_POINTS, 0, 2);

}

void draw_line(struct line myLine) {
    glUseProgram(line_shader);

    glBindVertexArray(myLine.vao);

    glDrawArrays(GL_LINES, 0, 2);

}

void draw_triangle(struct triangle my_triangle) {
    glUseProgram(triangle_shader);

    glBindVertexArray(my_triangle.vao);

    // draw coords 0-3 from the currently bound VAO with current in-use shader
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
