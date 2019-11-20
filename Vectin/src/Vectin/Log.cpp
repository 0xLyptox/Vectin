#include <vnpch.h>
#include "Log.h"

namespace Vectin {

	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("Vectin");
		sCoreLogger->set_level(spdlog::level::trace);

		sClientLogger = spdlog::stdout_color_mt("Client");
		sClientLogger->set_level(spdlog::level::trace);
	}

}