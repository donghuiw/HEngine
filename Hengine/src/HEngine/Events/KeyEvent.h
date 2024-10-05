#pragma once

#include "Event.h"

namespace HEngine
{
	class HENGINE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode;  }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: m_KeyCode(keycode){}

		int m_KeyCode;
	};
	class HENGINE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycod, int repeatCount)
			: KeyEvent(keycod), m_RepeatCount(repeatCount){}

		inline int GetRepeatCount() const { return m_RepeatCount;  }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};
	class HENGINE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
