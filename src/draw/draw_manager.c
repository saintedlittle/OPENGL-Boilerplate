//
// Created by saintedlittle on 29.07.2023.
//

#include <math.h>
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

void draw_circle(struct circle my_circle) {
    glBegin(GL_LINE_LOOP);

    for (int ii = 0; ii < my_circle.num_segments; ii++)   {
        float theta = 2.0f * 3.1415926f * ii / my_circle.num_segments;//get the current angle
        float x = my_circle.r * cosf(theta);//calculate the x component
        float y = my_circle.r * sinf(theta);//calculate the y component
        glVertex2f(x + my_circle.cx, y + my_circle.cy);//output vertex
    }

    glEnd();
}

void drawFilledSun(struct circle my_circle, int color[3]) {
    static int isFirst = 0;

    int cx = my_circle.cx;
    int cy = my_circle.cy;

    glLoadIdentity();
    glTranslatef(0, 0, -10);

    double radius = my_circle.r;
    //glColor3ub(253, 184, 19);
    glColor3ub(color[0], color[1], color[2]);
    double twicePi = 2.0 * 3.142;

    glBegin(GL_TRIANGLE_FAN); //BEGIN CIRCLE
    glVertex2f(cx, cy); // center of circle
    for (int i = 0; i <= 20; i++)   {
        glVertex2f (
                (cx + (radius * cos(i * twicePi / 20))), (cy + (radius * sin(i * twicePi / 20)))
        );
    }
    glEnd(); //END

}