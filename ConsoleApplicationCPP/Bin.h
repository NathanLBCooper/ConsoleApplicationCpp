#pragma once
#include <unordered_set>
#include <memory>

#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	class Bin
	{
		std::unordered_set<std::shared_ptr<Outcome>> outcomes;
	public:
		Bin(std::unordered_set<std::shared_ptr<Outcome>> binOutcomes);
		Bin::Bin(Bin&& rhs);
		Bin& operator=(Bin&&);
		std::unordered_set<std::shared_ptr<Outcome>> GetOutcomes() const;
		_property_readonly(std::unordered_set<std::shared_ptr<Outcome>>, Outcomes, GetOutcomes);
	};
}