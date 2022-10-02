#ifndef SHALLOT_CORE_INDEXBUFFERS
#define SHALLOT_CORE_INDEXBUFFERS

#include<GL/glew.h>

namespace shallot {  namespace graphics {
	class IndexBuffer{	
		private:
			GLuint m_BufferID;
			GLuint m_Count;

		public:
			IndexBuffer(GLushort* data, GLsizei count);
			
			void bind() const;
			void unbind() const;
			
			inline GLuint getCount() const { return m_Count; };

	};
}}

#endif
