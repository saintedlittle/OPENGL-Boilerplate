//
// Created by saintedlittle on 29.07.2023.
//

#include <vcruntime.h>
#include <vcruntime_string.h>
#include "point.h"
#include "GL/glew.h"

static void init_point(struct point *point) {
    glGenBuffers(1, &point->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, point->vbo);
    glBufferData(GL_ARRAY_BUFFER, 2 * sizeof(float), point->coord, GL_STATIC_DRAW);
    glGenVertexArrays(1, &point->vao);
    glBindVertexArray(point->vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, point->vbo);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, NULL);
}


struct point create_point(float x, float y) {
    static struct point my_point;

    my_point.vbo = 0;
    my_point.vao = 0;

    float coords[3] = {x, y, 0};

    memcpy(my_point.coord, coords, sizeof(coords));

    init_point(&my_point);

    return my_point;
}