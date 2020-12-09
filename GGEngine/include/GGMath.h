#ifndef GGMATH_H
#define GGMATH_H

#include <iostream>
#include <math.h>
#include <float.h>
#include <stdlib.h>

struct vec2D
{
	
	float x, y;

	 
	vec2D() {}

	
	vec2D(float x, float y) : x(x), y(y) {}

	
	void setZero();

	
	void Set(const float& x_, const float& y_);

	
	void displayVector() const;

	
	float lengthSquared() const;

	
	float length() const;

	
	void operator += (const vec2D& v);

	
	void operator -= (const vec2D& v);

	
	void operator *= (const float& k);

};

inline vec2D operator + (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x + b.x, a.y + b.y);
}

inline vec2D operator - (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x - b.x, a.y - b.y);
}

inline vec2D operator * (const float& k, const vec2D& v)
{
	return vec2D(k * v.x, k * v.y);
}

#endif