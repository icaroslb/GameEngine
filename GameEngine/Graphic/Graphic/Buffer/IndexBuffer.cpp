#include "IndexBuffer.h"

#include <glad/glad.h>


namespace geb {
	IndexBuffer::IndexBuffer(const float* buffer_data, const unsigned int* indices, size_t size_of_buffer, size_t size_of_indices) {
		// Initialize vertex array object (vao), vertex buffer object (vbo) and element buffer object (ebo) buffers
		glGenVertexArrays(1, &_vao_id);
		glGenBuffers(1, &_vbo_id);
		glGenBuffers(1, &_ebo_id);

		// Bind the vao to configure it
		glBindVertexArray(_vao_id);

		// Bind the vbo to configure it
		glBindBuffer(GL_ARRAY_BUFFER, _vbo_id);
		// Link the data with the buffer
		glBufferData(GL_ARRAY_BUFFER, size_of_buffer, buffer_data, GL_STATIC_DRAW);
		
		// Bind the ebo to configure it
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo_id);
		// Link the data with the buffer
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_of_indices, indices, GL_STATIC_DRAW);

		// Pass information how the data is structured
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);

		// Detach the buffers
		glEnableVertexAttribArray(0);
		glBindVertexArray(0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

	IndexBuffer::~IndexBuffer() {
		glDeleteBuffers(1, &_vbo_id);
		glDeleteBuffers(1, &_ebo_id);
	}
};