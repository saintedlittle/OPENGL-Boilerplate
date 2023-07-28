#include "GL/glew.h" // include GLEW and new version of GL on Windows
#include "GLFW/glfw3.h" // GLFW helper library
#include "objects/triangle.h"
#include "shaders/shader_manager.h"

#include <stdio.h>
#include <stdlib.h>

static GLFWwindow* window;

void initialize_window();
void initialize_glew();

void print_service_information();
void print_fps();

int main() {

    /* INIT BLOCK */

    initialize_window();
    initialize_glew();

    print_service_information();

    /* OTHER STUFF GOES HERE NEXT */

    const float coords[] = {            0.0f,  0.5f,  0.0f,
                                        0.5f, -0.5f,  0.0f,
                                        -0.5f, -0.5f,  0.0f
    };

    struct triangle my_triangle = create_triangle(coords);
    GLuint triangle_shader = load_shader("triangle");

    while(!glfwWindowShouldClose(window)) {

        if (GLFW_PRESS == glfwGetKey(window, GLFW_KEY_ESCAPE)) {
            glfwSetWindowShouldClose(window, 1);
        }

        // wipe the drawing surface clear
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        print_fps();

        glUseProgram(triangle_shader);

        glBindVertexArray(my_triangle.vao);

        // draw points 0-3 from the currently bound VAO with current in-use shader
        glDrawArrays(GL_TRIANGLES, 0, 3);

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
        fprintf(stderr, "ERROR: could not start GLFW3\n");
        exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not open window with GLFW3\n");
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
    printf("Renderer: %s\n", renderer);
    printf("OpenGL version supported %s\n", version);
}

void print_fps() {
    double previous_seconds = glfwGetTime();
    static int frame_count = 1;
    double current_seconds = glfwGetTime();
    double elapsed_seconds = current_seconds - previous_seconds;
    double fps = (double)frame_count / elapsed_seconds;

    printf("fps: %.2f\n", fps);

    frame_count++;
}