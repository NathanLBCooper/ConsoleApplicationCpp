#include "stdafx.h"
#include "Bet.h"
#include <cstdint>
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Bet"/> class.
	/// </summary>
	/// <param name="amountBet">The amount bet.</param>
	/// <param name="outcome">The outcome.</param>
	Bet::Bet(std::int32_t amountBet, std::shared_ptr<Outcome> outcome)
		: amountBet(amountBet), outcome(outcome) { }

	/// <summary>
	/// Gets the amount bet.
	/// </summary>
	/// <returns></returns>
	std::int32_t Bet::GetAmountBet() const
	{
		return this->amountBet;
	}

	/// <summary>
	/// Gets the outcome.
	/// </summary>
	/// <returns></returns>
	std::shared_ptr<Outcome> Bet::GetOutcome() const
	{
		return this->outcome;
	}

	/// <summary>
	/// Caculate the Win Amount. The overall, including the returned stake.
	/// </summary>
	/// <returns></returns>
	std::int32_t Bet::WinAmount() const
	{
		return this->outcome->WinAmount(this->amountBet);
	}
}