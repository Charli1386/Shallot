#pragma once
#include<iostream>

#ifndef SHALLOT_CORE_MATHS_H
#define	SHALLOT_CORE_MATHS_H
namespace shallot { namespace maths {
	struct vec2{
		float x, y;

		vec2(); 
		vec2(const float& x, const float& y);

		vec2& add(const vec2& other);
		vec2& sub(const vec2& other);
		vec2& mul(const vec2& other);
		vec2& div(const vec2& other);

		friend vec2& operator+(vec2& left, vec2& right);
		friend vec2& operator-(vec2& left, vec2& right);
		friend vec2& operator*(vec2& left, vec2& right);
		friend vec2& operator/(vec2& left, vec2& right);

		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);

		vec2& operator+=(vec2& other);
		vec2& operator-=(vec2& other);
		vec2& operator*=(vec2& other);
		vec2& operator/=(vec2& other);

	};

}}
#endif
