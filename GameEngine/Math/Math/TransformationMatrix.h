#ifndef MATH_TRANSFORMATION_MATRIX_H
#define MATH_TRANSFORMATION_MATRIX_H

#include "Matrix.h"

namespace geb {
	/**
	* Matrix Transformation
	* Save the transformation and its inverse
	*/
	class TransformationMatrix {
	public:
		TransformationMatrix();
		TransformationMatrix(const TransformationMatrix& tm);

		/**
		* Get Transformation matrix
		* @return Transformation matrix
		*/
		const Matrix& transformation() const;

		/**
		* Get Inverse Transformation matrix
		* @return Inverse Transformation matrix
		*/
		const Matrix& i_transformation() const;

		TransformationMatrix& operator= (const TransformationMatrix& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix operator* (const TransformationMatrix& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix& operator*= (const TransformationMatrix& tm);

	private:
		Matrix _transformation;
		Matrix _i_transformation;

		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const TransformationMatrix& mt);
	};

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix& mt);
};

#endif // MATH_TRANSFORMATION_MATRIX_H
