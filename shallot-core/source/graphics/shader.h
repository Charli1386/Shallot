#pragma once

#include "../utils/fileutils.h"
#include <GL/glew.h>
#include <vector>

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
