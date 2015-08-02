#pragma once
#include "stdafx.h"
#include <cstdint>
#include <string>

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Contains a single outcome on which a bet can be placed.
	/// </summary>
	class Outcome
	{
	private:
		std::string name;
		std::int32_t odds;
	public:
		Outcome(std::string name, std::int32_t odds);
		std::string GetName() const;
		_property_readonly(std::string, Name, GetName);
		std::int32_t GetOdds() const;	
		_property_readonly(std::int32_t, Odds, GetOdds);
		std::int32_t WinAmount(std::int32_t betAmount);

		bool operator== (const Outcome& outcomeOther) const;
		bool operator!= (const Outcome& outcomeOther) const;
	};

	/// <summary>
	/// Hash function for a pointer to Outcome
	/// </summary>
	struct OutcomePointerHash
	{
	public:
		template<class POINTERTYPE>
		std::uint64_t operator()(const POINTERTYPE &outcome) const
		{
			return std::hash<std::string>()(outcome->Name);
		}
	};

	/// <summary>
	/// Equals function for a pointer  to Outcome
	/// </summary>
	struct OutcomePointerEqual
	{
	public:
		template<class POINTERTYPE>
		bool operator()(POINTERTYPE const& lhs, POINTERTYPE const& rhs)
		{
			return (lhs->Name == rhs->Name);
		}
	};

	#define _hashedUnorderedOutcomePtrSet(POINTERTYPE) std::unordered_set<POINTERTYPE<Outcome>,OutcomePointerHash, OutcomePointerEqual>
	#define _hashedUnorderedOutcomeRawPtrSet std::unordered_set<Outcome*,OutcomePointerHash, OutcomePointerEqual>
}