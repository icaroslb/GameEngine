// GameEngine.cpp: define o ponto de entrada para o aplicativo.
//

#include "GameEngine.h"
#include "Math/Vector.h"
#include "Math/Matrix.h"
#include "Math/TransformationMatrix.h"
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <limits>

const int vectors_size = 10000;
const int qtd_loops = 10000;

int main()
{
	geb::Vector v0{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector v1{ 5.0, 2.0, 3.0, 0.0 };
	geb::Vector v2 = v0 - v1;
	double dot = v0.dot(v1);

	std::cout << dot << std::endl;

	std::cout << v2 << std::endl;

	geb::Matrix m0{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};

	geb::Matrix m1{
		1.0f,  2.0f,  3.0f,  4.0f,
		5.0f,  6.0f,  7.0f,  8.0f,
		9.0f,  10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	};
	geb::Matrix m2 = m0 * m1;

	std::cout << m2 << std::endl;

	geb::TransformationMatrix tm0;

	std::cout << tm0 << std::endl;
	
	return 0;
}
