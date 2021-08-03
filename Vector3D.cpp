#include "Vector3D.h"
#include <cmath>
#include "Quaternion.h"


	//Constructors
	Vec3::Vec3() :x(0.0), y(0.0), z(0.0) {};

	Vec3::Vec3(real uX, real uY, real uZ) :x(uX), y(uY), z(uZ) {};

	//Destructor
	Vec3::~Vec3() {};

	//Copy Constructors
	Vec3::Vec3(const Vec3& v) :x(v.x), y(v.y), z(v.z) {};

	Vec3& Vec3::operator=(const Vec3& v) {

		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}
	
	void Vec3::operator*=(const Mat3 m) 
	{
		real x1=x*m.Matrix[0]+y*m.Matrix[3]+z*m.Matrix[6];
		real x2 = x * m.Matrix[1] + y * m.Matrix[4] + z * m.Matrix[7];
		real x3 = x * m.Matrix[2] + y * m.Matrix[5] + z * m.Matrix[8];
		x=x1;
		y=x2;
		z=x3;
	}

	void Vec3::operator+=(const Vec3& v) {

		x += v.x;
		y += v.y;
		z += v.z;

	}

	Vec3 Vec3::operator+(const Vec3& v)const {

		return Vec3(x + v.x, y + v.y, z + v.z);

	}

	void Vec3::operator-=(const Vec3& v) {

		x -= v.x;
		y -= v.y;
		z -= v.z;

	}

	Vec3 Vec3::operator-(const Vec3& v)const {

		return Vec3(x - v.x, y - v.y, z - v.z);

	}

	void Vec3::operator/=(const real s) {

		x = x / s;
		y = y / s;
		z = z / s;

	}

	Vec3 Vec3::operator/(const real s)const {

		return Vec3(x / s, y / s, z / s);

	}

	void Vec3::operator*=(const real s) {

		x *= s;
		y *= s;
		z *= s;

	}

	Vec3 Vec3::operator*(const real s)const {

		return Vec3(x * s, y * s, z * s);

	}

	real Vec3::operator*(const Vec3& v)const {

		return x * v.x + y * v.y + z * v.z;

	}

	real Vec3::dot(const Vec3& v)const {
		//Vector dot product
		return x * v.x + y * v.y + z * v.z;

	}

	Vec3 Vec3::cross(const Vec3& v)const {
		//Vector cross product
		return Vec3(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);

	}

	void Vec3::operator%=(const Vec3& v) {

		*this = cross(v);

	}

	Vec3 Vec3::operator%(const Vec3& v)const {

		return Vec3(y * v.z - z * v.y,
			z * v.x - x * v.z,
			x * v.y - y * v.x);

	}

	real Vec3::operator[](unsigned int i)const
	{
		if (i<3)
		{
			if (i == 0)
			{
				return x;
			}
			else if (i==1)
			{
				return y;
			}
			else if (i==2)
			{
				return z;
			}
		}
	}

	real Vec3::magnitude()const {

		return std::sqrt(x * x + y * y + z * z);

	}

	void Vec3::normalize() {

		real length = std::sqrt(x * x + y * y + z * z);

		x = x / length;
		y = y / length;
		z = z / length;

	}

	Vec3 Vec3::rotate(const real uAngle, Vec3& uAxis) {

		Quaternion pureQuaternion = Quaternion(0, *this);
		uAxis.normalize();

		Quaternion q(uAngle, uAxis);
		q.normalize();

		Quaternion qInverse = q.inverse();

		Quaternion rotatedVector = q * pureQuaternion * qInverse;

		return rotatedVector.v;



	}

