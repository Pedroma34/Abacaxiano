#include "Core/Logger.h"
#include "Core/Context.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace abx {

	Logger::Logger() : 
		m_abxLogger("empty"),
		m_clientLogger("empty")
	{
		Context::logger = this;
		
		//Engine
		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		console_sink->set_pattern("%^[ABX]%$ [%H:%M:%S.%f] [%^%l%$] %v");
		m_abxLogger = spdlog::logger("ABXLogger", console_sink);
	
		//Client
		auto client_console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		client_console_sink->set_pattern("%^[CLIENT]%$ [%H:%M:%S.%f] [%^%l%$] %v");
		m_clientLogger = spdlog::logger("ClientLogger", client_console_sink);
	}

	spdlog::logger& Logger::CoreLog(){
		return m_abxLogger;
	}
	spdlog::logger& Logger::ClientLog(){
		return m_clientLogger;
	}

}