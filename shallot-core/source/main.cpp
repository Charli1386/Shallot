#include "graphics/window.h"
#include "graphics/shader.h"
#include "input/input.h"
#include "maths/maths.h"
#include "graphics/Buffers/buffer.h"
#include "graphics/Buffers/indexbuffer.h"
#include "graphics/Buffers/vertexarray.h"

#include "graphics/renderer2d.h"
#include "graphics/shallot2drenderer.h"

#include "graphics/static_object.h"


#include "../headers/shalhz.h"

#define DEBUG

int main(int argc, char* argv[])
{
	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Shallot", 940, 500);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4,3,0)));

	StaticObject sprite1(5, 5, 4, 8, vec4(1,0,1,1), shader);
	StaticObject sprite3(7, 1, 8, 4, vec4(0,1,0,1), shader);
	Shallot2DRenderer renderer;

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	input::Mouse& mouse = input::Mouse::getInstance();

	while(!window.closed()){
		window.clear();
		double x, y;
		mouse.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / window.getWidth()), (float)(9.0f - y * 9.0f / window.getHeight())));
		renderer.submit(&sprite1);
		renderer.flush();
		renderer.submit(&sprite3);
		renderer.flush();
		window.update();
	}

    return 0;
}
