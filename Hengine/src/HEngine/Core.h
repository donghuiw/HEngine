#pragma once

#include <memory>

#ifdef HE_PLATFORM_WINDOWS
#if HE_DYNAMIC_LINK
	#ifdef HE_BUILD_DLL
		#define HENGINE_API __declspec(dllexport)
	#else
		#define HENGINE_API __declspec(dllimport)
	#endif
#else
	#define HENGINE_API 
#endif
#else
	#error HEngine only support Windows!
#endif

#define BIT(x) (1 << x)

#ifdef HE_DEBUG
	#define HE_ENABLE_ASSERTS
#endif

#ifdef HE_ENABLE_ASSERTS
	#define  HE_ASSERT(x, ...) {if(!(x)) { HE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define  HE_CORE_ASSERT(x, ...) { if(!(x)) { HE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HE_ASSERT(x, ...)
	#define HE_CORE_ASSERT(x, ...)
#endif

#define HE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace HEngine
{
	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;
}
