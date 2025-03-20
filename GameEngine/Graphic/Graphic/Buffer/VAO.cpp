#include "VAO.h"

#include <glad/glad.h>


namespace geb {
	VAO::VAO() {
		glGenVertexArrays(1, &_id);
	}

	VAO::~VAO() {}

	void VAO::link_vbo(const VBO* vbo, unsigned int index, unsigned int num_components, enum_type type, size_t stride, void* offset) const {

		vbo->bind();

		glVertexAttribPointer(index, num_components, type, false, stride, offset);
		glEnableVertexAttribArray(index);

		vbo->unbind();
	}

	void VAO::bind() const {
		glBindVertexArray(_id);
	}

	void VAO::unbind() const {
		glBindVertexArray(0);
	}
};