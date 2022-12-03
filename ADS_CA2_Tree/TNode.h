#pragma once

template <typename K, typename E>
class TNode {
	
private:
	/// <summary>
	/// A subset of the main data used to generate a unique number for the node
	/// </summary>
	K key;
	/// <summary>
	/// The actual data that the node stores e.g. Person, Record, Student
	/// </summary>
	E data;

	/// <summary>
	/// Pointers to the two kids. Go left if new data key < key for this node, else go right
	/// </summary>
	TNode* pLeft, * pRight;

public:
	TNode();
	~TNode();
	TNode(K key, E data);
	bool insert(K key, E data) {
		return false;
	}
	
	int count();
	void add(K key, E item);
	void setData(E data) { this->data = data; }
	TNode<K, E>* getParent();
	E getData() const { return this->data; }
	TNode<K, E>* getLeft();
	TNode<K, E>* getRight();
	void setLeft(TNode<K, E>* l);
	void setRight(TNode<K, E>* r);
	E getItem();
	void setItem(K, E item);
};

template <typename K, typename E>
TNode<K, E>::~TNode()
{
	delete pLeft;
	delete pRight;
}
template <typename K, typename E>
E TNode<K, E>::getItem()
{
	return this->data;
}
template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getLeft()
{
	return this->pLeft;
}
template <typename K, typename E>
TNode<K, E>* TNode<K, E>::getRight()
{
	return this->pRight;
}
template <typename K, typename E>
void TNode<K, E>::setLeft(TNode<K, E>* l)
{
	this->left = l;
}
template <typename K, typename E>
void TNode<K, E>::setRight(TNode<K, E>* r)
{
	this->pRight = l;
}

template <typename K, typename E>
TNode<typename K, typename E>::TNode()
{
	pLeft = nullptr;
	pRight = nullptr;
}
template <typename K, typename E>
TNode<typename K, typename E>::TNode(K key, E data)
{
	pLeft = nullptr;
	pRight = nullptr;
	this->key = key;
	this->data = data;
}
template <typename K, typename E>
int TNode<K, E>::count()
{
	int c = 1;
	if (pLeft != nullptr)
	{
		c += left->count();
	}
	if (pRight != nullptr)
	{
		c += right->count();
	}
	return c;
}
template <typename K, typename E>
void TNode<K, E>::add(K key, E item)
{
	if (item == this->data && key == this->key)
	{
		return;
	}
	else if (item < this->data && key < this->key)
	{
		if (pLeft == nullptr)
		{
			pLeft = new TNode<K, E>();
			pLeft->data = item;
			pLeft->parent = this;
		}
		else
		{
			left->add(item);
		}
	}
	else
	{
		if (right == nullptr)
		{
			right = new TNode<K, E>();
			right->data = item;
			right->parent = this;
		}
		else
		{
			right->add(item);
		}
	}
}
template <typename K, typename E>
void TNode<K, E>::setItem(K key, E item)
{
	this->data = item;
}