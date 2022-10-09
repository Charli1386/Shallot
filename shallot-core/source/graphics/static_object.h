#ifndef SHALLOT_ENGINE_STATIC_OBJECT
#define SHALLOT_ENGINE_STATIC_OBJECT

#include "renderable2d.h"
namespace shallot { namespace graphics {

    class StaticObject : public Renderable2D{
        private:
            VertexArray* m_vertexArray;
            IndexBuffer* m_IndexBuffer;
            Shader& m_Shader;
        public:
            StaticObject(float x, float y, float width, float height, maths::vec4 color, Shader& shader);
            ~StaticObject();

            inline const VertexArray* getVAO() const { return  m_vertexArray; }
            inline const IndexBuffer* getIBO() const { return  m_IndexBuffer; }

            inline Shader& getShader() const { return m_Shader; }
 
    };

}}

#endif