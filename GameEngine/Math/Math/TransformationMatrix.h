#ifndef MATH_TRANSFORMATION_MATRIX_H
#define MATH_TRANSFORMATION_MATRIX_H

#include "Matrix.h"

namespace geb {
	class TransformationMatrix {
	public:
		TransformationMatrix();
		TransformationMatrix(const TransformationMatrix& tm);

		TransformationMatrix& operator= (const TransformationMatrix& tm);

		TransformationMatrix operator* (const TransformationMatrix& tm);

	private:
		Matrix _transformation;
		Matrix _i_transformation;
	};
};

#endif // MATH_TRANSFORMATION_MATRIX_H
