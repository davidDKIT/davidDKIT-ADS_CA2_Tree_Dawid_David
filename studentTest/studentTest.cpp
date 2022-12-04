#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/TNode.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace studentTest
{
	TEST_CLASS(studentTest)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			TNode<int, int> node(1, 1);
			Assert::AreEqual(1, node.getItem());
			Assert::IsNull(node.getLeft());
			Assert::IsNull(node.getRight());
		}
	};
}
