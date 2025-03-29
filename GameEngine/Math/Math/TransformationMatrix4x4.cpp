#include "TransformationMatrix4x4.h"

namespace geb {

	TransformationMatrix4x4::TransformationMatrix4x4()
		: _transformation({
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			})
		, _i_transformation({
			1.0f, 0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 1.0f
			}) {
	}

	TransformationMatrix4x4::TransformationMatrix4x4(const TransformationMatrix4x4& tm)
		: _transformation(tm._transformation)
		, _i_transformation(tm._i_transformation) {}

	const Matrix4x4& TransformationMatrix4x4::transformation() const {
		return _transformation;
	}

	const Matrix4x4& TransformationMatrix4x4::i_transformation() const {
		return _i_transformation;
	}

	TransformationMatrix4x4& TransformationMatrix4x4::operator= (const TransformationMatrix4x4& tm) {
		_transformation = tm._transformation;
		_i_transformation = tm._i_transformation;

		return *this;
	}

	TransformationMatrix4x4 TransformationMatrix4x4::operator* (const TransformationMatrix4x4& tm) {
		TransformationMatrix4x4 result;

		result._transformation = _transformation * tm._transformation;
		result._i_transformation = tm._i_transformation * _i_transformation;

		return result;
	}

	TransformationMatrix4x4& TransformationMatrix4x4::operator*= (const TransformationMatrix4x4& tm) {
		_transformation *= tm._transformation;
		_i_transformation = tm._i_transformation * _i_transformation;

		return *this;
	}

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix4x4& mt) {
		return os
			<< " ------------------- " << std::endl
			<< mt._transformation << std::endl
			<< mt._i_transformation
			<< " ------------------- " << std::endl;
	}

};