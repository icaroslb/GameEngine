#ifndef GRAPHICS_VBO_DATA_H
#define GRAPHICS_VBO_DATA_H

#include "Graphic/Buffer/VAO.h"

namespace sge{
	class VBOData {
	public:
		virtual void draw() = 0;

	protected:
		virtual void load(VAO& vao) = 0;
	};
};

#endif // GRAPHICS_VBO_DATA_H