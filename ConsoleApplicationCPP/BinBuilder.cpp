#include "stdafx.h"
#include <array>
#include <vector>
#include <mutex>
#include "Bin.h"

#include "BinBuilder.h"

namespace ConsoleApplicationCpp
{
	BinBuilder::BinBuilder()
	{
	}

	std::vector<std::shared_ptr<Bin>> BinBuilder::GetBins()
	{	
		this->LazyInitialise();
		return this->bins;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::GetOutcomes()
	{
		this->LazyInitialise();
		return this->outcomes;
	}

	void BinBuilder::LazyInitialise()
	{
		std::lock_guard<std::mutex> lock(this->initMutex);
		if (this->initialised)
		{
			return;
		}

		initialised = true;

		std::vector<OutcomesSet> binOutcomesSets(numberOfBins, OutcomesSet());
		this->BuildStraightOutcomes(this->outcomes, binOutcomesSets);
		this->BuildStreetOutcomes(this->outcomes, binOutcomesSets);
		this->BuildDoubleStreetOutcomes(this->outcomes, binOutcomesSets);
		this->BuildDozenBetsOutcomes(this->outcomes, binOutcomesSets);
		this->BuildColumnBetsOutcomes(this->outcomes, binOutcomesSets);
		this->BuildHorizontalSplitOutcomes(this->outcomes, binOutcomesSets);
		this->BuildVerticalSplitOutcomes(this->outcomes, binOutcomesSets);
		this->BuildCornerOutcomes(this->outcomes, binOutcomesSets);
		this->BuildEvenOddsOutcomes(this->outcomes, binOutcomesSets);

		for (auto binOutcomes : binOutcomesSets)
		{
			this->bins.push_back(std::make_unique<Bin>(binOutcomes));
		}
	}

	void BinBuilder::BuildStraightOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto straightBetOdds = 35;

		for (auto i = 0; i <= numberOfNonZeroBins; i++)
		{
			auto nthStraightOutcome = std::make_shared<Outcome>(std::to_string(i), straightBetOdds);
			binOutcomeSets[i].push_back(nthStraightOutcome);
			allOutcomes.push_back(std::move(nthStraightOutcome));
			
		}

		{
			auto doubleZeroOutcome = std::make_shared<Outcome>("00", straightBetOdds);
			binOutcomeSets[numberOfBins - 1].push_back(doubleZeroOutcome);
			allOutcomes.push_back(std::move(doubleZeroOutcome));
		}
	}

	void BinBuilder::BuildStreetOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto streetBetOdds = 11;
		static const auto numberOfRows = 12;
		static const auto rowSize = 3;

