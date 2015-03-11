#include "stdafx.h"
#include <unordered_set>

#include "CppUnitTest.h"
#include "Outcome.h"
#include "Outcome.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ConsoleApplicationCPPTests
{		
	TEST_CLASS(OutcomeTests)
	{
	public:
		/// <summary>
		/// Tests that the '==' and the hash is evaluated only by the value of the string Name.
		/// </summary>
		TEST_METHOD(TestEqualityAndHashIsEvaluatedByName)
		{
			Outcome outcomeOne = Outcome("1", 17);
			Outcome outcomeOneAlso = Outcome("1", 0);
			Outcome outcomeTwo = Outcome("2", 15);

			Assert::IsTrue(outcomeOne == outcomeOneAlso);
			Assert::IsFalse(outcomeOne == outcomeTwo);
			Assert::IsFalse(outcomeOne != outcomeOneAlso);
			Assert::IsTrue(outcomeOne != outcomeTwo);

			std::unordered_set<Outcome> unorderedSet;
			unorderedSet.insert(outcomeOne);
			unorderedSet.insert(outcomeOneAlso);
			unorderedSet.insert(outcomeTwo);

			Assert::IsTrue(unorderedSet.size() == 2);
		}

		/// <summary>
		/// Tests the WinAmount method.
		/// </summary>
		TEST_METHOD(TestWinAmount)
		{
			auto odds = 10;
			auto bet = 5;
			Outcome outcome = Outcome("outcome", odds);
			Assert::IsTrue(outcome.WinAmount(5) == odds * bet);
		}

		/// <summary>
		/// Tests the getters and setters.
		/// </summary>
		TEST_METHOD(TestGettersAndSetters)
		{
			auto name = "outcome";
			auto odds = 17;
			Outcome outcome = Outcome(name,odds);

			Assert::IsTrue(outcome.Name == name);
			Assert::IsTrue(outcome.Odds == odds);
			Assert::IsTrue(outcome.GetName() == name);
			Assert::IsTrue(outcome.GetOdds() == odds);
		}

		TEST_METHOD(TestInvalidNegativeNumbers)
		{
			Outcome outcome = Outcome("outcome", 1);
			try
			{
				outcome.WinAmount(-1);
				Assert::Fail();
			}
			catch (const std::invalid_argument& ia)
			{

			}

			try
			{
				Outcome invalidOutcome = Outcome("outcome", -1);
				Assert::Fail();
			}
			catch (const std::invalid_argument& ia)
			{

			}
		}
	};
}