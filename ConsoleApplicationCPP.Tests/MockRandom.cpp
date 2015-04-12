#include "stdafx.h"
#include <cstdint>
#include <vector>

#include "MockRandom.h"

namespace ConsoleApplicationCPPTests
{
	MockRandom::MockRandom(std::int32_t value)
		: returnValue(value)
	{
	}

	std::int32_t MockRandom::Next()
	{
		return this->returnValue;
	}
		
	std::int32_t MockRandom::Next(std::int32_t maxValue)
	{
		return this->returnValue;
	}
		
	std::int32_t MockRandom::Next(std::int32_t minValue, std::int32_t maxValue)
	{
		return this->returnValue;
	}
		
	std::double_t MockRandom::NextDouble()
	{
		throw std::exception("Not implemented");
	}
		
	std::double_t MockRandom::NextDouble(std::double_t minValue, std::double_t maxValue)
	{
		throw std::exception("Not implemented");
	}

	void MockRandom::NextBytes(std::vector<std::uint8_t>& buffer)
	{
		throw std::exception("Not implemented");
	}
}