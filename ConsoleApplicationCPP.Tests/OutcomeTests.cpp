#include "stdafx.h"
#include <unordered_set>
#include <memory>

#include "CppUnitTest.h"
#include "Outcome.h"
#include "Outcome.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ConsoleApplicationCpp;

namespace ConsoleApplicationCPPTests
{		
	TEST_CLASS(OutcomeTests)
	{
	public:
		/// <summary>
		/// Tests that the '==' and the hash is evaluated only by the value of the string Name.
		/// </summary>
		TEST_METHOD(OutcomeTestEqualityAndHashIsEvaluatedByName)
		{
			Outcome outcomeOne("1", 17);
			Outcome outcomeOneAlso("1", 0);
			Outcome outcomeTwo("2", 15);

			Assert::IsTrue(outcomeOne == outcomeOneAlso);
			Assert::IsFalse(outcomeOne == outcomeTwo);
			Assert::IsFalse(outcomeOne != outcomeOneAlso);
			Assert::IsTrue(outcomeOne != outcomeTwo);

			std::unordered_set<Outcome> unorderedSet;
			unorderedSet.insert(outcomeOne);
			unorderedSet.insert(outcomeOneAlso);
			unorderedSet.insert(outcomeTwo);
			Assert::IsTrue(unorderedSet.size() == 2);

			std::unordered_set<std::shared_ptr<Outcome>, OutcomePointerHash, OutcomePointerEqual> unorderedSet2;
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeOne));
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeOneAlso));
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeTwo));
			Assert::IsTrue(unorderedSet2.size() == 2);
		}

		/// <summary>
		/// Tests the WinAmount method.
		/// </summary>
		TEST_METHOD(OutcomeTestWinAmount)
		{
			auto odds = 10;
			auto bet = 5;
			Outcome outcome("outcome", odds);
			Assert::IsTrue(outcome.WinAmount(5) == odds * bet);
		}

		/// <summary>
		/// Tests the getters and setters.
		/// </summary>
		TEST_METHOD(OutcomeTestGettersAndSetters)
		{
			auto name = "outcome";
			auto odds = 17;
			Outcome outcome(name,odds);

			Assert::IsTrue(outcome.Name == name);
			Assert::IsTrue(outcome.Odds == odds);
			Assert::IsTrue(outcome.GetName() == name);
			Assert::IsTrue(outcome.GetOdds() == odds);
		}

		/// <summary>
		/// Tests invalid inputs: negative numbers.
		/// </summary>
		TEST_METHOD(OutcomeTestInvalidNegativeNumbers)
		{
			Outcome outcome("outcome", 1);
			try
			{
				outcome.WinAmount(-1);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}

			try
			{
				Outcome invalidOutcome("outcome", -1);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}
		}
	};
}