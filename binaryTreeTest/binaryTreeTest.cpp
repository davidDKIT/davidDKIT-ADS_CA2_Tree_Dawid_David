#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA2_Tree/BinaryTree.h"
#include "../ADS_CA2_Tree/TNode.h"
#include "../ADS_CA2_Tree/Student.h"
#include "../ADS_CA2_Tree/sKey.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace binaryTreeTest
{
	TEST_CLASS(binaryTreeTest)
	{
	public:
		
		//TEST_METHOD(TestAddToEmptyTree)
		//{
		//	BinaryTree<sKey, Student> tree;
		//	sKey keySamp1("WBC88XPE6LP", "Colby", "1-704-685-7028");

		//	Student student1("WBC88XPE6LP", "Colby", "1-704-685-7028");
		//	tree.add(keySamp1, student1);

		//	Assert::IsNotNull(tree.root);
		//	Student s = tree.root->getItem();

		//	string id = "WBC88XPE6LP";
		//
		//	Assert::AreEqual(id, s.getUserid());
		//}

#pragma region Add

#pragma region Test Add To Empty Tree

		TEST_METHOD(TestAddToEmptyTree)
		{
			BinaryTree<int, int> tree;
			tree.add(1, 2);
			Assert::IsNotNull(tree.root);

			Assert::AreEqual(2, tree.root->getItem());
		}

#pragma endregion
		
#pragma region Test Add To Root Left
		/*
		Test the add function for adding to the left of the root
		to test this we will use the following tree
		   2
		  /
		 1	 
		*/

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

#pragma endregion

#pragma region Test Add To Root Right
		/*
		Test the add function for adding to the right of the root
		to test this we will use the following tree
		   2
		    \
		     3
		*/

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

#pragma endregion

#pragma endregion

#pragma region Count

#pragma region Test Count On Empty

		/*
		Test the count function for empty tree
		*/
		TEST_METHOD(TestCountOnEmpty)
		{
			BinaryTree<int, int> tree;
			Assert::AreEqual(0, tree.count());
		}

#pragma endregion

#pragma region Test Count on Full Tree

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
#pragma endregion

#pragma endregion

#pragma region Removes

#pragma region Test Remove Item Not Present
		/*
		Test the remove function for item not present
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

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

#pragma endregion

#pragma region Test Remove Leaf Node
		/*
		Test the remvove function for removing a leaf node
		to test this we will use the following tree
		   4
		  / \
		 2   6
		/ \ / \
		1 3 5  7
		*/

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

#pragma endregion

#pragma region Test Remove Node With Multiple Children
		/*
		Test the remove function for removing a Node with multiple children
		to test this we will use the following tree
					   8
					  / \
					 /   \
                    /     \
				   /       \
				  /         \
				 4          12
				/ \         / \
			   2   6       10  14
			  /	  / \     /   / \
			 1   5   7   11  13  15
		*/
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

#pragma endregion

#pragma region Test Remove Node With One Child
		/*
		Test the remove function for removing a Node with one child
		to test this we will use the following tree
					   4
					  / \
					 /   \
					/     \
				   2       6
				  /       / \
			     1       5   7
							  \
							   8
		*/

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

#pragma endregion

#pragma region Test Remove Node With Two Children
		/*
		Test the remove function for removing a Node with two children
		to test this we will use the following tree
					   4
					  / \
					 /   \
					/     \
				   2       6
				  / \     / \
				 1   3   5   7
		*/
		TEST_METHOD(TestRemoveNodeWithTwoChildren)
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
			tree.remove(2);
			Assert::AreEqual(6, tree.count());
			Assert::AreEqual(4, tree.root->getItem());
			Assert::AreEqual(3, tree.root->getLeft()->getItem());
			Assert::AreEqual(6, tree.root->getRight()->getItem());
			TNode<int, int>* left = tree.root->getLeft();
			TNode<int, int>* right = tree.root->getRight();
			Assert::AreEqual(1, left->getLeft()->getItem());
			Assert::IsNull(left->getRight());
			Assert::AreEqual(5, right->getLeft()->getItem());
			Assert::AreEqual(7, right->getRight()->getItem());
		}

#pragma endregion

#pragma endregion

#pragma region Test Search Node
		/*
		Test the search function to search for a specific node
		to test this we will use the following tree
					   8
                      / \
					 /   \
					/     \
				   /       \
				  /         \
			     4           12
				/ \         /  \
  			   /   \       10   \
			  /     \     / \   14
			 2       6	 9  11 /  \
			/ \     / \       13  15
		   1   3   5   7
		*/

		TEST_METHOD(TestSearchNode)
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
			int foundNode = tree.SearchNode(5);
			Assert::AreEqual(5, foundNode);
		}

#pragma endregion

