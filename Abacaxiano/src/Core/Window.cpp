#include "Core/Window.h"
#include "Core/Context.h"
#include "Core/Logger.h"
#include <SFML/Window/Event.hpp>

static inline void Create(const std::string& l_title, 
	const abx::uint64 l_width, 
	const abx::uint64 l_height, 
	const bool l_fullScreen, 
	sf::RenderWindow& l_renderRindow,
	abx::Window* l_window) 
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 4;
	auto style = l_fullScreen ? sf::Style::Fullscreen : sf::Style::Default;
	l_renderRindow.create(sf::VideoMode(l_width, l_height), l_title, style, settings);
	l_renderRindow.setVerticalSyncEnabled(true);
	ABX_CORE_LOG_INFO(std::string("Window created: TITLE[" + l_window->GetTitle() + "] WIDTH[" + std::to_string(l_window->GetWidth()) + "] HEIGHT[" + std::to_string(l_window->GetHeight()) + "]"));
	ABX_CORE_LOG_INFO(std::string("Window fullscreen: " + [&]() -> std::string {return l_window->IsFullscreen() ? "ON" : "OFF"; }()));
}

namespace abx {
	
	Window::Window(const std::string& l_title, const uint64 l_width, const uint64 l_height, const bool l_fullscreen /*false*/) :
		m_title(l_title), 
		m_width(l_width), m_height(l_height), 
		m_isDone(false),
		m_isFullscreen(l_fullscreen),
		m_window(),
		m_eventManager()
	{
		Context::window = this;
		Create(m_title, m_width, m_height, m_isFullscreen, m_window, this);
		ABX_CORE_LOG_INFO("Window initialized.");
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

	void Window::ToggleFullscreen() {
		m_isFullscreen = !m_isFullscreen;
		m_window.close();
		Create(m_title, m_width, m_height, m_isFullscreen, m_window, this);
		const std::string fullScreenString = m_isFullscreen ? "ON" : "OFF";
		ABX_CORE_LOG_INFO(std::string("Window toggled fullscreen: " + fullScreenString));
	}

	void Window::Terminate() {
		m_isDone = true;
		ABX_CORE_LOG_INFO("Window terminated.");
	}

	const bool Window::IsDone() const {
		return m_isDone;
	}

	const bool Window::IsFullscreen() const {
		return m_isFullscreen;
	}

	void Window::SetTitle(const std::string& l_title) {
		m_title = l_title;
		m_window.setTitle(l_title);
		ABX_CORE_LOG_INFO(std::string("Window title set: " + m_title));
	}

	void Window::SetSize(const uint64 l_width, const uint64 l_height) {
		m_width  = l_width;
		m_height = l_height;
		m_window.setSize(sf::Vector2u(m_width, m_height));
		ABX_CORE_LOG_INFO(std::string("Window resized: WIDTH[" + std::to_string(m_width) + "] HEIGHT[" + std::to_string(m_height) + "]"));
	}

	void Window::SetSize(const Vector2u l_size) {
		m_width  = l_size.x;
		m_height = l_size.y;
		m_window.setSize(sf::Vector2u(m_width, m_height));
		ABX_CORE_LOG_INFO(std::string("Window resized: WIDTH[" + std::to_string(m_width) + "] HEIGHT[" + std::to_string(m_height) + "]"));
	}

	void Window::SetVSync(const bool l_vsync) {
		m_window.setVerticalSyncEnabled(l_vsync);
		ABX_CORE_LOG_INFO(std::string("Window VSync set: " + [&]() -> std::string {return l_vsync ? "ON" : "OFF"; }()));
	}

	const uint64  Window::GetWidth() const {
		return m_width;
	}

	const uint64  Window::GetHeight() const {
		return m_height;
	}

	const std::string& Window::GetTitle() const {
		return m_title;
	}

	sf::RenderWindow* Window::GetRenderWindow() {
		return &m_window;
	}

	EventManager* Window::GetEventManager() {
		return &m_eventManager;
	}

}