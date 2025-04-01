#ifndef GRAPHIC_UNIFORM_H
#define GRAPHIC_UNIFORM_H
namespace sge {

	class Uniform {
	public:
		static unsigned int get_uniform_location(unsigned int shader_id, const char* uniform_name);

		static void set_uniform_f(unsigned int uniform_location, const float &value);
		static void set_uniform_i(unsigned int uniform_location, const int &value);
		static void set_uniform_vec2(unsigned int uniform_location, size_t size, const float* value);
		static void set_uniform_mat4(unsigned int uniform_location, size_t size, bool transpose, const float* value);
	private:
		Uniform() = delete;
		Uniform(const Uniform&) = delete;
		Uniform& operator= (const Uniform&) = delete;
	};

};

#endif // GRAPHIC_UNIFORM_H