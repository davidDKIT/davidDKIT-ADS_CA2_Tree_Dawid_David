#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)
#include "TNode.h"
#include<iostream>
#include <math.h>
using namespace std;
template <typename K, typename E>
class BinaryTree
{
#pragma region BinaryTree Public
public:
	TNode<K, E> *root;
    BinaryTree();
	void add(K, E item);
    bool remove(K keyItem);
    int count();

    void printInOrder();
    void printInOrder(TNode<K, E>* node);
    void printPreOrder();
    void printPreOrder(TNode<K, E>* node);
    void printPostOrder();
    void printPostOrder(TNode<K, E>* node);
    int scanDepth(TNode<K, E>* root);
    //int getSubtree(TNode<K, E>* root, int sampKey);
    int SearchNode(K keySamp);
    int findMaxTreeHeight(TNode<K, E>* root);
    int findMinTreeHeight(TNode<K, E>* root);
    int height(TNode<K, E>* root);
    int isBalanced(TNode<K, E>* root);
#pragma endregion
};

template <typename K, typename E>
BinaryTree<K, E>::BinaryTree()
{
	root = nullptr;
}

#pragma region Add
template <typename K, typename E>
void BinaryTree<K, E>::add(K keySamp, E item)
{
	if (root == nullptr)
	{
		root = new TNode<K, E>();
		root->setKey(keySamp);
		root->setItem(item);
	}
	else
	{
		root->add(keySamp, item);
	}
}
#pragma endregion


#pragma region Remove
template <typename K, typename E>
bool BinaryTree<K, E>::remove(K keyItem)
{
    TNode<K, E>* toBeRemoved = root;
    TNode<K, E>* parent = nullptr;
    bool found = false;

    while (!found && toBeRemoved != nullptr)
    {

        if (toBeRemoved->getKey() == keyItem)
        {

            found = true;
        }
        else
        {
            parent = toBeRemoved;
            if (toBeRemoved->getKey() > keyItem)
            {
                toBeRemoved = toBeRemoved->getLeft();
            }
            else
            {
                toBeRemoved = toBeRemoved->getRight();
            }
        }
    }
    if (!found)
        return false;

    if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr)
    {
        TNode<K, E>* newChild;
        if (toBeRemoved->getLeft() == nullptr)
        {
            newChild = toBeRemoved->getRight();
        }
        else
        {
            newChild = toBeRemoved->getLeft();
        }
        if (parent == nullptr)
        {
            root = newChild;
        }
        else if (parent->getLeft() == toBeRemoved)
        {
            parent->setLeft(newChild);
        }
        else
        {
            parent->setRight(newChild);
        }
        return true;
    }

    TNode<K, E>* smallestParent = toBeRemoved;
    TNode<K, E>* smallest = toBeRemoved->getRight();
    while (smallest->getLeft() != nullptr)
    {
        smallestParent = smallest;
        smallest = smallest->getLeft();
    }
    toBeRemoved->setItem(smallest->getItem());
    if (smallestParent == toBeRemoved)
    {
        smallestParent->setRight(smallest->getRight());
    }
    else
    {
        smallestParent->setLeft(smallest->getRight());
    }
}
#pragma endregion

#pragma region SearchNode
template <typename K, typename E>
int BinaryTree<K, E>::SearchNode(K keySamp)
{
    TNode<K, E>* node = root;
    while (node != nullptr)
    {
        if (node->getKey() == keySamp)
        {
            break;
        }
        else if (keySamp < node->getKey())
        {
            node = node->getLeft();
        }
        else
        {
            node = node->getRight();
        }
    }
    if (node != nullptr)
    {
        return node->getItem();
    }
}
#pragma endregion

#pragma region Scan Depth
template <typename K, typename E>
int BinaryTree<K, E>::scanDepth(TNode<K, E>* root)
{
    // Check if the tree is empty
    if (root == nullptr)
        return 0;

    // Recursively search the left and right subtrees
    int leftDepth = scanDepth(root->getLeft());
    int rightDepth = scanDepth(root->getRight());

    // Return the maximum depth of the subtrees, plus 1 for the root node
    return std::max(leftDepth, rightDepth) + 1;
}
#pragma endregion

