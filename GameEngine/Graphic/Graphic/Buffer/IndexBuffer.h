#ifndef GRAPHIC_BUFFER_INDEX_BUFFER_H
#define GRAPHIC_BUFFER_INDEX_BUFFER_H

#include "Buffer.h"

namespace geb {
	class IndexBuffer : public Buffer {
	public:
		IndexBuffer(const float* buffer_data, const unsigned int* indices, size_t size_of_buffer, size_t size_of_indices);
		IndexBuffer(const IndexBuffer&) = delete;
		~IndexBuffer();

	private:
		unsigned int _vbo_id;
		unsigned int _ebo_id;
	};
};

#endif // GRAPHIC_BUFFER_INDEX_BUFFER_H