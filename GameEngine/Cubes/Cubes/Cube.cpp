#include "Cube.h"

Cube::Cube(sge::VAO& vao) {
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

	_data =
	{
		sge::DataColorStruct(a000, c010),
		sge::DataColorStruct(a110, c001),
		sge::DataColorStruct(a100, c100),

		sge::DataColorStruct(a000, c010),
		sge::DataColorStruct(a010, c111),
		sge::DataColorStruct(a110, c001),


		sge::DataColorStruct(a001, c100),
		sge::DataColorStruct(a101, c010),
		sge::DataColorStruct(a111, c111),

		sge::DataColorStruct(a001, c100),
		sge::DataColorStruct(a111, c111),
		sge::DataColorStruct(a011, c001),


		sge::DataColorStruct(a101, c100),
		sge::DataColorStruct(a100, c010),
		sge::DataColorStruct(a110, c111),

		sge::DataColorStruct(a101, c100),
		sge::DataColorStruct(a110, c111),
		sge::DataColorStruct(a111, c001),


		sge::DataColorStruct(a001, c010),
		sge::DataColorStruct(a010, c001),
		sge::DataColorStruct(a000, c100),

		sge::DataColorStruct(a001, c010),
		sge::DataColorStruct(a011, c111),
		sge::DataColorStruct(a010, c001),


		sge::DataColorStruct(a010, c100),
		sge::DataColorStruct(a111, c111),
		sge::DataColorStruct(a110, c010),

		sge::DataColorStruct(a010, c100),
		sge::DataColorStruct(a011, c001),
		sge::DataColorStruct(a111, c111),


		sge::DataColorStruct(a000, c001),
		sge::DataColorStruct(a101, c010),
		sge::DataColorStruct(a001, c100),

		sge::DataColorStruct(a000, c001),
		sge::DataColorStruct(a100, c111),
		sge::DataColorStruct(a101, c010),
	};

	load(vao);
}