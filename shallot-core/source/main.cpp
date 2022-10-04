#include "graphics/window.h"
#include "graphics/shader.h"
#include "input/input.h"
#include "maths/maths.h"
#include "graphics/Buffers/buffer.h"
#include "graphics/Buffers/indexbuffer.h"
#include "graphics/Buffers/vertexarray.h"

#include "graphics/renderer2d.h"
#include "graphics/shallot2drenderer.h"


#include "../headers/shalhz.h"

#define DEBUG

int main(int argc, char* argv[])
{
	using namespace shallot;
	using namespace graphics;
	using namespace maths;

	Window window("Shallot", 940, 500);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

#ifdef nDEBUG
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


	GLfloat vertices[] = {
		0, 0, 0,
		0, 3, 0,
		8, 3, 0,
		8, 0, 0
	};

	GLfloat minVertex[] = {
		0, 0, 0,
		0, 3, 0,
		3, 3, 0,
		3, 0, 0
	};

	GLushort indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	GLfloat colorA[] = {
		1.0f, 0.8f, 0.8f, 1.0f,
		1.0f, 0.8f, 0.8f, 1.0f,
		1.0f, 0.8f, 0.8f, 1.0f,
		1.0f, 0.8f, 0.8f, 1.0f
	};

	GLfloat colorB[] = {
		0.0f, 0.8f, 0.8f, 1.0f,
		0.0f, 0.8f, 0.8f, 1.0f,
		0.0f, 0.8f, 0.8f, 1.0f,
		0.0f, 0.8f, 0.8f, 1.0f
	};

	GLfloat colorC[] = {
		0.0f, 0.8f, 0.2f, 1.0f,
		0.0f, 0.8f, 0.2f, 1.0f,
		0.0f, 0.8f, 0.2f, 1.0f,
		0.0f, 0.8f, 0.2f, 1.0f
	};

	GLfloat colorD[] = {
		0.5f, 0.0f, 1.0f, 1,
		0.5f, 0.0f, 1.0f, 1,
		0.5f, 0.0f, 1.0f, 1,
		0.5f, 0.0f, 1.0f, 1
	};

	VertexArray rect1, rect2, rect3, rect4, rect5, square1, square2;
	IndexBuffer ibo(indices, 6);

	rect1.addBuffer(new Buffer(vertices, 4*3, 3), 0);
	rect1.addBuffer(new Buffer(colorA, 4*4, 4), 1);
	
	rect2.addBuffer(new Buffer(vertices, 4*3, 3), 0);
	rect2.addBuffer(new Buffer(colorB, 4*4, 4), 1);

	rect3.addBuffer(new Buffer(vertices, 4*3, 3), 0);
	rect3.addBuffer(new Buffer(colorC, 4*4, 4), 1);

	rect4.addBuffer(new Buffer(vertices, 4*3, 3), 0);
	rect4.addBuffer(new Buffer(colorC, 4*4, 4), 1);

	rect5.addBuffer(new Buffer(vertices, 4*3, 3), 0);
	rect5.addBuffer(new Buffer(colorB, 4*4, 4), 1);

	square1.addBuffer(new Buffer(minVertex, 4*4, 3), 0);
	square1.addBuffer(new Buffer(colorD, 4*4, 4), 1);

	square2.addBuffer(new Buffer(minVertex, 4*4, 3), 0);
	square2.addBuffer(new Buffer(colorD, 4*4, 4), 1);
#else

#endif
	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	
	Shader shader("shaders/basic.vert", "shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4,3,0)));

	Renderable2D sprite1(vec3(5,5,0), vec2(4,4), vec4(1,0,1,1), shader), sprite2(vec3(0,2,0), vec2(4,4), vec4(0,1,0,0), shader);
	Shallot2DRenderer renderer;

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	input::Mouse& mouse = input::Mouse::getInstance();

	while(!window.closed()){
		window.clear();
		double x, y;
		mouse.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		renderer.submit(&sprite1);
		renderer.flush();
		renderer.submit(&sprite2);
		renderer.flush();
		window.update();
	}

    return 0;
}
