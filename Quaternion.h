#pragma once
#include "Vector3D.h"
#include "constants.h"
#include <cmath>


	class Quaternion {

	private:

	public:
		real s;

		Vec3 v;

		Quaternion();

		Quaternion(real uS, Vec3 uV);

		Quaternion(real uS,real x,real y,real z);

		~Quaternion();

		Quaternion& operator=(const Quaternion& q);

		void operator+=(const Quaternion& q);

		Quaternion operator+(const Quaternion& q)const;

		void operator-=(const Quaternion& q);

		Quaternion operator-(const Quaternion& q)const;

		void operator*=(const real r);

		void operator*=(const Quaternion& q);

		Quaternion operator*(const real r)const;

		void operator/=(const real r);

		Quaternion operator/(const real r)const;

		Quaternion operator*(const Quaternion& q)const;

		Quaternion multiply(const Quaternion& q)const;

		real norm()const;

		void normalize();

		Quaternion conjugate()const;

		Quaternion inverse()const;

		void rotateByVector(const Vec3& v);

		void addScaledVector(const Vec3& vector,const real scale);

	};

