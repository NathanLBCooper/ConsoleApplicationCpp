#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "CppUnitTest.h"
#include "Bin.h"
#include "Outcome.h"
#include "BinBuilder.h"
#include "Wheel.h"
#include "Wheel.cpp"
#include "Random.h"
#include "MockRandom.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ConsoleApplicationCpp;

namespace ConsoleApplicationCPPTests
{
	TEST_CLASS(WheelTests)
	{
	public:
		/// <summary>
		/// Tests that the wheel returns bin based on the Outcome of IRandom.Next(min,max)
		/// </summary>
		TEST_METHOD(WheelTestReturnsCorrectBins)
		{
			auto binBuilder = BinBuilder();
			auto bins = binBuilder.GetBins();
			auto outcomes = binBuilder.GetOutcomes();

			for (std::size_t i = 0; i < bins.size(); i++){
				Wheel wheel(bins, outcomes, std::move(std::make_unique<MockRandom>(i)));
				Assert::IsTrue(wheel.Next() == bins[i]);
			}
		}
	};
}