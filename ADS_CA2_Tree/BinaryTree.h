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
    int scanDepth(TNode<K, E>* root, K key);
    bool boolSearchNode(K key);
    int findMaxTreeHeight(TNode<K, E>* root);
    int findMinTreeHeight(TNode<K, E>* root);
};
template <typename K, typename E>
BinaryTree<K, E>::BinaryTree()
{
	root = nullptr;
}

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
    /*return true;*/
}
template <typename K, typename E>
bool BinaryTree<K, E>::boolSearchNode(K key)
{
    TNode<K, E>* toBeSearch = root;
    TNode<K, E>* parent = nullptr;
    bool found = false;

    while (!found && toBeSearch != nullptr)
    {

        if (toBeSearch->getKey() == key)
        {
            found = true;
        }
        else
        {
            parent = toBeSearch;
            if (toBeSearch->getKey() > key)
            {
                toBeSearch = toBeSearch->getLeft();
            }
            else
            {
                toBeSearch = toBeSearch->getRight();
            }
        }
    }
    if (!found)
        return false;
}
template <typename K, typename E>
int BinaryTree<K, E>::scanDepth(TNode<K, E>* root, K keySamp)
{
    if (root == NULL)
        return -1;

    int dist = -1;

    if ((root->getKey() == keySamp)

        || (dist = scanDepth(root->getLeft(), keySamp)) >= 0

        || (dist = scanDepth(root->getRight(), keySamp)) >= 0)

        return dist + 1;

    return dist;
}

// Function to find the height of
// a given node in a Binary Tree
//template <typename K, typename E>
//int BinaryTree<K, E>::findTreeHeight(TNode<K, E>* root, int keySamp)
//{
//    int h = 0;
//    int s = 0;
//    if (root != nullptr)
//    {
//        int lHeight = findTreeHeight(root->getLeft(), keySamp);
//        int rHeight = findTreeHeight(root->getRight(), keySamp);
//        int maxHeight = max(lHeight, rHeight);
//        h = maxHeight + 1;
//    }
//    else if(root != nullptr)
//    {
//        int lHeight = findTreeHeight(root->getLeft(), keySamp);
//        int rHeight = findTreeHeight(root->getRight(), keySamp);
//        int maxHeight = min(lHeight, rHeight);
//        s = maxHeight + 1;
//    }
//    return h, s;
//}
// 
template <typename K, typename E>
int BinaryTree<K, E>::findMaxTreeHeight(TNode<K, E>* root)
{
    if (root == NULL)
        return 0;
    int leftHeight = findMaxTreeHeight(root->getLeft());
    int rightHeight = findMaxTreeHeight(root->getRight());

    return max(leftHeight, rightHeight) + 1;
}
template <typename K, typename E>
int BinaryTree<K, E>::findMinTreeHeight(TNode<K, E>* root)
{
    if (root == NULL)
        return 0;
    int leftHeight = findMinTreeHeight(root->getLeft());
    int rightHeight = findMinTreeHeight(root->getRight());

    return min(leftHeight, rightHeight) + 1;
}


template <typename K, typename E>
int BinaryTree<K, E>::count()
{
    if (root == nullptr)
        return 0;
    return root->count();
}

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