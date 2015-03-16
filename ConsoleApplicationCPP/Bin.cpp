#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "Bin.h"
#include "Outcome.h"

namespace ConsoleApplicationCpp
{
	// TODO Is bin really getting ownership tranfer or its it just observing (ie what is it's lifetime compared to the object that creates it)?
	// decision: We don't design objects to be brittle to being passed outside of the creation scope. Either smart pointer, or don't persist it.

	Bin::Bin(std::unordered_set<std::shared_ptr<Outcome>> binOutcomes)
		: outcomes(binOutcomes)
	{
	}

	Bin::Bin(Bin&& rhs)
		: outcomes(std::move(rhs.Outcomes))
	{
	}

	Bin& Bin::operator=(Bin&& other)
	{
		if (this != &other)
		{
			//todo 
		}   
	}

	std::unordered_set<std::shared_ptr<Outcome>> Bin::GetOutcomes() const
	{
		return outcomes;
	}

}