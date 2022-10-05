#pragma once

#include <memory>
#include "spdlog/spdlog.h"
#include "Core.h"

namespace Kicker {
	
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetLogger() { return s_Logger; }

	private:
	static Ref<spdlog::logger> s_Logger;
	};

}


#define KCK_TRACE(...) ::Kicker::Log::GetLogger()->trace(__VA_ARGS__)
#define KCK_INFO(...) ::Kicker::Log::GetLogger()->info(__VA_ARGS__)
#define KCK_WARN(...) ::Kicker::Log::GetLogger()->warn(__VA_ARGS__)
#define KCK_ERROR(...) ::Kicker::Log::GetLogger()->error(__VA_ARGS__)
#define KCK_FATAL(...) ::Kicker::Log::GetLogger()->critical(__VA_ARGS__)
