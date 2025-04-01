#include "OpenGLApp.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace sge {

	void OpenGLApp::init(void* (*proc)(const char*)) {
		gladLoadGLLoader(proc);

		glEnable(GL_DEPTH_TEST);

		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl
			<< "Renderer: " << glGetString(GL_RENDERER) << std::endl
			<< "Version: " << glGetString(GL_VERSION) << std::endl;
	}

	std::shared_ptr<ShaderProgram> OpenGLApp::create_shader_program(const char* vert_path, const char* frag_path) {
		// Open the files
		std::ifstream vert_file{ vert_path };
		std::ifstream frag_file{ frag_path };
		std::shared_ptr<ShaderProgram> result = std::make_shared<ShaderProgram>();

		if (vert_file.is_open() && frag_file.is_open()) { 
			std::stringstream vert_source;
			std::stringstream frag_source;

			// Get the buffer source
			vert_source << vert_file.rdbuf();
			frag_source << frag_file.rdbuf();

			// Compile the source
			result->init(vert_source.str().data(), frag_source.str().data());
		}
		else {
			if (!vert_file.is_open()) {
				std::cerr << "Error could not open the vertex file " << vert_path << "!!!" << std::endl;
			}

			if (!frag_file.is_open()) {
				std::cerr << "Error could not open the fragment file " << frag_path << "!!!" << std::endl;
			}
		}

		return result;
	}

};