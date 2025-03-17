#ifndef GRAPHIC_BUFFER_BUFFER_H
#define GRAPHIC_BUFFER_BUFFER_H

namespace geb {

	class Buffer {
	public:
		Buffer& operator=(const Buffer&) = delete;
		~Buffer();

		/**
		* BindBuffer
		* Bind the vertex array object buffer to use it
		*/
		void BindBuffer();

	protected:
		Buffer();

		unsigned int _vao_id;
	};

};

#endif // GRAPHIC_BUFFER_BUFFER_H