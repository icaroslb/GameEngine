// GameEngine.cpp: define o ponto de entrada para o aplicativo.
//

#define SDL_MAIN_HANDLED

#include "GameEngine.h"
#include "Math/Vector.h"
#include "Math/Matrix.h"
#include "Math/TransformationMatrix.h"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <limits>

#include "Graphic/SDL2App.h"
#include "Graphic/OpenGLApp.h"
#include "Graphic/Buffer/VertexBuffer.h"
#include "Graphic/Buffer/IndexBuffer.h"

const int vectors_size = 10000;
const int qtd_loops = 10000;

#if defined(__linux__)
int main(int argc, char* argv[]) {
#endif

#if defined(_WIN32)
int main(int argc, char* argv[]) {
#endif
	SDL_SetMainReady();

	geb::Vector v0{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector v1{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector v2 = v0 - v1;
	double dot = v0.dot(v1);

	std::cout << dot << std::endl;

	std::cout << v2 << std::endl;

	geb::Matrix m0{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};

	geb::Matrix m1{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};
	geb::Matrix m2 = m0 * m1;

	std::cout << m2 << std::endl;

	geb::TransformationMatrix tm0;

	std::cout << tm0 << std::endl;

	geb::Sdl2App sdl_app(SDL_INIT_VIDEO | SDL_INIT_EVENTS, 4, 6);

	sdl_app.CreateWindow("TESTE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	SDL_Event e;
	bool is_looping = true;

	glViewport(0, 0, 500, 500);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	sdl_app.SwapWindow();

	const float sqrt3 = static_cast<float>(sqrt(3.0));

	geb::Vector vertices[] =
	{
		geb::Vector(-0.5f , -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f),
		geb::Vector(+0.5f , -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f),
		geb::Vector(+0.0f , +0.5f * sqrt3 * 2.0f / 3.0f, 0.0f, 1.0f),
		geb::Vector(-0.25f, +0.5f * sqrt3 / 6.0f       , 0.0f, 1.0f),
		geb::Vector(+0.25f, +0.5f * sqrt3 / 6.0f       , 0.0f, 1.0f),
		geb::Vector(+0.0f,  -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f)
	};

	unsigned int indices[] =
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	std::shared_ptr<geb::ShaderProgram> sp = geb::OpenGLApp::create_shader_program("Shader/simple_shader.vert", "Shader/simple_shader.frag");
	geb::IndexBuffer vb{ (float*) & vertices, indices, sizeof(vertices), sizeof(indices) };

	while (is_looping) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				is_looping = false;
				break;
			}
		}

		sp->use();

		glClear(GL_COLOR_BUFFER_BIT);

		vb.BindBuffer();

		//glDrawArrays(GL_TRIANGLES, 0, 3);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		sdl_app.SwapWindow();
	}
	
	return 0;
}
