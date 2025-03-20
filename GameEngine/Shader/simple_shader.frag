#version 330 core

in vec4 color;
in vec2 tex_coord;

out vec4 FragColor;

uniform sampler2D tex0;

void main()
{
	FragColor = texture(tex0, tex_coord);// color; //vec4(0.8f, 0.3f, 0.02f, 1.0f);
}