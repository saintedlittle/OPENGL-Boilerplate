//
// Created by saintedlittle on 29.07.2023.
//

#include <vcruntime_string.h>
#include "line.h"

static void init_line(struct line *line) {
    glGenBuffers(1, &line->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, line->vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float), line->vertices, GL_STATIC_DRAW);
    glGenVertexArrays(1, &line->vao);
    glBindVertexArray(line->vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, line->vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (void*)0);

}


struct line create_line(struct point first, struct point second) {
    struct line lineObj;

    lineObj.vbo = 0;
    lineObj.vao = 0;

    // Vertices of the line (two points)
    GLfloat vertices[] = {
            first.coord[0], first.coord[1], first.coord[2],
            second.coord[0], second.coord[1], second.coord[2]
    };

    memcpy(lineObj.vertices, vertices, sizeof(vertices));

    init_line(&lineObj);

    return lineObj;
}