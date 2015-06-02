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

	/// <summary>
	/// Initializes a new instance of the <see cref="Wheel"/> class.
	/// </summary>
	/// <param name="bins">The bins.</param>
	/// <param name="outcomes">The outcomes.</param>
	/// <param name="randomNumberGenerator">The random number generator.</param>
	/// <returns></returns>
	Wheel::Wheel(std::vector<std::shared_ptr<Bin>> bins,
		std::vector<std::shared_ptr<Outcome>> outcomes,
		std::unique_ptr<IRandom> randomNumberGenerator)
		:
		bins(bins),
		outcomes(outcomes),
		rng(std::move(randomNumberGenerator))
	{
	}

	/// <summary>
	/// Returns another random Bin
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<Bin> Wheel::Next()
	{
		std::int32_t index(this->rng->Next(0, bins.size() - 1));
		return this->bins[index];
	}

	/// <summary>
	/// Gets the outcomes.
	/// </summary>
	/// <returns></returns>
	std::vector<std::shared_ptr<Outcome>> Wheel::GetOutcomes() const
	{
		return this->outcomes;
	}
}