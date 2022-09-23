#include "window.h"
#include <iostream>

namespace shallot { namespace graphics {

	void windowResizeCallback(GLFWwindow *window, int height, int width);
	
	Window::Window(const char* name, int width, int height){
		m_Name = name;
		m_Width = width;
		m_Height = height;
		if(!init()) glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	}

	void Window::clear() const{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::update() {
		glfwPollEvents();
		//glfwGetFramebufferSize(m_Window, &m_Width, &m_Height); //resize
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed(){
		return glfwWindowShouldClose(m_Window) == 1;
	}

	bool Window::init(){
		if(!glfwInit()){
			std::cout << "Failed to initialize window buffer" << std::endl;
			return false;
		}

		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);
		if(!m_Window){
			glfwTerminate();
			std::cout << "Failure" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowSizeCallback(m_Window, windowResizeCallback);

		if(glewInit() != GLEW_OK){
			std::cout << "Could not initialize GLEW" << std::endl;
			return false;
		}

		return true;
	}

	void windowResizeCallback(GLFWwindow *window, int height, int width){
		glViewport(0, 0, width, height);
	}


}}
