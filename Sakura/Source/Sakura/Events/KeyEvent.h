#pragma once

#include "Core.h"
#include "Event.h"

namespace Sakura {
	class SAKURA_API KeyEvent : public Event
	{
	public:
		inline usize GetKeyCode() const { return m_KeyCode; }
	
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(usize keycode)
			: m_KeyCode(keycode) {
		}
		usize m_KeyCode;
	};

	class SAKURA_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(usize keycode, usize repeatCount = 0)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {
		}

		inline usize GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		usize m_RepeatCount;
	};

	class SAKURA_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(usize keycode)
			: KeyEvent(keycode) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}