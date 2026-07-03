#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Window.h"
#include "Renderer/Shader.h"

namespace Sakura {
	class SAKURA_API Application {
	public:
		Application();
		virtual ~Application();

		int Run();

		void OnEvent(Event& e);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		u32 m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
		
	private:
		static Application* s_Instance;
	};

	// To be defined in the client
	Application* CreateApplication();
};