#pragma region Test Scan Depth
		/*
		Test the scan depth function to find the depth of the tree
		to test this we will use the following tree
					   8
					  / \
					 /   \
					/     \
				   /       \
				  /         \
				 2           12
				/ \         /  \
			   /   \       10   \
			  /     \     / \    14
			 1       6	 9  11  / \
			        / \        13 15
		           3   7
		*/

		TEST_METHOD(TestScanDepth)
		{
			BinaryTree<int, int> tree;
			tree.add(8, 8);
			tree.add(12, 12);
			tree.add(2, 2);
			tree.add(6, 6);
			tree.add(1, 1);
			tree.add(3, 3);
			tree.add(7, 7);
			tree.add(10, 10);
			tree.add(14, 14);
			tree.add(9, 9);
			tree.add(11, 11);
			tree.add(13, 13);
			tree.add(15, 15);
			int foundDepth = tree.scanDepth(tree.root);
			Assert::AreEqual(4, foundDepth);
		}

#pragma endregion

#pragma region Test Find Max Tree Height
		/*
		Test the tree height function to find the max height of the tree
		to test this we will use the following tree
					   8
					  / \
					 /   \
					/     \
				   /       \
				  /         \
				 2           12
				/ \         /  \
			   /   \       10   \
			  /     \     / \    14
			 1       6	 9  11  / \
					/ \        13 15
				   3   7
				    \
					 5
		*/

		TEST_METHOD(TestfindMaxTreeHeight)
		{
			BinaryTree<int, int> tree;
			tree.add(8, 8);
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
			int foundHeightMax = tree.findMaxTreeHeight(tree.root);
			Assert::AreEqual(5, foundHeightMax);
		}

#pragma endregion

#pragma region Test Find Min Tree Height
		/*
		Test the tree height function to find the min height of the tree
		to test this we will use the following tree
					   8
					  / \
					 /   \
					/     \
				   /       \
				  /         \
				 2           12
				/ \         /  \
			   /   \       10   \
			  /     \     / \    14
			 1       6	 9  11  / \
					/ \        13 15
				   3   7
					\
					 5
		*/

		TEST_METHOD(TestfindMinTreeHeight)
		{
			BinaryTree<int, int> tree;
			tree.add(8, 8);
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
			int foundHeightMin = tree.findMinTreeHeight(tree.root);
			Assert::AreEqual(3, foundHeightMin);
		}

#pragma endregion

#pragma region Test Get SubTree
		/*
		Test the subtree function to create a tree from an existing binary tree
		to test this we will use the following tree
					   5
					  / \
					 /   \
				    4    10
			       /    /  \
				  3    7   13
				 /
				2
		*/

		TEST_METHOD(TestGetSubTree)
		{

			/*BinaryTree<int, int> tree;
			TNode<int, int>* root = new TNode<int, int>;
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

			TNode<int, int>* subTree = tree.getSubtree(root, 12);

			Assert::AreEqual(12, subTree.root->getKey());
			Assert::AreEqual(10, subTree.root->getLeft()->getKey());
			Assert::AreEqual(14, subTree.root->getRight()->getKey());
			Assert::AreEqual(9, subTree.root->getLeft()->getLeft()->getKey());
			Assert::AreEqual(11, subTree.root->getLeft()->getRight()->getKey());
			Assert::AreEqual(13, subTree.root->getRight()->getRight()->getKey());
			Assert::AreEqual(15, subTree.root->getRight()->getLeft()->getKey());*/

			BinaryTree<int, int> tree;
			TNode<int, int>* root = new TNode<int, int>(5, 5);
			root->setLeft(new TNode<int, int>(4, 4));
			root->setRight(new TNode<int, int>(10, 10));
			root->getLeft()->setLeft(new TNode<int, int>(3, 3));
			root->getLeft()->setRight(new TNode<int, int>(7, 7));
			root->getLeft()->getLeft()->setLeft(new TNode<int, int>(2, 2));
			root->getLeft()->getRight()->setRight(new TNode<int, int>(15, 15));
			TNode<int, int>* new_root = tree.getSubtree(root, 10);

		}

#pragma endregion
#pragma region Test Find Balance
		/*
		Test the tree balance function to find the binary tree balance
		to test this we will use the following tree
					   8
					  / \
					 /   \
					/     \
				   /       \
				  /         \
				 3           10
				/ \         /  \
			   /   \       13   15
			  /     \     / 
			 2       5	 12  
		*/

		TEST_METHOD(TestfindBalance)
		{
			// Test with empty tree
			BinaryTree<int, int> tree;
			TNode<int, int>* root = tree.root;
			tree.add(8, 8);
			tree.add(3, 3);
			tree.add(10, 10);
			tree.add(5, 5);
			tree.add(2, 2);
			tree.add(15, 15);
			tree.add(13, 13);
			tree.add(12, 12);

			Assert::AreEqual(1, tree.isBalanced(root));

		};
#pragma endregion
	};
}
