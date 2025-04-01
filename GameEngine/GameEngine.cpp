// GameEngine.cpp: define o ponto de entrada para o aplicativo.
//

//#define SDL_MAIN_HANDLED

#include "GameEngine.h"
#include "Math/Vector4.h"
#include "Math/Matrix4.h"
#include "Math/TransformationMatrix4.h"
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
#include "Graphic/Camera.h"

//#include "Data/ObjectTexture.h"

#include <SDL3/SDL_main.h>

#include <Cubes/Cube.h>
#include <Cubes/CubeTexture.h>
#include <Cubes/CubeCreator.h>
#include <Cubes/CubeTextureCreator.h>

int main(int argc, char* argv[]) {
	//SDL_SetMainReady();
	sge::Sdl3App sdl_app(SDL_INIT_VIDEO | SDL_INIT_EVENTS, 4, 6);

	sdl_app.CreateWindow("TESTE", 500, 500, SDL_WINDOW_OPENGL);

	SDL_Event e;
	bool is_looping = true;

	glViewport(0, 0, 500, 500);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	sdl_app.SwapWindow();

	const sge::Vector4 a000 = sge::Vector4(-2.0f, -2.0f, -2.0f, 1.0f);
	const sge::Vector4 a100 = sge::Vector4(+2.0f, -2.0f, -2.0f, 1.0f);
	const sge::Vector4 a010 = sge::Vector4(-2.0f, +2.0f, -2.0f, 1.0f);
	const sge::Vector4 a110 = sge::Vector4(+2.0f, +2.0f, -2.0f, 1.0f);

	const sge::Vector4 a001 = sge::Vector4(-2.0f, -2.0f, +2.0f, 1.0f);
	const sge::Vector4 a101 = sge::Vector4(+2.0f, -2.0f, +2.0f, 1.0f);
	const sge::Vector4 a011 = sge::Vector4(-2.0f, +2.0f, +2.0f, 1.0f);
	const sge::Vector4 a111 = sge::Vector4(+2.0f, +2.0f, +2.0f, 1.0f);

	const sge::Vector4 c100 = sge::Vector4(1.0f, 0.0f, 0.0f, 1.0f);
	const sge::Vector4 c010 = sge::Vector4(0.0f, 0.1f, 0.0f, 1.0f);
	const sge::Vector4 c001 = sge::Vector4(0.0f, 0.0f, 1.0f, 1.0f);
	const sge::Vector4 c111 = sge::Vector4(1.0f, 1.0f, 1.0f, 1.0f);

	const sge::Vector2 uv00 = sge::Vector2(0.0f, 0.0f);
	const sge::Vector2 uv10 = sge::Vector2(1.0f, 0.0f);
	const sge::Vector2 uv01 = sge::Vector2(0.0f, 1.0f);
	const sge::Vector2 uv11 = sge::Vector2(1.0f, 1.0f);

	/*sge::ObjectTexture vertices[] =
	{
		sge::ObjectTexture(a000, c010, uv10),
		sge::ObjectTexture(a110, c001, uv01),
		sge::ObjectTexture(a100, c100, uv00),

		sge::ObjectTexture(a000, c010, uv10),
		sge::ObjectTexture(a010, c111, uv11),
		sge::ObjectTexture(a110, c001, uv01),


		sge::ObjectTexture(a001, c100, uv00),
		sge::ObjectTexture(a101, c010, uv10),
		sge::ObjectTexture(a111, c111, uv11),

		sge::ObjectTexture(a001, c100, uv00),
		sge::ObjectTexture(a111, c111, uv11),
		sge::ObjectTexture(a011, c001, uv01),


		sge::ObjectTexture(a101, c100, uv00),
		sge::ObjectTexture(a100, c010, uv10),
		sge::ObjectTexture(a110, c111, uv11),

		sge::ObjectTexture(a101, c100, uv00),
		sge::ObjectTexture(a110, c111, uv11),
		sge::ObjectTexture(a111, c001, uv01),


		sge::ObjectTexture(a001, c010, uv10),
		sge::ObjectTexture(a010, c001, uv01),
		sge::ObjectTexture(a000, c100, uv00),

		sge::ObjectTexture(a001, c010, uv10),
		sge::ObjectTexture(a011, c111, uv11),
		sge::ObjectTexture(a010, c001, uv01),


		sge::ObjectTexture(a010, c100, uv00),
		sge::ObjectTexture(a111, c111, uv11),
		sge::ObjectTexture(a110, c010, uv10),

		sge::ObjectTexture(a010, c100, uv00),
		sge::ObjectTexture(a011, c001, uv01),
		sge::ObjectTexture(a111, c111, uv11),


		sge::ObjectTexture(a000, c001, uv01),
		sge::ObjectTexture(a101, c010, uv10),
		sge::ObjectTexture(a001, c100, uv00),

		sge::ObjectTexture(a000, c001, uv01),
		sge::ObjectTexture(a100, c111, uv11),
		sge::ObjectTexture(a101, c010, uv10),
	};*/

	unsigned int indices[] =
	{
		0, 1, 2,
		3, 4, 5,

		6, 7, 8,
		9, 10, 11,
		
		12, 13, 14
	};

	std::shared_ptr<sge::ShaderProgram> sp = sge::OpenGLApp::create_shader_program("Shader/simple_shader.vert", "Shader/simple_shader.frag");
	sge::VAO vao{};

	//vao.bind();

	//CubeTexture cube{ vao };
	
	CubeTextureCreator cube_creator;
	std::shared_ptr<sge::VAOData> cube = cube_creator.CreateVAOData();

	/*sge::VBO vbo;
	sge::EBO ebo;

	vbo.load((float*)&vertices, sizeof(vertices));
	ebo.load(indices, sizeof(indices));

	vao.link_vbo(&vbo, 0, sge::ObjectTexture::GetdataSize(0), sge::FLOAT, sge::ObjectTexture::GetSize(), sge::ObjectTexture::GetOffsets(0));
	vao.link_vbo(&vbo, 1, sge::ObjectTexture::GetdataSize(1), sge::FLOAT, sge::ObjectTexture::GetSize(), sge::ObjectTexture::GetOffsets(1));
	vao.link_vbo(&vbo, 2, sge::ObjectTexture::GetdataSize(2), sge::FLOAT, sge::ObjectTexture::GetSize(), sge::ObjectTexture::GetOffsets(2));
	vao.unbind();
	vbo.unbind();
	ebo.unbind();*/

	//vao.unbind();

	unsigned int scale_location = sge::Uniform::get_uniform_location(sp->GetId(), "scale");
	unsigned int texture_location = sge::Uniform::get_uniform_location(sp->GetId(), "tex0");
	unsigned int option_location = sge::Uniform::get_uniform_location(sp->GetId(), "option");
	unsigned int resolution_location = sge::Uniform::get_uniform_location(sp->GetId(), "resolution");
	unsigned int mat_view_location = sge::Uniform::get_uniform_location(sp->GetId(), "mat_view");
	unsigned int mat_proj_location = sge::Uniform::get_uniform_location(sp->GetId(), "mat_proj");

	sge::Texture texture;
	texture.GenerateTexture(
		"sarue.png", sge::TexId::TEXTURE0,
		sge::Filter::NEAREST, sge::Filter::NEAREST,
		sge::TexRepeat::CLAMP_TO_BORDER, sge::TexRepeat::CLAMP_TO_BORDER, sge::Vector4(0.0f, 0.0f, 0.0f, 1.0f));

	int option = -1;

	sge::Vector4 camera_position(6.0f, 6.0f, -6.0f, 1.0f);
	sge::Vector4 look_at(0.0f, 0.0f, 0.0f, 1.0f);
	sge::Vector4 up_position = camera_position + sge::Vector4(0.0f, 1.0f, 0.0f, 0.0f);

	sge::Camera camera{ camera_position, look_at, up_position};

	camera.GenerateProjection(sge::projection_types::perspective, 1.0f, -1.0f, 1.0f, -1.0f, 100.0f, 1.0f);

	while (is_looping) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT ||
				(e.type == SDL_EVENT_KEY_UP && e.key.key == SDLK_ESCAPE)) {
				is_looping = false;
				break;
			}

			if (e.type == SDL_EVENT_KEY_UP) {
				switch (e.key.key)
				{
				case SDLK_KP_0:
				case SDLK_0:
					option = 0;
					break;
				case SDLK_KP_1:
				case SDLK_1:
					option = 1;
					break;
				case SDLK_KP_2:
				case SDLK_2:
					option = 2;
					break;
				case SDLK_KP_3:
				case SDLK_3:
					option = 3;
					break;
				case SDLK_KP_4:
				case SDLK_4:
					option = 4;
					break;
				case SDLK_KP_5:
				case SDLK_5:
					option = 5;
					break;
				case SDLK_KP_6:
				case SDLK_6:
					option = 6;
					break;
				case SDLK_KP_7:
				case SDLK_7:
					option = 7;
					break;
				case SDLK_KP_8:
				case SDLK_8:
					option = 8;
					break;
				case SDLK_KP_9:
				case SDLK_9:
					option = 9;
					break;
				default:
					option = -1;
					break;
				}
			}
		}

		sp->use();
		
		sge::Uniform::set_uniform_i(texture_location, 0);
		sge::Uniform::set_uniform_i(option_location, option);
		sge::Uniform::set_uniform_vec2(resolution_location, 1, texture.GetResolution().data());
		sge::Uniform::set_uniform_mat4(mat_view_location, 1, true, camera.GetMatrixView().data());
		sge::Uniform::set_uniform_mat4(mat_proj_location, 1, true, camera.GetMatrixProjection().data());

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//vao.bind();
		cube->bind();

		texture.bind();

		// glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		//glDrawElements(GL_TRIANGLES, 15, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 36);
		cube->draw();

		cube->unbind();

		sdl_app.SwapWindow();
	}
	
	return 0;
}
