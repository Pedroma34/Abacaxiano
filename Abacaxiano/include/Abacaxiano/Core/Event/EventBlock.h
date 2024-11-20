#pragma once
#include <string>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
// TODO: Joysticks, Touch, etc
#include "Core/Config.h"

namespace abx {

	enum class EventMethod {
		PerFrame,  ///< Event is triggered when the key is held down per frame
		OS,        ///< Event is triggered when the key is pressed based on OS timing
	};

	/*
		  * Holds information of an event.
		  * Owned by Event Container, which is handled by the Event Manager.
	*/
	class EventBlock {
	public:
		/*
		  * Sets block for any event type
		  * It will be called once the event type is triggered,
		  * but it has no specific key code, mouse button, joystick, etc, attached.
		  * Default will be an OS based event
		*/
		EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const EventMethod l_method = EventMethod::OS);

		/*
		  * Sets block for any event type
		  * It will be called once the Key pressed or Key released event is triggered.
		  * Default will be an OS based event
		*/
		EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const sf::Keyboard::Key l_keyCode, const EventMethod l_method = EventMethod::OS);
		
		/*
		  * Sets block for any event type
		  * It will be called once the Mouse pressed or Mouse released event is triggered.
		  * Default will be an OS based event
		*/
		EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const sf::Mouse::Button l_mouseButton, const EventMethod l_method = EventMethod::OS);
	
		//TODO: Joystick, Touch, etc

		EventBlock(const EventBlock&) = delete;
		EventBlock& operator=(const EventBlock&) = delete;
		EventBlock(EventBlock&& l_other) noexcept;
		EventBlock& operator=(EventBlock&& l_other) noexcept;

		const sf::Event::EventType GetEventType() const;
		const sf::Keyboard::Key GetKeyCode() const;
		const sf::Mouse::Button GetMouseButton() const;
		const std::string& GetHandle() const;
		const EventMethod GetMethod() const;

	protected:
		friend class EventManager;
		sf::Event::EventType m_eventType;
		sf::Keyboard::Key	 m_keyCode;
		sf::Mouse::Button	 m_mouseButton;
		//TODO: Implement Joystick, Touch, etc
		std::string          m_handle;
		EventMethod          m_method;
	};

}