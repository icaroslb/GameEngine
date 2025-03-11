#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

namespace geb {
	/**
	* Vector 4
	*/
	class Vector {
	public:
		Vector();
		Vector(float x, float y, float z, float w);
		Vector(const float* array);
		Vector(const Vector& v);

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
		* Vector values array
		* @return values array
		*/
		const float* data() const;

		/**
		* Vector values array
		* @return values array
		*/
		      float* data();

		Vector& operator= (const Vector& v);

		/**
		* Vector sum
		* @param v: Vector to be added
		* @return Vector with the sum values
		*/
		Vector operator+ (const Vector& v) const;

		/**
		* Vector subtraction
		* @param v: Vector to be subtracted
		* @return Vector with the subtraction values
		*/
		Vector operator- (const Vector& v) const;
		
		/**
		* Hadamard product
		* @param v: Vector to be multiplied
		* @return Vector with the product values
		*/
		Vector operator* (const Vector& v) const;

		/**
		* Hadamard division
		* @param v: Vector to be divided
		* @return Vector with the division values
		*/
		Vector operator/ (const Vector& v) const;

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return Vector with the product values
		*/
		Vector operator* (const float& a) const;

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return Vector with the division values
		*/
		Vector operator/ (const float& a) const;

		/**
		* Vector sum
		* @param v: Vector to be added
		* @return This vector with the sum values
		*/
		Vector& operator+= (const Vector& v);

		/**
		* Vector subtraction
		* @param v: Vector to be subtracted
		* @return This vector with the subtraction values
		*/
		Vector& operator-= (const Vector& v);

		/**
		* Hadamard product
		* @param v: Vector to be multiplied
		* @return This vector with the product values
		*/
		Vector& operator*= (const Vector& v);

		/**
		* Hadamard division
		* @param v: Vector to be divided
		* @return This vector with the division values
		*/
		Vector& operator/= (const Vector& v);

		/**
		* Scalar product
		* @param a: Scalar to be multiplied
		* @return This vector with the product values
		*/
		Vector& operator*= (const float& a);

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return This vector with the division values
		*/
		Vector& operator/= (const float& a);

		/**
		* Dot product (Use only if really necessary, this operation is slow [it uses hadd])
		* @param v: Vector to perform the operation
		* @return Dot product result
		*/
		float dot(const Vector& v) const;

		/**
		* Cross product
		* @param v: Vector to perform the operation
		* @return Cross product result
		*/
		Vector cross(const Vector& v) const;

		/**
		* Square norm
		* @return Square of the norm of the vector
		*/
		float square_norm() const;

		/**
		* Norm
		* @return Norm of the vector
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

		friend class Matrix;
	};
};

#endif // MATH_VECTOR_H
