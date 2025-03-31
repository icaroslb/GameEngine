#ifndef MATH_TRANSFORMATION_MATRIX4_H
#define MATH_TRANSFORMATION_MATRIX4_H

#include "Matrix4.h"

namespace geb {
	/**
	* Matrix4 Transformation
	* Save the transformation and its inverse
	*/
	class TransformationMatrix4 {
	public:
		TransformationMatrix4();
		TransformationMatrix4(const TransformationMatrix4& tm);

		/**
		* Get Transformation Matrix4
		* @return Transformation Matrix4
		*/
		const Matrix4& transformation() const;

		/**
		* Get Inverse Transformation Matrix4
		* @return Inverse Transformation Matrix4
		*/
		const Matrix4& i_transformation() const;

		TransformationMatrix4& operator= (const TransformationMatrix4& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix4 operator* (const TransformationMatrix4& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix4& operator*= (const TransformationMatrix4& tm);

	private:
		Matrix4 _transformation;
		Matrix4 _i_transformation;

		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const TransformationMatrix4& mt);
	};

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix4& mt);
};

#endif // MATH_TRANSFORMATION_Matrix4_H
