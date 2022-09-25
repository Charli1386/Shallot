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



}}

#endif
