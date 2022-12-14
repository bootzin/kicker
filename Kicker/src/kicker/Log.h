#pragma once

#include "Core.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

#ifdef KCK_DEBUG
#define KCK_ENABLE_ASSERT
#endif

#ifdef KCK_ENABLE_ASSERT
#define KCK_ASSERT(x, ...) { if (!(x)) { KCK_ERROR("Assertion Failed: {0}", __VA_ARGS__); } }
#else
#define KCK_ASSERT(x, ...)
#endif

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Kicker {
	
	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetLogger()
		{
			if (!s_Logger)
				Init();
			return s_Logger;
		}

	private:
	static Ref<spdlog::logger> s_Logger;
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
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}


#define KCK_TRACE(...) ::Kicker::Log::GetLogger()->trace(__VA_ARGS__)
#define KCK_INFO(...) ::Kicker::Log::GetLogger()->info(__VA_ARGS__)
#define KCK_WARN(...) ::Kicker::Log::GetLogger()->warn(__VA_ARGS__)
#define KCK_ERROR(...) ::Kicker::Log::GetLogger()->error(__VA_ARGS__)
#define KCK_CRITICAL(...) ::Kicker::Log::GetLogger()->critical(__VA_ARGS__)
