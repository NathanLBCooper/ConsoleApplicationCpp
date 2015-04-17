#pragma once
#include "stdafx.h"
#include <vector>
#include <map>
#include <mutex>
#include "Bin.h"

namespace ConsoleApplicationCpp
{
	class BinBuilder
	{
	private:
		typedef std::vector<std::shared_ptr<Outcome>> OutcomesSet;
		static const auto splitBetOdds = 17;
		static const auto numberOfBins = 38;
		static const auto numberOfNonZeroBins = 36;
		bool initialised = false;
		mutable std::mutex initMutex;
		std::vector<std::shared_ptr<Bin>> bins;
		OutcomesSet outcomes;
		void LazyInitialise();
		void BuildStraightOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildStreetOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildDoubleStreetOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildDozenBetsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildColumnBetsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildHorizontalSplitOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildVerticalSplitOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildCornerOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
		void BuildEvenOddsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const;
	public:
		BinBuilder();
		std::vector<std::shared_ptr<Bin>> GetBins();
		std::vector<std::shared_ptr<Outcome>> GetOutcomes();
	};
}

