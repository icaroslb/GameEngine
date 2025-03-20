#ifndef GRAPHIC_BUFFER_EBO_H
#define GRAPHIC_BUFFER_EBO_H

namespace geb {

	class EBO {
	public:
		EBO(const unsigned int* data, size_t lenght);
		~EBO();

		EBO(const EBO&) = delete;
		EBO& operator=(const EBO&) = delete;

		void bind() const;
		void unbind() const;

	private:
		unsigned int _id;
	};

};

#endif // GRAPHIC_BUFFER_EBO_H