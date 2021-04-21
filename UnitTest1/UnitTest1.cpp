#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_9_3/lab_9_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Goods* f = new Goods[1];
			f->price = 100.0;
			bool x = SearchPrice(f, 1, 10.0, 1000.0);
			Assert::AreEqual(x, true);
		}
	};
}
