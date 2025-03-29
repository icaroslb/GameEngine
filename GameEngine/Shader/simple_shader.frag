#version 330 core

in vec4 color;
in vec2 tex_coord;

out vec4 FragColor;

uniform sampler2D tex0;

vec4 convolution(float[9] weights, vec2 coord, sampler2D tex) {
	vec4 result_color = vec4(0.0f);
	float sum_weight = 0.0f;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vec2 offset = coord + vec2(j - 1, i - 1);
			float weight =  weights[(i * 3) + j];
			result_color += vec4(texture(tex, offset)) * weight;
			sum_weight += weight;
		}
	}

	sum_weight /= sum_weight;

	return result_color / result_color.a;
}

void main()
{
	//float[9] weights = float[](
	//	1.0f, 2.0f, 1.0f,
	//	2.0f, 4.0f, 2.0f,
	//	1.0f, 2.0f, 1.0f
	//);
	//float[9] weights = float[](
	//	 0.0f, -1.0f,  0.0f,
	//	-1.0f,  5.0f, -1.0f,
	//	 0.0f, -1.0f,  0.0f
	//);
	float[9] weights = float[](
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f
	);
	
	FragColor = convolution(weights, tex_coord, tex0);

	//FragColor = convolution(weights, tex_coord, tex0);// texture(tex0, tex_coord);// color; //vec4(0.8f, 0.3f, 0.02f, 1.0f);
}