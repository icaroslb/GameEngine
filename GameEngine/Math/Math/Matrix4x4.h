#ifndef MATH_MATRIX4x4_H
#define MATH_MATRIX4x4_H

#include "Vector4.h"

namespace geb {
	/**
	* Matrix 4x4
	* Divided by rows
	*/
	class Matrix4x4 {
	public:
		Matrix4x4();
		Matrix4x4(
			float v0, float v1, float v2, float v3,
			float v4, float v5, float v6, float v7,
			float v8, float v9, float v10, float v11,
			float v12, float v13, float v14, float v15);
		Matrix4x4(const float* array);
		Matrix4x4(const Matrix4x4& m);

		/**
		* Get the element in the line and column
		* @param line: Line position
		* @param column: Column position
		* @return The value from line and column position
		*/
		const float operator()(size_t line, size_t column) const;

		/**
		* Get the element in the line and column
		* @param line: Line position
		* @param column: Column position
		* @return The value from line and column position
		*/
		float& operator()(size_t line, size_t column);

		/**
		* Vector values array
		* @return values array
		*/
		const float* data() const;

		/**
		* Vector values array
		* @return values array
		*/
		      float* data();

		Matrix4x4& operator= (const Matrix4x4& m);

		/**
		* Matrix4x4 sum
		* @param m: Matrix4x4 to be added
		* @return Matrix4x4 with the sum values
		*/
		Matrix4x4 operator+ (const Matrix4x4& m) const;

		/**
		* Matrix4x4 subtraction
		* @param m: Matrix4x4 to be subtracted
		* @return Matrix4x4 with the subtraction values
		*/
		Matrix4x4 operator- (const Matrix4x4& m) const;

		/**
		* Matrix4x4 product
		* @param m: Matrix4x4 to be multiplied
		* @return Matrix4x4 with the product values
		*/
		Matrix4x4 operator* (const Matrix4x4& m) const;

		/**
		* Vector product
		* @param v: Vector to be multiplied
		* @return Vector with the product values
		*/
		Vector4 operator* (const Vector4& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix4x4 with the product values
		*/
		Matrix4x4 operator* (float a) const;

		/**
		* Matrix4x4 sum
		* @param m: Matrix4x4 to be added
		* @return Matrix4x4 with the sum values
		*/
		Matrix4x4& operator+= (const Matrix4x4& m);

		/**
		* Matrix4x4 subtraction
		* @param m: Matrix4x4 to be subtracted
		* @return Matrix4x4 with the subtraction values
		*/
		Matrix4x4& operator-= (const Matrix4x4& m);

		/**
		* Matrix4x4 product
		* @param m: Matrix4x4 to be multiplied
		* @return Matrix4x4 with the product values
		*/
		Matrix4x4& operator*= (const Matrix4x4& m);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix4x4 with the product values
		*/
		Matrix4x4& operator*= (float a);

		/**
		* Transpose Matrix4x4
		* @return Matrix4x4 transposed
		*/
		Matrix4x4& transpose ();

		/**
		* Matrix4x4 transposed
		* @return New Matrix4x4 transposed
		*/
		Matrix4x4 transposed();
	private:
		union {
			struct {
				float _d0;  float _d1;  float _d2;  float _d3;
				float _d4;  float _d5;  float _d6;  float _d7;
				float _d8;  float _d9;  float _d10; float _d11;
				float _d12; float _d13; float _d14; float _d15;
			};
			Vector4 _vectors[4];
			float _data[16];
		};

		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const Matrix4x4& m);
	};

	std::ostream& operator <<(std::ostream& os, const Matrix4x4& m);
};

#endif // MATH_MATRIX4x4_H