#ifndef CUBE_H
#define CUBE_H

#include <Data/VBOColorData.h>

class Cube : public sge::VBOColorData {
public:
	Cube(sge::VAO& vao);
};

#endif // CUBE_H