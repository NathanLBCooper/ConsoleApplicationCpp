#pragma once
#include "stdafx.h"
#include <memory>
#include <vector>

#include "IPlayer.h"
#include "Table.h"
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Passenger57 : public IPlayer
	{
	private:
		std::shared_ptr<Table> table;
		std::vector<Bet> bets;
	public:
		Passenger57(std::shared_ptr<Table> table);
		std::vector<Bet> PlaceBets() override;
		void Win(std::vector<Bet> winningBets) override;
	};
}