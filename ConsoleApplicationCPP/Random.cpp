#include "stdafx.h"
#include <cstdint>
#include <random>

#include "Random.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Random"/> class.
	/// </summary>
	/// <param name="seed">The seed.</param>
	Random::Random(std::uint_least32_t seed)
		: randomNumberGenerator(seed),
		byteDistribution(0, 256)
	{
	}

	/// <summary>
	/// Returns a non-negative random integer.
	/// </summary>
	/// <returns></returns>
	std::int32_t Random::Next()
	{
		return this->Next(0, std::numeric_limits<std::int32_t>::max());
	}

	/// <summary>
	/// Returns a non-negative random integer that is less than the specified maximum.
	/// </summary>
	/// <param name="maxValue">The maximum value.</param>
	/// <returns></returns>
	std::int32_t Random::Next(std::int32_t maxValue)
	{
		return this->Next(0, maxValue);
	}

	/// <summary>
	/// Returns a random integer that is within a specified range.
	/// </summary>
	/// <param name="minValue">The minimum value.</param>
	/// <param name="maxValue">The maximum value.</param>
	/// <returns></returns>
	std::int32_t Random::Next(std::int32_t minValue, std::int32_t maxValue)
	{
		if (minValue < 0 || maxValue < minValue)
		{
			throw 
				std::invalid_argument("minValue and maxValue must be non-negative. maxValue must be greater than minvalue");
		}
		std::uniform_int_distribution<std::int32_t> distribution(minValue, maxValue);
		return distribution(this->randomNumberGenerator);
	}

	/// <summary>
	/// Returns a random double in range [0.0,1.0)
	/// </summary>
	/// <returns></returns>
	std::double_t Random::NextDouble()
	{
		return this->NextDouble(0.0, 1.0);
	}

	/// <summary>
	/// Returns a random double that is within the range [minValue, maxValue)
	/// </summary>
	/// <param name="minValue">The minimum value.</param>
	/// <param name="maxValue">The maximum value.</param>
	/// <returns></returns>
	std::double_t Random::NextDouble(std::double_t minValue, std::double_t maxValue)
	{
		if (minValue < 0.0 || maxValue < minValue)
		{
			throw
				std::invalid_argument("minValue and maxValue must be non-negative. maxValue must be greater than minvalue");
		}
		std::uniform_real_distribution<std::double_t> distribution(minValue, maxValue);
		return distribution(this->randomNumberGenerator);
	}

	/// <summary>
	/// Fills the elements of a specified vector of bytes with random numbers.
	/// </summary>
	/// <param name="buffer">The buffer.</param>
	void Random::NextBytes(std::vector<std::uint8_t>& buffer)
	{
		for (auto &i : buffer)
		{
			i = static_cast<std::uint8_t>(byteDistribution(this->randomNumberGenerator));
		}
	}

}