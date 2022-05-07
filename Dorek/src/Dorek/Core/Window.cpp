#include "dkpch.h"
#include "Dorek/Core/Window.h"

#ifdef DK_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Dorek
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef DK_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		DK_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}