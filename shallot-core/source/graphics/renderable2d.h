#ifndef SHALLOT_CORE_RENDERABLE_2D
#define SHALLOT_CORE_RENDERABLE_2D

#include "../maths/maths.h"
#include "Buffers/buffer.h"
#include "Buffers/indexbuffer.h"
#include "Buffers/vertexarray.h"
#include "shader.h"


namespace shallot { namespace graphics{

    struct VertexData{
        maths::vec3 vertex;
        maths::vec4 color;
    };

    class Renderable2D{
        protected:
            maths::vec2 m_Size;
            maths::vec3 m_Position;
            maths::vec4 m_Color;

            VertexArray* m_vertexArray;
            IndexBuffer* m_IndexBuffer;
            Shader& m_Shader;
        
        public:
            Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color, Shader& shader) : m_Shader(shader){
                m_Position = position;
                m_Size = size;
                m_Color = color;

                m_vertexArray = new VertexArray();

                GLfloat vertices[] = {
                    0, 0, 0,
                    0, size.y, 0,
                    size.x, size.y, 0,
                    size.x, 0, 0
                };

                GLfloat colors[] = {
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w,
                    color.x, color.y, color.z, color.w
                };

                m_vertexArray->addBuffer(new Buffer(vertices, 4*3, 3), 0);
                m_vertexArray->addBuffer(new Buffer(colors, 4*4, 4), 1);

                GLushort indices[] = {0,1,2,2,3,0};

                m_IndexBuffer = new IndexBuffer(indices, 6);
            }

            virtual ~Renderable2D(){
                delete m_vertexArray;
                delete m_IndexBuffer;
            }

            inline const VertexArray* getVAO() const { return  m_vertexArray; }
            inline const IndexBuffer* getIBO() const { return  m_IndexBuffer; }

            inline Shader& getShader() const { return m_Shader; }

            inline const maths::vec3& getPosition() const { return m_Position; }
            inline const maths::vec2& getSize() const { return m_Size; }
            inline const maths::vec4& getColor() const { return m_Color; }

    };

}}

#endif