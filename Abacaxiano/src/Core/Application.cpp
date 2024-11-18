#include "Core/Application.h"
#include "Core/Logger.h"

namespace abx {
	Application::Application() :
		m_logger(),
		m_randy()
	{
		ABX_CORE_LOG_INFO("Application initialized.");
	}

	Application::~Application() {
		ABX_CORE_LOG_INFO("Application destroyed.");
	}

	void Application::Run() {
		while (true){

		}
	}
}