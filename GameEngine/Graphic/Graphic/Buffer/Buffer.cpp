#include "Buffer.h"

#include <glad/glad.h>

namespace geb {
	Buffer::Buffer() {}

	Buffer::~Buffer() {
		glDeleteVertexArrays(1, &_vao_id);
	}
	
	void Buffer::BindBuffer() {
		glBindVertexArray(_vao_id);
	}

};