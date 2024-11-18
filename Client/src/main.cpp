#include "Abacaxiano/Abacaxiano.h"

class Client : public abx::Application {
public:
	Client() {
		ABX_LOG_INFO("Client initialized.");

		auto num = abx::Context::randy->GenerateUnsignedInt(0, 10000);

		ABX_LOG_INFO(std::string("Random number: ") + std::to_string(num));
	}

	~Client() {}
};

abx::Application* abx::CreateApplication() {
	return new Client();
}