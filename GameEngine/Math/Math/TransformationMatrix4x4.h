#ifndef MATH_TRANSFORMATION_Matrix4x4_H
#define MATH_TRANSFORMATION_Matrix4x4_H

#include "Matrix4x4.h"

namespace geb {
	/**
	* Matrix4x4 Transformation
	* Save the transformation and its inverse
	*/
	class TransformationMatrix4x4 {
	public:
		TransformationMatrix4x4();
		TransformationMatrix4x4(const TransformationMatrix4x4& tm);

		/**
		* Get Transformation Matrix4x4
		* @return Transformation Matrix4x4
		*/
		const Matrix4x4& transformation() const;

		/**
		* Get Inverse Transformation Matrix4x4
		* @return Inverse Transformation Matrix4x4
		*/
		const Matrix4x4& i_transformation() const;

		TransformationMatrix4x4& operator= (const TransformationMatrix4x4& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix4x4 operator* (const TransformationMatrix4x4& tm);

		/**
		* Transformation product
		* @param tm: Transformation to be multiplied
		* @return Transformation with the product values
		*/
		TransformationMatrix4x4& operator*= (const TransformationMatrix4x4& tm);

	private:
		Matrix4x4 _transformation;
		Matrix4x4 _i_transformation;

		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const TransformationMatrix4x4& mt);
	};

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix4x4& mt);
};

#endif // MATH_TRANSFORMATION_Matrix4x4_H
