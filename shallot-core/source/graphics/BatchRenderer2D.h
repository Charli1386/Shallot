#ifndef SHALLOT_CORE_BATCH_RENDERER_2D
#define SHALLOT_CORE_BATCH_RENDERER_2D

#include "Buffers/indexbuffer.h"
#include "Buffers/vertexarray.h"
#include "renderer2d.h"

namespace shallot { namespace graphics {

#define RENDERER_MAX_OBJECTS    10000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_OBJECT_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    RENDERER_OBJECT_SIZE * RENDERER_MAX_OBJECTS
#define RENDERER_INDICES_SIZE   RENDERER_MAX_OBJECTS * 6
    
    class BatchRenderer2D : public Renderer2D{
        private:
            VertexArray m_VAO;
            IndexBuffer* m_IBO;
            GLsizei m_IndexCount;
            GLuint m_VBO;
        public:
            BatchRenderer2D();
            ~BatchRenderer2D();
            //virtual void submit(const Renderable2D* renderable) override;
            //virtual void flush() override;
        private:
            void init();
    };

}}

#endif 