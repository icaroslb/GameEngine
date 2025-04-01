#ifndef DATA_VBO_COLOR_DATA_H
#define DATA_VBO_COLOR_DATA_H

#include <vector>

#include <Graphic/Buffer/VAO.h>
#include <Graphic/Buffer/VBO.h>

#include "VBOData.h"
#include "DataColorStruct.h"

namespace sge {

	class VBOColorData : public VBOData {
	public:
		virtual void draw();

	protected:
		virtual void load(VAO& vao);

		VBO _vbo;
		std::vector<DataColorStruct> _data;
	};

};

#endif // DATA_VBO_COLOR_DATA_H