#ifndef GRAPHIC_SHADER_PROGRAM_H
#define GRAPHIC_SHADER_PROGRAM_H

namespace geb {

	class ShaderProgram {
	public:
		ShaderProgram();
		ShaderProgram(const ShaderProgram&) = delete;
		~ShaderProgram();

		/**
		* init
		* Initialize the shader program
		* @param vertex_shader_source: The vertex shader source
		* @param fragment_shader_source: The fragment shader source
		*/
		void init(const char* vertex_shader_source, const char* fragment_shader_source);

		/**
		* use
		* Bind the shader program to use it
		*/
		void use();

		unsigned int GetId();

	private:
		unsigned int _program_id;

		bool _initialized;
	};

};

#endif // GRAPHIC_SHADER_PROGRAM_H
