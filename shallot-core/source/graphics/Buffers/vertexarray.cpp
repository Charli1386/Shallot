#include "vertexarray.h"

namespace shallot { namespace graphics {

    VertexArray::VertexArray(){
        glGenVertexArrays(1, &m_ArrayID);
    }

    VertexArray::~VertexArray(){
        for(int i=0; i<m_Buffers.size(); ++i){
            delete m_Buffers[i];
        }
    }

    void VertexArray::addBuffer(Buffer *buffer, GLuint index){
        bind();
        buffer->bind();

        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, buffer->getCompCount(), GL_FLOAT, GL_FALSE, 0, 0);

        unbind();
        buffer->unbind();
    }

    void VertexArray::bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, m_ArrayID);
    }

    void VertexArray::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}}