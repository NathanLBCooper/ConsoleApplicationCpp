#pragma once
#include <vector>
#include <map>
#include "Bin.h"

namespace ConsoleApplicationCpp
{
	class BinBuilder
	{
	private:
		std::map<std::string, std::shared_ptr<Outcome>> BuildSharedOutcomes() const;
		Bin BuildBin(std::int32_t location, std::map<std::string, std::shared_ptr<Outcome>> sharedOutcomes) const;
	public:
		BinBuilder();
		std::vector<Bin> BuildBins() const;
	};
}

