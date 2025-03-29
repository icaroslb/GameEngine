#include "Transformation.h"
#include "SIMD_Math/simd.h"

#include <cmath>

namespace geb {
	TransformationMatrix4x4 Transformation::Translation(float x, float y, float z) {
		TransformationMatrix4x4 result;

		result._transformation(0, 3) = x;
		result._transformation(1, 3) = y;
		result._transformation(2, 3) = z;

		result._i_transformation(0, 3) = -x;
		result._i_transformation(1, 3) = -y;
		result._i_transformation(2, 3) = -z;

		return result;
	}

	TransformationMatrix4x4 Transformation::Scale(float x, float y, float z) {
		TransformationMatrix4x4 result;

		result._transformation(0, 0) = x;
		result._transformation(1, 1) = y;
		result._transformation(2, 2) = z;

		result._i_transformation(0, 0) = 1.0f / x;
		result._i_transformation(1, 1) = 1.0f / y;
		result._i_transformation(2, 2) = 1.0f / z;

		return result;
	}

	TransformationMatrix4x4 Transformation::EulerRotation_x(float angle) {
		TransformationMatrix4x4 result;

		float cos_angle = cos(angle);
		float sin_angle = sin(angle);

		result._transformation(1, 1) =  cos_angle;
		result._transformation(1, 2) = -sin_angle;
		result._transformation(2, 1) =  sin_angle;
		result._transformation(2, 2) =  cos_angle;

		result._transformation(1, 1) =  cos_angle;
		result._transformation(1, 2) =  sin_angle;
		result._transformation(2, 1) = -sin_angle;
		result._transformation(2, 2) =  cos_angle;

		return result;
	}

	TransformationMatrix4x4 Transformation::EulerRotation_y(float angle) {
		TransformationMatrix4x4 result;

		float cos_angle = cos(angle);
		float sin_angle = sin(angle);

		result._transformation(0, 0) =  cos_angle;
		result._transformation(0, 2) =  sin_angle;
		result._transformation(2, 0) = -sin_angle;
		result._transformation(2, 2) =  cos_angle;

		result._transformation(0, 0) =  cos_angle;
		result._transformation(0, 2) = -sin_angle;
		result._transformation(2, 0) =  sin_angle;
		result._transformation(2, 2) =  cos_angle;

		return result;
	}

	TransformationMatrix4x4 Transformation::EulerRotation_z(float angle) {
		TransformationMatrix4x4 result;

		float cos_angle = cos(angle);
		float sin_angle = sin(angle);

		result._transformation(0, 0) =  cos_angle;
		result._transformation(0, 1) = -sin_angle;
		result._transformation(1, 0) =  sin_angle;
		result._transformation(1, 1) =  cos_angle;

		result._transformation(0, 0) =  cos_angle;
		result._transformation(0, 1) =  sin_angle;
		result._transformation(1, 0) = -sin_angle;
		result._transformation(1, 1) =  cos_angle;

		return result;
	}

	TransformationMatrix4x4 Transformation::QuaternionRotation(const Vector4 &axis, float angle) {
		TransformationMatrix4x4 tm_result;
		Vector4 quaternion;
		Vector4 i_quaternion;
		const float half_angle = angle / 2.0f;
		const float i_half_angle = -half_angle;

		quaternion = axis * sin(half_angle);
		quaternion._w = cos(half_angle);

		i_quaternion = axis * sin(i_half_angle);
		i_quaternion._w = cos(i_half_angle);
		
		_matrix4x4_quaternion(quaternion._data, tm_result._transformation._data);
		_matrix4x4_quaternion(i_quaternion._data, tm_result._i_transformation._data);

		return tm_result;
	}
};