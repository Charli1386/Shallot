#include "static_object.h"

namespace shallot { namespace graphics {

    StaticObject::StaticObject(float x, float y, float width, float height, maths::vec4 color, Shader& shader) : Renderable2D(maths::vec3(x,y,0), maths::vec2(width, height), color), m_Shader(shader){
    
        m_vertexArray = new VertexArray();

        GLfloat vertices[] = {
            0, 0, 0,
            0, height, 0,
            width, height, 0,
            width, 0, 0
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

    StaticObject::~StaticObject(){
        delete m_vertexArray;
        delete m_IndexBuffer;
    }

}}