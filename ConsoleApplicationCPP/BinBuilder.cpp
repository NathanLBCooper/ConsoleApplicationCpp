#include "stdafx.h"
#include <array>
#include <vector>
#include "Bin.h"

#include "BinBuilder.h"

// todo See if there's a clean way to  build up bins (or vector<..Outcome> because bins are readonly) as outcomes are intialised (many outcome know where they fit as intialised)
// todo make methods state  altering, make bin builder the container for the bins. I don't see a problem with keeping different breeds of outcome in different containers.
namespace ConsoleApplicationCpp
{
	BinBuilder::BinBuilder()
	{
	}

	std::vector<Bin> BinBuilder::BuildBins() const
	{
		auto bins = std::vector<Bin>();

		auto a = this->BuildStraightOutcomes();
		auto b = this->BuildRightSplitOutcomes();
		auto c = this->BuildBottomSplitOutcomes();
		auto d = this->BuildStreetOutcomes();
		auto e = this->BuildDoubleStreetOutcomes();
		auto f = this->BuildDozenBetsOutcomes();
		auto g = this->BuildColumnBetsOutcomes();
		auto h = this->BuildCornerBets();
		auto i = this->BuildEvenOddsOutcomes();

		return bins;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildStraightOutcomes() const
	{
		static const auto straightBetOdds = 35;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i < 37; i++)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome(std::to_string(i), straightBetOdds)));
		}

		outcomes.push_back(std::make_shared<Outcome>(Outcome("00", straightBetOdds)));
		return outcomes;
	}

	std::map<std::int32_t,std::shared_ptr<Outcome>> BinBuilder::BuildRightSplitOutcomes() const
	{
		// Split bets indexed by to the leftmost member, todo xml comment
		auto outcomes = std::map<std::int32_t, std::shared_ptr<Outcome>>();
		for (auto i = 1; i < 36; i++)
		{
			if (i % 3 != 0)
			{
				outcomes.insert(std::pair<std::int32_t, std::shared_ptr<Outcome>>(
					i, std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 1), splitBetOdds))));
			}
		}

		return outcomes;
	}

	std::map<std::int32_t, std::shared_ptr<Outcome>> BinBuilder::BuildBottomSplitOutcomes() const
	{
		// Split bets indexed by to the top member, todo xml comment
		auto outcomes = std::map<std::int32_t, std::shared_ptr<Outcome>>();
		for (auto i = 1; i < 34; i++)
		{
			outcomes.insert(std::pair<std::int32_t, std::shared_ptr<Outcome>>(
				i, std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 3), splitBetOdds))));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildStreetOutcomes() const
	{
		static const auto streetBetOdds = 11;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i < 12; i++)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("row " + std::to_string(i), streetBetOdds)));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildDoubleStreetOutcomes() const
	{
		static const auto doubleStreetBetOdds = 5;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i < 11; i++)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("doubleStreet " + std::to_string(i), doubleStreetBetOdds)));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildDozenBetsOutcomes() const
	{
		static const auto dozentBetOdds = 2;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i < 3; i++)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("dozen " + std::to_string(i), dozentBetOdds)));
		}

		return outcomes;
	}

	std::vector<std::shared_ptr<Outcome>> BinBuilder::BuildColumnBetsOutcomes() const
	{
		static const auto columnBetOdds = 2;

		auto outcomes = std::vector<std::shared_ptr<Outcome>>();
		for (auto i = 0; i < 3; i++)
		{
			outcomes.push_back(std::make_shared<Outcome>(Outcome("column " + std::to_string(i), columnBetOdds)));
		}

		return outcomes;
	}

	std::map<std::int32_t, std::shared_ptr<Outcome>> BinBuilder::BuildCornerBets() const
	{
		static const auto cornerBetOdds = 8;
		// Split bets indexed by to the top left member, todo xml comment
		auto outcomes = std::map<std::int32_t, std::shared_ptr<Outcome>>();
		for (auto i = 1; i < 33; i++)
		{
			if (i % 3 != 0)
			{
				outcomes.insert(std::pair<std::int32_t, std::shared_ptr<Outcome>>(
					i, std::make_shared<Outcome>(Outcome(std::to_string(i) + " or " + std::to_string(i + 1) +
					" or " + std::to_string(i + 3) + " or " + std::to_string(i + 4), splitBetOdds))));
			}
		}

		return outcomes;
	}

	std::map<std::string, std::shared_ptr<Outcome>> BinBuilder::BuildEvenOddsOutcomes() const
	{
		auto outcomesMap = std::map<std::string, std::shared_ptr<Outcome>>();

		static const auto evenBetOdds = 1;

		outcomesMap["even"] = std::make_shared<Outcome>(Outcome("even", evenBetOdds));
		outcomesMap["odd"] = std::make_shared<Outcome>(Outcome("odd", evenBetOdds));
		outcomesMap["low"] = std::make_shared<Outcome>(Outcome("low", evenBetOdds));
		outcomesMap["high"] = std::make_shared<Outcome>(Outcome("high", evenBetOdds));
		outcomesMap["black"] = std::make_shared<Outcome>(Outcome("black", evenBetOdds));
		outcomesMap["red"] = std::make_shared<Outcome>(Outcome("red", evenBetOdds));

		return outcomesMap;
	}

	Bin BinBuilder::BuildBin(std::int32_t location, std::map<std::string, std::shared_ptr<Outcome>> sharedOutcomes, std::vector<Bin> const &bins) const
	{
		throw std::exception("not implemented");
	}
}