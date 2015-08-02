#include "stdafx.h"
#include <memory>
#include <vector>
#include "IPlayer.h"
#include "Table.h"
#include "Wheel.h"

#include "Game.h"

namespace ConsoleApplicationCpp
{
	Game::Game() {}

	Game::Game(std::shared_ptr<Table> table, std::vector<std::unique_ptr<IPlayer>> players)
		: table(table),
		players(std::move(players))
	{
		if (std::find(this->players.begin(), this->players.end(), nullptr) != this->players.end())
		{
			throw std::runtime_error("IPlayer cannot be nullptr");
		}
	}

	void Game::Cycle()
	{
		for (auto &player : this->players)
		{
			this->table->Cycle(*player);
		}
	}
}