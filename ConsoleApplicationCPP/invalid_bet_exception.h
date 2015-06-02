#pragma once
#include <stdexcept>
#include <string>

namespace ConsoleApplicationCpp
{
	class invalid_bet_exception :
		public std::runtime_error
	{
	public:
		invalid_bet_exception(const std::string& _type) : 
			std::runtime_error("Invalid Bet Exception::" + _type) {};
	};
}