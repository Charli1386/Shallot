#ifndef SHALLOT_CORE_WINDOW_H
#define SHALLOT_CORE_WINDOW_H

#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include<GL/gl.h>

#define MAX_KEYS 1024
#define MAX_BUTTONS 32

namespace shallot { namespace graphics {

	class Window{
		private:	// WINDOW MEMBERS
			const char* m_Name;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;

		public:
			Window(const char* name, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed();

			inline int getWidth() const { return m_Width; }
			inline int getHeight() const { return m_Height; }
			
			
		private:
			bool init();
			friend void windowResizeCallback(GLFWwindow *window, int height, int width);
			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	};
 
}}

#endif
