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
    void clear();
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    void PrintInOrder(TNode<K,E>* node);
    void PrintPreOrder(TNode<K, E>* node);
    void PrintPostOrder(TNode<K, E>* node);
	bool Search(K KeyItem);
	int Depth(K KeyItem);
	int Height();
	void SubTree(K keyItem, E Data);





//	bool search(K KeyItem, E DataItem)
//	{
//
//	TNode<K, E>* toBeFound = root;
//	bool found = false;
//
//	while (!found && toBeFound != nullptr)
//	{
//		if (toBeFound->getData() == DataItem)
//		{
//			found = true;
//			return toBeFound;
//		}
//		else
//		{
//			if (toBeFound->getData() > DataItem)
//			{
//				toBeFound = toBeFound->getLeft();
//			}
//			else
//			{
//				toBeFound = toBeFound->getRight();
//			}
//		}
//	}
//	if (!found)
//		return nullptr;
//}



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



//Delete Function
template <typename K, typename E>
bool BinaryTree<K, E>::Delete(K keyItem, E Dataitem)
{
	TNode<K, E>* toBeRemoved = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && toBeRemoved != nullptr)
	{

		if (toBeRemoved->getData() == Dataitem && toBeRemoved->getKey() == keyItem){

			found = true;
		}
		else{
			parent = toBeRemoved;
			if (toBeRemoved->getData() > Dataitem && toBeRemoved->getKey() > keyItem){
				toBeRemoved = toBeRemoved->getLeft();
			}
			else{
				toBeRemoved = toBeRemoved->getRight();
			}
		}
	}
	if (!found)
		return false;

	if (toBeRemoved->getLeft() == nullptr || toBeRemoved->getRight() == nullptr){
		TNode<K, E>* newChild;
		if (toBeRemoved->getLeft() == nullptr){

			newChild = toBeRemoved->getRight();
		}
		else{
			newChild = toBeRemoved->getLeft();
		}
		if (parent == nullptr){
			root = newChild;
		}
		else if (parent->getLeft() == toBeRemoved){
			parent->setLeft(newChild);
		}
		else{
			parent->setRight(newChild);
		}
		return true;
	}

	TNode<K, E>* smallestParent = toBeRemoved;
	TNode<K, E>* smallest = toBeRemoved->getRight();
	while (smallest->getLeft() != nullptr){
		
		smallestParent = smallest;
		
		smallest = smallest->getLeft();
	}
	toBeRemoved->setData(smallest->getData());
	if (smallestParent == toBeRemoved){

		smallestParent->setRight(smallest->getRight());
	}
	else{
		smallestParent->setLeft(smallest->getRight());
	}

}



template <typename K, typename E>
void BinaryTree<K, E>::clear()
{
    delete root;
    root = nullptr;
}


template<typename K, typename E>
void BinaryTree<K, E>::PrintInOrder()
{
    this->printInOrder(root);
    cout << endl;
}


template<typename K, typename E>
void BinaryTree<K, E>::PrintInOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {
        printInOrder(node->getLeft());
        cout << node->getItem() << " ";
        printInOrder(node->getRight());
    }
}


template<typename K, typename E>
void BinaryTree<K, E>::PrintPreOrder()
{
    this->printPreOrder(root);
    cout << endl;
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintPreOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {
        cout << node->getItem() << " ";
        printPreOrder(node->getLeft());
        printPreOrder(node->getRight());
    }
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintPostOrder()
{
    this->printPostOrder(root);
    cout << endl;
}
template<typename K, typename E>
void BinaryTree<K, E>::PrintPostOrder(TNode<K, E>* node)
{

    if (node != nullptr)
    {

        printPostOrder(node->getLeft());
        printPostOrder(node->getRight());
        cout << node->getItem() << " ";
    }
}



template <typename K, typename E>
bool BinaryTree<K, E>::Search(K keyItem)
{
	TNode<K, E>* toBeSearched = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && toBeSearched != nullptr){

		if (toBeSearched->getKey() == keyItem){
			found = true;
		}
		else{
			parent = toBeSearched;

			if (toBeSearched->getKey() > keyItem){
				toBeSearched = toBeSearched->getLeft();
			}
			else{
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return false;
}


template <typename K, typename E>
int BinaryTree<K, E>::Depth(K keyItem){

	TNode<K, E>* toBeSearched = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;
	int DepthCounter = -1;

	while (!found && toBeSearched != nullptr) {

		DepthCounter++;

		if (toBeSearched->getKey() == keyItem) {
			found = true;
			return DepthCounter;
		}
		else {
			parent = toBeSearched;

			if (toBeSearched->getKey() > keyItem) {
				toBeSearched = toBeSearched->getLeft();
			}
			else {
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return 0;

}


template <typename K, typename E>
int BinaryTree<K, E>::Height(){

	TNode<K, E>* toBeSearched = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;
	int HeightCounter = 0;

	while (!found && toBeSearched != nullptr){

		HeightCounter++;

		if (toBeSearched->getRight() == nullptr && toBeSearched->getLeft() == nullptr){
			found = true;
			return HeightCounter;

		}
		else {
			parent = toBeSearched;

			if (toBeSearched->getLeft != nullptr){
				toBeSearched = toBeSearched->getLeft();
			}
			else if(toBeSearched->getRight != nullptr) {
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return 0;

}




template <typename K, typename E>
void BinaryTree<K, E>::SubTree(K keyItem, E Data){




}