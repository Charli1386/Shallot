#ifndef SHALLOT_CORE_RENDERER
#define SHALLOT_CORE_RENDERER

#include "renderable2d.h"
#include <GL/glew.h>
#include "../maths/maths.h"

namespace shallot { namespace graphics {
    class Renderer2D{
        public:
            virtual void submit(const Renderable2D* renderable) = 0;
            virtual void flush() = 0;
    };
}}

#endif