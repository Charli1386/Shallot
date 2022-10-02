#include "graphics/window.h"
#include "graphics/shader.h"
#include "input/input.h"
#include "maths/maths.h"
#include "graphics/Buffers/buffer.h"

#include "../headers/shalhz.h"

#define DEBUG

int main(int argc, char* argv[])
{

	float f = 0;

	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Sample window", 940, 500);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	GLfloat vertices[] = {
		4, 3, 0,
		12, 3, 0,
		4, 6, 0,
		4, 6, 0,
		12, 6, 0,
		12, 3, 0
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	

	Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	shader.setUniform2f("light_pos", vec2(0.0f, 1.5f));
	shader.setUniform4f("color", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	input::Mouse& mouse = input::Mouse::getInstance();

	while(!window.closed()){
		window.clear();
		double x = mouse.getX(), y=mouse.getY();

		shader.setUniform2f("light_pos", vec2((float)(x*16.0f/960.0f), (float)(9.0f-y * 9.0f/540.0f)));
		

		glDrawArrays(GL_TRIANGLES, 0, 6);		
		window.update();
	#ifdef nDEBUG
		std::cin >> f;
		std::cout << "Rotating " << f << " degrees." << std::endl;
		shader.setUniformMat4("ml_matrix", mat4::rotation(f, vec3(0, 0, 1)));
	#endif
	}

    return 0;
}
