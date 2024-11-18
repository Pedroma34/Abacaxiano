#include "Abacaxiano/Abacaxiano.h"

class Client : public abx::Application {
public:
	Client() {
		ABX_LOG_INFO("Client initialized.");
	}

	~Client() {}
};

abx::Application* abx::CreateApplication() {
	return new Client();
}