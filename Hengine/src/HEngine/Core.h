#pragma once

#ifdef HE_PLATFORM_WINDOWS
	#ifdef HE_BUILD_DLL
		#define HENGINE_API __declspec(dllexport)
	#else
		#define HENGINE_API __declspec(dllimport)
	#endif
#else
	#error HEngine only support Windows!
#endif

#define BIT(x) (1 << x)

#ifdef HE_ENABLE_ASSERTS
	#define  HE_ASSERT(x, ...) {if(!(x)) { HE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define  HE_CORE_ASSERT(x, ...) { if(!(x)) { HE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define HE_ASSERT(x, ...)
	#define HE_CORE_ASSERT(x, ...)
#endif