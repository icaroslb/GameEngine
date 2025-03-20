#include "ShaderProgram.h"

#include <glad/glad.h>
#include <iostream>

namespace geb {

	ShaderProgram::ShaderProgram() : _initialized(false), _program_id(0) {}

	ShaderProgram::~ShaderProgram() {
		if (_initialized) {
			glDeleteProgram(_program_id);
		}
	}

	void ShaderProgram::init(const char* vertex_shader_source, const char* fragment_shader_source) {
		// compile vertex shader
		unsigned int _vert_shader_id = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(_vert_shader_id, 1, &vertex_shader_source, nullptr);
		glCompileShader(_vert_shader_id);

		// compile fragment shader
		unsigned int _frag_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(_frag_shader_id, 1, &fragment_shader_source, nullptr);
		glCompileShader(_frag_shader_id);

		// linking shaders in a program
		_program_id = glCreateProgram();

		glAttachShader(_program_id, _vert_shader_id);
		glAttachShader(_program_id, _frag_shader_id);
		glLinkProgram(_program_id);

		// clean
		glDeleteShader(_vert_shader_id);
		glDeleteShader(_frag_shader_id);

		_initialized = true;
	}

	void ShaderProgram::use() {
		glUseProgram(_program_id);
	}

	unsigned int ShaderProgram::GetId() {
		return _program_id;
	}

};