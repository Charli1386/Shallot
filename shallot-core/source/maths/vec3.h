#include<iostream>

#ifndef SHALLOT_CORE_MATHS_VEC3_H
#define	SHALLOT_CORE_MATHS_VEC3_H
namespace shallot { namespace maths {
	struct vec3{
		float x, y, z;

		vec3(); 
		vec3(const float& x, const float& y, const float& z);

		vec3& add(const vec3& other);
		vec3& sub(const vec3& other);
		vec3& mul(const vec3& other);
		vec3& div(const vec3& other);

		friend vec3& operator+(vec3 left, vec3& right);
		friend vec3& operator-(vec3 left, vec3& right);
		friend vec3& operator*(vec3 left, vec3& right);
		friend vec3& operator/(vec3 left, vec3& right);
		
		void operator=(vec3& other);

		friend std::ostream& operator<<(std::ostream& stream, const vec3& vector);

		bool operator==(const vec3& other);
		bool operator!=(const vec3& other);

		vec3& operator+=(vec3& other);
		vec3& operator-=(vec3& other);
		vec3& operator*=(vec3& other);
		vec3& operator/=(vec3& other);

	};

}}
#endif
