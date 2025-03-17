#ifndef GRAPHIC_BUFFER_VERTEX_BUFFER_H
#define GRAPHIC_BUFFER_VERTEX_BUFFER_H

#include "Buffer.h"

namespace geb {
	class VertexBuffer : public Buffer {
	public:
		VertexBuffer(const float* buffer_data, size_t size_of_buffer);
		VertexBuffer(const VertexBuffer&) = delete;
		~VertexBuffer();

	private:
		unsigned int _vbo_id;
	};
};

#endif // GRAPHIC_BUFFER_VERTEX_BUFFER_H