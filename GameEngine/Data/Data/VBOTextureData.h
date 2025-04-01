#ifndef DATA_VBO_TEXTURE_DATA_H
#define DATA_VBO_TEXTURE_DATA_H

#include <vector>

#include <Graphic/Buffer/VAO.h>
#include <Graphic/Buffer/VBO.h>

#include "DataTextureStruct.h"
#include "VBOData.h"

namespace sge {

	class VBOTextureData : public VBOData {
	public:
		virtual void draw();

	protected:
		virtual void load(VAO& vao);

		VBO _vbo;
		std::vector<DataTextureStruct> _data;
	};

};

#endif // DATA_VBO_TEXTURE_DATA_H