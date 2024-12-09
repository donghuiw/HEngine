#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#include "HEngine/Core/Base.h"
//This ignores call warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

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
template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternio)
{
	return os << glm::to_string(quaternio);
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

