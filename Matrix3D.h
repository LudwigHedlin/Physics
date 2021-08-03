#pragma once
#include "Vector3D.h"
#include "Quaternion.h"
#include "constants.h"


	class Mat3 {
	private:

	public:
		real Matrix[9] = { 0.0 };

		//Constructors
		Mat3();
		Mat3(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7, real x8);

		//Copy constructor
		Mat3& operator=(const Mat3& m);

		//Destructor
		~Mat3();


		void operator+=(const Mat3& m);

		Mat3 operator+(const Mat3& m)const;

		void operator-=(const Mat3& m);

		Mat3 operator-(const Mat3& m)const;

		void operator*=(const real s);

		Mat3 operator*(const real s)const;

		void operator/=(const real s);

		Mat3 operator/(const real s)const;

		Mat3 operator*(const Mat3& m)const;

		void operator*=(const Mat3& m);

		real operator[](unsigned int i)const;

		void setIdentityMatrix();

		void setInverseMatrix(const Mat3& m);

		Mat3 getInverseMatrix()const;

		void invertMatrix();

		void transpose();//transpose in place

		void setTranspose(const Mat3& m);

		Mat3 getTranspose()const;

		Vec3 operator*(const Vec3& v)const;

		Vec3 linearTransform(const Vec3& v)const;

		void setOrientation(const Quaternion& q);


	};

