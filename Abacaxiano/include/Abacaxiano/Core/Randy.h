#pragma once
#include "Config.h"
#include <random>

namespace abx {
	class Randy {
	public:
		Randy();
		~Randy();

		void SetSeed(const int64_t l_seed);
		const int64_t GenerateInt(const int64_t l_min, const int64_t l_max);
		const uint64_t GenerateUnsignedInt(const uint64_t l_min, const uint64_t l_max);
		const double GenerateDouble(const double l_min, const double l_max);
		const float GenerateFloat(const float l_min, const float l_max);

	private:
		std::mt19937_64 m_generator;
	};

}