#ifndef CUBE_TEXTURE_H
#define CUBE_TEXTURE_H

#include <Data/VBOTextureData.h>

class CubeTexture : public sge::VBOTextureData {
public:
	CubeTexture(sge::VAO& vao);
};

#endif // CUBE_TEXTURE_H