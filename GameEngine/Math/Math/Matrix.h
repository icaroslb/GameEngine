#ifndef MATH_MATRIX_H
#define MATH_MATRIX_H

#include "Vector.h"

namespace geb {
	/**
	* Matrix 4x4
	* Divided by rows
	*/
	class Matrix {
	public:
		Matrix();
		Matrix(
			float v0, float v1, float v2, float v3,
			float v4, float v5, float v6, float v7,
			float v8, float v9, float v10, float v11,
			float v12, float v13, float v14, float v15);
		Matrix(const float* array);
		Matrix(const Matrix& m);

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

		Matrix& operator= (const Matrix& m);

		/**
		* Matrix sum
		* @param m: Matrix to be added
		* @return Matrix with the sum values
		*/
		Matrix operator+ (const Matrix& m) const;

		/**
		* Matrix subtraction
		* @param m: Matrix to be subtracted
		* @return Matrix with the subtraction values
		*/
		Matrix operator- (const Matrix& m) const;

		/**
		* Matrix product
		* @param m: Matrix to be multiplied
		* @return Matrix with the product values
		*/
		Matrix operator* (const Matrix& m) const;

		/**
		* Vector product
		* @param v: Vector to be multiplied
		* @return Vector with the product values
		*/
		Vector operator* (const Vector& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix with the product values
		*/
		Matrix operator* (float a) const;

		/**
		* Matrix sum
		* @param m: Matrix to be added
		* @return Matrix with the sum values
		*/
		Matrix& operator+= (const Matrix& m);

		/**
		* Matrix subtraction
		* @param m: Matrix to be subtracted
		* @return Matrix with the subtraction values
		*/
		Matrix& operator-= (const Matrix& m);

		/**
		* Matrix product
		* @param m: Matrix to be multiplied
		* @return Matrix with the product values
		*/
		Matrix& operator*= (const Matrix& m);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Matrix with the product values
		*/
		Matrix& operator*= (float a);

		/**
		* Transpose Matrix
		* @return Matrix transposed
		*/
		Matrix& transpose ();

		/**
		* Matrix transposed
		* @return New Matrix transposed
		*/
		Matrix transposed();
	private:
		union {
			struct {
				float _d0;  float _d1;  float _d2;  float _d3;
				float _d4;  float _d5;  float _d6;  float _d7;
				float _d8;  float _d9;  float _d10; float _d11;
				float _d12; float _d13; float _d14; float _d15;
			};
			Vector _vectors[4];
			float _data[16];
		};

		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const Matrix& m);
	};

	std::ostream& operator <<(std::ostream& os, const Matrix& m);
};

#endif // MATH_MATRIX_H