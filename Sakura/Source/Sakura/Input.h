#pragma once

#include "spch.h"

#include "Core.h"

namespace Sakura {
	class SAKURA_API Input
	{
	public:
		inline static bool IsKeyPressed(int keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<f32, f32> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }

		inline static f32 GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static f32 GetMouseY() { return s_Instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(usize keycode) = 0;
		
		virtual bool IsMouseButtonPressedImpl(usize button) = 0;
		virtual std::pair<f32, f32> GetMousePositionImpl() = 0;

		virtual f32 GetMouseXImpl() = 0;
		virtual f32 GetMouseYImpl() = 0;
	private:
		static Input* s_Instance;
	};
}