//
// Created by saintedlittle on 28.07.2023.
//

#include <vcruntime.h>
#include "triangle.h"

static void init_triangle(struct triangle *triangle) {
    glGenBuffers(1, &triangle->vbo);
    glBindBuffer(GL_ARRAY_BUFFER, triangle->vbo);
    glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(float), triangle->points, GL_STATIC_DRAW);
    glGenVertexArrays(1, &triangle->vao);
    glBindVertexArray(triangle->vao);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, triangle->vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

struct triangle create_triangle(const float points[9]) {
    struct triangle tri;

    tri.vbo = 0;
    tri.vao = 0;

    // Store the pointer to the 'points' array in the 'triangle' struct
    // Copy the array values to the 'points' member of the 'triangle' struct
    for (int i = 0; i < 9; i++) {
        tri.points[i] = points[i];
    }

    // Add the OpenGL-related code to create VBO and VAO here (not shown)
    init_triangle(&tri);

    return tri;
}