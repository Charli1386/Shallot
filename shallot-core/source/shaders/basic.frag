#version 330 core

layout (location = 0) in vec4 color;

uniform mat4 pr_matrix;

void main(){

	color = vec4(1.0, 0.0, 1.0, 1.0);

}
