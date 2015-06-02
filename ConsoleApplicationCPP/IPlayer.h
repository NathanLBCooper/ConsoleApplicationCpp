#pragma once
#include "stdafx.h"
#include <vector>

#include "Bet.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Represents a Player
	/// </summary>
	class IPlayer
	{
	public:
		/// <summary>
		/// Finalizes an instance of the <see cref="IPlayer"/> class.
		/// </summary>
		virtual ~IPlayer() = default;
		
		virtual std::vector<Bet> PlaceBets() = 0;
		virtual void Win(std::vector<Bet> winningBets) = 0;
	};

}