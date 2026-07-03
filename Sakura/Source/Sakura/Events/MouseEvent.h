#pragma once

#include "Core.h"
#include "Event.h"

namespace Sakura {
	class SAKURA_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(f32 x, f32 y)
			: m_MouseX(x), m_MouseY(y) {
		}

		inline f32 GetX() const { return m_MouseX; }
		inline f32 GetY() const { return m_MouseY; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		f32 m_MouseX, m_MouseY;
	};

	class SAKURA_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(f32 xOffset, f32 yOffset)
			: m_XOffset(xOffset), m_YOffset(yOffset) {
		}
		inline f32 GetXOffset() const { return m_XOffset; }
		inline f32 GetYOffset() const { return m_YOffset; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		f32 m_XOffset, m_YOffset;
	};

	class SAKURA_API MouseButtonEvent : public Event
	{
	public:
		inline usize GetMouseButton() const { return m_Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(usize button)
			: m_Button(button) {
		}

		usize m_Button;
	};

	class SAKURA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(usize button)
			: MouseButtonEvent(button) {
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class SAKURA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(usize button)
			: MouseButtonEvent(button) {
		}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
