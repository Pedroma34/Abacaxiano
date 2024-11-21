#include "Abacaxiano/Abacaxiano.h"
#include <string>

class Client : public abx::Application {
public:
	Client() {
		ABX_LOG_INFO("Client initialized.");

		abx::Context::window->SetTitle("PeepeePoopoo");
		abx::Context::window->SetSize(1920, 1080);

		//Testing events
		abx::EventRef enterEvent = abx::MakeEvent("Enter Event", sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Escape, abx::EventMethod::OS);
		m_events.Add(enterEvent, [this](const sf::Event& l_event) {
			abx::Context::window->Terminate();
			});

		abx::EventRef fullScreenEvent = abx::MakeEvent("Full Screen Event", sf::Event::EventType::KeyPressed, sf::Keyboard::Enter, abx::EventMethod::OS);
		m_events.Add(fullScreenEvent, [this](const sf::Event& l_event) {
			abx::Context::window->ToggleFullscreen();
			});

	}

	~Client() {}
private:
	abx::EventContainer m_events;
};

abx::Application* abx::CreateApplication() {
	return new Client();
}