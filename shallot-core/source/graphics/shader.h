#ifndef SHALLOT_CORE_SHADER_H
#define SHALLOT_CORE_SHADER_H

#include <GL/glew.h>
#include <vector>
#include <string>
#include <iostream>
#include "../maths/maths.h"

namespace shallot { namespace graphics {

	class Shader{
		private:
			GLuint m_ShaderID;
			const char* m_vertexPath;
			const char* m_fragPath;

		public:
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();

			void setUniform1f(const char* name, float value);
			void setUniform1i(const char* name, int value);
			void setUniform2f(const char* name, const maths::vec2& vector);
			void setUniform3f(const char* name, const maths::vec3& vector);
			void setUniform4f(const char* name, const maths::vec4& vector);
			void setUniformMat4(const char* name, const maths::mat4& matrix);

			void enable() const;
			void disable() const;

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
	};

}}

#endif
