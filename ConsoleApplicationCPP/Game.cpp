#include "stdafx.h"
#include <memory>
#include <vector>
#include "IPlayer.h"
#include "Table.h"
#include "Wheel.h"

#include "Game.h"

namespace ConsoleApplicationCpp
{
	//Game::Game(std::unique_ptr<Wheel> wheel)
	//	: wheel(std::move(wheel))
	//{
	//}

	//void Game::Cycle(IPlayer &player)
	//{
	//	Table table(this->limit);
	//	table.PlaceBets(player.PlaceBets());

	//	std::unordered_set<std::shared_ptr<Outcome>> winningOutcomes(this->wheel->Next()->Outcomes);

	//	
	//}
}