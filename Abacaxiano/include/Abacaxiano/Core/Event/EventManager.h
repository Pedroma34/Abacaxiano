#pragma once
#include <vector>
#include <functional>
#include "SFML/Window/Event.hpp"
#include "Core/Config.h"
#include "Core/Event/EventBlock.h"

namespace abx {

	/*
	  * Supposed to be managed internally. The Window class owns this.
	  *	Other classes like EventContainer will actually own the event blocks
	  *	and call this class, through Window, to bind the events to their functions and trigger them.
	*/
	class EventManager {
	protected:
		EventManager();
		EventManager(const EventManager&) = delete;
		EventManager& operator=(const EventManager&) = delete;
		EventManager(EventManager&&) = delete;
		EventManager& operator=(EventManager&&) = delete;

		void HandleInput(const sf::Event& l_event);
		void HandleInput();

		/*
		  * Binds an event block to a function which will be called when the event is triggered.
		  * Example:
		  * line 1 - EventBlock block1("CloseWindow", abx::Event::EventType::KeyPressed, abx::Keyboard::Key::Escape, EventMethod::OS);
		  * line 2 - BindEvent(block1, [this](const Event& l_event) { CloseWindow(l_event); });
		*/
		void BindEvent(Ref<EventBlock> l_eventBlock, std::function<void(const sf::Event&)> l_function);

	private:
		friend class Window;
		friend class EventContainer;
		struct EventCallback {
			EventCallback() : block(), callback() {}
			EventCallback(const EventCallback&) = delete;
			EventCallback& operator=(const EventCallback&) = delete;
			EventCallback(EventCallback&& l_other) noexcept = default;
			EventCallback& operator=(EventCallback&& l_other) noexcept = default;
			
			WeakRef<EventBlock> block; // Does not own the event
			std::function<void(const sf::Event&)> callback;
		};
		std::vector<EventCallback> m_events; ///< Holds the event blocks and their functions
	};
}