#pragma region Get SubTree
//template <typename K, typename E>
//int BinaryTree<K, E>::getSubtree(TNode<K, E>* root, int sampKey)
//{
//    // Check if the tree is empty
//    if (root == nullptr)
//    {
//        return nullptr;
//    }
//
//    // Check if the root node has the value we are looking for
//    if (root->sampKey == sampKey)
//    {
//        return root;
//    }
//
//    // Recursively search the left and right subtrees
//    TNode<K, E>* leftSubtree = getSubtree(root->getLeft(), sampKey);
//    TNode<K, E>* rightSubtree = getSubtree(root->getRight(), sampKey);
//
//    // Return the subtree that contains the value, or nullptr if it is not found
//    if (leftSubtree != nullptr)
//    {
//        return leftSubtree;
//    }
//    else if (rightSubtree != nullptr)
//    {
//        return rightSubtree;
//    }
//    else
//    {
//        return nullptr;
//    }
//}
#pragma endregion

#pragma region Balance
template <typename K, typename E>
int BinaryTree<K, E>::height(TNode<K, E>* root)
{
    if (root == nullptr)
        return 0;
    return 1 + max(height(root->getLeft()), height(root->getRight()));
}
template <typename K, typename E>
int BinaryTree<K, E>::isBalanced(TNode<K, E>* root)
{
    if (root == nullptr)
        return true;
    int lh = height(root->getLeft());
    int rh = height(root->getRight());

    return (abs(lh - rh) <= 1 & isBalanced(root->getLeft()) & isBalanced(root->getRight()));
}
#pragma endregion

#pragma region Get Height

#pragma region Get Max Tree Height

template <typename K, typename E>
int BinaryTree<K, E>::findMaxTreeHeight(TNode<K, E>* root)
{
    if (root == nullptr)
        return 0;
    int leftHeight = findMaxTreeHeight(root->getLeft());
    int rightHeight = findMaxTreeHeight(root->getRight());

    return max(leftHeight, rightHeight) + 1;
}

#pragma endregion

#pragma region Get Min Tree Height

template <typename K, typename E>
int BinaryTree<K, E>::findMinTreeHeight(TNode<K, E>* root)
{
    if (root == nullptr)
        return 0;
    //Traverse the tree in a depth-first manner, starting from the root node.
    int leftHeight = findMinTreeHeight(root->getLeft());
    //For each node visited, calculate its height by comparing the height of its left and right subtrees.
    int rightHeight = findMinTreeHeight(root->getRight());
    //The height of a node is equal to the maximum height of its subtrees, plus 1.
    return min(leftHeight, rightHeight) + 1;
}

#pragma endregion

#pragma endregion

#pragma region Count

template <typename K, typename E>
int BinaryTree<K, E>::count()
{
    if (root == nullptr)
        return 0;
    return root->count();
}

#pragma endregion


#pragma region Prints

#pragma region Print in Order

template<typename K, typename E>
void BinaryTree<K, E>::printInOrder()
{
    this->printInOrder(root);
    cout << endl;
}

template<typename K, typename E>
void BinaryTree<K, E>::printInOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {
        printInOrder(node->getLeft());
        cout << node->getItem() << " ";
        printInOrder(node->getRight());
    }
}

#pragma endregion
    
#pragma region Print in Pre-Order

template<typename K, typename E>
void BinaryTree<K, E>::printPreOrder()
{
    this->printPreOrder(root);
    cout << endl;
}

template<typename K, typename E>
void BinaryTree<K, E>::printPreOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {
        cout << node->getItem() << " ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

#pragma endregion

#pragma region Print in Post-Order

template<typename K, typename E>
void BinaryTree<K, E>::printPostOrder()
{
    this->printPostOrder(root);
    cout << endl;
}
template<typename K, typename E>
void BinaryTree<K, E>::printPostOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {

        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getItem() << " ";
    }
}

#pragma endregion

#pragma endregion