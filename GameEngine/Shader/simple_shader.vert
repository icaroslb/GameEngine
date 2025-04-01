#version 330 core

layout (location = 0) in vec4 aPos;
layout (location = 1) in vec4 aColor;
layout (location = 2) in vec2 aTex;

out vec4 color;
out vec2 tex_coord;

uniform mat4 mat_model;
uniform mat4 mat_view;
uniform mat4 mat_proj;

void main()
{
	gl_Position = mat_proj * mat_view * vec4(aPos.xyz, 1.0);
	color = aColor;
	tex_coord = aTex;
}