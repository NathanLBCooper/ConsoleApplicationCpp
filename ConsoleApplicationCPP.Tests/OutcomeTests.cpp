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

			// Equality
			Assert::IsTrue(outcomeOne == outcomeOneAlso);
			Assert::IsFalse(outcomeOne == outcomeTwo);
			Assert::IsFalse(outcomeOne != outcomeOneAlso);
			Assert::IsTrue(outcomeOne != outcomeTwo);

			// hashset of Outcome
			std::unordered_set<Outcome> unorderedSet;
			unorderedSet.insert(outcomeOne);
			unorderedSet.insert(outcomeOneAlso);
			unorderedSet.insert(outcomeTwo);
			Assert::IsTrue(unorderedSet.size() == 2);

			// hashset of std::shared_ptr<Outcome>
			_hashedUnorderedOutcomePtrSet(std::shared_ptr) unorderedSet2;
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeOne));
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeOneAlso));
			unorderedSet2.insert(std::make_shared<Outcome>(outcomeTwo));
			Assert::IsTrue(unorderedSet2.size() == 2);

			// hashset of Outcome*
			_hashedUnorderedOutcomeRawPtrSet unorderedSet3;
			try
			{
				unorderedSet3.insert(new Outcome(outcomeOne));
				unorderedSet3.insert(new Outcome(outcomeOneAlso));
				unorderedSet3.insert(new Outcome(outcomeTwo));
				Assert::IsTrue(unorderedSet3.size() == 2);
			}
			// (hacky finally clause)
			catch (...)
			{
				for (auto & element : unorderedSet3)
				{
					delete element;
				}
				throw;
			}
			for (auto & element : unorderedSet3)
			{
				delete element;
			}
		}

		/// <summary>
		/// Tests the WinAmount method.
		/// </summary>
		TEST_METHOD(OutcomeTestWinAmount)
		{
			auto odds = 10;
			auto bet = 5;
			Outcome outcome("outcome", odds);
			Assert::IsTrue(outcome.WinAmount(5) == (odds * bet) + bet);
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