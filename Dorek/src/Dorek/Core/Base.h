#pragma once

#include <memory>

#include "Dorek/Core/PlatformDetection.h"

#ifdef DK_DEBUG
	#if defined(DK_PLATFORM_WINDOWS)
		#define DK_DEBUGBREAK() __debugbreak()
	#elif defined(DK_PLATFORM_LINUX)
		#include <signal.h>
		#define DK_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define DK_ENABLE_ASSERTS
#else
	#define DK_DEBUGBREAK()
#endif

#define DK_EXPAND_MACRO(x) x
#define DK_STRINGIFY_MACRO(x) #x

#define BIT(x) (1 << x)

#define DK_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Dorek {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Dorek/Core/Log.h"
#include "Dorek/Core/Assert.h"
