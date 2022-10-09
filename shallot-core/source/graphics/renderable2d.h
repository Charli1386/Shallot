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
        public:
            maths::vec2 m_Size;
            maths::vec3 m_Position;
            maths::vec4 m_Color;
        
        public:
            Renderable2D(maths::vec3 position, maths::vec2 size, maths::vec4 color) : m_Size(size), m_Position(position), m_Color(color){}

            virtual ~Renderable2D(){}

            inline const maths::vec3& getPosition() const { return m_Position; }
            inline const maths::vec2& getSize() const { return m_Size; }
            inline const maths::vec4& getColor() const { return m_Color; }

    };

}}

#endif