#include "graphics/window.h"
#include "../headers/shalhz.h"

int main(void)
{

	using namespace shallot;
	using namespace graphics;

	Window window("Sample window", 940, 500);
	glClearColor(0.2f, 0.5f, 0.8f, 1.0f);

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	while(!window.closed()){
		std::cout << "h: " << window.getHeight() << " w: " << window.getWidth() << std::endl;
		window.clear();
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}

    return 0;
}
