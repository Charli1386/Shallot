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

	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	while(!window.closed()){
		window.clear();
		
#ifdef DEBUG
		//std::cout << "h: " << window.getHeight() << " w: " << window.getWidth() << std::endl;
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		//glVertex2f(0.5f, -0.5f);
		glEnd();
#endif
		window.update();
	}

    return 0;
}
