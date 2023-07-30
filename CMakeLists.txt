cmake_minimum_required(VERSION 3.25)
project(education_opengl C)

set(CMAKE_C_STANDARD 23)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

#find_package(Freetype REQUIRED)
#find_package(freetype-gl CONFIG REQUIRED)

add_executable(education_opengl src/main.c src/objects/triangle/triangle.c src/objects/triangle/triangle.h src/shaders/shader_manager.c src/shaders/shader_manager.h src/utils/string_utils.h src/draw/draw_manager.c src/draw/draw_manager.h src/objects/point/point.c src/objects/point/point.h src/objects/line/line.c src/objects/line/line.h src/logger/logger.c src/logger/logger.h src/objects/circle/circle.c src/objects/circle/circle.h)

target_link_libraries(education_opengl PRIVATE glfw)
target_link_libraries(education_opengl PRIVATE GLEW::GLEW)

#target_link_libraries(education_opengl PRIVATE Freetype::Freetype) # since CMake 3.10
#target_link_libraries(education_opengl PRIVATE freetype-gl)

# Create a 'build' directory in the source directory for an out-of-source build
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# Add a custom command to copy resources during the build
add_custom_command(TARGET education_opengl POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        ${EXECUTABLE_OUTPUT_PATH}/
        )