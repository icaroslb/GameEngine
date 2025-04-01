#include "VBOTextureData.h"

#include <glad/glad.h>

namespace sge {
	void VBOTextureData::load(VAO& vao) {
		_vbo.load((float*)_data.data(), _data.size() * sizeof(DataTextureStruct));

		vao.link_vbo(&_vbo, 0, 4, sge::FLOAT, sizeof(DataTextureStruct), (void*)0);
		vao.link_vbo(&_vbo, 1, 4, sge::FLOAT, sizeof(DataTextureStruct), (void*)sizeof(Vector4));
		vao.link_vbo(&_vbo, 2, 2, sge::FLOAT, sizeof(DataTextureStruct), (void*)(2 * sizeof(Vector4)));

		_vbo.unbind();
	}

	void VBOTextureData::draw() {
		glDrawArrays(GL_TRIANGLES, 0, _data.size());
	}
};