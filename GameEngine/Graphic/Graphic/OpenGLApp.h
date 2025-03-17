#ifndef GRAPHIC_OPEN_GL_APP_H
#define GRAPHIC_OPEN_GL_APP_H

#include <glad/glad.h>
#include <memory>

#include "ShaderProgram.h"

namespace geb {

	class OpenGLApp {
	public:
		/**
		* init
		* Initialized the Opengl
		* @param proc: Method to get Opengl functions by name
		*/
		static void init(GLADloadproc proc);

		/**
		* create_shader_program
		* Create the shader program
		* @param vert_path: The Vertex Shader path
		* @param frag_path: The Fragment Shader path
		* @return The shader program
		*/
		static std::shared_ptr<ShaderProgram> create_shader_program(const char* vert_path, const char* frag_path);
	};

};

#endif // GRAPHIC_OPEN_GL_APP_H