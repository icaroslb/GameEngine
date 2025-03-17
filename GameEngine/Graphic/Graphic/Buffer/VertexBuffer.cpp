#include "VertexBuffer.h"
#include <glad/glad.h>


namespace geb {
	VertexBuffer::VertexBuffer(const float* buffer_data, size_t size_of_buffer) {
		// Initialize vertex array object (vao) and vertex buffer object (vbo) buffers
		glGenVertexArrays(1, &_vao_id);
		glGenBuffers(1, &_vbo_id);

		// Bind the vao to configure it
		glBindVertexArray(_vao_id);

		// Bind the vbo to configure it
		glBindBuffer(GL_ARRAY_BUFFER, _vbo_id);
		// Link the data with the buffer
		glBufferData(GL_ARRAY_BUFFER, size_of_buffer, buffer_data, GL_STATIC_DRAW);

		// Pass information how the data is structured
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, size_of_buffer, (void*)0);

		// Detach the buffers
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	VertexBuffer::~VertexBuffer() {
		glDeleteBuffers(1, &_vbo_id);
	}
};