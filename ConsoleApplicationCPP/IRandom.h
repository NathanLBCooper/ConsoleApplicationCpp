#pragma once
#include "stdafx.h"
#include <cstdint>
#include <vector>

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Represents a pseudo-random number generator.
	/// </summary>
	class IRandom
	{
	public:
		/// <summary>
		/// Finalizes an instance of the <see cref="IRandom"/> class.
		/// </summary>
		virtual ~IRandom() = default;

		/// <summary>
		/// Returns a non-negative random integer.
		/// </summary>
		/// <returns></returns>
		virtual std::int32_t Next() = 0;

		/// <summary>
		/// Returns a non-negative random integer that is less than the specified maximum.
		/// </summary>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		virtual std::int32_t Next(std::int32_t maxValue) = 0;

		/// <summary>
		/// Returns a random integer that is within a specified range.
		/// </summary>
		/// <param name="minValue">The minimum value.</param>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		virtual std::int32_t Next(std::int32_t minValue, std::int32_t maxValue) = 0;

		/// <summary>
		/// Returns a random double
		/// </summary>
		/// <returns></returns>
		virtual std::double_t NextDouble() = 0;

		/// <summary>
		/// Returns a random double that is within a specified range.
		/// </summary>
		/// <param name="minValue">The minimum value.</param>
		/// <param name="maxValue">The maximum value.</param>
		/// <returns></returns>
		virtual std::double_t NextDouble(std::double_t minValue, std::double_t maxValue) = 0;

		/// <summary>
		/// Fills the elements of a specified vector of bytes with random numbers.
		/// </summary>
		/// <param name="buffer">The buffer.</param>
		virtual void NextBytes(std::vector<std::uint8_t>& buffer) = 0;
	}; 

}