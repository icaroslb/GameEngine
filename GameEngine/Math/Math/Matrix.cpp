#include "Matrix.h"
#include <immintrin.h>
#include <algorithm>

const size_t float4_size = sizeof(float) * 4;
const size_t float16_size = sizeof(float) * 16;

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
		__m128 __m0[4];
		__m128 __m1[4];
		__m128 __result[4];

		auto mul_vec_mat = [&](const __m128& v, const __m128 m[4]) -> __m128 {
				__m128 v_x = _mm_shuffle_ps(v, v, 0x00); // [ x x x x ]
				__m128 v_y = _mm_shuffle_ps(v, v, 0x55); // [ y y y y ]
				__m128 v_z = _mm_shuffle_ps(v, v, 0xaa); // [ z z z z ]
				__m128 v_w = _mm_shuffle_ps(v, v, 0xff); // [ w w w w ]

				__m128 result = _mm_mul_ps(v_x, m[0]);
				result = _mm_add_ps(result, _mm_mul_ps(v_y, m[1]));
				result = _mm_add_ps(result, _mm_mul_ps(v_z, m[2]));
				result = _mm_add_ps(result, _mm_mul_ps(v_w, m[3]));

				return result;
			};

		// Load the values
		for (int i = 0; i < 4; i++) {
			__m0[i] = _mm_load_ps(_vectors[i]._data);
			__m1[i] = _mm_load_ps(m._vectors[i]._data);
		}

		

		// Perform the operation
		__result[0] = mul_vec_mat(__m0[0], __m1);
		__result[1] = mul_vec_mat(__m0[1], __m1);
		__result[2] = mul_vec_mat(__m0[2], __m1);
		__result[3] = mul_vec_mat(__m0[3], __m1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result._data, &__result[0], float16_size);
#endif

#if defined(_WIN32)
		memcpy(result._data, &__result[0].m128_f32, float16_size);
#endif

		return result;
	}

	Vector Matrix::operator* (const Vector& v) const {
		Vector result;

		__m128 __lines[4];
		__m128 __v;
		__m128 __result;

		// Load the values
		for (int i = 0; i < 4; i++) {
			__lines[i] = _mm_load_ps(_vectors[i]._data);
		}
		__v = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_mul_ps(__lines[0], __v);
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[1], __v));
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[2], __v));
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[3], __v));

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result._data, __result.m128_f32, float4_size);
#endif

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
		return *this = *this + m;
	}

	Matrix& Matrix::operator-= (const Matrix& m) {
		return *this = *this - m;
	}

	Matrix& Matrix::operator*= (const Matrix& m) {
		return *this = *this * m;
	}

	Matrix& Matrix::operator*= (float a) {
		return *this = *this * a;
	}
}