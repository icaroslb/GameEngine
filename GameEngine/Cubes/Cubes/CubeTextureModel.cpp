#include "CubeTextureModel.h"

#include "CubeTexture.h"

CubeTextureModel::CubeTextureModel() {
	_vao.bind();

	_vbo_data.push_back(std::make_shared<CubeTexture>(_vao));

	_vao.unbind();
}