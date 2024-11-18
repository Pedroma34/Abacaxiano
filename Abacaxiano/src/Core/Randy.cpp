#include "Core/Randy.h"
#include "Core/Context.h"
#include "Core/Logger.h"

namespace abx {
	Randy::Randy() : 
		m_generator(std::random_device()())
	{
		Context::randy = this;
		ABX_CORE_LOG_INFO("Randy initialized");
	}

	Randy::~Randy() {}

	void Randy::SetSeed(int64_t l_seed) {
		m_generator.seed(l_seed);
	}
	
	const int64_t Randy::GenerateInt(const int64_t l_min, const int64_t l_max) {
		std::uniform_int_distribution<int64_t> distribution(l_min, l_max);
		return distribution(m_generator);
	}

	const uint64_t Randy::GenerateUnsignedInt(const uint64_t l_min, const uint64_t l_max) {
		std::uniform_int_distribution<uint64_t> distribution(l_min, l_max);
		return distribution(m_generator);
	}

	const double Randy::GenerateDouble(const double l_min, const double l_max) {
		std::uniform_real_distribution<double> distribution(l_min, l_max);
		return distribution(m_generator);
	}

	const float Randy::GenerateFloat(const float l_min, const float l_max) {
		std::uniform_real_distribution<float> distribution(l_min, l_max);
		return distribution(m_generator);
	}
}