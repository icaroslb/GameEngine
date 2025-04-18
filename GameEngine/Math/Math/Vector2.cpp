#include "Vector2.h"
#include "SIMD_Math/simd.h"

#include <cmath>
#include <algorithm>

namespace sge {
	Vector2::Vector2() {
		std::fill_n(_data, 2, 0.0f);
	}

	Vector2::Vector2(float x, float y) : _x(x), _y(y) {}

	Vector2::Vector2(const float* array) {
		memcpy(_data, array, float2_size);
	}

	Vector2::Vector2(const Vector2& v) {
		memcpy(_data, v._data, float2_size);
	}

	const float Vector2::X() const {
		return _x;
	}

	float& Vector2::X() {
		return _x;
	}

	const float Vector2::Y() const {
		return _y;
	}

	float& Vector2::Y() {
		return _y;
	}

	const float* Vector2::data() const {
		return _data;
	}

	float* Vector2::data() {
		return _data;
	}

	Vector2& Vector2::operator= (const Vector2& v) {
		if (this != &v) {
			memcpy(_data, v._data, float2_size);
		}

		return *this;
	}

	Vector2 Vector2::operator+ (const Vector2& v) const {
		Vector2 result_vector2{};

		_vector2_sum(_data, v._data, result_vector2._data);

		return result_vector2;
	}

	Vector2 Vector2::operator- (const Vector2& v) const {
		Vector2 result_vector2{};

		_vector2_sub(_data, v._data, result_vector2._data);

		return result_vector2;
	}

	Vector2 Vector2::operator* (const Vector2& v) const {
		Vector2 result_vector2{};

		_vector2_mul(_data, v._data, result_vector2._data);

		return result_vector2;
	}

	Vector2 Vector2::operator/ (const Vector2& v) const {
		Vector2 result_vector2{};

		_vector2_div(_data, v._data, result_vector2._data);

		return result_vector2;
	}

	Vector2 Vector2::operator* (const float& a) const {
		Vector2 result_vector2{};

		_vector2_mul_scalar(_data, a, result_vector2._data);

		return result_vector2;
	}

	Vector2 Vector2::operator/ (const float& a) const {
		Vector2 result_vector2{};

		_vector2_div_scalar(_data, a, result_vector2._data);

		return result_vector2;
	}

	Vector2& Vector2::operator+= (const Vector2& v) {
		_vector2_sum(_data, v._data, _data);

		return *this;
	}

	Vector2& Vector2::operator-= (const Vector2& v) {
		_vector2_sub(_data, v._data, _data);

		return *this;
	}

	Vector2& Vector2::operator*= (const Vector2& v) {
		_vector2_mul(_data, v._data, _data);

		return *this;
	}

	Vector2& Vector2::operator/= (const Vector2& v) {
		_vector2_div(_data, v._data, _data);

		return *this;
	}

	Vector2& Vector2::operator*= (const float& a) {
		_vector2_mul_scalar(_data, a, _data);

		return *this;
	}

	Vector2& Vector2::operator/= (const float& a) {
		_vector2_div_scalar(_data, a, _data);

		return *this;
	}

	float Vector2::dot(const Vector2& v) const {
		float result;

		_vector2_dot(_data, v._data, result);

		return result;
	}

	float Vector2::cross(const Vector2& v) const {
		float result;

		_vector2_cross(_data, v._data, result);

		return result;
	}

	float Vector2::square_norm() const {
		float result;

		_vector2_dot(_data, _data, result);

		return result;
	}

	float Vector2::norm() const {
		float result;

		_vector2_dot(_data, _data, result);

		return sqrt(result);
	}

	std::ostream& operator <<(std::ostream& os, const Vector2& v) {
		return os << "[ " << v._x << " " << v._y << " ]" << std::endl;
	}
};