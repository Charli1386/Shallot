 #ifndef SHALLOT_CORE_BUFFER_VERTEX_ARRAYS
 #define SHALLOT_CORE_BUFFER_VERTEX_ARRAYS

#include <vector>
#include <GL/eglew.h>

#include "buffer.h"


namespace shallot { namespace graphics {

    class VertexArray{
        private:
            GLuint m_ArrayID;
            std::vector<Buffer *> m_Buffers;
        
        public:
            VertexArray();
            ~VertexArray();

            void addBuffer(Buffer* buffer, GLuint index);

            void bind() const;
            void unbind() const;
    };

}}

 #endif