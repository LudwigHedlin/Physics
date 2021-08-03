#include "Matrix3D.h"



	Mat3::Mat3() {
		//Initialize identity matrix if no argument

		for (int i = 0; i < 9; i++) {

			Matrix[i] = 0.0f;

		}

		Matrix[0] = Matrix[4] = Matrix[8] = 1.0f;

	}

	Mat3::Mat3(real x0, real x1, real x2, real x3, real x4, real x5, real x6, real x7, real x8) {

		Matrix[0]=x0;
		Matrix[3]=x3;
		Matrix[6]=x6;

		Matrix[1]=x1;
		Matrix[4]=x4;
		Matrix[7]=x7;

		Matrix[2]=x2;
		Matrix[5]=x5;
		Matrix[8]=x8;

	}

	Mat3::~Mat3() {};

	Mat3& Mat3::operator=(const Mat3& m) {

		for (int i = 0; i < 9; i++) {

			Matrix[i] = m.Matrix[i];

		}

		return *this;
	

	}

	void Mat3::operator+=(const Mat3& m) {

		for (int i = 0; i < 9; i++) {

			Matrix[i] += m.Matrix[i];

		}

	}

	Mat3 Mat3::operator+(const Mat3& m)const {

		Mat3 n;

		for (int i = 0; i < 9; i++) {

			n.Matrix[i] = Matrix[i] + m.Matrix[i];

		}

		return n;

	}

	void Mat3::operator-=(const Mat3& m) {

		for (int i = 0; i < 9; i++) {

			Matrix[i] -= m.Matrix[i];

		}

	}

	Mat3 Mat3::operator-(const Mat3& m)const {

		Mat3 n;

		for (int i = 0; i < 9; i++) {

			n.Matrix[i] = Matrix[i] - m.Matrix[i];

		}

		return n;

	}

	void Mat3::operator*=(const real s) {

		for (int i = 0; i < 9; i++) {

			Matrix[i] *= s;

		}

	}

	Mat3 Mat3::operator*(const real s)const {

		Mat3 n;

		for (int i = 0; i < 9; i++) {

			n.Matrix[i] = Matrix[i]*s;

		}

		return n;

	}


	void Mat3::operator/=(const real s){
	
		for (int i = 0; i < 9; i++) {

			Matrix[i] = Matrix[i] / s;

		}

	}

	Mat3 Mat3::operator/(const real s)const {

		Mat3 n;

		for (int i = 0; i < 9; i++) {

			n.Matrix[i] = Matrix[i] / s;

		}

		return n;

	}

	Mat3 Mat3::operator*(const Mat3& m)const {

		Mat3 n;

		n.Matrix[0] = Matrix[0] * m.Matrix[0] + Matrix[3] * m.Matrix[1] + Matrix[6] * m.Matrix[2];
		n.Matrix[1] = Matrix[1] * m.Matrix[0] + Matrix[4] * m.Matrix[1] + Matrix[7] * m.Matrix[2];
		n.Matrix[2] = Matrix[2] * m.Matrix[0] + Matrix[5] * m.Matrix[1] + Matrix[8] * m.Matrix[2];

		n.Matrix[3] = Matrix[0] * m.Matrix[3] + Matrix[3] * m.Matrix[4] + Matrix[6] * m.Matrix[5];
		n.Matrix[4] = Matrix[1] * m.Matrix[3] + Matrix[4] * m.Matrix[4] + Matrix[7] * m.Matrix[5];
		n.Matrix[5] = Matrix[2] * m.Matrix[3] + Matrix[5] * m.Matrix[4] + Matrix[8] * m.Matrix[5];

		n.Matrix[6] = Matrix[0] * m.Matrix[6] + Matrix[3] * m.Matrix[7] + Matrix[6] * m.Matrix[8];
		n.Matrix[7] = Matrix[1] * m.Matrix[6] + Matrix[4] * m.Matrix[7] + Matrix[7] * m.Matrix[8];
		n.Matrix[8] = Matrix[2] * m.Matrix[6] + Matrix[5] * m.Matrix[7] + Matrix[8] * m.Matrix[8];

		return n;
	}

	void Mat3::operator*=(const Mat3& m) {

		Matrix[0] = Matrix[0] * m.Matrix[0] + Matrix[3] * m.Matrix[1] + Matrix[6] * m.Matrix[2];
		Matrix[1] = Matrix[1] * m.Matrix[0] + Matrix[4] * m.Matrix[1] + Matrix[7] * m.Matrix[2];
		Matrix[2] = Matrix[2] * m.Matrix[0] + Matrix[5] * m.Matrix[1] + Matrix[8] * m.Matrix[2];

		Matrix[3] = Matrix[0] * m.Matrix[3] + Matrix[3] * m.Matrix[4] + Matrix[6] * m.Matrix[5];
		Matrix[4] = Matrix[1] * m.Matrix[3] + Matrix[4] * m.Matrix[4] + Matrix[7] * m.Matrix[5];
		Matrix[5] = Matrix[2] * m.Matrix[3] + Matrix[5] * m.Matrix[4] + Matrix[8] * m.Matrix[5];

		Matrix[6] = Matrix[0] * m.Matrix[6] + Matrix[3] * m.Matrix[7] + Matrix[6] * m.Matrix[8];
		Matrix[7] = Matrix[1] * m.Matrix[6] + Matrix[4] * m.Matrix[7] + Matrix[7] * m.Matrix[8];
		Matrix[8] = Matrix[2] * m.Matrix[6] + Matrix[5] * m.Matrix[7] + Matrix[8] * m.Matrix[8];

	}

	real Mat3::operator[](unsigned int i)const
	{
		if (i<9)
		{
			return Matrix[i];
		}
		
	}

	void Mat3::setIdentityMatrix() {

		for (int i = 0; i < 9; i++) {

			Matrix[i] = 0.0f;

		}

		Matrix[0] = Matrix[4] = Matrix[8] = 1.0f;

	}

	void Mat3::setInverseMatrix(const Mat3& m) {

		real det = m.Matrix[0] * m.Matrix[4] * m.Matrix[8]
			+ m.Matrix[1] * m.Matrix[5] * m.Matrix[6]
			+ m.Matrix[2] * m.Matrix[3] * m.Matrix[7]
			- m.Matrix[0] * m.Matrix[5] * m.Matrix[7]
			- m.Matrix[1] * m.Matrix[3] * m.Matrix[8]
			- m.Matrix[2] * m.Matrix[4] * m.Matrix[6];

		if (det == 0) return;
		//wrong
		det=((real)1.0f)/det;
		Matrix[0] = (m.Matrix[4] * m.Matrix[8] - m.Matrix[5] * m.Matrix[7]) *det;
		Matrix[1] = -(m.Matrix[1]*m.Matrix[8]-m.Matrix[2]*m.Matrix[7])*det;
		Matrix[2] = (m.Matrix[1]*m.Matrix[5]-m.Matrix[2]*m.Matrix[4])*det;
		
		Matrix[3] = -(m.Matrix[3]*m.Matrix[8]-m.Matrix[5]*m.Matrix[6])*det;
		Matrix[4] = (m.Matrix[0] * m.Matrix[8] - m.Matrix[2] * m.Matrix[6]) *det;
		Matrix[5] = -(m.Matrix[0]*m.Matrix[5]-m.Matrix[2]*m.Matrix[3])*det;

		Matrix[6] = (m.Matrix[3]*m.Matrix[7]-m.Matrix[4]*m.Matrix[6])*det;
		Matrix[7] = -(m.Matrix[0]*m.Matrix[7]-m.Matrix[1]*m.Matrix[6])*det;
		Matrix[8] = (m.Matrix[0] * m.Matrix[4] - m.Matrix[1] * m.Matrix[3]) *det;


	}

	Mat3 Mat3::getInverseMatrix()const {

		Mat3 inverse;
		inverse.setInverseMatrix(*this);
		return inverse;

	}

	void Mat3::invertMatrix() {

		setInverseMatrix(*this);

	}
	
	void Mat3::transpose() 
	{
		int m[9];
		for(int i=0;i<9;i++){
			m[i]=Matrix[i];
		}
		Matrix[0] = m[0];
		Matrix[1] = m[3];
		Matrix[2] = m[6];

		Matrix[3] = m[1];
		Matrix[4] = m[4];
		Matrix[5] = m[7];

		Matrix[6] = m[2];
		Matrix[7] = m[5];
		Matrix[8] = m[8];
	}

	void Mat3::setTranspose(const Mat3& m) {

		Matrix[0] = m.Matrix[0];
		Matrix[1] = m.Matrix[3];
		Matrix[2] = m.Matrix[6];

		Matrix[3] = m.Matrix[1];
		Matrix[4] = m.Matrix[4];
		Matrix[5] = m.Matrix[7];

		Matrix[6] = m.Matrix[2];
		Matrix[7] = m.Matrix[5];
		Matrix[8] = m.Matrix[8];

	}

	Mat3 Mat3::getTranspose()const {

		Mat3 transpose;
		transpose.setTranspose(*this);
		return transpose;

	}

	Vec3 Mat3::operator*(const Vec3& v)const {

		return Vec3(Matrix[0] * v.x + Matrix[3] * v.y + Matrix[6] * v.z,
			Matrix[1] * v.x + Matrix[4] * v.y + Matrix[7] * v.z,
			Matrix[2] * v.x + Matrix[5] * v.y + Matrix[8] * v.z);

	}

	Vec3 Mat3::linearTransform(const Vec3& v)const {

		return (*this) * v;

	}
	
	void Mat3::setOrientation(const Quaternion& q) 
	{
		Matrix[0] = 1-2*(q.v.y*q.v.y+q.v.z*q.v.z);
		Matrix[1] = 2*q.v.x*q.v.y+q.v.z*q.s;
		Matrix[2] = 2*q.v.x*q.v.z-2*q.v.y*q.s;
		Matrix[3] = 2*q.v.x*q.v.z-2*q.v.z*q.v.z;
		Matrix[4] = 1-2*(q.v.x*q.v.x+q.v.z*q.v.z);
		Matrix[5] = 2*q.v.y*q.v.z+2*q.v.x*q.s;
		Matrix[6] = 2*q.v.x*q.v.z+2*q.v.y*q.s;
		Matrix[7] = 2*q.v.y*q.v.z-2*q.v.x*q.s;
		Matrix[8] = 1- 2*(q.v.x*q.v.x+q.v.y*q.v.y);
	}
