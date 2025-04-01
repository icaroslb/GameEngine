#include "CubeTexture.h"

CubeTexture::CubeTexture(sge::VAO& vao) {
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

	const sge::Vector2 uv00 = sge::Vector2(0.0f, 0.0f);
	const sge::Vector2 uv10 = sge::Vector2(1.0f, 0.0f);
	const sge::Vector2 uv01 = sge::Vector2(0.0f, 1.0f);
	const sge::Vector2 uv11 = sge::Vector2(1.0f, 1.0f);

	_data =
	{
		sge::DataTextureStruct(a000, c010, uv10),
		sge::DataTextureStruct(a110, c001, uv01),
		sge::DataTextureStruct(a100, c100, uv00),

		sge::DataTextureStruct(a000, c010, uv10),
		sge::DataTextureStruct(a010, c111, uv11),
		sge::DataTextureStruct(a110, c001, uv01),


		sge::DataTextureStruct(a001, c100, uv00),
		sge::DataTextureStruct(a101, c010, uv10),
		sge::DataTextureStruct(a111, c111, uv11),

		sge::DataTextureStruct(a001, c100, uv00),
		sge::DataTextureStruct(a111, c111, uv11),
		sge::DataTextureStruct(a011, c001, uv01),


		sge::DataTextureStruct(a101, c100, uv00),
		sge::DataTextureStruct(a100, c010, uv10),
		sge::DataTextureStruct(a110, c111, uv11),

		sge::DataTextureStruct(a101, c100, uv00),
		sge::DataTextureStruct(a110, c111, uv11),
		sge::DataTextureStruct(a111, c001, uv01),


		sge::DataTextureStruct(a001, c010, uv10),
		sge::DataTextureStruct(a010, c001, uv01),
		sge::DataTextureStruct(a000, c100, uv00),

		sge::DataTextureStruct(a001, c010, uv10),
		sge::DataTextureStruct(a011, c111, uv11),
		sge::DataTextureStruct(a010, c001, uv01),


		sge::DataTextureStruct(a010, c100, uv00),
		sge::DataTextureStruct(a111, c111, uv11),
		sge::DataTextureStruct(a110, c010, uv10),

		sge::DataTextureStruct(a010, c100, uv00),
		sge::DataTextureStruct(a011, c001, uv01),
		sge::DataTextureStruct(a111, c111, uv11),


		sge::DataTextureStruct(a000, c001, uv01),
		sge::DataTextureStruct(a101, c010, uv10),
		sge::DataTextureStruct(a001, c100, uv00),

		sge::DataTextureStruct(a000, c001, uv01),
		sge::DataTextureStruct(a100, c111, uv11),
		sge::DataTextureStruct(a101, c010, uv10),
	};

	load(vao);
}