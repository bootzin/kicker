#include "kckpch.h"
#include "Log.h"
#include "Core.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Kicker {

	Ref<spdlog::logger> Log::s_Logger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T]: %v%s");
		s_Logger = spdlog::stdout_color_mt("console");
		s_Logger->set_level(spdlog::level::trace);
	}

}