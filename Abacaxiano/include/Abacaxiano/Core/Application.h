#pragma once
#include "Core/Config.h"
#include "Core/Logger.h"
#include "Core/Randy.h"
#include "Core/Window.h"

namespace abx {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		Logger m_logger;
		Randy  m_randy;
		Window m_window;
	};

	Application* CreateApplication(); // To be defined in CLIENT
}