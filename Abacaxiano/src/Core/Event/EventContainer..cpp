#include "Core/Window.h"
#include "Core/Event/EventContainer.h"
#include "Core/Context.h"
#include "Core/Logger.h"

namespace abx {

	EventContainer::EventContainer(const unsigned int l_eventCapacity /*10*/) :
		m_eventBlocks() 
	{
		m_eventBlocks.reserve(l_eventCapacity);
	}

	void EventContainer::Add(Ref<EventBlock> l_eventBlock, std::function<void(const sf::Event&)> l_function) {
		Context::window->GetEventManager()->BindEvent(l_eventBlock, l_function);
		m_eventBlocks.emplace_back(l_eventBlock);
		ABX_CORE_LOG_INFO(std::string("Event added to event container: " + l_eventBlock->GetHandle()).c_str());
	}

	void EventContainer::Erase(const std::string& l_handle) {
		m_eventBlocks.erase(std::remove_if(m_eventBlocks.begin(), m_eventBlocks.end(), [&l_handle](Ref<EventBlock>& l_event) {
			return l_event->GetHandle() == l_handle;
			}), m_eventBlocks.end());
		ABX_CORE_LOG_INFO(std::string("Event erased from event container: " + l_handle).c_str());
	}

	void EventContainer::Clear() {
		m_eventBlocks.clear();
	}
}