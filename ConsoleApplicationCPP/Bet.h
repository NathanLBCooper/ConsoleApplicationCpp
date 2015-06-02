#pragma once
#include "stdafx.h"
#include <cstdint>
#include <memory>
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Bet
	{
	private:
		std::int32_t amountBet;
		std::shared_ptr<Outcome> outcome;
	public:
		Bet(std::int32_t amountBet, std::shared_ptr<Outcome> outcome);

		std::int32_t GetAmountBet() const;
		std::shared_ptr<Outcome> GetOutcome() const;
		_property_readonly(std::int32_t, AmountBet, GetAmountBet);
		_property_readonly(std::shared_ptr<Outcome>, TheOutcome, GetOutcome);

		std::int32_t WinAmount() const;
	};
}