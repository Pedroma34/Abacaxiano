#pragma once
#include <vector>
#include <functional>
#include <SFML/Window/Event.hpp>
#include "Core/Config.h"
#include "Core/Event/EventBlock.h"

namespace abx {

	class EventContainer {
	public:
		/*
		  * l_eventCapacity reserves the capacity of the event container to avoid reallocations.
		*/
		EventContainer(const unsigned int l_eventCapacity = 10);
		EventContainer(const EventContainer&) = delete;
		EventContainer& operator=(const EventContainer&) = delete;
		EventContainer(EventContainer&&) noexcept = default;
		EventContainer& operator=(EventContainer&&) noexcept = default;

		void Add(Ref<EventBlock> l_eventBlock, std::function<void(const sf::Event&)> l_function);

	private:
		std::vector<Ref<EventBlock>> m_eventBlocks;
	};

}