#include "window.h"
#include <iostream>

namespace shallot { namespace graphics {
	
	Window::Window(const char* name, int width, int height){
		m_Name = name;
		m_Width = width;
		m_Height = height;
		if(!init()) glfwTerminate();
	}

	Window::~Window() {
		glfwTerminate();
	} 

	void Window::update() const {
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::closed(){
		return glfwWindowShouldClose(m_Window);
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
		return true;
	}


}}
