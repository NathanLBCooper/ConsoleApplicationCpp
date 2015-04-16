#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "CppUnitTest.h"
#include "Bin.h"
#include "Outcome.h"
#include "BinBuilder.h"
#include "BinBuilder.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ConsoleApplicationCpp;

namespace ConsoleApplicationCPPTests
{
	TEST_CLASS(BinBuilderTests)
	{
	public:
		/// <summary>
		/// Tests Wheel returns Bin n where n is the return value from IRandom.Next(min,max)
		/// </summary>
		TEST_METHOD(BinBuilderTestBuildBins)
		{
			auto binBuilder = BinBuilder();
			auto foo = binBuilder.BuildBins();
			//binBuilder.Foo();
		}

	};
}