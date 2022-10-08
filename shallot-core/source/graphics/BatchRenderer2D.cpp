#include "BatchRenderer2D.h"

namespace shallot { namespace graphics {

    BatchRenderer2D::BatchRenderer2D(){
        init();
    }

    BatchRenderer2D::~BatchRenderer2D(){
        delete m_IBO;
        glDeleteBuffers(1, &m_VBO);
    }

     void BatchRenderer2D::init(){
        
    }

}}