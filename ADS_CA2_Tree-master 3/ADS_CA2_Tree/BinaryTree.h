#pragma once
#include "../ADS_CA2_Tree/TNode.h"
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{

	void addItemToArray(TNode<K, E>* node, int& pos, int* arr);




public:


	TNode<K, E> *root;
	BinaryTree();
	void add(K KeyItem, E DataItem);
	bool Delete(K KeyItem, E DataItem);
    int count();
	E* search(K key) {
		return nullptr;
	}
};



template<typename K, typename E>
BinaryTree<K, E>::BinaryTree() {
	root = nullptr;
}


template<typename K, typename E>
void BinaryTree<K, E>::add(K KeyItem, E DataItem) {
	if (root == nullptr)
	{
		root = new TNode<K, E>();
        root->setKey(KeyItem);
		root->setData(DataItem);
	}
	else {
		root->add(KeyItem, DataItem);
	}
}


template <typename K, typename E>
int BinaryTree<K, E>::count()
{
    if (root == nullptr)
        return 0;
    return root->count();
}


template <typename K, typename E>
bool BinaryTree<K, E>::Delete(K keyItem, E Dataitem)
{
    TNode<K, E>* toBeRemoved = root;
    TNode<K, E>* parent = nullptr;
    bool found = false;

    while (!found && toBeRemoved != nullptr)
    {

        if (toBeRemoved->getData() == Dataitem && toBeRemoved->getKey() == keyItem)
        {

            found = true;
        }
        else
        {
            parent = toBeRemoved;
            if (toBeRemoved->getData() > Dataitem && toBeRemoved->getKey() > keyItem)
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
    toBeRemoved->setData(smallest->getData());
    if (smallestParent == toBeRemoved)
    {
        smallestParent->setRight(smallest->getRight());
    }
    else
    {
        smallestParent->setLeft(smallest->getRight());
    }

}