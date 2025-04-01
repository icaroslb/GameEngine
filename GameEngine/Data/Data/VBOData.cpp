#include "VBOColorData.h"
#include <glad/glad.h>

namespace sge {

	void VBOColorData::load(VAO& vao) {
		_vbo.load((float*)_data.data(), _data.size() * sizeof(DataColorStruct));

		vao.link_vbo(&_vbo, 0, 4, sge::FLOAT, sizeof(DataColorStruct), (void*)0);
		vao.link_vbo(&_vbo, 1, 4, sge::FLOAT, sizeof(DataColorStruct), (void*)sizeof(Vector4));

		_vbo.unbind();
	}

	void VBOColorData::draw() {
		glDrawArrays(GL_TRIANGLES, 0, _data.size());
	}
};