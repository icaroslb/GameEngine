#include "TransformationMatrix.h"

namespace geb {

	TransformationMatrix::TransformationMatrix()
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

	TransformationMatrix::TransformationMatrix(const TransformationMatrix& tm)
		: _transformation(tm._transformation)
		, _i_transformation(tm._i_transformation) {}

	TransformationMatrix& TransformationMatrix::operator= (const TransformationMatrix& tm) {
		_transformation = tm._transformation;
		_i_transformation = tm._i_transformation;

		return *this;
	}

	TransformationMatrix TransformationMatrix::operator* (const TransformationMatrix& tm) {
		TransformationMatrix result;

		result._transformation = _transformation * tm._transformation;
		result._i_transformation = tm._i_transformation * _i_transformation;

		return result;
	}

	TransformationMatrix& TransformationMatrix::operator*= (const TransformationMatrix& tm) {
		_transformation *= tm._transformation;
		_i_transformation = tm._i_transformation * _i_transformation;

		return *this;
	}

	std::ostream& operator <<(std::ostream& os, const TransformationMatrix& mt) {
		return os
			<< " ------------------- " << std::endl
			<< mt._transformation << std::endl
			<< mt._i_transformation
			<< " ------------------- " << std::endl;
	}

};