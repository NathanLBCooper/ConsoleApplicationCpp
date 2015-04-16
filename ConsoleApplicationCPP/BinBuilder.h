#pragma once
#include <vector>
#include <map>
#include "Bin.h"

namespace ConsoleApplicationCpp
{
	class BinBuilder
	{
	private:
		typedef std::vector<std::shared_ptr<Outcome>> BinOutcomes;
		static const auto splitBetOdds = 17;
		static const auto numberOfBins = 38;
		static const auto numberOfNonZeroBins = 36;
		std::vector<std::shared_ptr<Outcome>> BuildStraightOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildStreetOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildDoubleStreetOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildDozenBetsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildColumnBetsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildHorizontalSplitOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildVerticalSplitOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildCornerOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
		std::vector<std::shared_ptr<Outcome>> BuildEvenOddsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const;
	public:
		BinBuilder();
		std::vector<Bin> BuildBins() const;

		void BinBuilder::Foo();
	};
}

