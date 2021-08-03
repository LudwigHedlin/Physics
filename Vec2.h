#pragma once
#include "constants.h"
#include <cmath>
class Vec2 {
public:
	Vec2(): x(0.0) , y(0.0)
	{

	}
	~Vec2(){}

	Vec2(real x1, real x2)
	{
		x = x1;
		y = x2;
	}

	real x;
	real y;

	Vec2 operator+(const Vec2& v)const;

	Vec2 operator-(const Vec2& v)const;

	Vec2 operator=(const Vec2& v);

	Vec2 operator*(const real r)const;

	real operator*(const Vec2& b)const;

	Vec2 operator/(const real r)const;

	void operator+=(const Vec2& v);

	void operator-=(const Vec2& v);

	void normalize();

	real length()const;

	real distance(const Vec2& v)const;
};

