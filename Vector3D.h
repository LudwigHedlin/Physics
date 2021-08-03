//Math engine base
#pragma once
#include "Matrix3D.h"


	class Vec3 {

	private:

	public:
		real x;
		real y;
		real z;

		//constructors
		Vec3();		
		Vec3(real uX, real uY, real uZ);	

		//Destructor
		~Vec3();

		//Copy constructors
		Vec3(const Vec3& v);
		Vec3& operator=(const Vec3& v);

		
		void operator+=(const Vec3& v);

		
		Vec3 operator+(const Vec3& v)const;

		
		void operator-=(const Vec3& v);

		
		Vec3 operator-(const Vec3& v)const;

		
		void operator/=(const real s);

		Vec3 operator/(const real s)const;

		void operator*=(const real s);

		void operator*=(const Mat3 m);

		Vec3 operator*(const real s)const;

		real operator*(const Vec3& v)const;

		real dot(const Vec3& v)const;

		Vec3 cross(const Vec3& v)const;

		void operator%=(const Vec3& v);

		Vec3 operator%(const Vec3& v)const;

		real operator[](unsigned int i)const;

		real magnitude()const;

		void normalize();

		Vec3 rotate(const real uAngle, Vec3& uAxis);

	};

	

