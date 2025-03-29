// GameEngine.cpp: define o ponto de entrada para o aplicativo.
//

//#define SDL_MAIN_HANDLED

#include "GameEngine.h"
#include "Math/Vector4.h"
#include "Math/Matrix4x4.h"
#include "Math/TransformationMatrix4x4.h"
#include "Math/Vector2.h"

#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <limits>

#include <stb/stb_image.h>

#include "Graphic/SDL3App.h"
#include "Graphic/OpenGLApp.h"
#include "Graphic/Buffer/VAO.h"
#include "Graphic/Buffer/VBO.h"
#include "Graphic/Buffer/EBO.h"
#include "Graphic/Uniform.h"
#include "Graphic/Texture.h"

#include "Objects/ObjectTexture.h"

#include <SDL3/SDL_main.h>

const int vectors_size = 10000;
const int qtd_loops = 10000;

int main(int argc, char* argv[]) {
	//SDL_SetMainReady();

	geb::Vector2 v0_{ 5.0, 2.0 };
	geb::Vector2 v1_{ 5.0, 2.0 };
	geb::Vector2 v2_ = v0_ + v1_;
	double dot_ = v0_.dot(v1_);

	std::cout << dot_ << std::endl;

	std::cout << v2_ << std::endl;

	geb::Vector4 v0{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector4 v1{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector4 v2 = v0 - v1;
	double dot = v0.dot(v1);

	std::cout << dot << std::endl;

	std::cout << v2 << std::endl;

	geb::Matrix4x4 m0{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};

	geb::Matrix4x4 m1{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};
	geb::Matrix4x4 m2 = m0 * m1;

	std::cout << m2 << std::endl;

	geb::TransformationMatrix4x4 tm0;

	std::cout << tm0 << std::endl;

	geb::Sdl3App sdl_app(SDL_INIT_VIDEO | SDL_INIT_EVENTS, 4, 6);

	sdl_app.CreateWindow("TESTE", 500, 500, SDL_WINDOW_OPENGL);

	SDL_Event e;
	bool is_looping = true;

	glViewport(0, 0, 500, 500);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	sdl_app.SwapWindow();

	const float sqrt3 = static_cast<float>(sqrt(3.0));

	/*geb::Vector4 vertices[] =
	{
		geb::Vector4(-0.5f , -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f), geb::Vector4(0.8f, 0.3f , 0.02f, 1.0f),
		geb::Vector4(+0.5f , -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f), geb::Vector4(0.8f, 0.3f , 0.02f, 1.0f),
		geb::Vector4(+0.0f , +0.5f * sqrt3 * 2.0f / 3.0f, 0.0f, 1.0f), geb::Vector4(1.0f, 0.6f , 0.32f, 1.0f),
		geb::Vector4(-0.25f, +0.5f * sqrt3 / 6.0f       , 0.0f, 1.0f), geb::Vector4(0.9f, 0.45f, 0.17f, 1.0f),
		geb::Vector4(+0.25f, +0.5f * sqrt3 / 6.0f       , 0.0f, 1.0f), geb::Vector4(0.9f, 0.45f, 0.17f, 1.0f),
		geb::Vector4(+0.0f,  -0.5f * sqrt3 / 3.0f       , 0.0f, 1.0f), geb::Vector4(0.8f, 0.3f , 0.02f, 1.0f)
	};*/

	geb::ObjectTexture vertices[] =
	{
		geb::ObjectTexture(geb::Vector4(-0.5f, -0.5f, 0.0f, 1.0f), geb::Vector4(1.0f, 0.0f, 0.0f, 1.0f), geb::Vector2(0.0f, 0.0f)),
		geb::ObjectTexture(geb::Vector4(-0.5f, +0.5f, 0.0f, 1.0f), geb::Vector4(0.0f, 1.0f, 0.0f, 1.0f), geb::Vector2(0.0f, 1.0f)),
		geb::ObjectTexture(geb::Vector4(+0.5f, +0.5f, 0.0f, 1.0f), geb::Vector4(0.0f, 0.0f, 1.0f, 1.0f), geb::Vector2(1.0f, 1.0f)),
		geb::ObjectTexture(geb::Vector4(+0.5f, -0.5f, 0.0f, 1.0f), geb::Vector4(1.0f, 1.0f, 1.0f, 1.0f), geb::Vector2(1.0f, 0.0f))
	};

	unsigned int indices[] =
	{
		0, 2, 1,
		0, 3, 2
	};

	std::shared_ptr<geb::ShaderProgram> sp = geb::OpenGLApp::create_shader_program("Shader/simple_shader.vert", "Shader/simple_shader.frag");
	geb::VAO vao{};
	vao.bind();

	geb::VBO vbo{ (float*)&vertices, sizeof(vertices) };

	geb::EBO ebo{ indices, sizeof(indices) };

	vao.link_vbo(&vbo, 0, geb::ObjectTexture::GetdataSize(0), geb::FLOAT, geb::ObjectTexture::GetSize(), geb::ObjectTexture::GetOffsets(0));
	vao.link_vbo(&vbo, 1, geb::ObjectTexture::GetdataSize(1), geb::FLOAT, geb::ObjectTexture::GetSize(), geb::ObjectTexture::GetOffsets(1));
	vao.link_vbo(&vbo, 2, geb::ObjectTexture::GetdataSize(2), geb::FLOAT, geb::ObjectTexture::GetSize(), geb::ObjectTexture::GetOffsets(2));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();

	unsigned int scale_location = geb::Uniform::get_uniform_location(sp->GetId(), "scale");
	unsigned int texture_location = geb::Uniform::get_uniform_location(sp->GetId(), "tex0");

	geb::Texture texture;
	texture.GenerateTexture(
		"Gentleman.png", geb::TexId::TEXTURE0,
		geb::Filter::NEAREST, geb::Filter::NEAREST,
		geb::TexRepeat::CLAMP_TO_BORDER, geb::TexRepeat::CLAMP_TO_BORDER, geb::Vector4(0.0f, 0.0f, 0.0f, 1.0f));

	while (is_looping) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				is_looping = false;
				break;
			}
		}

		sp->use();
		geb::Uniform::set_uniform_f(scale_location, 0.5f);
		geb::Uniform::set_uniform_i(texture_location, 0);

		glClear(GL_COLOR_BUFFER_BIT);

		vao.bind();

		texture.bind();

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

		sdl_app.SwapWindow();
	}
	
	return 0;
}
