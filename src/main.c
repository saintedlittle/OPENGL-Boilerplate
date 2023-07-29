#include "GL/glew.h" // include GLEW and new version of GL on Windows
#include "GLFW/glfw3.h" // GLFW helper library
#include "objects/triangle/triangle.h"
#include "draw/draw_manager.h"
#include "logger/logger.h"

#include <stdio.h>
#include <stdlib.h>

static GLFWwindow* window;

void initialize_window();
void initialize_glew();

void print_service_information();
void print_fps();

static double previous_seconds;

int main() {
    previous_seconds = glfwGetTime();
    /* INIT BLOCK */

    initialize_window();
    initialize_glew();

    restart_gl_log();

    print_service_information();
    initialize_shaders();

    /* OTHER STUFF GOES HERE NEXT */

    const float coords[] = {            0.0f,  0.5f,  0.0f,
                                        0.5f, -0.5f,  0.0f,
                                        -0.5f, -0.5f,  0.0f
    };

    struct triangle my_triangle = create_triangle(coords);

    struct point my_point = create_point(2, 0);
    struct point another_point = create_point(4, 0);

    while(!glfwWindowShouldClose(window)) {

        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, 1);
        }

        // wipe the drawing surface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        print_fps();

        draw_triangle(my_triangle);

        draw_point(my_point);
        draw_point(another_point);

        draw_line(my_point, another_point);

        // update other events like input handling
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    // close GL context and any other GLFW resources
    glfwTerminate();
    return EXIT_SUCCESS;
}

void initialize_window() {
    // start GL context and O/S window using the GLFW helper library
    if (!glfwInit()) {
        gl_log_err("ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
    if (!window) {
        gl_log_err("ERROR: could not open window with GLFW3\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);

}

void initialize_glew() {
    // start GLEW extension handler
    glewExperimental = GL_TRUE;
    glewInit();

    // tell GL to only draw onto a pixel if the shape is closer to the viewer
    glEnable(GL_DEPTH_TEST); // enable depth-testing
    glDepthFunc(GL_LESS); // depth-testing interprets a smaller value as "closer"

}

void print_service_information() {
    // get version info
    const GLubyte* renderer = glGetString(GL_RENDERER); // get renderer string
    const GLubyte* version = glGetString(GL_VERSION); // version as a string

    gl_log("Renderer: %s\n", renderer);
    gl_log("OpenGL version supported %s\n\n", version);
}

void print_fps() {
    static int frame_count = 1;
    double current_seconds = glfwGetTime();
    double elapsed_seconds = current_seconds - previous_seconds;

    double fps = (double)frame_count / elapsed_seconds;

    if (elapsed_seconds > 0.25)
        printf("fps: %.2f\n", fps);

    previous_seconds = current_seconds;

    frame_count++;
}