#include "hepch.h"
#include "HEngine/Core/Input.h"

#ifdef HE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsInput.h"
#endif

namespace HEngine {

	Scope<Input> Input::s_Instance = Input::Create();

	Scope<Input> Input::Create()
	{
#ifdef HE_PLATFORM_WINDOWS
		return CreateScope<WindowsInput>();
#else
		HE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}
}