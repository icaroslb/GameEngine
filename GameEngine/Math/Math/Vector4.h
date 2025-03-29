#ifndef MATH_VECTOR4_H
#define MATH_VECTOR4_H

#include <ostream>

namespace geb {
	/**
	* Vector 4
	*/
	class Vector4 {
	public:
		Vector4();
		Vector4(float x, float y, float z, float w);
		Vector4(const float* array);
		Vector4(const Vector4& v);

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
		* Z value
		* @return Z value
		*/
		const float  Z() const;

		/**
		* Z value
		* @return Z value
		*/
		      float& Z();

		/**
		* W value
		* @return W value
		*/
		const float  W() const;

		/**
		* W value
		* @return W value
		*/
		      float& W();

		/**
		* Vector4 values array
		* @return values array
		*/
		const float* data() const;

		/**
		* Vector4 values array
		* @return values array
		*/
		      float* data();

		Vector4& operator= (const Vector4& v);

		/**
		* Vector4 sum
		* @param v: Vector4 to be added
		* @return Vector4 with the sum values
		*/
		Vector4 operator+ (const Vector4& v) const;

		/**
		* Vector4 subtraction
		* @param v: Vector4 to be subtracted
		* @return Vector4 with the subtraction values
		*/
		Vector4 operator- (const Vector4& v) const;
		
		/**
		* Hadamard product
		* @param v: Vector4 to be multiplied
		* @return Vector4 with the product values
		*/
		Vector4 operator* (const Vector4& v) const;

		/**
		* Hadamard division
		* @param v: Vector4 to be divided
		* @return Vector4 with the division values
		*/
		Vector4 operator/ (const Vector4& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Vector4 with the product values
		*/
		Vector4 operator* (const float& a) const;

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return Vector4 with the division values
		*/
		Vector4 operator/ (const float& a) const;

		/**
		* Vector4 sum
		* @param v: Vector4 to be added
		* @return This Vector4 with the sum values
		*/
		Vector4& operator+= (const Vector4& v);

		/**
		* Vector4 subtraction
		* @param v: Vector4 to be subtracted
		* @return This Vector4 with the subtraction values
		*/
		Vector4& operator-= (const Vector4& v);

		/**
		* Hadamard product
		* @param v: Vector4 to be multiplied
		* @return This Vector4 with the product values
		*/
		Vector4& operator*= (const Vector4& v);

		/**
		* Hadamard division
		* @param v: Vector4 to be divided
		* @return This Vector4 with the division values
		*/
		Vector4& operator/= (const Vector4& v);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return This Vector4 with the product values
		*/
		Vector4& operator*= (const float& a);

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return This Vector4 with the division values
		*/
		Vector4& operator/= (const float& a);

		/**
		* Dot product (Use only if really necessary, this operation is slow [it uses hadd])
		* @param v: Vector4 to perform the operation
		* @return Dot product result
		*/
		float dot(const Vector4& v) const;

		/**
		* Cross product
		* @param v: Vector4 to perform the operation
		* @return Cross product result
		*/
		Vector4 cross(const Vector4& v) const;

		/**
		* Square norm
		* @return Square of the norm of the Vector4
		*/
		float square_norm() const;

		/**
		* Norm
		* @return Norm of the Vector4
		*/
		float norm() const;

	private:
		union {
			struct
			{
				float _x;
				float _y;
				float _z;
				float _w;
			};
			float _data[4];
		};

		friend class Matrix4x4;
		friend class Transformation;
		friend std::ostream& operator <<(std::ostream& os, const Vector4& v);
	};

	std::ostream& operator <<(std::ostream& os, const Vector4& v);
};

#endif // MATH_VECTOR4_H
