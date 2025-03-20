#ifndef GRAPHIC_BUFFER_VBO_H
#define GRAPHIC_BUFFER_VBO_H

namespace geb {

	class VBO {
	public:
		VBO(const float* data, size_t lenght);
		~VBO();

		VBO(const VBO&) = delete;
		VBO& operator=(const VBO&) = delete;

		void bind() const;
		void unbind() const;

	private:
		unsigned int _id;
	};

};

#endif // GRAPHIC_BUFFER_VBO_H