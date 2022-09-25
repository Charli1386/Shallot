#include "graphics/window.h"
#include "maths/maths.h"

#include "../headers/shalhz.h"

#define DEBUG

int main()
{

	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Sample window", 940, 500);

	glClearColor(0.2f, 0.5f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	mat4 positiom = mat4::translation(vec3(2,4,6));

	while(!window.closed()){
		window.clear();
		
#ifdef DEBUG
		//std::cout << "h: " << window.getHeight() << " w: " << window.getWidth() << std::endl;
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
#else
		glDrawArrays(GL_ARRAY_BUFFER, 0, 0);
#endif
		window.update();
	}

    return 0;
}
