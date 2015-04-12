#pragma once
#include <unordered_set>
#include <memory>

#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Bin
	{
	private:
		std::unordered_set<std::shared_ptr<Outcome>> outcomes;
	public:
		Bin();
		Bin(std::vector<std::shared_ptr<Outcome>> binOutcomes);
		Bin(std::unordered_set<std::shared_ptr<Outcome>> binOutcomes);
		std::unordered_set<std::shared_ptr<Outcome>> GetOutcomes() const;
		_property_readonly(std::unordered_set<std::shared_ptr<Outcome>>, Outcomes, GetOutcomes);
	};
}