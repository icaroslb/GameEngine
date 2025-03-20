#include "Uniform.h"

#include <glad/glad.h>

namespace geb {
	unsigned int Uniform::get_uniform_location(unsigned int shader_id, const char* uniform_name) {
		return glGetUniformLocation(shader_id, uniform_name);
	}

	void Uniform::set_uniform_f(unsigned int uniform_location, float value) {
		glUniform1f(uniform_location, value);
	}

	void Uniform::set_uniform_i(unsigned int uniform_location, int value) {
		glUniform1i(uniform_location, value);
	}
};