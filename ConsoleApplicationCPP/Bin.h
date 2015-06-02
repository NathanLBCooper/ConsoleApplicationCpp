#pragma once
#include <unordered_set>
#include <memory>

#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Bin
	{
	private:
		_hashedUnorderedOutcomePtrSet(std::shared_ptr) outcomes;
	public:
		Bin();
		Bin(std::vector<std::shared_ptr<Outcome>> binOutcomes);
		Bin(_hashedUnorderedOutcomePtrSet(std::shared_ptr) binOutcomes);
		_hashedUnorderedOutcomePtrSet(std::shared_ptr) GetOutcomes() const;
		_property_readonly(_hashedUnorderedOutcomePtrSet(std::shared_ptr), Outcomes, GetOutcomes);
	};
}