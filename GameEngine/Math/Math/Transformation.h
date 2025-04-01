#ifndef MATH_TRANSFORMATION_H
#define MATH_TRANSFORMATION_H

#include "TransformationMatrix4.h"

namespace sge {

	class Transformation {
	public:
		/**
		* Translation
		* Generate a translation transformation matrix
		* @param x: Translation in x
		* @param y: Translation in y
		* @param z: Translation in z
		* @return Translation transformation matrix
		*/
		static TransformationMatrix4 Translation(float x, float y, float z);

		/**
		* Scale
		* Generate a Scale transformation matrix
		* @param x: Scale in x
		* @param y: Scale in y
		* @param z: Scale in z
		* @return Scale transformation matrix
		*/
		static TransformationMatrix4 Scale(float x, float y, float z);

		/**
		* Euler rotation in x
		* Generate a Euler rotation in x transformation matrix
		* @param angle: Rotation angle in rad
		* @return Rotation transformation matrix
		*/
		static TransformationMatrix4 EulerRotation_x(float angle);

		/**
		* Euler rotation in y
		* Generate a Euler rotation in y transformation matrix
		* @param angle: Rotation angle in rad
		* @return Rotation transformation matrix
		*/
		static TransformationMatrix4 EulerRotation_y(float angle);

		/**
		* Euler rotation in z
		* Generate a Euler rotation in z transformation matrix
		* @param angle: Rotation angle in rad
		* @return Rotation transformation matrix
		*/
		static TransformationMatrix4 EulerRotation_z(float angle);

		/**
		* Quaternion rotation
		* Generate a Quaternion rotation transformation matrix
		* @param axis: Rotation axis
		* @param angle: Rotation angle in rad
		* @return Rotation transformation matrix
		*/
		static TransformationMatrix4 QuaternionRotation(const Vector4& axis, float angle);

	private:
		Transformation() = delete;
	};

};

#endif // MATH_TRANSFORMATION_H