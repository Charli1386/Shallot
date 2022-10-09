#ifndef SHALLOT_ENGINE_OBJECT
#define SHALLOT_ENGINE_OBJECT

#include "renderable2d.h"
namespace shallot { namespace graphics {

    class Object : public Renderable2D{

        private:

        public:
            Object(float x, float y, float width, float height, const maths::vec4& color);

    };

}}

#endif