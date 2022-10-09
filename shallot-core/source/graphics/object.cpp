#include "object.h"

namespace shallot { namespace graphics {

    Object::Object(float x, float y, float width, float height, const maths::vec4& color) : Renderable2D(maths::vec3(x, y,0), maths::vec2(width, height), color){

    }

}}