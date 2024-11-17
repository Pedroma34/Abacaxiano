#pragma once
#include "Core/Config.h"
#include "Core/Logger.h"

namespace abx {
	class Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		Logger m_logger;
	};

	Application* CreateApplication(); // To be defined in CLIENT
}