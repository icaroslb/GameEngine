#include "CubeColor.h"

#include "Cube.h"

CubeColor::CubeColor() {
	_vao.bind();

	_vbo_data.push_back(std::make_shared<Cube>(_vao));

	_vao.unbind();
}