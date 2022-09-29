#ifndef SHALLOT_CORE_SHADER_H
#define SHALLOT_CORE_SHADER_H

#include <GL/glew.h>
#include <vector>
#include <string>
#include <iostream>

namespace shallot { namespace graphics {

	class Shader{
		private:
			GLuint m_ShaderID;
			const char* m_vertexPath;
			const char* m_fragPath;

		public:
			Shader(const char* vertexPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;

		private:
			GLuint load();

	};

}}

#endif
