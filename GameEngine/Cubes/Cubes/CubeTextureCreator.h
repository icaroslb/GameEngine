#ifndef CUBE_TEXTURE_CREATOR_H
#define CUBE_TEXTURE_CREATOR_H

#include <Data/VAODataCreator.h>

class CubeTextureCreator : public sge::VAODataCreator {
public:
	virtual std::shared_ptr<sge::VAOData> CreateVAOData();
};

#endif // CUBE_CREATOR_H