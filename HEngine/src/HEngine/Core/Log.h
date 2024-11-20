#pragma once

#include "HEngine/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

#if FMT_VERSION >= 90000
#include "HEngine/Events/Event.h"
template <> struct fmt::formatter<HEngine::Event> : ostream_formatter {};
#endif

namespace HEngine
{
	class  Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}
//core log macros
#define HE_CORE_TRACE(...)		 ::HEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HE_CORE_INFO(...)			 ::HEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HE_CORE_WARN(...)		 ::HEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HE_CORE_ERROR(...)		 ::HEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_CRITICAL(...)		 ::HEngine::Log::GetCoreLogger()->critical (__VA_ARGS__)

//client log macros
#define HE_TRACE(...)		 ::HEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HE_INFO(...)		 ::HEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HE_WARN(...)		 ::HEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HE_ERROR(...)		 ::HEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HE_CRITICAL(...)		 ::HEngine::Log::GetClientLogger()->critical(__VA_ARGS__)

