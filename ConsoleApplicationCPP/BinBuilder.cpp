#include "stdafx.h"
#include <array>
#include <vector>
#include "Bin.h"

#include "BinBuilder.h"

// todo need to provide list of all outcomes as well as bins
// todo is intialise : bins ' outcomes okay?
namespace ConsoleApplicationCpp
{
	BinBuilder::BinBuilder()
	{
	}

	std::vector<Bin> BinBuilder::BuildBins() const
	{
		auto binOutcomesVector = std::vector<BinOutcomes>(numberOfBins, BinOutcomes());

		auto straightOutcomes = this->BuildStraightOutcomes(binOutcomesVector);
		auto streetOutcomes = this->BuildStreetOutcomes(binOutcomesVector);
		auto doubleStreetOutcomes = this->BuildDoubleStreetOutcomes(binOutcomesVector);
		auto dozenOutcomes = this->BuildDozenBetsOutcomes(binOutcomesVector);
		auto columnOutcomes = this->BuildColumnBetsOutcomes(binOutcomesVector);
		auto horizontalSplitOutcomes = this->BuildHorizontalSplitOutcomes(binOutcomesVector);
		auto verticalSplitOutcomes = this->BuildVerticalSplitOutcomes(binOutcomesVector);
		auto cornerOutcomes = this->BuildCornerOutcomes(binOutcomesVector);
		auto evenOddsoutcomes = this->BuildEvenOddsOutcomes(binOutcomesVector);

		// todo clean up, may want to pass allOutcomes by ref as well
		auto allOutcomes = std::vector<std::shared_ptr<Outcome>>();
		allOutcomes.insert(allOutcomes.end(), straightOutcomes.begin(), straightOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), streetOutcomes.begin(), streetOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), doubleStreetOutcomes.begin(), doubleStreetOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), dozenOutcomes.begin(), dozenOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), columnOutcomes.begin(), columnOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), horizontalSplitOutcomes.begin(), horizontalSplitOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), verticalSplitOutcomes.begin(), verticalSplitOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), cornerOutcomes.begin(), cornerOutcomes.end());
		allOutcomes.insert(allOutcomes.end(), evenOddsoutcomes.begin(), evenOddsoutcomes.end());

		auto bins = std::vector<Bin>();
		for (auto binOutcomes : binOutcomesVector)
		{
			bins.push_back(Bin(binOutcomes));
		}

		return bins;
	}

	void BinBuilder::Foo()
	{
		/*auto a = this->BuildStraightOutcomes();
		auto b = this->BuildRightSplitOutcomes();
		auto c = this->BuildBottomSplitOutcomes();
		auto d = this->BuildStreetOutcomes();
		auto e = this->BuildDoubleStreetOutcomes();
		auto f = this->BuildDozenBetsOutcomes();
		auto g = this->BuildColumnBetsOutcomes();
		auto h = this->BuildCornerBets();
		auto i = this->BuildEvenOddsOutcomes();*/
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildStraightOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto straightBetOdds = 35;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i <= numberOfNonZeroBins; i++)
		{
			auto nthStraightOutcome = std::make_shared<Outcome>(Outcome(std::to_string(i), straightBetOdds));
			binOutcomesVector[i].push_back(nthStraightOutcome);
			outcomes.push_back(std::move(nthStraightOutcome));
			
		}

		{
			auto doubleZeroOutcome = std::make_shared<Outcome>(Outcome("00", straightBetOdds));
			binOutcomesVector[numberOfBins - 1].push_back(doubleZeroOutcome);
			outcomes.push_back(std::move(doubleZeroOutcome));
		}
		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildStreetOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto streetBetOdds = 11;
		static const auto numberOfRows = 12;
		static const auto rowSize = 3;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0, j = 1; i < numberOfRows; i++)
		{
			auto nthStreetOutcome = std::make_shared<Outcome>(Outcome("row " + std::to_string(i), streetBetOdds));
			for (auto k = 0; k < rowSize; k++)
			{
				binOutcomesVector[j++].push_back(nthStreetOutcome);
			}
			outcomes.push_back(std::move(nthStreetOutcome));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildDoubleStreetOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto doubleStreetBetOdds = 5;
		static const auto numberOfDoubleRowSelections = 11;
		static const auto doubleRowSize = 6;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0, j = 1; i < numberOfDoubleRowSelections; i++)
		{
			auto nthDoubleStreetOutcome = std::make_shared<Outcome>(Outcome("doubleStreet " + std::to_string(i), doubleStreetBetOdds));
			for (auto k = 0; k < doubleRowSize; k++)
			{
				binOutcomesVector[j++].push_back(nthDoubleStreetOutcome);
			}
			outcomes.push_back(std::move(nthDoubleStreetOutcome));
			j = j - 3;
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildDozenBetsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto dozentBetOdds = 2;
		static const auto numberofDozens = 3;
		static const auto dozenSize = 12; // Unsurpisingly

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0, j = 1; i < numberofDozens; i++)
		{
			auto nthDozenOutcome = std::make_shared<Outcome>(Outcome("dozen " + std::to_string(i), dozentBetOdds));
			for (auto k = 0; k < dozenSize; k++)
			{
				binOutcomesVector[j++].push_back(nthDozenOutcome);
			}
			outcomes.push_back(std::move(nthDozenOutcome));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildColumnBetsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto columnBetOdds = 2;
		static const auto numberOfColumns = 3;
		static const auto columnSize = 12;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0, j = 1; i < numberOfColumns; i++)
		{
			auto nthColumnOutcome = std::make_shared<Outcome>(Outcome("column " + std::to_string(i), columnBetOdds));
			for (auto k = 0; k < columnSize; k++)
			{
				binOutcomesVector[j++].push_back(nthColumnOutcome);
			}
			outcomes.push_back(std::move(nthColumnOutcome));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildHorizontalSplitOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		// creates split bet on leftmost member  * -
		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 1; i <= numberOfNonZeroBins - 1; i++)
		{
			if (i % 3 != 0)
			{
				auto splitWithNthElementOnLeft = std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 1), splitBetOdds));

				binOutcomesVector[i].push_back(splitWithNthElementOnLeft);
				binOutcomesVector[i + 1].push_back(splitWithNthElementOnLeft);

				outcomes.push_back(std::move(splitWithNthElementOnLeft));
			}
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildVerticalSplitOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		// creates split bet on topmost member		*
		//											-
		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 1; i <= numberOfNonZeroBins - 3; i++)
		{
			auto splitWithNthElementOnTop = std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 3), splitBetOdds));

			binOutcomesVector[i].push_back(splitWithNthElementOnTop);
			binOutcomesVector[i + 3].push_back(splitWithNthElementOnTop);

			outcomes.push_back(std::move(splitWithNthElementOnTop));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildCornerOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		static const auto cornerBetOdds = 8;

		// creates split bet on top left member    *  -
		//										   -  -
		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 1; i <= numberOfNonZeroBins - 4; i++)
		{
			if (i % 3 != 0)
			{
				auto cornerWithNthElementTopLeft = std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 1) +
					" or " + std::to_string(i + 3) + " or " + std::to_string(i + 4), splitBetOdds));			

				binOutcomesVector[i].push_back(cornerWithNthElementTopLeft);
				binOutcomesVector[i + 1].push_back(cornerWithNthElementTopLeft);
				binOutcomesVector[i + 3].push_back(cornerWithNthElementTopLeft);
				binOutcomesVector[i + 4].push_back(cornerWithNthElementTopLeft);

				outcomes.push_back(std::move(cornerWithNthElementTopLeft));
			}
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildEvenOddsOutcomes(std::vector<BinOutcomes> &binOutcomesVector) const
	{
		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		{
			static const auto evenBetOdds = 1;
			static const std::array<int, 18> redNumbers{ { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 } };

			auto even = std::make_shared<Outcome>(Outcome("even", evenBetOdds));
			auto odd = std::make_shared<Outcome>(Outcome("odd", evenBetOdds));
			auto low = std::make_shared<Outcome>(Outcome("low", evenBetOdds));
			auto high = std::make_shared<Outcome>(Outcome("high", evenBetOdds));
			auto black = std::make_shared<Outcome>(Outcome("black", evenBetOdds));
			auto red = std::make_shared<Outcome>(Outcome("red", evenBetOdds));

			for (auto i = 1; i <= numberOfNonZeroBins; i++)
			{
				binOutcomesVector[i].push_back(i % 2 == 0 ? even : odd);
				binOutcomesVector[i].push_back(i < 19 ? low : high);
				binOutcomesVector[i].push_back(std::find(std::begin(redNumbers), std::end(redNumbers), i) != std::end(redNumbers) ? red : black);
			}
			outcomes.push_back(std::move(even));
			outcomes.push_back(std::move(odd));
			outcomes.push_back(std::move(low));
			outcomes.push_back(std::move(high));
		}

		return outcomes;
	}
}