#version 330 core

in vec4 color;
in vec2 tex_coord;

out vec4 FragColor;

uniform sampler2D tex0;
uniform int option;
uniform vec2 resolution;

vec4 convolution(float[9] weights, vec2 coord, sampler2D tex) {
	vec2 tex_offset = 1.0f / resolution;
	vec3 color = vec3(0.0f);
	vec4 result_color = vec4(0.0f);
	float sum_weight = 0.0f;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			vec2 offset = vec2(j - 1, i - 1) * tex_offset;
			float weight =  weights[(i * 3) + j];
			color += texture(tex, coord + offset).rgb * weight;
			sum_weight += weight;
		}
	}

	if (sum_weight > 0.0f) {
		result_color = vec4(color / sum_weight, 1.0f);
	} else {
		result_color = vec4(color, 1.0f);
	}

	return result_color;
}

void main()
{
	float[9] weights0 = float[](
		1.0f, 2.0f, 1.0f,
		2.0f, 4.0f, 2.0f,
		1.0f, 2.0f, 1.0f
	);
	float[9] weights1 = float[](
		 0.0f, -1.0f,  0.0f,
		-1.0f,  5.0f, -1.0f,
		 0.0f, -1.0f,  0.0f
	);
	float[9] weights2 = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	float[9] weights3 = float[](
		-1.0f, -1.0f, -1.0f,
		-1.0f,  8.0f, -1.0f,
		-1.0f, -1.0f, -1.0f
	);
	float[9] weights4 = float[](
		0.0f,  1.0f, 0.0f,
		1.0f, -4.0f, 1.0f,
		0.0f,  1.0f, 0.0f
	);
	float[9] weights5 = float[](
		 1.0f, 0.0f, -1.0f,
		 0.0f, 0.0f,  0.0f,
		-1.0f, 0.0f,  1.0f
	);
	float[9] weights6 = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	float[9] weights7 = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	float[9] weights8 = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	float[9] weights9 = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);

	vec4 color_convolutioned = vec4(0.0f);
	
	switch (option) {
		case 0:
			color_convolutioned = convolution(weights0, tex_coord, tex0);
			break;
		case 1:
			color_convolutioned = convolution(weights1, tex_coord, tex0);
			break;
		case 2:
			color_convolutioned = convolution(weights2, tex_coord, tex0);
			break;
		case 3:
			color_convolutioned = convolution(weights3, tex_coord, tex0);
			break;
		case 4:
			color_convolutioned = convolution(weights4, tex_coord, tex0);
			break;
		case 5:
			color_convolutioned = convolution(weights5, tex_coord, tex0);
			break;
		case 6:
			color_convolutioned = convolution(weights6, tex_coord, tex0);
			break;
		case 7:
			color_convolutioned = convolution(weights7, tex_coord, tex0);
			break;
		case 8:
			color_convolutioned = convolution(weights8, tex_coord, tex0);
			break;
		case 9:
			color_convolutioned = convolution(weights9, tex_coord, tex0);
			break;
		default:
			color_convolutioned = texture(tex0, tex_coord);
	}
	FragColor = color_convolutioned;

	//FragColor = convolution(weights, tex_coord, tex0);// texture(tex0, tex_coord);// color; //vec4(0.8f, 0.3f, 0.02f, 1.0f);
}