#pragma once 
#include "spdlog/spdlog.h"
#include "Core/Config.h"

namespace abx {
	
	class Logger {
	public:
		Logger();

		spdlog::logger& CoreLog();
		spdlog::logger& ClientLog();

	private:
		spdlog::logger m_abxLogger;
		spdlog::logger m_clientLogger;
	};

}

//Only log for Debug and Release mode, not for Dist
#if defined(ABX_DEBUG) || defined(ABX_RELEASE)
	#include "Core/Context.h"
	#define LOG_FUNC() __FUNCTION__
	//Engine	
	#define ABX_CORE_LOG_INFO(x)     abx::Context::logger->CoreLog().info("[{}] {}", LOG_FUNC(), x)
	#define ABX_CORE_LOG_WARN(x)     abx::Context::logger->CoreLog().warn("[{}] {}", LOG_FUNC(), x)
	#define ABX_CORE_LOG_ERROR(x)    abx::Context::logger->CoreLog().error("[{}] {}", LOG_FUNC(), x)
	#define ABX_CORE_LOG_CRITICAL(x) abx::Context::logger->CoreLog().critical("[{}] {}", LOG_FUNC(), x)
	//Client
	#define ABX_LOG_INFO(x)     abx::Context::logger->ClientLog().info("[{}] {}", LOG_FUNC(), x)
	#define ABX_LOG_WARN(x)     abx::Context::logger->ClientLog().warn("[{}] {}", LOG_FUNC(), x)
	#define ABX_LOG_ERROR(x)    abx::Context::logger->ClientLog().error("[{}] {}", LOG_FUNC(), x)
	#define ABX_LOG_CRITICAL(x) abx::Context::logger->ClientLog().critical("[{}] {}", LOG_FUNC(), x)
#elif defined(ABX_DIST)
	#define ABX_CORE_LOG_INFO(x)
	#define ABX_CORE_LOG_WARN(x)
	#define ABX_CORE_LOG_ERROR(x)
	#define ABX_CORE_LOG_CRITICAL(x)
	#define ABX_LOG_INFO(x)
	#define ABX_LOG_WARN(x)
	#define ABX_LOG_ERROR(x)
	#define ABX_LOG_CRITICAL(x)
#endif