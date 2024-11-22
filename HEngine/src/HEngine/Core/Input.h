#pragma once

#include "HEngine/Core/Base.h"
#include "HEngine/Core/KeyCodes.h"
#include "HEngine/Core/MouseCodes.h"

#include <utility>

namespace HEngine
{
	class  Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

	private:
		static bool IsMouseButtonPressed(MouseCode button);
		static std::pair<float, float> GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}