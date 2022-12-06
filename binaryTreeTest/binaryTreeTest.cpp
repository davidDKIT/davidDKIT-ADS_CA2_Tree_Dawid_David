#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace binaryTreeTest
{
	TEST_CLASS(binaryTreeTest)
	{
	public:
		
		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int, int> tree;
			tree.add(1, 1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(1, tree.root->getItem());
		}

		TEST_METHOD(TestAddToRootLeft)
		{
			BinaryTree<int, int> tree;
			tree.add(2, 2);
			tree.add(1, 1);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			Assert::IsNotNull(left);
			Assert::AreEqual(1, left->getItem());
		}

		TEST_METHOD(TestAddToRootRight)
		{
			BinaryTree<int, int> tree;
			tree.add(2, 2);
			tree.add(3, 3);
			Assert::IsNotNull(tree.root);
			Assert::AreEqual(2, tree.root->getItem());
			TNode<int, int>* right = tree.root->getRight();
			Assert::IsNotNull(right);
			Assert::AreEqual(3, right->getItem());
		}
		
		TEST_METHOD(TestRemoveItemNotPresent)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			Assert::AreEqual(7, tree.count());
			tree.remove(8);
			Assert::AreEqual(7, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}
		/*
		Test the count function for empty tree
		*/
		TEST_METHOD(TestCountOnEmpty)
		{
			BinaryTree<int, int> tree;
			Assert::AreEqual(0, tree.count());
		}

		/*
		Test the count function for full tree
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

		TEST_METHOD(TestCountOnFullTree)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(9, 7);

			Assert::AreEqual(7, tree.count());
		}
		TEST_METHOD(TestRemoveLeafNode)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			Assert::AreEqual(7, tree.count());
			tree.remove(5);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(3, left->getRight()->getItem());
			Assert::IsNull(right->getLeft());
			Assert::AreEqual(7, right->getRight()->getItem());
		}
		TEST_METHOD(TestRemoveNodeWithMultipleChildren)
		{
			BinaryTree<int, int> tree;
			tree.add(8, 8);
			tree.add(4, 4);
			tree.add(12, 12);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(10, 10);
			tree.add(14, 14);
			tree.add(9, 9);
			tree.add(11, 11);
			tree.add(13, 13);
			tree.add(15, 15);
			Assert::AreEqual(15, tree.count());

			Assert::IsNotNull(tree.root->getRight()->getRight()->getLeft());
			Assert::AreEqual(13, tree.root->getRight()->getRight()->getLeft()->getItem());
			tree.remove(12);
			Assert::AreEqual(14, tree.count());
			Assert::AreEqual(13, tree.root->getRight()->getItem());
			Assert::IsNull(tree.root->getRight()->getRight()->getLeft());
		}

		TEST_METHOD(TestRemoveNodeWithOneChild)
		{
			BinaryTree<int, int> tree;
			tree.add(4, 4);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(5, 5);
			tree.add(7, 7);
			tree.add(8, 8);
			Assert::AreEqual(7, tree.count());
			tree.remove(7);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(2, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(8, right->getRight()->getItem());
		}

	};
}
