#include "VAOData.h"

#include <algorithm>

namespace sge {

	void VAOData::bind() {
		_vao.bind();
	}

	void VAOData::unbind() {
		_vao.unbind();
	}

	void VAOData::draw() {
		std::for_each(std::begin(_vbo_data), std::end(_vbo_data), [](const std::shared_ptr<VBOData>& ob)
			{
				ob->draw();
			});
	}

};