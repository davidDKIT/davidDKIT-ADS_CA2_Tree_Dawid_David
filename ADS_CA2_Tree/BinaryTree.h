#pragma once
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)
#include "TNode.h"
template <typename K, typename E>
class BinaryTree
{
public:
	TNode<K, E> *root;
	void add(K, E item);
	BinaryTree();
	E* search(K key) {
		return nullptr;
	}
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
		root->setItem(keySamp, item);
		/*root->setItem(item);*/
	}
	else
	{
		root->add(keySamp, item);
	}
}
