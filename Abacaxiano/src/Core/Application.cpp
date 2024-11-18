#include "Core/Application.h"
#include "Core/Logger.h"

namespace abx {
	Application::Application() :
		m_logger(),
		m_randy(),
		m_window("Abacaxiano", 1280, 720)
	{
		ABX_CORE_LOG_INFO("Application initialized.");
	}

	Application::~Application() {
		ABX_CORE_LOG_INFO("Application destroyed.");
	}

	void Application::Run() {
		while (!m_window.IsDone()){
			m_window.Update();

			m_window.Clear();

			m_window.Display();
		}
	}
}