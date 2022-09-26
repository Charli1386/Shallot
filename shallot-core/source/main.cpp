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

	mat4 position = mat4::translation(vec3(4,3,2));

	position *= mat4::identity();

	vec4 column = position.columns[3];

	std::cout << column << std::endl;

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
#endif
		window.update();
	}

    return 0;
}
