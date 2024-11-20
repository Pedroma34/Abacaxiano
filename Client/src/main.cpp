#include "Abacaxiano/Abacaxiano.h"

class Client : public abx::Application {
public:
	Client() {
		ABX_LOG_INFO("Client initialized.");

		std::shared_ptr<abx::EventBlock> testEvent = std::make_shared<abx::EventBlock>("TestEvent", sf::Event::EventType::KeyPressed, sf::Keyboard::Key::Enter, abx::EventMethod::OS);
		m_events.Add(testEvent, [this](const sf::Event& l_event) {
			ABX_LOG_INFO("Test event triggered.");
		});
	}

	~Client() {}
private:
	abx::EventContainer m_events;
};

abx::Application* abx::CreateApplication() {
	return new Client();
}