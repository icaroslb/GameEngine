#ifndef DATA_VAO_DATA_H
#define DATA_VAO_DATA_H

#include <memory>
#include <vector>

#include <Graphic/Buffer/VAO.h>
#include "VBOData.h"

namespace sge {
	class VAOData {
	public:
		void bind();
		void unbind();

		void draw();

	protected:
		VAO _vao;
		std::vector<std::shared_ptr<VBOData>> _vbo_data;
	};
};

#endif // DATA_VAO_DATA_H