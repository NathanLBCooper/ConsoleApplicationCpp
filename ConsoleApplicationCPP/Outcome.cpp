#include "stdafx.h"
#include <cstdint>
#include <string>

#include "Outcome.h"

Outcome::Outcome(std::string name, std::int32_t odds)
	: name(name), odds(odds)
{
	if (this->Odds < 0)
	{
		throw std::invalid_argument("Odds must be non-negative");
	}
}

Outcome::~Outcome()
{
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
		throw std::invalid_argument("bet must be non-negative");
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

namespace std {
	template <> struct hash<Outcome>
	{
		size_t operator()(const Outcome & x) const
		{
			return hash<std::string>()(x.Name);
		}
	};
}