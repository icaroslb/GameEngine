#include "Uniform.h"

#include <glad/glad.h>

namespace sge {
	unsigned int Uniform::get_uniform_location(unsigned int shader_id, const char* uniform_name) {
		return glGetUniformLocation(shader_id, uniform_name);
	}

	void Uniform::set_uniform_f(unsigned int uniform_location, const float& value) {
		glUniform1f(uniform_location, value);
	}

	void Uniform::set_uniform_i(unsigned int uniform_location, const int& value) {
		glUniform1i(uniform_location, value);
	}

	void Uniform::set_uniform_vec2(unsigned int uniform_location, size_t size, const float* value) {
		glUniform2fv(uniform_location, size, value);
	}

	void Uniform::set_uniform_mat4(unsigned int uniform_location, size_t size, bool transpose, const float* value) {
		glUniformMatrix4fv(uniform_location, size, transpose, value);
	}
};