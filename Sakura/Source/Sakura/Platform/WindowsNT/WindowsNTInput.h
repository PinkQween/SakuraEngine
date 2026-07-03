#pragma once

#include "Input.h"

namespace Sakura {
	class WindowsNTInput : public Input
	{
	protected:
		virtual bool IsKeyPressedImpl(usize keycode) override;

		virtual bool IsMouseButtonPressedImpl(usize button) override;
		virtual std::pair<f32, f32> GetMousePositionImpl() override;
		virtual f32 GetMouseXImpl() override;
		virtual f32 GetMouseYImpl() override;
	};
}