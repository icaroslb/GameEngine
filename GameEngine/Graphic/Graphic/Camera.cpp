#include "Camera.h"

#include <iostream>
namespace geb {
	Camera::Camera(const Vector4& position, const Vector4& look_at, const Vector4& up_position)
	: _mat_proj(MatrixTypes::identity) {
		_k = (position - look_at).normalized();
		
		Vector4 aux_j = up_position - position;

		_i = aux_j.cross(_k).normalized();
		_j = _k.cross(_i).normalized();

		Matrix4 transformation(MatrixTypes::identity);
		Matrix4 translation(MatrixTypes::identity);

		transformation[0] = _i;
		transformation[1] = _j;
		transformation[2] = _k;

		translation[3] = -position;
		translation(3, 3) = 1.0f;

		_mat_view = transformation * translation.transposed();
	}

	void Camera::GenerateProjection(const projection_types& projection_type, float right, float left, float top, float bottom, float far, float near) {
		_proj_type = projection_type;

		_mat_proj = Matrix4{ MatrixTypes::identity };

		float right_minus_left = right - left;
		float top_minus_bottom = top - bottom;
		float far_minus_near = far - near;
		float A = (right + left) / right_minus_left;
		float B = (top + bottom) / top_minus_bottom;
		float C = -(far + near) / far_minus_near;

		float double_near = 2.0f * near;

		switch (_proj_type) {
		case projection_types::ortho:
			_mat_proj(0, 0) =  2.0f / right_minus_left;
			_mat_proj(0, 3) = -A;
			_mat_proj(1, 1) =  2.0f / top_minus_bottom;
			_mat_proj(1, 3) = -B;
			_mat_proj(2, 2) = -2.0f / far_minus_near;
			_mat_proj(2, 3) = C;
			break;
		case projection_types::perspective:
			_mat_proj(0, 0) = double_near / right_minus_left;
			_mat_proj(0, 2) = A;
			_mat_proj(1, 1) = double_near / right_minus_left;
			_mat_proj(1, 2) = B;
			_mat_proj(2, 2) = C;
			_mat_proj(2, 3) = -((2.0f * far * near) / far_minus_near);
			_mat_proj(3, 2) = -1.0;
			_mat_proj(3, 3) = 0.0f;
		default:
			break;
		}

		std::cout << _mat_proj << std::endl;
	}

	const Matrix4& Camera::GetMatrixView() const {
		return _mat_view;
	}

	const Matrix4& Camera::GetMatrixProjection() const {
		return _mat_proj;
	}
};