#include "stdafx.h"
#include "RouletteTable.h"
#include "Game.h"
#include "BinBuilder.h"

namespace ConsoleApplicationCpp
{
	RouletteTable::RouletteTable(int tableLimit)
		: RouletteTable(BinBuilder(), tableLimit)
	{
	}

	RouletteTable::RouletteTable(BinBuilder binBuilder, int tableLimit)
		: Table(tableLimit, std::move(std::make_unique<Wheel>(binBuilder.GetBins(), binBuilder.GetOutcomes(), std::move(std::make_unique<Random>()))))
	{

	}
}
