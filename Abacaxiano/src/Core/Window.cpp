#include "Core/Window.h"
#include "Core/Context.h"
#include "Core/Logger.h"
#include <SFML/Window/Event.hpp>

static inline void Create(const std::string& l_title, const uint64 l_width, const uint64 l_height, sf::RenderWindow& l_window) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	l_window.create(sf::VideoMode(l_width, l_height), l_title, sf::Style::Default, settings);
}

namespace abx {
	
	Window::Window(const std::string& l_title, const uint64 l_width, const uint64 l_height) :
		m_title(l_title), 
		m_width(l_width), m_height(l_height), 
		m_isDone(false),
		m_window(),
		m_eventManager()
	{
		Context::window = this;
		Create(m_title, m_width, m_height, m_window);
		ABX_CORE_LOG_INFO(std::string("Window created: TITLE[" + m_title + "] WIDTH[" + std::to_string(m_width) + "] HEIGHT[" + std::to_string(m_height) + "]"));
	}

	void Window::Update() {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			m_eventManager.HandleInput(event);
			if (event.type == sf::Event::Closed)
				m_isDone = true;
		}
		m_eventManager.HandleInput();
	}

	void Window::Clear(sf::Color l_color) {
		m_window.clear(l_color);
	}

	void Window::Draw(const sf::Drawable& l_drawable) {
		m_window.draw(l_drawable);
	}

	void Window::Display() {
		m_window.display();
	}

	const bool Window::IsDone() const {
		return m_isDone;
	}

	const uint64  Window::GetWidth() const {
		return m_width;
	}

	const uint64  Window::GetHeight() const {
		return m_height;
	}

	sf::RenderWindow* Window::GetRenderWindow() {
		return &m_window;
	}

	EventManager* Window::GetEventManager() {
		return &m_eventManager;
	}

}