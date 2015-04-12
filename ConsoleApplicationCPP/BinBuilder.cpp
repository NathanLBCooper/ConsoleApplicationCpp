#include "stdafx.h"
#include <array>
#include <vector>
#include "Bin.h"

#include "BinBuilder.h"

namespace ConsoleApplicationCpp
{
	BinBuilder::BinBuilder()
	{
	}

	std::vector<Bin> BinBuilder::BuildBins() const
	{
		throw std::exception("not implemnted");
	}

	std::map<std::string, std::shared_ptr<Outcome>> BinBuilder::BuildSharedOutcomes() const
	{
		auto outcomesMap = std::map<std::string, std::shared_ptr<Outcome>>();

		static const auto evenOdds = 2;
		static const auto columnodds = 3;

		outcomesMap["even"] = std::make_shared<Outcome>(Outcome("even", evenOdds));
		outcomesMap["odd"] = std::make_shared<Outcome>(Outcome("odd", evenOdds));
		outcomesMap["lowOutcome"] = std::make_shared<Outcome>(Outcome("low", evenOdds));
		outcomesMap["highOutcome"] = std::make_shared<Outcome>(Outcome("high", evenOdds));
		outcomesMap["blackOutcome"] = std::make_shared<Outcome>(Outcome("black", evenOdds));
		outcomesMap["redOutcome"] = std::make_shared<Outcome>(Outcome("red", evenOdds));

		outcomesMap["firstColumn"] = std::make_shared<Outcome>(Outcome("first", columnodds));
		outcomesMap["secondColumn"] = std::make_shared<Outcome>(Outcome("second", columnodds));
		outcomesMap["thirdColumn"] = std::make_shared<Outcome>(Outcome("third", columnodds));

		return outcomesMap;
	}

	// todo work in progress, not covered all bets
	Bin BinBuilder::BuildBin(std::int32_t location, std::map<std::string, std::shared_ptr<Outcome>> sharedOutcomes) const
	{
		static const auto straightBetOdds = 35;
		static const auto red = std::array<std::int32_t,18> {
			{1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36}
		};

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();

		if (location < 0 || location > 37)
		{
			throw std::exception("Argument out of range");
		}
		// Zero (0) and DoubleZero (37) are special
		else if (location == 0)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("0", straightBetOdds)));
			return outcomes;
		}
		else if (location == 37)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("00", straightBetOdds)));
			return outcomes;
		}

		// Straight bet
		outcomes.push_back(std::make_shared<Outcome>(Outcome(std::to_string(location), straightBetOdds)));

		// Odds and Evens
		outcomes.push_back(location % 2 == 0 ? sharedOutcomes["even"] : sharedOutcomes["odd"]);
		
		// Column
		switch (location % 3)
		{
		case 1:
			outcomes.push_back(sharedOutcomes["firstColumn"]);
			break;
		case 2:
			outcomes.push_back(sharedOutcomes["secondColumn"]);
			break;
		case 0:
			outcomes.push_back(sharedOutcomes["thirdColumn"]);
			break;
		}

		// Low High
		outcomes.push_back(location < 18 ? sharedOutcomes["low"] : sharedOutcomes["high"]);

		// Red Black
		outcomes.push_back(std::find(red.begin(), red.end(), location) != red.end() ? sharedOutcomes["red"] : sharedOutcomes["black"]);

		throw std::exception("Not implemented");
	}
}