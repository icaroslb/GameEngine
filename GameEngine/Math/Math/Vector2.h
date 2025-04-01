#ifndef MATH_VECTOR2_H
#define MATH_VECTOR2_H

#include <ostream>

namespace sge {
	/**
	* Vector 4
	*/
	class Vector2 {
	public:
		Vector2();
		Vector2(float x, float y);
		Vector2(const float* array);
		Vector2(const Vector2& v);

		/**
		* X value
		* @return X value
		*/
		const float  X() const;

		/**
		* X value
		* @return X value
		*/
		float& X();

		/**
		* Y value
		* @return Y value
		*/
		const float  Y() const;

		/**
		* Y value
		* @return Y value
		*/
		float& Y();

		/**
		* Vector2 values array
		* @return values array
		*/
		const float* data() const;

		/**
		* Vector2 values array
		* @return values array
		*/
		float* data();

		Vector2& operator= (const Vector2& v);

		/**
		* Vector2 sum
		* @param v: Vector2 to be added
		* @return Vector2 with the sum values
		*/
		Vector2 operator+ (const Vector2& v) const;

		/**
		* Vector2 subtraction
		* @param v: Vector2 to be subtracted
		* @return Vector2 with the subtraction values
		*/
		Vector2 operator- (const Vector2& v) const;

		/**
		* Hadamard product
		* @param v: Vector2 to be multiplied
		* @return Vector2 with the product values
		*/
		Vector2 operator* (const Vector2& v) const;

		/**
		* Hadamard division
		* @param v: Vector2 to be divided
		* @return Vector2 with the division values
		*/
		Vector2 operator/ (const Vector2& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Vector2 with the product values
		*/
		Vector2 operator* (const float& a) const;

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return Vector2 with the division values
		*/
		Vector2 operator/ (const float& a) const;

		/**
		* Vector2 sum
		* @param v: Vector2 to be added
		* @return This Vector2 with the sum values
		*/
		Vector2& operator+= (const Vector2& v);

		/**
		* Vector2 subtraction
		* @param v: Vector2 to be subtracted
		* @return This Vector2 with the subtraction values
		*/
		Vector2& operator-= (const Vector2& v);

		/**
		* Hadamard product
		* @param v: Vector2 to be multiplied
		* @return This Vector2 with the product values
		*/
		Vector2& operator*= (const Vector2& v);

		/**
		* Hadamard division
		* @param v: Vector2 to be divided
		* @return This Vector2 with the division values
		*/
		Vector2& operator/= (const Vector2& v);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return This Vector2 with the product values
		*/
		Vector2& operator*= (const float& a);

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return This Vector2 with the division values
		*/
		Vector2& operator/= (const float& a);

		/**
		* Dot product (Use only if really necessary, this operation is slow [it uses hadd])
		* @param v: Vector2 to perform the operation
		* @return Dot product result
		*/
		float dot(const Vector2& v) const;

		/**
		* Cross product
		* @param v: Vector2 to perform the operation
		* @return Cross product result
		*/
		float cross(const Vector2& v) const;

		/**
		* Square norm
		* @return Square of the norm of the Vector2
		*/
		float square_norm() const;

		/**
		* Norm
		* @return Norm of the Vector2
		*/
		float norm() const;

	private:
		union {
			struct
			{
				float _x;
				float _y;
			};
			float _data[2];
		};

		// friend class Matrix;
		// friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const Vector2& v);
	};

	std::ostream& operator <<(std::ostream& os, const Vector2& v);
};

#endif // MATH_VECTOR2_H
