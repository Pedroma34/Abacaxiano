#pragma once

namespace abx {
	struct Context {
		inline static class Logger*       logger       = nullptr;
		inline static class Randy*        randy        = nullptr;
		inline static class Window*       window       = nullptr;
	};
}