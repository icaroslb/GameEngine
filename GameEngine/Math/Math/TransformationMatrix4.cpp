#include "TransformationMatrix4.h"

namespace sge {

	TransformationMatrix4::TransformationMatrix4()
		: _transformation(MatrixTypes::identity)
		, _i_transformation(MatrixTypes::identity) {
	}

	TransformationMatrix4::TransformationMatrix4(const TransformationMatrix4& tm)
		: _transformation(tm._transformation)
		, _i_transformation(tm._i_transformation) {}

	const Matrix4& TransformationMatrix4::transformation() const {
		return _transformation;
	}

	const Matrix4& TransformationMatrix4::i_transformation() const {
		return _i_transformation;
	}

	TransformationMatrix4& TransformationMatrix4::operator= (const TransformationMatrix4& tm) {
		_transformation = tm._transformation;
		_i_transformation = tm._i_transformation;

		return *this;
	}

	TransformationMatrix4 TransformationMatrix4::operator* (const TransformationMatrix4& tm) {
		TransformationMatrix4 result;

		result._transformation = _transformation * tm._transformation;
		result._i_transformation = tm._i_transformation * _i_transformation;

		return result;
	}

	TransformationMatrix4& TransformationMatrix4::operator*= (const TransformationMatrix4& tm) {
		_transformation *= tm._transformation;
		_i_transformation = tm._i_transformation * _i_transformation;

		return *this;
	}

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix4& mt) {
		return os
			<< " ------------------- " << std::endl
			<< mt._transformation << std::endl
			<< mt._i_transformation
			<< " ------------------- " << std::endl;
	}

};