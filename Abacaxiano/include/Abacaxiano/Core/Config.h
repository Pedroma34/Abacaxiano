#pragma once
// File to set up some configurations for the project, like platform, compiler, variables, etc.

// Compilers
#if defined(__GNUC__)
	#define COMPILER "GNU Compiler"
	#define ASSERT(x) if (!(x)) __builtin_trap()
	#define FUNC_SIG __func__
	#define PRETTY_FUNCTION __PRETTY_FUNCTION__
#elif defined(_MSC_VER)
	#define COMPILER "Microsoft Visual C++"
	#define ASSERT(x) if (!(x)) __debugbreak()
	#define FUNC_SIG __func__
	#define PRETTY_FUNCTION __FUNCSIG__
#elif defined(__clang__)
	#define COMPILER "Clang Compiler"
	#define ASSERT(x) if (!(x)) __builtin_trap()
	#define FUNC_SIG __func__
	#define PRETTY_FUNCTION __PRETTY_FUNCTION__
#else
	#define COMPILER "Unknown Compiler"
	#define ASSERT(x)
	#define FUNC_SIG
#endif

#ifdef _WIN64
	#define ABX_WINDOWS
	#define NOMINMAX// Windows.h defines min and max macros, which can cause conflicts with std::min and std::max
	#include <Windows.h>
	#define POPUP_ERROR(x) MessageBoxA(NULL, x, "ERROR", MB_OK)
#elif defined(__linux__) && defined(__x86_64__) || defined(__linux__) && defined(__arm64__)
	#define ABX_LINUX
	#include <iostream>
	#define POPUP_ERROR(x) std::cout <<"[ERROR!]" << x << "\n"; system("pause")
#elif defined(__APPLE__) && defined(__x86_64__) || defined(__APPLE__) && defined(__arm64__)
	#define ABX_MAC
	#include <iostream>	
	#define POPUP_ERROR(x) std::cout <<"[ERROR!]" << x << "\n"; system("pause")
#else
	#error "Unknown platform. Only 64bit systems!"
#endif

//A macro function that prints to the console only if it's on debug or release mode
#ifndef DIST
	#if defined(_DEBUG)
        #define ABX_DEBUG
	#elif defined(NDEBUG)
		#define ABX_RELEASE
	#endif
#else // DIST build
	#define ABX_DIST
#endif

#define ABX_EXIT_PROGRAM exit(1);

#include "Core/Utilities.h"