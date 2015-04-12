#pragma once
#include "stdafx.h"
#include <cstdint>
#include <vector>

#include "IRandom.h"

using namespace ConsoleApplicationCpp;

namespace ConsoleApplicationCPPTests
{
	class MockRandom : public IRandom
	{
	private:
		std::int32_t returnValue;
	public:
		MockRandom(std::int32_t value);
		std::int32_t Next() override;
		std::int32_t Next(std::int32_t maxValue) override;
		std::int32_t Next(std::int32_t minValue, std::int32_t maxValue) override;
		std::double_t NextDouble() override;
		std::double_t NextDouble(std::double_t minValue, std::double_t maxValue) override;
		void NextBytes(std::vector<std::uint8_t>& buffer) override;
	};
}