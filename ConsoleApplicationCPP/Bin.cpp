#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "Bin.h"
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	/// <summary>
	/// Initializes a new instance of the <see cref="Bin"/> class.
	/// </summary>
	/// <param name="binOutcomes">The bin outcomes.</param>
	Bin::Bin(std::unordered_set<std::shared_ptr<Outcome>> binOutcomes)
		: outcomes(binOutcomes) { }

	/// <summary>
	/// Initializes a new instance of the <see cref="Bin"/> class.
	/// </summary>
	/// <param name="binOutcomes">The bin outcomes.</param>
	Bin::Bin(std::vector<std::shared_ptr<Outcome>> binOutcomes)
		: outcomes(binOutcomes.begin(), binOutcomes.end()) { }

	/// <summary>
	/// Initializes a new instance of the <see cref="Bin"/> class.
	/// </summary>
	Bin::Bin()
		: outcomes() { }

	/// <summary>
	/// Gets the outcomes.
	/// </summary>
	/// <returns></returns>
	std::unordered_set<std::shared_ptr<Outcome>> Bin::GetOutcomes() const
	{
		return outcomes;
	}
}