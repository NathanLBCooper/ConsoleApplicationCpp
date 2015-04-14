#pragma once
#include <vector>
#include <map>
#include "Bin.h"

namespace ConsoleApplicationCpp
{
	class BinBuilder
	{
	private:
		static const auto splitBetOdds = 17;
		std::vector<std::shared_ptr<Outcome>> BuildStraightOutcomes() const;
		std::map<std::int32_t, std::shared_ptr<Outcome>> BuildRightSplitOutcomes() const;
		std::map<std::int32_t, std::shared_ptr<Outcome>> BuildBottomSplitOutcomes() const;
		std::vector<std::shared_ptr<Outcome>> BuildStreetOutcomes() const;
		std::map<std::int32_t, std::shared_ptr<Outcome>> BuildCornerBets() const;
		std::vector<std::shared_ptr<Outcome>> BuildDoubleStreetOutcomes() const;
		std::vector<std::shared_ptr<Outcome>> BuildDozenBetsOutcomes() const;
		std::vector<std::shared_ptr<Outcome>> BuildColumnBetsOutcomes() const;
		std::map<std::string, std::shared_ptr<Outcome>> BuildEvenOddsOutcomes() const;
		Bin BuildBin(std::int32_t location, std::map<std::string, std::shared_ptr<Outcome>> sharedOutcomes, std::vector<Bin> const &bins) const;
	public:
		BinBuilder();
		std::vector<Bin> BuildBins() const;
	};
}

