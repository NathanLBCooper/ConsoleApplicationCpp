#pragma once
#include "Table.h"
#include "BinBuilder.h"

namespace ConsoleApplicationCpp
{
	class RouletteTable : public Table
	{
	private:
		RouletteTable(BinBuilder binBuilder, int tableLimit);
	public:
		RouletteTable(int tableLimit);
	};
}

