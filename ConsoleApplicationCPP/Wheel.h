#pragma once
#include "stdafx.h"
#include <cstdint>
#include <string>
#include <memory>
#include <vector>
#include "IRandom.h"
#include "Bin.h"

namespace ConsoleApplicationCpp
{

	class Wheel
	{
	private:
		std::unique_ptr<IRandom> rng;
		std::vector<Bin> bins;
	public:
		Wheel(std::unique_ptr<IRandom> randomNumberGenerator, std::vector<Bin> binsCollection);
		Bin Next();
	};

}