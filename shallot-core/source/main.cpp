#include <GLFW/glfw3.h>
#include "../headers/shalhz.h"
#include "graphics/window.h"

int main(void)
{

	using namespace shallot;
	using namespace graphics;

	Window window("Sample window", 280, 640);
	
	while(!window.closed()){
		window.update();
	}

    return 0;
}
