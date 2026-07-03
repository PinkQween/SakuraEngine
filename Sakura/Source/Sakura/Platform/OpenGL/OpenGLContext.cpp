#include "spch.h"

#include "OpenGLContext.h"

#include "Logging.h"
#include "Core.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Sakura {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SAKURA_INTERNAL_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		
		usize status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		SAKURA_INTERNAL_ASSERT(status, "Failed to initialize Glad!");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}