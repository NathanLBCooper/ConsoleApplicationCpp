#pragma once
#include "stdafx.h"
#include <random>
#include <vector>

#include "IRandom.h"

namespace ConsoleApplicationCpp
{

	class Random : public IRandom
	{
		std::mt19937 randomNumberGenerator;
		std::uniform_real_distribution<std::double_t> realDistribution;
		std::uniform_int_distribution<std::int32_t> byteDistribution;
	public:
		Random(std::uint_least32_t seed);
		Random() : Random(std::_Random_device()) {};
		std::int32_t Next() override;
		std::int32_t Next(std::int32_t maxValue) override;
		std::int32_t Next(std::int32_t minValue, std::int32_t maxValue) override;
		std::double_t NextDouble() override;
		std::double_t NextDouble(std::double_t minValue, std::double_t maxValue) override;
		void NextBytes(std::vector<std::uint8_t>& buffer) override;
	};

}