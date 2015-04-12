#include "stdafx.h"
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "IRandom.h"
#include "Bin.h"

#include "Wheel.h"

namespace ConsoleApplicationCpp
{

	Wheel::Wheel(std::unique_ptr<IRandom> randomNumberGenerator, std::vector<Bin> binsCollection)
		: rng(std::move(randomNumberGenerator)),
		bins(binsCollection)
	{
	}

	Bin Wheel::Next()
	{
		std::int32_t index(this->rng->Next(0, bins.size() - 1));
		return bins[index];
	}
}