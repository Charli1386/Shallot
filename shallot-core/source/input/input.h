#ifndef SHALLOT_CORE_INPUT_H
#define SHALLOT_CORE_INPUT_H

namespace shallot { namespace input {
	
	#define MAX_KEYS 1024
	#define MAX_BUTTONS 32

	class Keyboard{
		private:
			static Keyboard m_Instance;
			bool m_Keys[MAX_KEYS];

		private:
			Keyboard(){
				m_Keys[MAX_KEYS] = {0}; 
			}

		public:
			static Keyboard& getInstance();
			inline void setKeyState(int key, bool state) { m_Keys[key] = state; } 
			inline bool nthKeyPressed(int key) const { return m_Keys[key]; }


	};

	class Mouse{
		private:
			static Mouse m_Instance;
			bool m_Buttons[MAX_BUTTONS];
			double mX, mY;
		
		private:
			Mouse(){
				m_Buttons[MAX_BUTTONS] = {0}; 
			}

		public:
			static Mouse& getInstance();
			
			inline double getX() const { return mX; }
			inline double getY() const { return mY; }
			inline void getMousePosition(double &x, double &y) { x = mX, y = mY; }
			inline void setX(double X) { mX = X; }
			inline void setY(double Y) { mY = Y; }

			inline void setButtonState(int button, bool state) { m_Buttons[button] = state; }
			inline bool nthButtonPressed(int button) const { return m_Buttons[button]; }

	};



}}

#endif
