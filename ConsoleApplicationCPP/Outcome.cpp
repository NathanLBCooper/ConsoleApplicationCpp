#include "stdafx.h"
#include <cstdint>
#include <string>
#include <memory>

#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	Outcome::Outcome(std::string name, std::int32_t odds)
		: name(name), odds(odds)
	{
		if (this->Odds < 0)
		{
			throw std::invalid_argument("Odds must be non-negative");
		}
	}

	std::string Outcome::GetName() const
	{
		return this->name;
	}


	std::int32_t Outcome::GetOdds() const
	{
		return this->odds;
	}

	std::int32_t Outcome::WinAmount(std::int32_t bet)
	{
		if (bet < 0)
		{
			throw std::invalid_argument("Bet must be non-negative");
		}
		return this->Odds * bet;
	}

	bool Outcome::operator==(const Outcome& outcomeOther) const
	{
		return (this->Name == outcomeOther.Name);
	}

	bool Outcome::operator!=(const Outcome& outcomeOther) const
	{
		return !(this->operator==(outcomeOther));
	}

	template<class POINTERTYPE>
	std::uint64_t OutcomePointerHash::operator()(const POINTERTYPE &outcome) const
	{
		return std::hash<std::string>()(outcome->Name);
	}
	
	template<class POINTERTYPE>
	bool OutcomePointerEqual::operator()(POINTERTYPE const& lhs, POINTERTYPE const& rhs)
	{
		return (lhs->Name == rhs->Name);
	}
}

namespace std {
	template <> struct hash <ConsoleApplicationCpp::Outcome>
	{
		size_t operator()(const ConsoleApplicationCpp::Outcome & x) const
		{
			return hash<std::string>()(x.Name);
		}
	};
}