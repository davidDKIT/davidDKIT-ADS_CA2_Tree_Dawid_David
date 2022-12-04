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
		TEST_METHOD(TestAddLessThan)
		{
			TNode<int, int> node(1, 2);
			Assert::AreEqual(2, node.getItem());
			Assert::IsNull(node.getLeft());
			node.add(1, 1);
			Assert::IsNotNull(node.getLeft());
			Assert::AreEqual(1, node.getLeft()->getItem());
		}
		TEST_METHOD(TestAddLessThanChildren)
		{
			TNode<int, int> node(4, 4);
			node.add(2, 2);
			TNode<int, int>* pLeft = node.getLeft();
			node.add(1, 1);
			node.add(3, 3);
			Assert::IsNotNull(pLeft->getLeft());
			Assert::AreEqual(1, pLeft->getLeft()->getItem());
			Assert::IsNotNull(pLeft->getRight());
			Assert::AreEqual(3, pLeft->getRight()->getItem());

		}
		TEST_METHOD(TestAddGreaterThanChildren)
		{
			TNode<int, int> node(4, 4);
			node.add(6, 6);
			TNode<int, int>* pRight = node.getRight();
			node.add(5, 5);
			node.add(8, 8);
			Assert::IsNotNull(pRight);
			Assert::AreEqual(6, pRight->getItem());
			Assert::IsNotNull(pRight->getRight());
			Assert::AreEqual(8, pRight->getRight()->getItem());
		}
		/*TEST_METHOD(TestCount)
		{
			TNode<int, int> node(3, 3);
			node.add(2, 2);
			node.add(6, 6);
			TNode<int, int>* pLeft = node.getLeft();
			node.add(1, 1);
			node.add(3, 3);
			node.add(5, 5);
			node.add(7, 7);
			Assert::AreEqual(7, node.count());

		}*/
	};
}
