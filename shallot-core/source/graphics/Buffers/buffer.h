#ifndef SHALLOT_CORE_BUFFERS
#define SHALLOT_CORE_BUFFERS

#include<GL/glew.h>

namespace shallot {  namespace graphics {
	class Buffer{	
		private:
			GLuint m_BufferID;
			GLuint m_CompCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint compCount);
			~Buffer();

			void bind() const;
			void unbind() const;
			
			inline GLuint getCompCount() const { return m_CompCount; };
			inline GLuint getBufferID() const { return m_BufferID; }

	};
}}

#endif
