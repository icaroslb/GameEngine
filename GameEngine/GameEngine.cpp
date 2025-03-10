// GameEngine.cpp: define o ponto de entrada para o aplicativo.
//

#include "GameEngine.h"
#include "Math/Vector.h"


int main()
{
	geb::Vector v0{ 1.0, 0.0, 0.0, 0.0 };
	geb::Vector v1{ 0.0, 1.0, 0.0, 0.0 };
	geb::Vector v2 = v0.cross(v1);

	std::cout << v2.X() << " " << v2.Y() << " " << v2.Z() << " " << v2.W() << std::endl;
	
	return 0;
}
