#pragma once

#include <glm/glm.hpp>

#include "Dorek/Core/KeyCodes.h"
#include "Dorek/Core/MouseCodes.h"

namespace Dorek {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);
		static glm::vec2 GetMousePosition();
		static float GetMouseX();
		static float GetMouseY();
	};
}
