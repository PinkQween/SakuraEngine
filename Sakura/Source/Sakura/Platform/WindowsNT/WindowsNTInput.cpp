#include "spch.h"

#include "WindowsNTInput.h"

#include "Application.h"

#include "GLFW/glfw3.h"

namespace Sakura {
	Input* Input::s_Instance = new WindowsNTInput();

	bool WindowsNTInput::IsKeyPressedImpl(usize keycode)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, (int)keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsNTInput::IsMouseButtonPressedImpl(usize button)
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, (int)button);
		return state == GLFW_PRESS;
	}

	std::pair<f32, f32> WindowsNTInput::GetMousePositionImpl()
	{
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		f64 xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return { (f32)xpos, (f32)ypos };
	}

	f32 WindowsNTInput::GetMouseXImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return x;
	}

	f32 WindowsNTInput::GetMouseYImpl()
	{
		auto [x, y] = GetMousePositionImpl();
		return y;
	}
}