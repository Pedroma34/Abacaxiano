#pragma once
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "Core/Config.h"
#include "Core/Event/EventManager.h"

namespace abx {
	class Window {
	public:
		/*
		  * VSync automatically on 
		*/
		Window(const std::string& l_title, const uint64 l_width, const uint64 l_height, const bool l_fullScreen = false);
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator=(Window&&) = delete;

		void Draw(const sf::Drawable& l_drawable);
		void ToggleFullscreen();
		void Terminate(); //Ends program

		const bool IsDone() const;
		const bool IsFullscreen() const;

		void SetTitle(const std::string& l_title);
		void SetSize(const uint64 l_width, const uint64 l_height);
		void SetSize(const Vector2u l_size);
		void SetVSync(const bool l_vsync);

		const uint64 GetWidth() const;
		const uint64 GetHeight() const;
		const std::string& GetTitle() const;

		sf::RenderWindow* GetRenderWindow();
		EventManager* GetEventManager();

	protected:
		friend class Application;
		void Update();
		void Clear(sf::Color l_color = sf::Color::Black);
		void Display();
	private:
		std::string m_title;
		uint64 m_width;
		uint64 m_height;
		bool m_isDone;
		bool m_isFullscreen;
		sf::RenderWindow m_window;
		EventManager m_eventManager;
	};
}