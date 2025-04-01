#include "EBO.h"

#include <glad/glad.h>

namespace sge {
	EBO::EBO() {}

	EBO::~EBO() {
		glDeleteBuffers(1, &_id);
	}

	void EBO::load(const unsigned int* data, size_t lenght) {
		// Initialize vertex buffer object (EBO) buffer
		glGenBuffers(1, &_id);

		// Bind the EBO to configure it
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
		// Link the data with the buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, lenght, data, GL_STATIC_DRAW);
	}

	void EBO::bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _id);
	}

	void EBO::unbind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
};