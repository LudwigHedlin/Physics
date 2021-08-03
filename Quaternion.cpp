#include "Quaternion.h"



	Quaternion::Quaternion():s(0.0),v() {}

	Quaternion::Quaternion(real uS, Vec3 uV) :s(uS), v(uV) {}
	
	Quaternion::Quaternion(real uS,real x,real y,real z) 
	{
		s=uS;
		v=Vec3(x,y,z);
	}

	Quaternion::~Quaternion() {}

	Quaternion& Quaternion::operator=(const Quaternion& q) {

		s = q.s;
		v = q.v;
		return *this;

	}
	
	void Quaternion::operator*=(const Quaternion& q) 
	{
		*this=(*this)*q;
	}

	void Quaternion::operator+=(const Quaternion& q) {

		s += q.s;
		v += q.v;

	}

	Quaternion Quaternion::operator+(const Quaternion& q)const {

		Quaternion sum;
		sum.s = s + q.s;
		sum.v = v + q.v;
		return sum;

	}

	void Quaternion::operator-=(const Quaternion& q) {

		s -= q.s;
		v -= q.v;

	}

	Quaternion Quaternion::operator-(const Quaternion& q)const {

		Quaternion sum;
		sum.s = s - q.s;
		sum.v = v - q.v;
		return sum;

	}

	void Quaternion::operator*=(const real r) {

		s *= r;
		v *= r;

	}

	Quaternion Quaternion::operator*(const real r)const {

		Quaternion product;
		product.s = s * r;
		product.v = v * s;
		return product;

	}

	void Quaternion::operator/=(const real r) {

		s = s / r;
		v = v / r;

	}

	Quaternion Quaternion::operator/(const real r)const {

		Quaternion div;
		div.s = s / r;
		div.v = v / r;
		return div;

	}

	Quaternion Quaternion::operator*(const Quaternion& q)const {

		Quaternion product;
		product.s = s * q.s - v * q.v;
		product.v = q.v * s + v * q.s + v.cross(q.v);
		return product;

	}

	Quaternion Quaternion::multiply(const Quaternion& q)const {

		Quaternion product;
		product.s = s * q.s - v * q.v;
		product.v = q.v * s + v * q.s + v.cross(q.v);
		return product;

	}

	real Quaternion::norm()const {

		return sqrt(s * s + v * v);

	}

	void Quaternion::normalize() {
		
		real normValue = norm();
		if (normValue != 0) {
			s = s / normValue;
			v = v / normValue;

		}
		
	}

	Quaternion Quaternion::conjugate()const {

		return Quaternion(s, v * (-1));

	}

	Quaternion Quaternion::inverse()const {

		real norm2 = norm() * norm();
		if (norm2 != 0) {

			return conjugate() / norm2;

		}

	}
	
	void Quaternion::rotateByVector(const Vec3& v) 
	{
		Quaternion q=Quaternion(0,v.x,v.y,v.z);
		(*this)*=q;
	}
	
	void Quaternion::addScaledVector(const Vec3& vector,const real scale) 
	{
		Quaternion q(0,vector*scale);
		q*=*this;

		s=q.s*0.5;
		v.x=q.v.x*0.5;
		v.y = q.v.y * 0.5;
		v.z = q.v.z * 0.5;
	}

