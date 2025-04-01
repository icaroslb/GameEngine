#include "CubeTextureCreator.h"

#include "CubeTextureModel.h"

std::shared_ptr<sge::VAOData> CubeTextureCreator::CreateVAOData() {
	std::shared_ptr<sge::VAOData> new_cube = std::make_shared<CubeTextureModel>();

	return new_cube;
}