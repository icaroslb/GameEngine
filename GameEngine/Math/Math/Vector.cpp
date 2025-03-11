#include "Vector.h"
#include <cmath>
#include <immintrin.h>
#include <cstring>
#include <algorithm>

namespace geb {
	const size_t float4_size = sizeof(float) * 4;

	Vector::Vector() {
		std::fill_n(_data, 4, 0.0);
	}

	Vector::Vector(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w) {}

	Vector::Vector(const float* array) {
		memcpy(_data, array, float4_size);
	}

	Vector::Vector(const Vector& v) {
		memcpy(_data, v._data, float4_size);
	}

	const float Vector::X() const {
		return _x;
	}

	float& Vector::X() {
		return _x;
	}

	const float Vector::Y() const {
		return _y;
	}

	float& Vector::Y() {
		return _y;
	}

	const float Vector::Z() const {
		return _z;
	}

	float& Vector::Z() {
		return _z;
	}

	const float Vector::W() const {
		return _w;
	}

	float& Vector::W() {
		return _w;
	}

	const float* Vector::data() const {
		return _data;
	}

	float* Vector::data() {
		return _data;
	}

	Vector& Vector::operator= (const Vector& v) {
		if (this != &v) {
			memcpy(_data, v._data, float4_size);
		}

		return *this;
	}

	Vector Vector::operator+ (const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_add_ps(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
			memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
			memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator- (const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_sub_ps(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator* (const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_mul_ps(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator/ (const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_div_ps(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator* (const float& a) const {
		__m128 __v0;
		__m128 __a;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__a = _mm_set1_ps(a);

		// Perform the operation
		__result = _mm_mul_ps(__v0, __a);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator/ (const float& a) const {
		__m128 __v0;
		__m128 __a;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__a = _mm_set1_ps(a);

		// Perform the operation
		__result = _mm_div_ps(__v0, __a);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	Vector& Vector::operator+= (const Vector& v) {
		return *this = *this + v;
	}

	Vector& Vector::operator-= (const Vector& v) {
		return *this = *this - v;
	}

	Vector& Vector::operator*= (const Vector& v) {
		return *this = *this * v;
	}

	Vector& Vector::operator/= (const Vector& v) {
		return *this = *this / v;
	}

	Vector& Vector::operator*= (const float& a) {
		return *this = *this * a;
	}

	Vector& Vector::operator/= (const float& a) {
		return *this = *this * a;
	}

	float Vector::dot(const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __operation;
		__m128 __result;
		Vector result_vector0{};
		Vector result_vector1{};
		float result;

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__operation = _mm_mul_ps(__v0, __v1);

		__operation = _mm_hadd_ps(__operation, __operation);
		__result = _mm_hadd_ps(__operation, __operation);

		// Save the result in a scalar
#if defined(__linux__)				
		result = __result[0];
#endif

#if defined(_WIN32)
		result = __result.m128_f32[0];
#endif

		return result;
	}

	Vector Vector::cross(const Vector& v) const {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm_load_ps(_data);
		__v1 = _mm_load_ps(v._data);

		// Perform the operation
		__result = _mm_sub_ps(
			_mm_mul_ps(
				// Permute to [y, z, x ,w]
				_mm_shuffle_ps(__v0, __v0, _MM_SHUFFLE(3, 0, 2, 1)),
				// Permute to [z, x, y ,w]
				_mm_shuffle_ps(__v1, __v1, _MM_SHUFFLE(3, 1, 0, 2))
			),
			_mm_mul_ps(
				// Permute to [z, x, y ,w]
				_mm_shuffle_ps(__v0, __v0, _MM_SHUFFLE(3, 1, 0, 2)),
				// Permute to [y, z, x ,w]
				_mm_shuffle_ps(__v1, __v1, _MM_SHUFFLE(3, 0, 2, 1))
			)
		);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, float4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m128_f32, float4_size);
#endif

		return result_vector;
	}

	float Vector::square_norm() const {
		return dot(*this);
	}

	float Vector::norm() const {
		return sqrt(square_norm());
	}
};