#ifndef GRAPHIC_CAMERA_CAMERA_H
#define GRAPHIC_CAMERA_CAMERA_H

#include <Math/Matrix4.h>
#include <Math/Vector4.h>

namespace sge {

	enum projection_types {
		ortho,
		perspective
	};

	class Camera {
	public:
		Camera(const Vector4& position, const Vector4& look_at, const Vector4& up_position);
		void GenerateProjection(const projection_types& projection_type, float right, float left, float top, float bottom, float far, float near);

		const Matrix4& GetMatrixView() const;
		const Matrix4& GetMatrixProjection() const;

	private:
		Vector4 _i;
		Vector4 _j;
		Vector4 _k;

		float _near;
		float _far;

		Matrix4 _mat_view;
		Matrix4 _mat_proj;
		projection_types _proj_type;
	};

};

#endif // GRAPHIC_CAMERA_CAMERA_H