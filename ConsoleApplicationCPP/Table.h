#pragma once
#include "stdafx.h"
#include <cstdint>
#include <unordered_set>
#include <memory>
#include <vector>
#include "Bet.h"
#include "Bin.h"
#include "IPlayer.h"
#include "Wheel.h"
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Table
	{
	private:
		std::int32_t limit;
		std::unique_ptr<Wheel> wheel;
		bool Table::IsBetWinning(Bet const &bet, std::shared_ptr<Bin> const &winningBin) const;
		std::int32_t SumBet(std::vector<Bet> const &bets) const;
	public:
		Table::Table(std::int32_t limit, std::unique_ptr<Wheel> wheel);
		bool IsValid(std::vector<Bet> const &bets) const;
		void Cycle(IPlayer &player) const;
		std::int32_t GetLimit() const;
		std::vector<std::shared_ptr<Outcome>> GetOutcomes() const;
		_property_readonly(std::int32_t, Limit, GetLimit);
		_property_readonly(std::vector<std::shared_ptr<Outcome>>, Outcomes, GetOutcomes);
	};
}
