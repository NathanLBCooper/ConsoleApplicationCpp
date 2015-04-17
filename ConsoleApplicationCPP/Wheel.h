#pragma once
#include "stdafx.h"
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "IRandom.h"
#include "Random.h"
#include "Bin.h"

namespace ConsoleApplicationCpp
{

	class Wheel
	{
	private:
		std::unique_ptr<IRandom> rng;
		std::vector<std::shared_ptr<Bin>> bins;
		std::vector<std::shared_ptr<Outcome>> outcomes;
	public:
		Wheel(std::vector<std::shared_ptr<Bin>> bins, std::vector<std::shared_ptr<Outcome>> outcomes, std::unique_ptr<IRandom> randomNumberGenerator);
		Wheel(std::vector<std::shared_ptr<Bin>> bins, std::vector<std::shared_ptr<Outcome>> outcomes) : Wheel(bins, outcomes, std::move(std::make_unique<Random>())) {};
		std::shared_ptr<Bin> Next();
		std::vector<std::shared_ptr<Outcome>> GetOutcomes() const;
		_property_readonly(std::vector<std::shared_ptr<Outcome>>, Outcomes, GetOutcomes);
	};

}