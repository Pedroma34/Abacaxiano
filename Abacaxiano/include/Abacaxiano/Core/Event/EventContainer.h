#pragma once
#include "Core/Config.h"

namespace abx {

	class EventContainer {
	public:
		EventContainer();

	private:
		std::vector<Ref<class EventBlock>> m_eventBlocks;
	};

}