#pragma once
#include "constants.h"
#include "Vector3D.h"
#include "Matrix3D.h"
#include "Quaternion.h"
class Mat34 {
	//A 3x4 column major representation of a 4x4 matrix where the last row is always assumed to be [0,0,0,1]
	
public:
	Mat34(real data[12]);

	Mat34(); //No argument initializes identity matrix

	Vec3 operator*(const Vec3& v)const;

	Mat34 operator*(const Mat34& m)const;

	real getDeterminant()const;

	Mat3 getRotation()const;

	void setInverse(const Mat34 m);

	Mat34 inverse()const;

	void invert();

	void setOrientationAndPos(const Quaternion& q,const Vec3& v);

	Vec3 localToWorld(const Vec3& local,const Mat34& transform)const;

	Vec3 worldToLocal(const Vec3& world,const Mat34& transform)const;

	Vec3 transformDirection(const Vec3& vector)const;

	Vec3 transformInverseDirection(const Vec3& v)const;

public:
	real matrix[12];
};

