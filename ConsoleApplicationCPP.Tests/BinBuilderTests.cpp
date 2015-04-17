#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "CppUnitTest.h"
#include "Bin.h"
#include "Bin.cpp"
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
		/// Tests whether GetBins returns correct number of bins of the correct size
		/// </summary>
		TEST_METHOD(BinBuilderTestGetBinsSizes)
		{
			auto binBuilder = BinBuilder();			
			auto bins = binBuilder.GetBins();

			Assert::IsTrue(bins.size() == 38);

			Assert::IsTrue(bins[0]->Outcomes.size() == 1);
			Assert::IsTrue(bins[37]->Outcomes.size() == 1);

			Assert::IsTrue(bins[1]->Outcomes.size() == 11);
			Assert::IsTrue(bins[2]->Outcomes.size() == 13);
			Assert::IsTrue(bins[3]->Outcomes.size() == 11);
			Assert::IsTrue(bins[34]->Outcomes.size() == 11);
			Assert::IsTrue(bins[35]->Outcomes.size() == 13);
			Assert::IsTrue(bins[36]->Outcomes.size() == 11);

			for (int i = 4; i < 34; i = i + 3)
			{
				Assert::IsTrue(bins[i]->Outcomes.size() == 14);
				Assert::IsTrue(bins[i + 1]->Outcomes.size() == 17);
				Assert::IsTrue(bins[i + 2]->Outcomes.size() == 14);
			}
		}

		/// <summary>
		/// Tests whether GetOutcomes returns correct number of outcomes
		/// </summary>
		TEST_METHOD(BinBuilderTesGetOutcomesSize)
		{
			auto binBuilder = BinBuilder();
			auto bins = binBuilder.GetOutcomes();

			Assert::IsTrue(bins.size() == 152);
		}
	};
}