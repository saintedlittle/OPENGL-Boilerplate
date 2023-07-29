#version 400

layout (location = 0) in vec3 aPosition;

// Uniform for line thickness (adjust this value to change the line thickness)
uniform float lineThickness;

void main() {
    gl_Position = vec4(aPosition, 1.0);
    gl_PointSize = lineThickness;
}