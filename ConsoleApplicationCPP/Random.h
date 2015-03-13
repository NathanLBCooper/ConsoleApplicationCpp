#pragma once
#include "stdafx.h"
#include <random>
#include <vector>

#include "IRandom.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Represents a pseudo-random number generator.
	/// Uses a Uniform Distribution
	/// </summary>
	class Random : public IRandom
	{
		std::mt19937 randomNumberGenerator;
		std::uniform_int_distribution<std::int32_t> byteDistribution;
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="Random"/> class.
		/// </summary>
		/// <param name="seed">The seed.</param>
		Random(std::uint_least32_t seed);

		/// <summary>
		/// Initializes a new instance of the <see cref="Random"/> class with random_device seed.
		/// </summary>
		Random() : Random(std::_Random_device()) {};

		/// <summary>
		/// Returns a non-negative random integer.
		/// </summary>
		/// <returns></returns>
		std::int32_t Next() override;

		/// <summary>
		/// Returns a non-negative random integer that is less than the specified maximum.
		/// </summary>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		std::int32_t Next(std::int32_t maxValue) override;

		/// <summary>
		/// Returns a random integer that is within a specified range.
		/// </summary>
		/// <param name="minValue">The minimum value.</param>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		std::int32_t Next(std::int32_t minValue, std::int32_t maxValue) override;

		/// <summary>
		/// Returns a random double in range [0.0,1.0)
		/// </summary>
		/// <returns></returns>
		std::double_t NextDouble() override;

		/// <summary>
		/// Returns a random double that is within the range [minValue, maxValue)
		/// </summary>
		/// <param name="minValue">The minimum value.</param>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		std::double_t NextDouble(std::double_t minValue, std::double_t maxValue) override;

		/// <summary>
		/// Fills the elements of a specified vector of bytes with random numbers.
		/// </summary>
		/// <param name="buffer">The buffer.</param>
		void NextBytes(std::vector<std::uint8_t>& buffer) override;
	};

}