#ifndef SIMD_MATH_SIMD_H
#define SIMD_MATH_SIMD_H

#include <immintrin.h>
#include <cstring>

namespace geb {

#if defined(__linux__)
#define SAVE_ARRAY(dst_data, src_data, byte_size) memcpy(dst_data, src_data, byte_size)
#define SAVE_SCALAR(src_data, id, scalar) scalar = src_data[id]
#endif

#if defined(_WIN32)
#define SAVE_ARRAY(dst_data, src_data, byte_size) memcpy(dst_data, src_data.m128_f32, byte_size)
#define SAVE_SCALAR(src_data, id, scalar) scalar = src_data.m128_f32[id]
#endif

	const size_t float4_size = sizeof(float) * 4;
	const size_t float16_size = sizeof(float) * 16;

	/**
	* Vector sum
	* @param _v0: Vector to be added
	* @param _v1: Vector to be added
	* @param _result: Vector returned with the sum values
	*/
	inline void _vector_sum(const float* _v0, const float* _v1, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

		// Perform the operation
		__result = _mm_add_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Vector sub
	* @param _v0: Vector to be subtracted
	* @param _v1: Vector to be subtracted
	* @param _result: Vector returned with the sub values
	*/
	inline void _vector_sub(const float* _v0, const float* _v1, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

		// Perform the operation
		__result = _mm_sub_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Vector mul
	* @param _v0: Vector to be multiplied
	* @param _v1: Vector to be multiplied
	* @param _result: Vector returned with the mul values
	*/
	inline void _vector_mul(const float* _v0, const float* _v1, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

		// Perform the operation
		__result = _mm_mul_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Vector div
	* @param _v0: Vector to be divied
	* @param _v1: Vector to be divied
	* @param _result: Vector returned with the div values
	*/
	inline void _vector_div(const float* _v0, const float* _v1, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

		// Perform the operation
		__result = _mm_div_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Vector mul scalar
	* @param _v0: Vector to be multiplied
	* @param _a: Scalar to be multiplied
	* @param _result: Vector returned with the mul values
	*/
	inline void _vector_mul_scalar(const float* _v0, const float& _a, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_set1_ps(_a);

		// Perform the operation
		__result = _mm_mul_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Vector div scalar
	* @param _v0: Vector to be divided
	* @param _a: Scalar to be divided
	* @param _result: Vector returned with the div values
	*/
	inline void _vector_div_scalar(const float* _v0, const float& _a, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_set1_ps(_a);

		// Perform the operation
		__result = _mm_div_ps(__v0, __v1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Dot product
	* @param _v0: Vector to perform the operation
	* @param _v1: Vector to perform the operation
	* @param _result: Dot product result
	*/
	inline void _vector_dot(const float* _v0, const float* _v1, float& _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __operation;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

		// Perform the operation
		__operation = _mm_mul_ps(__v0, __v1);

		__operation = _mm_hadd_ps(__operation, __operation);
		__result = _mm_hadd_ps(__operation, __operation);

		// Save the result in a scalar
		SAVE_SCALAR(__result, 0, _result);
	}

	/**
	* Cross product
	* @param _v0: Vector to perform the operation
	* @param _v1: Vector to perform the operation
	* @param _result: Cross product result
	*/
	inline void _vector_cross(const float* _v0, const float* _v1, float* _result) {
		__m128 __v0;
		__m128 __v1;
		__m128 __result;

		// Load the values
		__v0 = _mm_load_ps(_v0);
		__v1 = _mm_load_ps(_v1);

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
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Matrix product
	* @param _m0: Matrix to be multiplied
	* @param _m1: Matrix to be multiplied
	* @param _result: Matrix returned with the product values
	*/
	inline void _matrix_mul(const float* _m0, const float* _m1, float* _result) {
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
			__m0[i] = _mm_load_ps(_m0 + (i * 4));
			__m1[i] = _mm_load_ps(_m1 + (i * 4));
		}

		// Perform the operation
		__result[0] = mul_vec_mat(__m0[0], __m1);
		__result[1] = mul_vec_mat(__m0[1], __m1);
		__result[2] = mul_vec_mat(__m0[2], __m1);
		__result[3] = mul_vec_mat(__m0[3], __m1);

		// Save the result in a new vector
		SAVE_ARRAY(_result, &(__result[0]), float16_size);
	}

	/**
	* Matrix Vector product
	* @param _m: Matrix to be multiplied
	* @param _v: Vector to be multiplied
	* @param _result: Vector returned with the product values
	*/
	inline void _matrix_vector_mul(const float* _m, const float* _v, float* _result) {
		__m128 __lines[4];
		__m128 __v;
		__m128 __result;

		// Load the values
		for (int i = 0; i < 4; i++) {
			__lines[i] = _mm_load_ps((_m + (i * 4)));
		}

		__v = _mm_load_ps(_v);

		// Perform the operation
		__result = _mm_mul_ps(__lines[0], __v);
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[1], __v));
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[2], __v));
		__result = _mm_add_ps(__result, _mm_mul_ps(__lines[3], __v));

		// Save the result in a new vector
		SAVE_ARRAY(_result, __result, float4_size);
	}

	/**
	* Matrix transpose
	* @param _m: Matrix to be transposed
	* @param _m_result: Matrix returned with transpose values
	*/
	inline void _matrix_transpose(const float* _m, float* _m_result) {
		__m128 __lines[4];

		// Load the values
		for (int i = 0; i < 4; i++) {
			__lines[i] = _mm_load_ps((_m + (i * 4)));
		}

		_MM_TRANSPOSE4_PS(__lines[0], __lines[1], __lines[2], __lines[3]);

		// Save the result in a new vector
		SAVE_ARRAY(_m_result, &(__lines[0]), float16_size);
	}

	/**
	* Matrix quaternion
	* Generates the matrix of a quaternion rotation
	* @param _q: Quaternion rotation
	* @param _m_result: Matrix of the quaternion rotation
	*/
	inline void _matrix_quaternion(const float* _q, float* _m_result) {
		const float _twos[4] = { +2.0f, -2.0f, +2.0f, +2.0f };
		const float _ones[16] = { 
			+1.0f, -1.0f, -1.0f, +1.0f,
			-1.0f, +1.0f, -1.0f, +1.0f,
			-1.0f, -1.0f, +1.0f, +1.0f,
			+1.0f, +1.0f, +1.0f, +1.0f };
		
		__m128 __q;
		__m128 __ones[4];
		__m128 __twos;

		__m128 __result;
		__m128 __q_others;
		__m128 __q_mul;

		// Zerates the matrix
		memset(_m_result, 0, float16_size);

		// Load the values
		__q = _mm_load_ps(_q);

		for (int i = 0; i < 4; i++) {
			__ones[i] = _mm_load_ps(_ones + (i * 4));
		}

		__twos = _mm_load_ps(_twos);


		//////////////////////////////
		// Calculates others values //
		//////////////////////////////


			////////////////////////////
			// Values [0,1] and [1,0] //
			////////////////////////////
		__q_others = _mm_shuffle_ps(__q, __q, _MM_SHUFFLE(3, 0, 3, 0)); // [ x w x w ]
		__q_mul = _mm_shuffle_ps(__q, __q, _MM_SHUFFLE(2, 1, 2, 1));    // [ y z y z ]

		__q_mul = _mm_mul_ps(__q_others, __q_mul);
		__q_mul = _mm_mul_ps(__q_mul, __twos);
		__result = _mm_hadd_ps(__q_mul, __q_mul);

		SAVE_SCALAR(__result, 0, _m_result[1]);
		SAVE_SCALAR(__result, 1, _m_result[4]);

			////////////////////////////
			// Values [0,2] and [2,0] //
			////////////////////////////                                // [ x w x w ]
		__q_mul = _mm_shuffle_ps(__q, __q, _MM_SHUFFLE(1, 2, 1, 2));    // [ z y z y ]

		__q_mul = _mm_mul_ps(__q_others, __q_mul);
		__q_mul = _mm_mul_ps(__q_mul, __twos);
		__result = _mm_hadd_ps(__q_mul, __q_mul);

		SAVE_SCALAR(__result, 0, _m_result[2]);
		SAVE_SCALAR(__result, 1, _m_result[8]);

			////////////////////////////
			// Values [1,2] and [2,1] //
			////////////////////////////
		__q_others = _mm_shuffle_ps(__q, __q, _MM_SHUFFLE(3, 1, 3, 1)); // [ x w x w ]
		__q_mul = _mm_shuffle_ps(__q, __q, _MM_SHUFFLE(0, 2, 0, 2));    // [ z x z x ]

		__q_mul = _mm_mul_ps(__q_others, __q_mul);
		__q_mul = _mm_mul_ps(__q_mul, __twos);
		__result = _mm_hadd_ps(__q_mul, __q_mul);

		SAVE_SCALAR(__result, 0, _m_result[6]);
		SAVE_SCALAR(__result, 1, _m_result[9]);


		/////////////////////////////
		// Calculates the diagonal //
		/////////////////////////////


		__q = _mm_mul_ps(__q, __q); // square q

		for (int i = 0; i < 4; i++) {
			__ones[i] = _mm_mul_ps(__q, __ones[i]);
		}

		_MM_TRANSPOSE4_PS(__ones[0], __ones[1], __ones[2], __ones[3]);

		__result = _mm_add_ps(__ones[0], __ones[1]);
		__result = _mm_add_ps(__result, __ones[2]);
		__result = _mm_add_ps(__result, __ones[3]);

		SAVE_SCALAR(__result, 0, _m_result[0]);
		SAVE_SCALAR(__result, 1, _m_result[5]);
		SAVE_SCALAR(__result, 2, _m_result[10]);
		SAVE_SCALAR(__result, 3, _m_result[15]);
	}
};


#endif // SIMD_MATH_SIMD_H