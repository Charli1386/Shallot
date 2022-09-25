#include "vec2.h"

namespace shallot { namespace maths {

	vec2::vec2(){
		x = 0.0f;
		y = 0.0f;
	}

	vec2::vec2(const float& x, const float& y){
		this->x = x;
		this->y = y;
	}

	vec2& vec2::add(const vec2& other){
		x += other.x;
		y += other.y;

		return *this;
	}

	vec2& vec2::sub(const vec2& other){
		x -= other.x;
		y -= other.y;

		return *this;
	}

	vec2& vec2::mul(const vec2& other){
		x *= other.x;
		y *= other.y;

		return *this;
	}

	vec2& vec2::div(const vec2& other){
		x /= other.x;
		y /= other.y;

		return *this;
	}

	vec2& operator+(vec2& left, vec2& right){
		return left.add(right);
	}

	vec2& operator-(vec2& left, vec2& right){
		return left.sub(right);
	}

	vec2& operator*(vec2& left, vec2& right){
		return left.mul(right);
	}

	vec2& operator/(vec2& left, vec2& right){
		return left.div(right);
	}

	vec2& vec2::operator+=(vec2& other){
		*this = *this + other;
		return *this;
	}


	std::ostream& operator<<(std::ostream& stream, const vec2& vector){
		stream << "vec2: [" << vector.x << ", " << vector.y << "]";
		return stream;
	}




}}
