#include "input.h"

namespace shallot { namespace input {

	Keyboard Keyboard::m_Instance;
	Keyboard& Keyboard::getInstance() { return Keyboard::m_Instance; }

	Mouse Mouse::m_Instance;
	Mouse& Mouse::getInstance() { return Mouse::m_Instance; }

}}
