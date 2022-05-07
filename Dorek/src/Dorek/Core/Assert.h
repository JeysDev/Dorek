#pragma once

#include "Dorek/Core/Base.h"
#include "Dorek/Core/Log.h"
#include <filesystem>

#ifdef DK_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define DK_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { DK##type##ERROR(msg, __VA_ARGS__); DK_DEBUGBREAK(); } }
	#define DK_INTERNAL_ASSERT_WITH_MSG(type, check, ...) DK_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define DK_INTERNAL_ASSERT_NO_MSG(type, check) DK_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", DK_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define DK_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define DK_INTERNAL_ASSERT_GET_MACRO(...) DK_EXPAND_MACRO( DK_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, DK_INTERNAL_ASSERT_WITH_MSG, DK_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define DK_ASSERT(...) DK_EXPAND_MACRO( DK_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define DK_CORE_ASSERT(...) DK_EXPAND_MACRO( DK_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define DK_ASSERT(...)
	#define DK_CORE_ASSERT(...)
#endif
