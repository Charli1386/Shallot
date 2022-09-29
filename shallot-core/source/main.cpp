#include "graphics/window.h"
#include "graphics/shader.h"
#include "maths/maths.h"

#include "../headers/shalhz.h"

int main()
{

	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Sample window", 940, 500);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Shader shader("shaders/basic.vert", "shaders/basic.frag");

	while(!window.closed()){
		window.clear();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);		
		window.update();
	}

    return 0;
}
