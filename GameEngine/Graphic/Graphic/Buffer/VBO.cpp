#include "VBO.h"

#include <glad/glad.h>

namespace geb {
	VBO::VBO(const float* data, size_t lenght) {
		// Initialize vertex buffer object (vbo) buffer
		glGenBuffers(1, &_id);

		// Bind the vbo to configure it
		glBindBuffer(GL_ARRAY_BUFFER, _id);
		// Link the data with the buffer
		glBufferData(GL_ARRAY_BUFFER, lenght, data, GL_STATIC_DRAW);
	}

	VBO::~VBO() {
		glDeleteBuffers(1, &_id);
	}

	void VBO::bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, _id);
	}

	void VBO::unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
};