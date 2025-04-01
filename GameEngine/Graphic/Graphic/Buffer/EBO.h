#ifndef GRAPHIC_BUFFER_EBO_H
#define GRAPHIC_BUFFER_EBO_H

namespace sge {

	class EBO {
	public:
		EBO();
		~EBO();

		EBO(const EBO&) = delete;
		EBO& operator=(const EBO&) = delete;

		void load(const unsigned int* data, size_t lenght);
		void bind() const;
		void unbind() const;

	private:
		unsigned int _id;
	};

};

#endif // GRAPHIC_BUFFER_EBO_H