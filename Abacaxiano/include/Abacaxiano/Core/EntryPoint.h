#pragma once
#include "Core/Config.h"
#include "Core/Application.h"

#ifdef ABX_WINDOWS

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	#ifndef ABX_DIST
	#define ABX_CONSOLE
		if (!AllocConsole()) {
			POPUP_ERROR("COULD NOT ALLOCATED CONSOLE!");
			ABX_EXIT_PROGRAM;
		}
		FILE* fp = freopen("CONOUT$", "w", stdout);
		if (!fp) {
			POPUP_ERROR("COULD NOT OPEN CONSOLE!");
			ABX_EXIT_PROGRAM;
		}
	#endif

		abx::Application* app = abx::CreateApplication();
		app->Run();
		delete app;
	
	#ifdef ABX_CONSOLE
		fclose(fp);
		FreeConsole();
	#endif
}
#elif (defined(ABX_LINUX))
	int main(int argc, char** argv) {
		abx::Application* app = abx::CreateApplication();
		app->Run();
		delete app;
	}
#elif (defined(ABX_MAC)
	int main(int argc, char** argv) {
		abx::Application* app = abx::CreateApplication();
		app->Run();
		delete app;
	}
#endif