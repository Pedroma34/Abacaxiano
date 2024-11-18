#pragma once
#include "Core/Config.h"
#include "Core/Logger.h"
#include "Core/Randy.h"

namespace abx {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		Logger m_logger;
		Randy  m_randy;
	};

	Application* CreateApplication(); // To be defined in CLIENT
}