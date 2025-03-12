#include "Matrix.h"
#include "SIMD_Math/simd.h"

#include <algorithm>

namespace geb {
	Matrix::Matrix() {
		std::fill_n(_data, 16, 0.0);
	}

	Matrix::Matrix(
		float v0, float v1, float v2, float v3,
		float v4, float v5, float v6, float v7,
		float v8, float v9, float v10, float v11,
		float v12, float v13, float v14, float v15)
	: _d0(v0),   _d1(v1),   _d2(v2),   _d3(v3)
	, _d4(v4),   _d5(v5),   _d6(v6),   _d7(v7) 
	, _d8(v8),   _d9(v9),   _d10(v10), _d11(v11) 
	, _d12(v12), _d13(v13), _d14(v14), _d15(v15) {}
	
	Matrix::Matrix(const float* array) {
		memcpy(_data, array, float16_size);
	}

	Matrix::Matrix(const Matrix& m) {
		memcpy(_data, m._data, float16_size);
	}

	const float Matrix::operator()(size_t line, size_t column) const {
		return _data[column + (4 * line)];
	}

	float Matrix::operator()(size_t line, size_t column) {
		return _data[column + (4 * line)];
	}

	Matrix& Matrix::operator= (const Matrix& m) {
		if (this != &m) {
			memcpy(_data, m._data, float16_size);
		}

		return *this;
	}

	Matrix Matrix::operator+ (const Matrix& m) const {
		Matrix result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] + m._vectors[i];
		}

		return result;
	}

	Matrix Matrix::operator- (const Matrix& m) const {
		Matrix result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] - m._vectors[i];
		}

		return result;
	}

	Matrix Matrix::operator* (const Matrix& m) const {
		Matrix result;

		_matrix_mul(_data, m._data, result._data);

		return result;
	}

	Vector Matrix::operator* (const Vector& v) const {
		Vector result;

		_matrix_vector_mul(_data, v._data, result._data);

		return result;
	}

	Matrix Matrix::operator* (float a) const {
		Matrix result;

		for (int i = 0; i < 4; i++) {
			result._vectors[i] = _vectors[i] * a;
		}

		return result;
	}

	Matrix& Matrix::operator+= (const Matrix& m) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] + m._vectors[i];
		}
		
		return *this;
	}

	Matrix& Matrix::operator-= (const Matrix& m) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] - m._vectors[i];
		}
		
		return *this;
	}

	Matrix& Matrix::operator*= (const Matrix& m) {
		_matrix_mul(_data, m._data, _data);
		
		return *this;
	}

	Matrix& Matrix::operator*= (float a) {
		for (int i = 0; i < 4; i++) {
			_vectors[i] = _vectors[i] * a;
		}
		
		return *this = *this * a;
	}

	std::ostream& operator <<(std::ostream& os, const Matrix& m) {
		return os << m._vectors[0] << m._vectors[1] << m._vectors[2] << m._vectors[3];
	}
}