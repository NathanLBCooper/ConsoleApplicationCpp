#include "stdafx.h"
#include <cstdint>
#include <vector>

#include "CppUnitTest.h"
#include "IRandom.h"
#include "Random.h"
#include "Random.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace ConsoleApplicationCpp;

namespace ConsoleApplicationCPPTests
{
	TEST_CLASS(RandomTests)
	{
	public:
		/// <summary>
		/// Regression test against fixed seed.
		/// Not really an effective unit test, brittle against <random> implementation.
		/// </summary>
		TEST_METHOD(RandomRegressionTestAgainstFixedSeed)
		{
			Random random(1);

			std::vector <int32_t> arr1{ 1791095845, 2135392491, 946286476, 1857819720, 491263 };
			for (auto &i : arr1)
			{
				Assert::IsTrue(random.Next() == i);
			}

			std::vector <int32_t> arr2{ 1, 1, 1, 1, 0 };
			for (auto &i : arr2)
			{
				Assert::IsTrue(random.Next(0,1) == i);
			}

			std::vector <int32_t> arr3{ 2, 81 };
			for (auto &i : arr3)
			{
				Assert::IsTrue(random.Next(0, 100) == i);
			}
			
			std::vector <double_t> arr4
			{
				0.18626021128147840, 0.38791074021719396, 0.34556072507984936, 0.66974604036659002,
				0.39676746865734458, 0.93553907261230052, 0.53881673188880086, 0.84631091821938753,
				0.41919451905414462, 0.31327351299114525
			};

			for (auto &i : arr4)
			{
				Assert::IsTrue(random.NextDouble() == i);
			}

			std::vector <double_t> arr5
			{	
				68.521950067952275, 52.454816270619631, 20.445224898867309, 44.345289375633001,
				87.811743700876832, 22.957722004503012, 2.7387595968320966, 53.441390721127391,
				67.046750755980611, 91.396202240139246
			};

			for (auto &i : arr5)
			{
				i = random.NextDouble(0.0,100.0);
			}

			Assert::IsTrue(random.Next(54, 54) == 54);
			Assert::IsTrue(random.NextDouble(12.0, 12.0) == 12.0);
		}

		/// <summary>
		/// Tests invalid inputs.
		/// </summary>
		TEST_METHOD(RandomTestInvalidInputs)
		{
			Random random;
			random.Next();

			try
			{
				random.Next(54, 53);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}

			try
			{
				random.Next(-1, 1);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}

			try
			{
				random.NextDouble(10.0, 0.0);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}

			try
			{
				random.NextDouble(-2.0, 0.0);
				Assert::Fail();
			}
			catch (const std::invalid_argument&)
			{

			}
		}
	};

}