		for (auto i = 0, j = 1; i < numberOfRows; i++)
		{
			auto nthStreetOutcome = std::make_shared<Outcome>("row " + std::to_string(i), streetBetOdds);
			for (auto k = 0; k < rowSize; k++)
			{
				binOutcomeSets[j++].push_back(nthStreetOutcome);
			}
			allOutcomes.push_back(std::move(nthStreetOutcome));
		}
	}

	void BinBuilder::BuildDoubleStreetOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto doubleStreetBetOdds = 5;
		static const auto numberOfDoubleRowSelections = 11;
		static const auto doubleRowSize = 6;

		for (auto i = 0, j = 1; i < numberOfDoubleRowSelections; i++)
		{
			auto nthDoubleStreetOutcome = std::make_shared<Outcome>("doubleStreet " + std::to_string(i), doubleStreetBetOdds);
			for (auto k = 0; k < doubleRowSize; k++)
			{
				binOutcomeSets[j++].push_back(nthDoubleStreetOutcome);
			}
			allOutcomes.push_back(std::move(nthDoubleStreetOutcome));
			j = j - 3;
		}
	}

	void BinBuilder::BuildDozenBetsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto dozentBetOdds = 2;
		static const auto numberofDozens = 3;
		static const auto dozenSize = 12; // Unsurpisingly

		for (auto i = 0, j = 1; i < numberofDozens; i++)
		{
			auto nthDozenOutcome = std::make_shared<Outcome>("dozen " + std::to_string(i), dozentBetOdds);
			for (auto k = 0; k < dozenSize; k++)
			{
				binOutcomeSets[j++].push_back(nthDozenOutcome);
			}
			allOutcomes.push_back(std::move(nthDozenOutcome));
		}
	}

	void BinBuilder::BuildColumnBetsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto columnBetOdds = 2;
		static const auto numberOfColumns = 3;
		static const auto columnSize = 12;

		for (auto i = 0, j = 1; i < numberOfColumns; i++)
		{
			auto nthColumnOutcome = std::make_shared<Outcome>("column " + std::to_string(i), columnBetOdds);
			for (auto k = 0; k < columnSize; k++)
			{
				binOutcomeSets[j++].push_back(nthColumnOutcome);
			}
			allOutcomes.push_back(std::move(nthColumnOutcome));
		}
	}

	void BinBuilder::BuildHorizontalSplitOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		// creates split bet on leftmost member  * -
		for (auto i = 1; i <= numberOfNonZeroBins - 1; i++)
		{
			if (i % 3 != 0)
			{
				auto splitWithNthElementOnLeft = std::make_shared<Outcome>(std::to_string(i) + " or " + std::to_string(i + 1), splitBetOdds);

				binOutcomeSets[i].push_back(splitWithNthElementOnLeft);
				binOutcomeSets[i + 1].push_back(splitWithNthElementOnLeft);

				allOutcomes.push_back(std::move(splitWithNthElementOnLeft));
			}
		}
	}

	void BinBuilder::BuildVerticalSplitOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		// creates split bet on topmost member		*
		//											-
		for (auto i = 1; i <= numberOfNonZeroBins - 3; i++)
		{
			auto splitWithNthElementOnTop = std::make_shared<Outcome>(std::to_string(i) + " or " + std::to_string(i + 3), splitBetOdds);

			binOutcomeSets[i].push_back(splitWithNthElementOnTop);
			binOutcomeSets[i + 3].push_back(splitWithNthElementOnTop);

			allOutcomes.push_back(std::move(splitWithNthElementOnTop));
		}
	}

	void BinBuilder::BuildCornerOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		static const auto cornerBetOdds = 8;

		// creates split bet on top left member    *  -
		//										   -  -
		for (auto i = 1; i <= numberOfNonZeroBins - 4; i++)
		{
			if (i % 3 != 0)
			{
				auto cornerWithNthElementTopLeft = std::make_shared<Outcome>(std::to_string(i) + " or " + std::to_string(i + 1) +
					" or " + std::to_string(i + 3) + " or " + std::to_string(i + 4), splitBetOdds);			

				binOutcomeSets[i].push_back(cornerWithNthElementTopLeft);
				binOutcomeSets[i + 1].push_back(cornerWithNthElementTopLeft);
				binOutcomeSets[i + 3].push_back(cornerWithNthElementTopLeft);
				binOutcomeSets[i + 4].push_back(cornerWithNthElementTopLeft);

				allOutcomes.push_back(std::move(cornerWithNthElementTopLeft));
			}
		}
	}

	void BinBuilder::BuildEvenOddsOutcomes(OutcomesSet &allOutcomes, std::vector<OutcomesSet> &binOutcomeSets) const
	{
		{
			static const auto evenBetOdds = 1;
			static const std::array<int, 18> redNumbers{ { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 } };

			auto even = std::make_shared<Outcome>("even", evenBetOdds);
			auto odd = std::make_shared<Outcome>("odd", evenBetOdds);
			auto low = std::make_shared<Outcome>("low", evenBetOdds);
			auto high = std::make_shared<Outcome>("high", evenBetOdds);
			auto black = std::make_shared<Outcome>("black", evenBetOdds);
			auto red = std::make_shared<Outcome>("red", evenBetOdds);

			for (auto i = 1; i <= numberOfNonZeroBins; i++)
			{
				binOutcomeSets[i].push_back(i % 2 == 0 ? even : odd);
				binOutcomeSets[i].push_back(i < 19 ? low : high);
				binOutcomeSets[i].push_back(std::find(std::begin(redNumbers), std::end(redNumbers), i) != std::end(redNumbers) ? red : black);
			}
			allOutcomes.push_back(std::move(even));
			allOutcomes.push_back(std::move(odd));
			allOutcomes.push_back(std::move(low));
			allOutcomes.push_back(std::move(high));
			allOutcomes.push_back(std::move(black));
			allOutcomes.push_back(std::move(red));
		}
	}
}