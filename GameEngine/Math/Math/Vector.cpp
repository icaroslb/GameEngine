#include "Vector.h"
#include "cmath"
#include <immintrin.h>
#include <cstring>
#include <algorithm>
#include <iostream>

namespace geb {
	const size_t double4_size = sizeof(double) * 4;

	Vector::Vector() {
		std::fill_n(_data, 4, 0.0);
	}

	Vector::Vector(double x, double y, double z, double w) : _x(x), _y(y), _z(z), _w(w) {}

	Vector::Vector(const Vector& v) {
		memcpy(_data, v._data, double4_size);
	}

	double Vector::X() const {
		return _x;
	}

	double Vector::Y() const {
		return _y;
	}

	double Vector::Z() const {
		return _z;
	}

	double Vector::W() const {
		return _w;
	}

	const double* Vector::data() const {
		return _data;
	}

	Vector& Vector::operator= (const Vector& v) {
		if (this != &v) {
			memcpy(_data, v._data, double4_size);
		}

		return *this;
	}

	Vector Vector::operator+ (const Vector& v) const {
		__m256d __v0, __v1, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__result = _mm256_add_pd(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
			memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
			memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator- (const Vector& v) const {
		__m256d __v0, __v1, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__result = _mm256_sub_pd(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator* (const Vector& v) const {
		__m256d __v0, __v1, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__result = _mm256_mul_pd(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator/ (const Vector& v) const {
		__m256d __v0, __v1, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__result = _mm256_div_pd(__v0, __v1);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator* (const double& a) const {
		__m256d __v0, __a, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__a = _mm256_set1_pd(a);

		// Perform the operation
		__result = _mm256_mul_pd(__v0, __a);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	Vector Vector::operator/ (const double& a) const {
		__m256d __v0, __a, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__a = _mm256_set1_pd(a);

		// Perform the operation
		__result = _mm256_div_pd(__v0, __a);

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	double Vector::dot(const Vector& v) const {
		__m256d __v0, __v1, __v_permute_value, __operation_result, __result;
		Vector result_vector0{};
		Vector result_vector1{};
		double result;

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__operation_result = _mm256_mul_pd(__v0, __v1);

		/** 
		* 1. Permute the vector [x, y, z, w] to [z, w, x, y]
		* 2. Adds the the two vector, getting [x+z, y+w, x+z, y+w]
		* 3. Permute the vector [x+z, y+w, x+z, y+w] to [y+w, x+z, y+w, x+z]
		* 4. Adds again, getting [x+z+y+w, y+w+x+z, x+z+y+w, y+w+x+z]
		*/
		__v_permute_value = _mm256_permute2f128_pd(__operation_result, __operation_result, 0b01);
		__operation_result = _mm256_add_pd(__operation_result, __v_permute_value);
		__v_permute_value = _mm256_permute_pd(__operation_result, 0b0101);
		__result = _mm256_add_pd(__operation_result, __v_permute_value);

		// Save the result in a scalar
#if defined(__linux__)				
		result = __result[0];
#endif

#if defined(_WIN32)
		result = __result.m256d_f64[0];
#endif

		return result;
	}

	Vector Vector::cross(const Vector& v) const {
		__m256d __v0, __v1, __result;
		Vector result_vector{};

		// Load the values
		__v0 = _mm256_load_pd(_data);
		__v1 = _mm256_load_pd(v._data);

		// Perform the operation
		__result = _mm256_sub_pd(
			_mm256_mul_pd(
				// Permute to [y, z, x ,w]
				_mm256_permute4x64_pd(__v0, 0b11001001),
				// Permute to [z, x, y ,w]
				_mm256_permute4x64_pd(__v1, 0b11010010)),
			_mm256_mul_pd(
				// Permute to [z, x, y ,w]
				_mm256_permute4x64_pd(__v0, 0b11010010),
				// Permute to [y, z, x ,w]
				_mm256_permute4x64_pd(__v1, 0b11001001)));

		// Save the result in a new vector
#if defined(__linux__)				
		memcpy(result_vector._data, __result, double4_size);
#endif

#if defined(_WIN32)
		memcpy(result_vector._data, __result.m256d_f64, double4_size);
#endif

		return result_vector;
	}

	double Vector::square_norm() const {
		return dot(*this);
	}

	double Vector::norm() const {
		return sqrt(square_norm());
	}
};