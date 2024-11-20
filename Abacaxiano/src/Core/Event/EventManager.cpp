#include "Core/Event/EventManager.h"
#include "Core/Logger.h"

namespace abx {
	EventManager::EventManager() :
		m_events() 
	{
		m_events.reserve(100);
	}
	void EventManager::HandleInput(const sf::Event& l_event) {

		// Loop through all event blocks and trigger the ones that match the event
		for (auto& eventItr : m_events) {

			Ref<EventBlock> eventBlock = eventItr.block.lock();
			if (!eventBlock)
				continue;
			if (eventBlock->m_method != EventMethod::OS)
				continue;
			if (eventBlock->m_eventType != l_event.type)
				continue;

			const sf::Keyboard::Key keyCode = eventBlock->m_keyCode;
			const sf::Mouse::Button mouseButton = eventBlock->m_mouseButton;


			// If key code or mouse button is the same as the event
			if ((keyCode == l_event.key.code && keyCode != sf::Keyboard::Unknown) ||
				(mouseButton == l_event.mouseButton.button && mouseButton != sf::Mouse::Button::ButtonCount)) {
				eventItr.callback(l_event);
				continue;
			}

			// If it's an "open" event with no key or mouse button
			// TODO: Expand to other event types
			if (keyCode == sf::Keyboard::Key::Unknown &&
				mouseButton == sf::Mouse::Button::ButtonCount) 
			{
				eventItr.callback(l_event);
				continue;
			}

		}

		// Remove all expired event blocks from container
		auto removed = std::remove_if(m_events.begin(), m_events.end(), [](const EventCallback& l_event) {
			return l_event.block.expired();
			});
		if (removed != m_events.end())
			m_events.erase(removed, m_events.end());

	}
	void EventManager::HandleInput() {
		for (auto& eventItr : m_events) {

			Ref<EventBlock> eventBlock = eventItr.block.lock();
			if (!eventBlock)
				continue;

			if (eventBlock->m_method != EventMethod::PerFrame)
				continue;

			//Keyboard
			if (sf::Keyboard::isKeyPressed(eventBlock->m_keyCode)) {
				eventItr.callback(sf::Event());
				continue;
			}

			//Mouse
			if (sf::Mouse::isButtonPressed(eventBlock->m_mouseButton)) {
				eventItr.callback(sf::Event());
				continue;
			}

			// TODO: Add other event types
		}
	}
	void EventManager::BindEvent(Ref<EventBlock> l_eventBlock, std::function<void(const sf::Event&)> l_function) {
		//Checking if event is already in container
		for (auto& eventItr : m_events)
			if (eventItr.block.lock()->GetHandle() == l_eventBlock->GetHandle()) {
				ABX_CORE_LOG_WARN("Event already bound to function.");
				return;
			}
		m_events.emplace_back();
	}
}