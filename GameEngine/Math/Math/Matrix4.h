#ifndef MATH_MATRIX4_H
#define MATH_MATRIX4_H

#include "Vector4.h"

namespace sge {
	
	enum MatrixTypes {
		identity,
		zeros,
		ones
	};

	/**
	* Matrix 4x4
	* Divided by rows
	*/
	class Matrix4 {
	public:
		Matrix4();
		Matrix4(
			float v0, float v1, float v2, float v3,
			float v4, float v5, float v6, float v7,
			float v8, float v9, float v10, float v11,
			float v12, float v13, float v14, float v15);
		Matrix4(const MatrixTypes& type);
		Matrix4(const float* array);
		Matrix4(const Matrix4& m);

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
		* Get the line
		* @param line: Line position
		* @return The line
		*/
		const Vector4 operator[](size_t line) const;

		/**
		* Get the line
		* @param line: Line position
		* @return The line
		*/
		Vector4& operator[](size_t line);

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

		Matrix4& operator= (const Matrix4& m);

		/**
		* Matrix4 sum
		* @param m: Matrix4 to be added
		* @return Matrix4 with the sum values
		*/
		Matrix4 operator+ (const Matrix4& m) const;

		/**
		* Matrix4 subtraction
		* @param m: Matrix4 to be subtracted
		* @return Matrix4 with the subtraction values
		*/
		Matrix4 operator- (const Matrix4& m) const;

		/**
		* Matrix4 product
		* @param m: Matrix4 to be multiplied
		* @return Matrix4 with the product values
		*/
		Matrix4 operator* (const Matrix4& m) const;

		/**
		* Vector product
		* @param v: Vector to be multiplied
		* @return Vector with the product values
		*/
		Vector4 operator* (const Vector4& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix4 with the product values
		*/
		Matrix4 operator* (float a) const;

		/**
		* Matrix4 sum
		* @param m: Matrix4 to be added
		* @return Matrix4 with the sum values
		*/
		Matrix4& operator+= (const Matrix4& m);

		/**
		* Matrix4 subtraction
		* @param m: Matrix4 to be subtracted
		* @return Matrix4 with the subtraction values
		*/
		Matrix4& operator-= (const Matrix4& m);

		/**
		* Matrix4 product
		* @param m: Matrix4 to be multiplied
		* @return Matrix4 with the product values
		*/
		Matrix4& operator*= (const Matrix4& m);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix4 with the product values
		*/
		Matrix4& operator*= (float a);

		/**
		* Transpose Matrix4
		* @return Matrix4 transposed
		*/
		Matrix4& transpose ();

		/**
		* Matrix4 transposed
		* @return New Matrix4 transposed
		*/
		Matrix4 transposed();
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
		friend std::ostream& operator <<(std::ostream& os, const Matrix4& m);
	};

	std::ostream& operator <<(std::ostream& os, const Matrix4& m);
};

#endif // MATH_Matrix4_H