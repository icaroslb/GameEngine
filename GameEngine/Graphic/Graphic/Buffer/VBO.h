#ifndef GRAPHIC_BUFFER_VBO_H
#define GRAPHIC_BUFFER_VBO_H

namespace sge {

	class VBO {
	public:
		VBO();
		~VBO();

		VBO(const VBO&) = delete;
		VBO& operator=(const VBO&) = delete;

		void load(const float* data, size_t lenght);

		void bind() const;
		void unbind() const;

	private:
		unsigned int _id;
	};

};

#endif // GRAPHIC_BUFFER_VBO_H