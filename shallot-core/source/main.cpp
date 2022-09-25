#include "graphics/window.h"
#include "maths/vec2.h"


#include "../headers/shalhz.h"

#define nDEBUG

int main(void)
{

	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Sample window", 940, 500);

	glClearColor(0.2f, 0.5f, 0.8f, 1.0f);

	GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	vec2 vector(1.0f, 1.0f);
	vector.add(vec2(3.5f, 7.5f));

	std::cout << vector << std::endl;
	
	while(!window.closed()){
		window.clear();
		
#ifndef DEBUG
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
