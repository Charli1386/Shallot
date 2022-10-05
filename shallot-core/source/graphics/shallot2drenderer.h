#ifndef SHALLOT_CORE_SHALLOT_2DRENDERER
#define SHALLOT_CORE_SHALLOT_2DRENDERER

#include <deque>
#include "renderer2d.h"

namespace shallot { namespace graphics {

    class Shallot2DRenderer : public Renderer2D{
        private:
            std::deque<const Renderable2D*> m_RenderQueue;
        public:
            void submit(const Renderable2D* renderable) override;
            void flush() override;
    };

}}

#endif 