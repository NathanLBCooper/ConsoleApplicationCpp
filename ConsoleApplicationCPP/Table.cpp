#include "stdafx.h"
#include <cstdint>
#include <unordered_set>
#include <vector>
#include "invalid_bet_exception.h"
#include "Bet.h"
#include "Outcome.h"

#include "Table.h"

namespace ConsoleApplicationCpp
{
	Table::Table(std::int32_t limit, std::unique_ptr<Wheel> wheel)
		: limit(limit), wheel(std::move(wheel))
	{
	}

	std::int32_t Table::GetLimit() const
	{
		return this->limit;
	}

	bool Table::IsValid(std::vector<Bet> const &bets) const
	{		
		return this->SumBet(bets) <= this->limit;
	}

	void Table::Cycle(IPlayer &player) const
	{
		std::vector<Bet> bets(player.PlaceBets());
		if (!this->IsValid(bets))
		{
			throw invalid_bet_exception("Bets exceeds table limit");
		}

		std::shared_ptr<Bin> winningBin = this->wheel->Next();

		std::vector<Bet> winningBets;
		for (auto const &bet : bets)
		{
			if (this->IsBetWinning(bet, winningBin))
			{
				winningBets.push_back(bet);
			}
		}

		player.Win(winningBets);
	}

	bool Table::IsBetWinning(Bet const &bet, std::shared_ptr<Bin> const &winningBin) const
	{
		auto outcomes = winningBin->Outcomes;
		return (outcomes.find(bet.TheOutcome) != outcomes.end());
	}

	std::int32_t Table::SumBet(std::vector<Bet> const &bets) const
	{
		auto total = 0;
		for (auto const &i : bets)
		{
			total += i.AmountBet;
		}

		return total;
	}

	std::vector<std::shared_ptr<Outcome>> Table::GetOutcomes() const
	{
		return this->wheel->Outcomes;
	}
}