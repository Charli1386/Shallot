#pragma once

#include<GLFW/glfw3.h>

namespace shallot { namespace graphics {

	class Window{
		private:
			const char* m_Name;
			int m_Width, m_Height;
			GLFWwindow* m_Window;
			bool m_Closed;
		public:
			Window(const char* name, int width, int height);
			~Window();
			bool closed();
			void update() const;

		private:
			bool init();

	};

}}
