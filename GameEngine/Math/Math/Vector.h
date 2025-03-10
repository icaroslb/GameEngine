#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

namespace geb {
	class Vector {
	public:
		Vector();
		Vector(double x, double y, double z, double w);
		Vector(const Vector& v);

		double X() const;
		double Y() const;
		double Z() const;
		double W() const;

		const double* data() const;

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
		Vector operator* (const double& a) const;

		/**
		* Scalar division
		* @param a: Scalar to be divided
		* @return Vector with the division values
		*/
		Vector operator/ (const double& a) const;

		/**
		* Dot product
		* @param v: Vector to perform the operation
		* @return Dot product result
		*/
		double dot(const Vector& v) const;

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
		double square_norm() const;

		/**
		* Norm
		* @return Norm of the vector
		*/
		double norm() const;

	private:
		union {
			struct
			{
				double _x;
				double _y;
				double _z;
				double _w;
			};
			double _data[4];
		};
	};
};

#endif // MATH_VECTOR_H
