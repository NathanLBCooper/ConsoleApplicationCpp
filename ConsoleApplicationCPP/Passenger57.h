#pragma once
#include "stdafx.h"

#include "IPlayer.h"

namespace ConsoleApplicationCpp
{
	class Passenger57 : IPlayer
	{
	public:
		Passenger57();
		std::vector<Bet> PlaceBets() override;
		void Win(std::vector<Bet> winningBets) override;
	};
}