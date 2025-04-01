#ifndef GRAPHIC_BUFFER_VAO_H
#define GRAPHIC_BUFFER_VAO_H

#include <vector>
#include <memory>

#include "VBO.h"

namespace sge {
	enum enum_type {
		BOOLEAN = 0x8B56,
		BYTE   = 0x1400,
		UBYTE  = 0x1401,
		SHORT  = 0x1402,
		USHORT = 0x1403,
		INT    = 0x1404,
		UINT   = 0x1405,
		HALF   = 0x140B,
		FLOAT  = 0x1406,
		DOUBLE = 0x140A
	};

	class VAO {
	public:
		VAO();
		VAO(const VAO&) = delete;
		~VAO();

		VAO& operator= (const VAO&) = delete;

		void link_vbo(const VBO* vbo, unsigned int index, unsigned int num_components, enum_type type, size_t stride, void* offset) const;

		void bind() const;
		void unbind() const;

	private:
		unsigned int _id;
	};
};

#endif // GRAPHIC_BUFFER_VAO_H