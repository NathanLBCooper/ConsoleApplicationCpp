#include "stdafx.h"
#include <memory>
#include <algorithm>  
#include <vector>
#include <iostream>

#include "Passenger57.h"
#include "Table.h"
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	Passenger57::Passenger57(std::shared_ptr<Table> table) :
		table(std::move(table)),
		bets()
	{
		const int BetAmount = this->table->Limit;

		auto outcomes = this->table->Outcomes;
		this->bets.push_back
			(
				Bet
					(
						BetAmount,
						*std::find_if(outcomes.begin(), outcomes.end(), [](std::shared_ptr<Outcome> outcome) { return outcome->Name == "black"; })
					)
			);
	}

	std::vector<Bet> Passenger57::PlaceBets()
	{
		return this->bets;
	}

	void Passenger57::Win(std::vector<Bet> winningBets)
	{
		auto outStr = winningBets.size() == 0 ? "Lost" : "Won";
		std::cout << outStr << std::endl;
	}
}