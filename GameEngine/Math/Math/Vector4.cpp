#include "Vector4.h"
#include "SIMD_Math/simd.h"

#include <cmath>
#include <algorithm>

namespace sge {
	Vector4::Vector4() {
		std::fill_n(_data, 4, 0.0f);
	}

	Vector4::Vector4(float x, float y, float z, float w) : _x(x), _y(y), _z(z), _w(w) {}

	Vector4::Vector4(const float* array) {
		memcpy(_data, array, float4_size);
	}

	Vector4::Vector4(const Vector4& v) {
		memcpy(_data, v._data, float4_size);
	}

	const float Vector4::X() const {
		return _x;
	}

	float& Vector4::X() {
		return _x;
	}

	const float Vector4::Y() const {
		return _y;
	}

	float& Vector4::Y() {
		return _y;
	}

	const float Vector4::Z() const {
		return _z;
	}

	float& Vector4::Z() {
		return _z;
	}

	const float Vector4::W() const {
		return _w;
	}

	float& Vector4::W() {
		return _w;
	}

	const float* Vector4::data() const {
		return _data;
	}

	float* Vector4::data() {
		return _data;
	}

	Vector4& Vector4::operator= (const Vector4& v) {
		if (this != &v) {
			memcpy(_data, v._data, float4_size);
		}

		return *this;
	}

	Vector4 Vector4::operator+ (const Vector4& v) const {
		Vector4 result_vector{};

		_vector4_sum(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector4 Vector4::operator- (const Vector4& v) const {
		Vector4 result_vector{};

		_vector4_sub(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector4 Vector4::operator* (const Vector4& v) const {
		Vector4 result_vector{};

		_vector4_mul(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector4 Vector4::operator/ (const Vector4& v) const {
		Vector4 result_vector{};

		_vector4_div(_data, v._data, result_vector._data);

		return result_vector;
	}

	Vector4 Vector4::operator* (const float& a) const {
		Vector4 result_vector{};

		_vector4_mul_scalar(_data, a, result_vector._data);

		return result_vector;
	}

	Vector4 Vector4::operator/ (const float& a) const {
		Vector4 result_vector{};

		_vector4_div_scalar(_data, a, result_vector._data);

		return result_vector;
	}

	Vector4& Vector4::operator+= (const Vector4& v) {
		_vector4_sum(_data, v._data, _data);

		return *this;
	}

	Vector4& Vector4::operator-= (const Vector4& v) {
		_vector4_sub(_data, v._data, _data);

		return *this;
	}

	Vector4& Vector4::operator*= (const Vector4& v) {
		_vector4_mul(_data, v._data, _data);
		
		return *this;
	}

	Vector4& Vector4::operator/= (const Vector4& v) {
		_vector4_div(_data, v._data, _data);
		
		return *this;
	}

	Vector4& Vector4::operator*= (const float& a) {
		_vector4_mul_scalar(_data, a, _data);

		return *this;
	}

	Vector4& Vector4::operator/= (const float& a) {
		_vector4_div_scalar(_data, a, _data);
		
		return *this;
	}

	float Vector4::dot(const Vector4& v) const {
		float result;

		_vector4_dot(_data, v._data, result);

		return result;
	}

	Vector4 Vector4::cross(const Vector4& v) const {
		Vector4 result_vector{};

		_vector4_cross(_data, v._data, result_vector._data);

		return result_vector;
	}

	float Vector4::square_norm() const {
		float result;
		
		_vector4_dot(_data, _data, result);
		
		return result;
	}

	float Vector4::norm() const {
		float result;

		_vector4_dot(_data, _data, result);

		return sqrt(result);
	}

	Vector4& Vector4::normalized() {
		*this /= norm();

		return *this;
	}

	std::ostream& operator <<(std::ostream& os, const Vector4& v) {
		return os << "[ " << v._x << " " << v._y << " " << v._z << " " << v._w << " ]" << std::endl;
	}

	Vector4 operator -(const Vector4& v) {
		Vector4 result;

		_vector4_sub(result._data, v._data, result._data);

		return result;
	}

	Vector4 operator +(const Vector4& v) {
		return v;
	}
};