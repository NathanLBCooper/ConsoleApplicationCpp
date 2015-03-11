#pragma once
#include "stdafx.h"
#include <cstdint>
#include <string>

/// <summary>
/// Contains a single outcome on which a bet can be placed.
/// </summary>
class Outcome
{
private:
	std::string name;
	std::int32_t odds;
public:
	/// <summary>
	/// Initializes a new instance of the <see cref="Outcome"/> class.
	/// </summary>
	/// <param name="name">The name.</param>
	/// <param name="odds">The odds.</param>
	Outcome(std::string name, std::int32_t odds);

	/// <summary>
	/// Finalizes an instance of the <see cref="Outcome"/> class.
	/// </summary>
	~Outcome();

	/// <summary>
	/// Gets the Name (Use the property Name).
	/// </summary>
	/// <returns>The Name</returns>
	std::string GetName() const;

	/// <summary>
	/// Gets the Odds (Use the property Odds).
	/// </summary>
	/// <returns>The Odds</returns>
	std::int32_t GetOdds() const;

	/// <summary>
	/// Holds the name of the Outcome. Examples include "1", "Red".
	/// </summary>
	_property_readonly(std::string, Name, GetName);

	/// <summary>
	/// Holds the payout odds for this Outcome. Odds are stated as eg 17:1, we only keep the numerator (17).
	/// </summary>
	_property_readonly(std::int32_t, Odds, GetOdds);

	/// <summary>
	/// Calculates the Win Amount
	/// </summary>
	/// <param name="bet">The bet.</param>
	/// <returns>The win amount</returns>
	std::int32_t WinAmount(std::int32_t bet);

	bool operator== (const Outcome& outcomeOther) const;
	bool operator!= (const Outcome& outcomeOther) const;
};