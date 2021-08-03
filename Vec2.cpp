#include "Vec2.h"



Vec2 Vec2::operator+(const Vec2& v)const
{
	Vec2 v2 = Vec2();
	v2.x = this->x + v.x;
	v2.y = this->y + v.y;
	return v2;
}

Vec2 Vec2::operator-(const Vec2& v)const
{
	Vec2 v2 = Vec2();
	v2.x = x - v.x;
	v2.y = y - v.y;
	return v2;
}


Vec2 Vec2::operator=(const Vec2& v)
{
	x = v.x;
	y = v.y;
	return *this;
}

Vec2 Vec2::operator*(const real r)const
{
	Vec2 v = Vec2();
	v.x = x * r;
	v.y = y * r;
	return v;
}

real Vec2::operator*(const Vec2& b)const
{
	return x * b.x + y * b.y;
}

Vec2 Vec2::operator/(const real r)const
{
	Vec2 v = Vec2();
	v.x = x / r;
	v.y = y / r;
	return v;
}

void Vec2::operator+=(const Vec2& v)
{
	x += v.x;
	y += v.y;
}

void Vec2::operator-=(const Vec2& v)
{
	x -= v.x;
	y -= v.y;
}

void Vec2::normalize()
{
	real l = this->length();
	x /= l;
	y /= l;
}


real Vec2::length()const
{
	return std::sqrt(x*x+y*y);
}

real Vec2::distance(const Vec2& v)const
{
	return std::sqrt((x-v.x) * (x-v.x) + (y-v.y) * (y-v.y));
}
