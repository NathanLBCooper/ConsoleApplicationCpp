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

	Wheel::Wheel(std::vector<std::shared_ptr<Bin>> bins,
		std::vector<std::shared_ptr<Outcome>> outcomes,
		std::unique_ptr<IRandom> randomNumberGenerator)
		:
		bins(bins),
		outcomes(outcomes),
		rng(std::move(randomNumberGenerator))
	{
	}

	std::shared_ptr<Bin> Wheel::Next()
	{
		std::int32_t index(this->rng->Next(0, bins.size() - 1));
		return this->bins[index];
	}

	std::vector<std::shared_ptr<Outcome>> Wheel::GetOutcomes() const{
		return this->outcomes;
	}
}