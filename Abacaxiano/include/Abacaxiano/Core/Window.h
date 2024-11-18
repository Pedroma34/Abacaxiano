#pragma once
#include "Core/Config.h"
#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

namespace abx {
	class Window {
	public:
		Window(const std::string& l_title, const uint64 l_width, const uint64 l_height);
		~Window();

		void Update();
		void Clear(sf::Color l_color = sf::Color::Black);
		void Draw(const sf::Drawable& l_drawable);
		void Display();

		const bool IsDone() const;

		const uint64 GetWidth() const;
		const uint64 GetHeight() const;

		sf::RenderWindow* GetRenderWindow();

	private:
		std::string m_title;
		uint64 m_width;
		uint64 m_height;
		bool m_isDone;
		sf::RenderWindow m_window;
	};
}