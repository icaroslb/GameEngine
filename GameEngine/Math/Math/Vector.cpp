#include "Vector.h"
#include "SIMD_Math/simd.h"

#include <cmath>
#include <algorithm>

namespace geb {
	Vector::Vector() {
		std::fill_n(_data, 4, 0.0);
	}

	Vector::Vector(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w) {}

	Vector::Vector(const float* array) {
		memcpy(_data, array, float4_size);
	}

	Vector::Vector(const Vector& v) {
		memcpy(_data, v._data, float4_size);
	}

	const float Vector::X() const {
		return _x;
	}

	float& Vector::X() {
		return _x;
	}

	const float Vector::Y() const {
		return _y;
	}

	float& Vector::Y() {
		return _y;
	}

	const float Vector::Z() const {
		return _z;
	}

	float& Vector::Z() {
		return _z;
	}

	const float Vector::W() const {
		return _w;
	}

	float& Vector::W() {
		return _w;
	}

	const float* Vector::data() const {
		return _data;
	}

	float* Vector::data() {
		return _data;
	}

	Vector& Vector::operator= (const Vector& v) {
		if (this != &v) {
			memcpy(_data, v._data, float4_size);
		}

		return *this;
	}

	Vector Vector::operator+ (const Vector& v) const {
		Vector result_vector{};

		_vector_sum(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector Vector::operator- (const Vector& v) const {
		Vector result_vector{};

		_vector_sub(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector Vector::operator* (const Vector& v) const {
		Vector result_vector{};

		_vector_mul(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector Vector::operator/ (const Vector& v) const {
		Vector result_vector{};

		_vector_div(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector Vector::operator* (const float& a) const {
		Vector result_vector{};

		_vector_mul_scalar(_data, a, result_vector._data);

		return result_vector;
	}

	Vector Vector::operator/ (const float& a) const {
		Vector result_vector{};

		_vector_div_scalar(_data, a, result_vector._data);

		return result_vector;
	}

	Vector& Vector::operator+= (const Vector& v) {
		_vector_sum(_data, v._data, _data);

		return *this;
	}

	Vector& Vector::operator-= (const Vector& v) {
		_vector_sub(_data, v._data, _data);

		return *this;
	}

	Vector& Vector::operator*= (const Vector& v) {
		_vector_mul(_data, v._data, _data);
		
		return *this;
	}

	Vector& Vector::operator/= (const Vector& v) {
		_vector_div(_data, v._data, _data);
		
		return *this;
	}

	Vector& Vector::operator*= (const float& a) {
		_vector_mul_scalar(_data, a, _data);

		return *this;
	}

	Vector& Vector::operator/= (const float& a) {
		_vector_div_scalar(_data, a, _data);
		
		return *this;
	}

	float Vector::dot(const Vector& v) const {
		float result;

		_vector_dot(_data, v._data, result);

		return result;
	}

	Vector Vector::cross(const Vector& v) const {
		Vector result_vector{};

		_vector_cross(_data, v._data, result_vector._data);

		return result_vector;
	}

	float Vector::square_norm() const {
		float result;
		
		_vector_dot(_data, _data, result);
		
		return result;
	}

	float Vector::norm() const {
		float result;

		_vector_dot(_data, _data, result);

		return sqrt(result);
	}

	std::ostream& operator <<(std::ostream& os, const Vector& v) {
		return os << "[ " << v._x << " " << v._y << " " << v._z << " " << v._w << " ]" << std::endl;
	}
};