#pragma once

#include "spch.h"
#include "Events/Event.h"

namespace Sakura {
	struct WindowProps {
		std::string Title;
		usize Width;
		usize Height;
		WindowProps(const std::string& title = "Sakura Engine",
			usize width = 1280,
			usize height = 720)
			: Title(title), Width(width), Height(height) {
		}
	};

	class SAKURA_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual usize GetWidth() const = 0;
		virtual usize GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}