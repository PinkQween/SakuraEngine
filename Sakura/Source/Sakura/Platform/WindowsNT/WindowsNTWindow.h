#pragma once

#include "Window.h"

#include "Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Sakura {
	class SAKURA_API WindowsNTWindow : public Window
	{
	public:
		WindowsNTWindow(const WindowProps& props);
		virtual ~WindowsNTWindow();

		void OnUpdate() override;

		inline usize GetWidth() const override { return m_Data.Width; }
		inline usize GetHeight() const override { return m_Data.Height; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
	
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const override { return m_Window; }

	private:

		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
		
		GLFWwindow* m_Window;
		GraphicsContext* m_Context;
		
		struct WindowData
		{
			std::string Title;
			usize Width = 0;
			usize Height = 0;
			bool VSync = false;
			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};
}