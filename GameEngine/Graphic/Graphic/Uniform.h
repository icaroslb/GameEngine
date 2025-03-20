#ifndef GRAPHIC_UNIFORM_H
#define GRAPHIC_UNIFORM_H
namespace geb {

	class Uniform {
	public:
		static unsigned int get_uniform_location(unsigned int shader_id, const char* uniform_name);

		static void set_uniform_f(unsigned int uniform_location, float value);
		static void set_uniform_i(unsigned int uniform_location, int value);
	private:
		Uniform() = delete;
		Uniform(const Uniform&) = delete;
		Uniform& operator= (const Uniform&) = delete;
	};

};

#endif // GRAPHIC_UNIFORM_H