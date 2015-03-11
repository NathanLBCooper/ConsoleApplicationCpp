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

using namespace ConsoleApplicationCpp;

int _tmain(int argc, _TCHAR* argv[])
{
	Outcome outcomeOne = Outcome("1", 17);

	/*std::unique_ptr<IRandom> randomService = std::make_unique<Random>();

	std::cout << "NUMBERS" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << randomService->Next(0, 10) << std::endl;
	}

	std::vector<std::uint8_t> buffer(100);
	randomService->NextBytes(buffer);

	std::cout << "BUFFER" << std::endl;
	for (auto &i : buffer)
	{
		std::cout << i << std::endl;
	}

	return 0;*/
}

