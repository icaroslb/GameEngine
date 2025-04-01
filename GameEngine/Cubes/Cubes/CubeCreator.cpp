#include "CubeCreator.h"

#include "CubeColor.h"

std::shared_ptr<sge::VAOData> CubeCreator::CreateVAOData() {
	std::shared_ptr<sge::VAOData> new_cube = std::make_shared<CubeColor>();

	return new_cube;
}