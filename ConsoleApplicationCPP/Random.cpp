#include "stdafx.h"
#include <cstdint>
#include <random>

#include "Random.h"

namespace ConsoleApplicationCpp
{

	Random::Random(std::uint_least32_t seed)
		: randomNumberGenerator(seed),
		realDistribution(),
		byteDistribution(0, 256)
	{
	}

	std::int32_t Random::Next()
	{
		return this->Next(0, std::numeric_limits<std::int32_t>::max());
	}

	std::int32_t Random::Next(std::int32_t maxValue)
	{
		return this->Next(0, maxValue);
	}

	std::int32_t Random::Next(std::int32_t minValue, std::int32_t maxValue)
	{
		std::uniform_int_distribution<std::int32_t> distribution(minValue, maxValue);
		return distribution(this->randomNumberGenerator);
	}

	std::double_t Random::NextDouble()
	{
		return this->realDistribution(this->randomNumberGenerator);
	}

	std::double_t Random::NextDouble(std::double_t minValue, std::double_t maxValue)
	{
		std::uniform_real_distribution<std::double_t> distribution(minValue, minValue);
		return this->realDistribution(this->randomNumberGenerator);
	}

	void Random::NextBytes(std::vector<std::uint8_t>& buffer)
	{
		for (auto &i : buffer)
		{
			i = static_cast<std::uint8_t>(byteDistribution(this->randomNumberGenerator));
		}
	}

}