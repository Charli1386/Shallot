#pragma once
#include<iostream>

#ifndef SHALLOT_CORE_MATHS_VEC4_H
#define	SHALLOT_CORE_MATHS_VEC4_H
namespace shallot { namespace maths {
	struct vec4{
		float x, y, z, w;

		vec4(); // default is a constructor that takes in no arguments 
		vec4(const float& x, const float& y, const float& z, const float& w);

		vec4& add(const vec4& other);
		vec4& sub(const vec4& other);
		vec4& mul(const vec4& other);
		vec4& div(const vec4& other);

		friend vec4& operator+(vec4 left, vec4& right);
		friend vec4& operator-(vec4 left, vec4& right);
		friend vec4& operator*(vec4 left, vec4& right);
		friend vec4& operator/(vec4 left, vec4& right);
		
		void operator=(vec4& other);

		friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);

		bool operator==(const vec4& other);
		bool operator!=(const vec4& other);

		vec4& operator+=(vec4& other);
		vec4& operator-=(vec4& other);
		vec4& operator*=(vec4& other);
		vec4& operator/=(vec4& other);

	};

}}
#endif
