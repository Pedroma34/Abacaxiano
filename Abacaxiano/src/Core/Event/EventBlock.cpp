#include <utility>
#include "Core/Event/EventBlock.h"
#include "Core/Logger.h"

namespace abx {
	EventBlock::EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const EventMethod l_method) :
		m_eventType(l_eventType),
		m_keyCode(sf::Keyboard::Key::Unknown),
		m_mouseButton(sf::Mouse::Button::ButtonCount),
		m_handle(l_handle),
		m_method(l_method) {
		// We want to invalidate event key code, mouse buttons, joystick, etc,
		// since we want to call our callback with no specific key or mouse button
	}

	EventBlock::EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const sf::Keyboard::Key l_keyCode, const EventMethod l_method) :
		m_eventType(l_eventType),
		m_keyCode(l_keyCode),
		m_mouseButton(sf::Mouse::Button::ButtonCount),
		m_handle(l_handle),
		m_method(l_method) {
		if (l_eventType != sf::Event::EventType::KeyPressed && l_eventType != sf::Event::EventType::KeyReleased) {
			ABX_CORE_LOG_CRITICAL("Invalid event type for key code");
			POPUP_ERROR("Invalid event type for key code");
			exit(EXIT_FAILURE);
		}
	}

	EventBlock::EventBlock(const std::string& l_handle, const sf::Event::EventType l_eventType, const sf::Mouse::Button l_mouseButton, const EventMethod l_method) :
		m_eventType(l_eventType),
		m_keyCode(sf::Keyboard::Key::Unknown),
		m_mouseButton(l_mouseButton),
		m_handle(l_handle),
		m_method(l_method) {
		if (l_eventType != sf::Event::EventType::MouseButtonPressed && l_eventType != sf::Event::EventType::MouseButtonReleased) {
			ABX_CORE_LOG_CRITICAL("Invalid event type for mouse button");
			POPUP_ERROR("Invalid event type for mouse button");
			exit(EXIT_FAILURE);
		}
	}

	EventBlock::EventBlock(EventBlock&& l_other) noexcept :
		m_eventType(l_other.m_eventType),
		m_keyCode(l_other.m_keyCode),
		m_mouseButton(l_other.m_mouseButton),
		m_handle(std::move(l_other.m_handle)),
		m_method(l_other.m_method) 
	{
		l_other.m_eventType = sf::Event::EventType::Count;
		l_other.m_keyCode = sf::Keyboard::Key::Unknown;
		l_other.m_mouseButton = sf::Mouse::Button::ButtonCount;
		l_other.m_handle.clear();
		l_other.m_method = EventMethod::OS;
	}

	EventBlock& EventBlock::operator=(EventBlock&& l_other) noexcept {
		if (this != &l_other) {
			m_eventType = l_other.m_eventType;
			m_keyCode = l_other.m_keyCode;
			m_mouseButton = l_other.m_mouseButton;
			m_handle = std::move(l_other.m_handle);
			m_method = l_other.m_method;
			l_other.m_eventType = sf::Event::EventType::Count;
			l_other.m_keyCode = sf::Keyboard::Key::Unknown;
			l_other.m_mouseButton = sf::Mouse::Button::ButtonCount;
			l_other.m_handle.clear();
			l_other.m_method = EventMethod::OS;
		}
		return *this;
	}

	const sf::Event::EventType EventBlock::GetEventType() const {
		return m_eventType;
	}

	const sf::Keyboard::Key EventBlock::GetKeyCode() const {
		return m_keyCode;
	}

	const sf::Mouse::Button EventBlock::GetMouseButton() const {
		return m_mouseButton;
	}

	const std::string& EventBlock::GetHandle() const {
		return m_handle;
	}

	const EventMethod EventBlock::GetMethod() const {
		return m_method;
	}

}