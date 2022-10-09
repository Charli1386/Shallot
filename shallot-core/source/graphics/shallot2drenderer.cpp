#include "shallot2drenderer.h"
#include "renderable2d.h"
#include "static_object.h"

namespace shallot { namespace graphics {

    void Shallot2DRenderer::submit(const Renderable2D* renderable){
        m_RenderQueue.push_back((StaticObject*) renderable);
    }
    void Shallot2DRenderer::flush(){
        while(!m_RenderQueue.empty()){
            const StaticObject* object = m_RenderQueue.front();
            object->getVAO()->bind(); 
            object->getIBO()->bind();

            object->getShader().setUniformMat4("ml_matrix", maths::mat4::translation((object->getPosition())));
            glDrawElements(GL_TRIANGLES, object->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

            object->getVAO()->unbind();
            object->getIBO()->unbind();

            m_RenderQueue.pop_front();

        }
    }

}}