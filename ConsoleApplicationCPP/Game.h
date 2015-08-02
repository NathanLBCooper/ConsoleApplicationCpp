#pragma once
#include "stdafx.h"
#include <cstdint>
#include <memory>
#include <vector>
#include <algorithm>  

#include "IPlayer.h"
#include "Table.h"

#include "Wheel.h"

namespace ConsoleApplicationCpp
{
	class Game
	{
	private:
		std::shared_ptr<Table> table;
		std::vector<std::unique_ptr<IPlayer>> players;
	public:
		Game(); //todo remove
		Game(std::shared_ptr<Table> table, std::vector<std::unique_ptr<IPlayer>> players);
		void Cycle();
	};
}