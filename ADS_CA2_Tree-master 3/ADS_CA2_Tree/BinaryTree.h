#pragma once
#include "../ADS_CA2_Tree/TNode.h"
//if E == Student (email, dob, address, id,...)
//then K = Key(email, dob, address)

template <typename K, typename E>
class BinaryTree
{

	int addItemToArray(TNode<K, E>* node, int& pos, int* arr);

public:


	TNode<K, E> *root;
	BinaryTree();
	void add(K KeyItem, E DataItem);
	bool Delete(K KeyItem, E DataItem);
	bool Search(E Dataitem);
    int count();
    void clear();
    void PrintInOrder();
    void PrintPreOrder();
    void PrintPostOrder();
    void PrintInOrder(TNode<K,E>* node);
    void PrintPreOrder(TNode<K, E>* node);
    void PrintPostOrder(TNode<K, E>* node);
	int Depth(K KeyItem);
	int Height();
	void SubTree(TNode<K, E>* node);
	void BalancedTree();
	void Balance();
};



//Setting root as null pointer
template<typename K, typename E>
BinaryTree<K, E>::BinaryTree() {
	root = nullptr;
}









//Add Function
template<typename K, typename E>
void BinaryTree<K, E>::add(K KeyItem, E DataItem) {
	if (root == nullptr){
		root = new TNode<K, E>();
        root->setKey(KeyItem);
		root->setData(DataItem);
	}
	else{
		root->add(KeyItem, DataItem);
	}
}










//Search Function
template <typename K, typename E>
bool BinaryTree<K, E>::Search(E DataItem){
	//create Searcher which finds the node we want
	TNode<K, E>* Searcher = root;
	bool found = false;

	//while what were looking for isnt found and our Searcher exists
	while (!found && Searcher != nullptr){

		//if our Searcher is equal to the data its looking at we set found to true
		if (Searcher->getData() == DataItem){
			found = true;
		}
		//if what were looking for is smaller than the item were on, go right, if not we go left
		else {
			if (Searcher->getData() < DataItem){
				Searcher = Searcher->getRight();
			}
			if (Searcher->getData() > DataItem){
				Searcher = Searcher->getLeft();
			}
		}
	}
	if (!found)
		return false;
}









//Count Function
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
	//create Remover which searches out what we want removed 
	TNode<K, E>* Remover = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;

	while (!found && Remover != nullptr){

		//if the Remover is equal to the data and key, set found to true
		if (Remover->getData() == Dataitem && Remover->getKey() == keyItem){
			found = true;
		}

		else{
			parent = Remover;

			//if the Remover is bigger than our data and key, go left, if not go right, 
			if (Remover->getData() > Dataitem && Remover->getKey() > keyItem){
				Remover = Remover->getLeft();
			}
			else{
				Remover = Remover->getRight();
			}
		}
	}
	if (!found)
		return false;

	//if left or right of Remover is empty then set Remover as child there
	if (Remover->getLeft() == nullptr || Remover->getRight() == nullptr){
		TNode<K, E>* newChild;
		if (Remover->getLeft() == nullptr){

			newChild = Remover->getRight();
		}
		else{
			newChild = Remover->getLeft();
		}
		if (parent == nullptr){
			root = newChild;
		}
		else if (parent->getLeft() == Remover){
			parent->setLeft(newChild);
		}
		else{
			parent->setRight(newChild);
		}
		return true;
	}

	TNode<K, E>* smallestParent = Remover;
	TNode<K, E>* smallest = Remover->getRight();
	while (smallest->getLeft() != nullptr){
		
		smallestParent = smallest;
		smallest = smallest->getLeft();
	}
	Remover->setData(smallest->getData());
	if (smallestParent == Remover){

		smallestParent->setRight(smallest->getRight());
	}
	else{
		smallestParent->setLeft(smallest->getRight());
	}

}








//Clear Function
template <typename K, typename E>
void BinaryTree<K, E>::clear(){
    delete root;
    root = nullptr;
}










//Print Functions
template<typename K, typename E>
void BinaryTree<K, E>::PrintInOrder(){
    this-> printInOrder();
    cout << endl;
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintInOrder(TNode<K, E>* node){

    if (node != nullptr){
        PrintInOrder(node->getLeft());
        cout << node->getData() << " ";
        PrintInOrder(node->getRight());
    }
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintPreOrder(){
    this->PrintPreOrder(root);
    cout << endl;
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintPreOrder(TNode<K, E>* node){

    if (node != nullptr){
        cout << node->getData() << " ";
		PrintPreOrder(node->getLeft());
		PrintPreOrder(node->getRight());
    }
}

template<typename K, typename E>
void BinaryTree<K, E>::PrintPostOrder(){
    this->PrintPostOrder(root);
    cout << endl;
}
template<typename K, typename E>
void BinaryTree<K, E>::PrintPostOrder(TNode<K, E>* node){

    if (node != nullptr){

		PrintPostOrder(node->getLeft());
		PrintPostOrder(node->getRight());
        cout << node->getData() << " ";
    }
}










//Depth Function
template <typename K, typename E>
int BinaryTree<K, E>::Depth(K keyItem){

	TNode<K, E>* toBeSearched = root;
	TNode<K, E>* parent = nullptr;
	bool found = false;
	//Create Depth Counter to track how many times we move down the tree
	int DepthCounter = -1;

	//Everytime we dont find our bottom node we move down and add to out depth counter
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










//Height Function
//Code not 100% functional
template <typename K, typename E>
int BinaryTree<K, E>::Height(){

	//Code goes down through the tree similar to depth and when it finds a node with no children we return true, finds a path to the end but not the longest path
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

			if (toBeSearched->getLeft() != nullptr) {
				toBeSearched = toBeSearched->getLeft();
			}
			else if(toBeSearched->getRight() != nullptr) {
				toBeSearched = toBeSearched->getRight();
			}
		}
	}
	if (!found)
		return 0;

}









//Subtree Function
template<typename K, typename E>
void BinaryTree<K, E>::SubTree(TNode<K, E>* node) {

	BinaryTree<K, E> tree;
	if (node == nullptr) {
		tree.root = node;
	}

	return BinaryTree();

}








//Balance Function
template<typename K, typename E>
void BalancedTree(BinaryTree<K, E>& tree, int min, int max, int arr)
{
	if (min < max){

		int mid = (min + max) / 2;
		tree.add(arr[mid]);
		BalancedTree(tree, min, mid, arr);
		BalancedTree(tree, mid + 1, max, arr);
	}
}

//Balance Funstion
template<typename K, typename E>
void Balance(BinaryTree<K, E>& tree){

	int min;
	int max;
	int mid;
	int array[];

	array = tree.addItemToArray();
	int max = tree.count();
	tree.clear();
	BalancedTree(tree, min, max, array);
	delete[] array;

}