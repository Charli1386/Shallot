#pragma once

#define _USE_MATH_DEFINES

#include "maths.h"

namespace shallot { namespace maths {
	
	struct mat4{
		float elements[4*4]; // 4x4 matrix

		mat4();
		mat4(float diagonal);

		static mat4 identity();

		mat4& multiply(const mat4& other);
		friend mat4& operator*(const mat4& other);
		mat4& operator*=(const mat4& other);

		static mat4 orthographic(float left, float right, float bot, float top, float near, float far); // Ortho mat -> projection matrix, farther things will not be smaller (not scaled down)
		static mat4 perspective(float fov, float aspectRatio, float near, float far);

		static mat4 translation(const vec3& translation);
		static mat4 rotation(float angle, const vec3& axis);
		static mat4 scale(const vec3& scale);
		
	};

}}
