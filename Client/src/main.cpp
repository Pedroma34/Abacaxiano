#include "Abacaxiano/Abacaxiano.h"
#include <string>

class Client : public abx::Application {
public:
	Client() {
		ABX_LOG_INFO("Client initialized.");

		//Testing events
		abx::EventRef enterEvent = MakeEvent("Enter Event", sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Enter, abx::EventMethod::OS);
		m_events.Add(enterEvent, [this](const sf::Event& l_event) {
			ABX_LOG_INFO("Test event triggered.");
		});

		abx::EventRef mouseMoveEvent = MakeEvent("Mouse Move Event", sf::Event::EventType::MouseMoved, abx::EventMethod::OS);
		m_events.Add(mouseMoveEvent, [this](const sf::Event& l_event) {
			ABX_LOG_INFO(std::string("Mouse moved: " + std::to_string(l_event.mouseMove.x) + ", " + std::to_string(l_event.mouseMove.y)).c_str());
			});

	}

	~Client() {}
private:
	abx::EventContainer m_events;
};

abx::Application* abx::CreateApplication() {
	return new Client();
}