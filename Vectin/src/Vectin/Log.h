#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vectin {
	
	class VECTIN_API Log {
	public:
		static void init();
		
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {
			return sCoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() {
			return sClientLogger;
		}
	
	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};

}

#define VN_CORE_ERROR(...)		::Vectin::Log::getCoreLogger()->error(__VA_ARGS__)
#define VN_CORE_INFO(...)		::Vectin::Log::getCoreLogger()->info(__VA_ARGS__)
#define VN_CORE_TRACE(...)		::Vectin::Log::getCoreLogger()->trace(__VA_ARGS__)
#define VN_CORE_WARN(...)		::Vectin::Log::getCoreLogger()->warn(__VA_ARGS__)
#define VN_CORE_CRITICAL(...)	::Vectin::Log::getCoreLogger()->critical(__VA_ARGS__)
#define VN_CORE_DEBUG(...)		::Vectin::Log::getCoreLogger()->debug(__VA_ARGS__)

#define VN_CLIENT_ERROR(...)	::Vectin::Log::getCoreLogger()->error(__VA_ARGS__)
#define VN_CLIENT_INFO(...)		::Vectin::Log::getCoreLogger()->info(__VA_ARGS__)
#define VN_CLIENT_TRACE(...)	::Vectin::Log::getCoreLogger()->trace(__VA_ARGS__)
#define VN_CLIENT_WARN(...)		::Vectin::Log::getCoreLogger()->warn(__VA_ARGS__)
#define VN_CLIENT_CRITICAL(...) ::Vectin::Log::getCoreLogger()->critical(__VA_ARGS__)
#define VN_CLIENT_DEBUG(...)	::Vectin::Log::getCoreLogger()->debug(__VA_ARGS__)