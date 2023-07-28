cmake_minimum_required(VERSION 3.25)
project(education_opengl C)

set(CMAKE_C_STANDARD 23)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

add_executable(education_opengl src/main.c src/objects/triangle.c src/objects/triangle.h src/shaders/shader_manager.c src/shaders/shader_manager.h src/utils/string_utils.h)

target_link_libraries(education_opengl PRIVATE glfw)
target_link_libraries(education_opengl PRIVATE GLEW::GLEW)

# Create a 'build' directory in the source directory for an out-of-source build
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Add a custom command to copy resources during the build
add_custom_command(TARGET education_opengl POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${EXECUTABLE_OUTPUT_PATH}/
        )