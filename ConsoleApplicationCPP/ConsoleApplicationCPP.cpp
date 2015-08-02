// ConsoleApplicationCPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <tchar.h>
#include <cstdint>
#include <memory>
#include <vector>
#include <iostream>

#include "Random.h"
#include "IRandom.h"
#include "Outcome.h"
#include "Game.h"
#include "Table.h"
#include "IPlayer.h"
#include "Passenger57.h"
#include "BinBuilder.h"
#include "RouletteTable.h"

using namespace ConsoleApplicationCpp;

int _tmain(int argc, _TCHAR* argv[])
{
	const int tableLimit = 100;
	std::shared_ptr<Table> table = std::make_shared<RouletteTable>(tableLimit);

	std::vector<std::unique_ptr<IPlayer>> players;
	players.push_back(std::move(std::make_unique<Passenger57>(table)));


	Game game(table, std::move(players));

	for (int i = 0; i < 50; i++)
	{
		game.Cycle();
	}

	return 0;
}

