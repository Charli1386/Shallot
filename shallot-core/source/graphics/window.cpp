#include "window.h"
#include "../input/input.h"

#include <iostream>

namespace shallot { namespace graphics {

	void windowResizeCallback(GLFWwindow *window, int width, int height);
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void on_mouse_move(GLFWwindow* window, double xpos, double ypos);
	void on_mouse_press(GLFWwindow* window, int button, int action, int mods);
	
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
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetCursorPosCallback(m_Window, on_mouse_move);
		glfwSetMouseButtonCallback(m_Window, on_mouse_press);

		if(glewInit() != GLEW_OK){
			std::cout << "Could not initialize GLEW" << std::endl;
			return false;
		}
		std::cout << glGetString(GL_VERSION) << std::endl;
		return true;
	}

	void windowResizeCallback(GLFWwindow *window, int width, int height){
		glViewport(0, 0, width, height);
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
		input::Keyboard::getInstance().setKeyState(key, action != GLFW_RELEASE);
		
		#ifdef DEBUG
		if(action == GLFW_PRESS) std::cout << "Key: " << key << std::endl; 
		#endif

		if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GLFW_TRUE);
	}

	void on_mouse_move(GLFWwindow* window, double xpos, double ypos){
		input::Mouse& mouse = input::Mouse::getInstance();
		mouse.setX(xpos); mouse.setY(ypos);
		
		#ifdef DEBUG
		std::cout << "x: " << mouse.getX() << " y: " << mouse.getY() << std::endl;
		#endif

	}

	void on_mouse_press(GLFWwindow* window, int button, int action, int mods){
		input::Mouse::getInstance().setButtonState(button, action != GLFW_RELEASE);
		
		#ifdef DEBUG
		std::cout << "Pressed" << std::endl;
		#endif
	}




}}
