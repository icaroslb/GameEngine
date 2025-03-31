#include "Matrix4.h"
#include "SIMD_Math/simd.h"

#include <algorithm>

namespace geb {
	Matrix4::Matrix4() {
		std::fill_n(_data, 16, 0.0);
	}

	Matrix4::Matrix4(
		float v0, float v1, float v2, float v3,
		float v4, float v5, float v6, float v7,
		float v8, float v9, float v10, float v11,
		float v12, float v13, float v14, float v15)
	: _d0(v0),   _d1(v1),   _d2(v2),   _d3(v3)
	, _d4(v4),   _d5(v5),   _d6(v6),   _d7(v7) 
	, _d8(v8),   _d9(v9),   _d10(v10), _d11(v11) 
	, _d12(v12), _d13(v13), _d14(v14), _d15(v15) {}
	
	Matrix4::Matrix4(const MatrixTypes& type) {
		switch (type)
		{
		case MatrixTypes::zeros:
			std::fill_n(_data, 16, 0.0);
			break;
		case MatrixTypes::ones:
			std::fill_n(_data, 16, 1.0);
			break;
		case MatrixTypes::identity:
		default:
			std::fill_n(_data, 16, 0.0);
			_data[0] = 1.0f;
			_data[5] = 1.0f;
			_data[10] = 1.0f;
			_data[15] = 1.0f;
			break;
		}
	}

	Matrix4::Matrix4(const float* array) {
		memcpy(_data, array, float16_size);
	}

	Matrix4::Matrix4(const Matrix4& m) {
		memcpy(_data, m._data, float16_size);
	}

	const float Matrix4::operator()(size_t line, size_t column) const {
		return _data[column + (4 * line)];
	}

	float& Matrix4::operator()(size_t line, size_t column) {
		return _data[column + (4 * line)];
	}

	const Vector4 Matrix4::operator[](size_t line) const {
		return _vectors[line];
	}

	Vector4& Matrix4::operator[](size_t line) {
		return _vectors[line];
	}

	const float* Matrix4::data() const {
		return _data;
	}

	float* Matrix4::data() {
		return _data;
	}

	Matrix4& Matrix4::operator= (const Matrix4& m) {
		if (this != &m) {
			memcpy(_data, m._data, float16_size);
		}

		return *this;
	}

	Matrix4 Matrix4::operator+ (const Matrix4& m) const {
		Matrix4 result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] + m._vectors[i];
		}

		return result;
	}

	Matrix4 Matrix4::operator- (const Matrix4& m) const {
		Matrix4 result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] - m._vectors[i];
		}

		return result;
	}

	Matrix4 Matrix4::operator* (const Matrix4& m) const {
		Matrix4 result;

		_matrix4_mul(_data, m._data, result._data);

		return result;
	}

	Vector4 Matrix4::operator* (const Vector4& v) const {
		Vector4 result;

		_matrix4_vector4_mul(_data, v._data, result._data);

		return result;
	}

	Matrix4 Matrix4::operator* (float a) const {
		Matrix4 result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] * a;
		}

		return result;
	}

	Matrix4& Matrix4::operator+= (const Matrix4& m) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] + m._vectors[i];
		}
		
		return *this;
	}

	Matrix4& Matrix4::operator-= (const Matrix4& m) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] - m._vectors[i];
		}
		
		return *this;
	}

	Matrix4& Matrix4::operator*= (const Matrix4& m) {
		_matrix4_mul(_data, m._data, _data);
		
		return *this;
	}

	Matrix4& Matrix4::operator*= (float a) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] * a;
		}
		
		return *this = *this * a;
	}

	Matrix4& Matrix4::transpose() {
		_matrix4_transpose(_data, _data);
		
		return *this;
	}

	Matrix4 Matrix4::transposed() {
		Matrix4 result;

		_matrix4_transpose(_data, result._data);

		return result;
	}

	std::ostream& operator <<(std::ostream& os, const Matrix4& m) {
		return os << m._vectors[0] << m._vectors[1] << m._vectors[2] << m._vectors[3];
	}
}